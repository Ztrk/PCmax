#ifndef GENETIC_ALGORITHM_H_GUARD
#define GENETIC_ALGORITHM_H_GUARD

#include <vector>
#include "Genome_permutation.h"
#include "Genetic_randoms.h"

class Genetic_algorithm {
public:
	Genetic_algorithm (int p, std::vector<int> tasks, unsigned population, unsigned best_chosen, unsigned random_chosen, double mutation_rate);
	void test();
	void print();
	int solve(int);
private:
	int processors;
	std::vector<int> jobs;
	std::vector<Genome_permutation> individuals;

	// initialized in constructor
	const unsigned population;
	const unsigned best_chosen;
	const unsigned random_chosen;
	const double mutation_rate;

	Genetic_randoms rng;
};

#endif
