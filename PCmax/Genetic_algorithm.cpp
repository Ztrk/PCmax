#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <chrono>

#include "Genome_permutation.h"
#include "Genetic_algorithm.h"
#include "Genetic_randoms.h"
using namespace std;

Genetic_algorithm::Genetic_algorithm (int p, vector<int> tasks, unsigned population, unsigned best_chosen, unsigned random_chosen, double mutation_rate) 
: processors(p), jobs(tasks), population(population), best_chosen(best_chosen), mutation_rate(mutation_rate), rng(p, jobs.size(), population) 
{

	sort(jobs.begin(), jobs.end(), greater<int>());	

	individuals.push_back( Genome_permutation(processors, jobs, rng) ); 
	individuals[0].score();

	for (unsigned i = 1; i < population; ++i) {
		shuffle(jobs.begin(), jobs.end(), rng.get_generator());
		individuals.push_back(Genome_permutation(p, jobs, rng));
		individuals[i].score();
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

		vector<Genome_permutation> new_individuals(individuals);
		nth_element(individuals.begin(), individuals.begin() + best_chosen - 1, individuals.end());
				
		// takes individuals with best fitness
		for (unsigned i = 0; i < best_chosen; ++i)
			new_individuals[i] = individuals[i];

		// takes random individuals
		sample(individuals.begin() + best_chosen, individuals.end(), 
				new_individuals.begin() + best_chosen, random_chosen, rng.get_generator());

		// generates children
		for (unsigned i = random_chosen + best_chosen; i < individuals.size(); ++i) {
			unsigned parent1 = rng.get_parent1();
			unsigned parent2 = rng.get_parent2();

			if(parent2 >= parent1)
				++parent2;

			Genome_permutation child = crossover(individuals[parent1], individuals[parent2]);
			child.mutate(mutation_rate);
			child.score();
			new_individuals[i] = child;
		}
		
		individuals = new_individuals;	
		
		/*Genome_permutation *worst = &individuals[0];
		for(Genome_permutation &g : individuals) {
			if(*worst < g)
				worst = &g;
		}

		if(child < *worst)
			*worst = child;
		*/	
		++counter;
	}
	
	cout << counter << " ";

	return min_element(individuals.begin(), individuals.end())->get_fitness();
}
