#include <random>
#include <vector>
#include <algorithm>
#include <iostream>

#include "Genome.h"
#include "Genetic_randoms.h"
using namespace std;

Genome::Genome(int p, int n, Genetic_randoms &rng) : processors(p), chromosome(n), rng(rng) {
    for(int &i : chromosome)
        i = rng.get_processor();
}


Genome::Genome(int p, int score, vector<int> assignment, Genetic_randoms &rng) : processors(p), fitness(score), 
chromosome(assignment), rng(rng) {}


Genome &Genome::operator=(const Genome &g2) {
	this->chromosome = g2.chromosome;
	this->fitness = g2.fitness;
	return *this;
}


Genome crossover(const Genome &parent1, const Genome &parent2) {
    Genome child = parent1;
	
	for (unsigned i = 0; i < child.chromosome.size(); ++i) {
		if (child.rng.get_double() < 0.5) 
			child.chromosome[i] = parent2.chromosome[i];
	}

    return child;
}


void Genome::mutate(double mutation_rate) {
	for (int &i : chromosome) {
		if (rng.get_double() < mutation_rate)
			i = rng.get_processor();	
	}
}


int Genome::get_fitness() {
	return fitness;
}

int Genome::score(const vector<int> &jobs) {
    vector<int> processors_time(processors);
	
	for (unsigned i = 0; i < chromosome.size(); ++i) {
		processors_time[chromosome[i]] += jobs[i];
	}
	
	fitness = *max_element(processors_time.begin(), processors_time.end());
	
	return fitness;
}


void Genome::print() const {
    cout << fitness << endl;
    //for(int i : chromosome)
    //	cout << i << " ";
    //cout << endl;
}


bool operator<(const Genome& g1, const Genome& g2) {
	return g1.fitness < g2.fitness;
}
