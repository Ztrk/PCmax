#ifndef GENETIC_ALGORITHM_H_GUARD
#define GENETIC_ALGORITHM_H_GUARD

#include <vector>
#include "Genome_permutation.h"
#include "Genetic_randoms.h"

class Genetic_algorithm {
public:
	Genetic_algorithm(int, std::vector<int>);
	void test();
	void print();
	int solve(int);
private:
	int processors;
	std::vector<int> jobs;
	std::vector<Genome_permutation> individuals;

	// population is initialized in constructor
	const unsigned population;
	const unsigned best_chosen = 10;
	const unsigned random_chosen = 15;
	const double mutation_rate = 0.010;

	Genetic_randoms rng;
};

#endif
