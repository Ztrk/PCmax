#include <vector>
#include <algorithm>
#include <iostream>

#include "Genome_permutation.h"
#include "Genetic_randoms.h"
#include "LPT.h"
using namespace std;

Genome_permutation::Genome_permutation(int p, vector<int> jobs, Genetic_randoms &rng) : processors(p), chromosome(jobs), rng(rng) { }


Genome_permutation &Genome_permutation::operator=(const Genome_permutation &g2) {
	this->chromosome = g2.chromosome;
	this->fitness = g2.fitness;
	return *this;
}


Genome_permutation crossover(const Genome_permutation &parent1, const Genome_permutation &parent2) {
    // Crossover by order
}


void Genome_permutation::mutate(double mutation_rate) {
    if (rng.get_double() < mutation_rate)
        swap(chromosome[rng.get_gene()], chromosome[rng.get_gene()]);
}


int Genome_permutation::get_fitness() {
	return fitness;
}

int Genome_permutation::score(const vector<int> &jobs) {
    fitness = list_algorithm(processors, chromosome).first;
}


void Genome_permutation::print() const {
    cout << fitness << endl;
    //for(int i : chromosome)
    //	cout << i << " ";
    //cout << endl;
}


bool operator<(const Genome_permutation& g1, const Genome_permutation& g2) {
	return g1.fitness < g2.fitness;
}
