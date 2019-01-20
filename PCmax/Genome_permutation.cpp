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
    Genome_permutation child = parent1;
    unsigned begin = child.rng.get_gene(), end = child.rng.get_gene();

    if (begin > end)
        swap(begin, end);

    unordered_map<unsigned, unsigned> sum;

    // count tasks outside of [begin, end]
    for (unsigned i = 0; i < child.chromosome.size(); ++i) {
        if (i == begin) {
            i = end;
            continue;
        }

        if (sum.count(child.chromosome[i]) == 0)
            sum[child.chromosome[i]] = 1;
        else
            ++sum[child.chromosome[i]];
    }
    
    // if gene is counted replace by parent2 gene
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
    fitness = list_algorithm(processors, chromosome);
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
