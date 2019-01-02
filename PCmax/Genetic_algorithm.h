#ifndef GENETIC_ALGORITHM_H_GUARD
#define GENETIC_ALGORITHM_H_GUARD

#include <vector>
#include "Genome.h"
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
	std::vector<Genome> individuals;

	const unsigned POPULATION = 50;
	const unsigned best_chosen = 15;
	const unsigned random_chosen = 10;
	const double mutation_rate = 0.005;

	Genetic_randoms rng;
};

#endif
