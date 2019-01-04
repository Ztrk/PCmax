#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <chrono>
#include <utility>

#include "Genome.h"
#include "Genetic_algorithm.h"
#include "Genetic_randoms.h"
#include "LPT.h"
using namespace std;

Genetic_algorithm::Genetic_algorithm (int p, vector<int> tasks) : processors(p), jobs(tasks), population(30), rng(p, jobs.size(), population) {

	sort(jobs.begin(), jobs.end(), greater<int>());	

	auto lpt_result = lpt(p, jobs);
	individuals.push_back( Genome(p, lpt_result.first, lpt_result.second, rng) ); 

	for (unsigned i = 1; i < population; ++i) {
		individuals.push_back(Genome(p, jobs.size(), rng));
		individuals[i].score(jobs);
	} 
}


void Genetic_algorithm::print() {
	for (unsigned i = 0; i < individuals.size(); ++i) {
		cout << i << ". ";
		individuals[i].print();
	}
}


int Genetic_algorithm::solve (int sec) {
	int counter = 0;
	auto start = chrono::high_resolution_clock::now();
	auto time_limit = chrono::seconds(sec);

	while(chrono::high_resolution_clock::now() - start < time_limit)  {

		vector<Genome> new_individuals(individuals);
		sort(individuals.begin(), individuals.end());
				
		// takes individuals with best fitness
		for (unsigned i = 0; i < best_chosen; ++i)
			new_individuals[i] = individuals[i];

		/*for (unsigned i = best_chosen; i < 5; ++i) {
			new_individuals[i] = Genome(processors, jobs.size(), rng);
			new_individuals[i].score(jobs);
		}*/
		
		// takes random individuals
		sample(individuals.begin() + best_chosen, individuals.end(), 
				new_individuals.begin() + best_chosen, random_chosen, rng.get_generator());

		// generates children
		for (unsigned i = random_chosen + best_chosen; i < individuals.size(); ++i) {
			unsigned parent1 = rng.get_parent1();
			unsigned parent2 = rng.get_parent2();

			if(parent2 >= parent1)
				++parent2;

			Genome child = crossover(individuals[parent1], individuals[parent2]);
			child.mutate(mutation_rate);
			child.score(jobs);
			new_individuals[i] = child;
		}
		
		individuals = new_individuals;	
		
		/*Genome *worst = &individuals[0];
		for(Genome &g : individuals) {
			if(*worst < g)
				worst = &g;
		}

		if(child < *worst)
			*worst = child;
		*/	
		++counter;
	}
	
	cout << "Iterations: " << counter << endl;

	return min_element(individuals.begin(), individuals.end())->get_fitness();
}
