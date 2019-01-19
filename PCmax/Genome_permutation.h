#ifndef GENOME_PERMUTATION_H_GUARD
#define GENOME_PERMUTATION_H_GUARD

#include <vector>
#include "Genetic_randoms.h"

/**
 * Solution is represented as a permutation of jobs 
 * feeded into list algorithm
*/
class Genome_permutation {
    friend Genome_permutation crossover(const Genome_permutation& , const Genome_permutation&);
	friend bool operator<(const Genome_permutation&, const Genome_permutation&);
public:
    Genome_permutation(int, std::vector<int>, Genetic_randoms &);
	Genome_permutation &operator=(const Genome_permutation &);

    void mutate(double mutation_rate);
	int get_fitness();
    int score();
    void print() const;
private:
	int processors;
    int fitness;
    std::vector<int> chromosome;
	Genetic_randoms &rng;
};

#endif
