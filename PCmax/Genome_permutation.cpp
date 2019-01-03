#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

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
    unordered_map<unsigned, unsigned> sum;
    for (int i : parent1.chromosome) {
        if (sum.count(i) == 0)
            sum[i] = 1;
        else
            ++sum[i];
    }

    Genome_permutation child = parent1;

    unsigned begin = child.rng.get_gene(), end = child.rng.get_gene();

    if (begin > end)
        swap(begin, end);
    
    for (unsigned i = begin; i <= end; ++i) {
        --sum[child.chromosome[i]];
    }

    for (unsigned i = 0, j = 0; i < child.chromosome.size() && j < parent2.chromosome.size(); ++j) {
        if (i == begin) {
            i = end + 1;
        }

        if (sum[parent2.chromosome[j]] != 0) {
            --sum[parent2.chromosome[j]];
            child.chromosome[i] = parent2.chromosome[j];
            ++i;
        }
    }

    return child;
}


void Genome_permutation::mutate(double mutation_rate) {
    if (rng.get_double() < mutation_rate)
        swap(chromosome[rng.get_gene()], chromosome[rng.get_gene()]);
}


int Genome_permutation::get_fitness() {
	return fitness;
}

int Genome_permutation::score() {
    fitness = list_algorithm(processors, chromosome).first;
    return fitness;
}


void Genome_permutation::print() const {
    cout << fitness << endl;
    for(int i : chromosome)
    	cout << i << " ";
    cout << endl;
}


bool operator<(const Genome_permutation& g1, const Genome_permutation& g2) {
	return g1.fitness < g2.fitness;
}
