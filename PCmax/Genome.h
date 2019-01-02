#ifndef GENOME_H_GUARD
#define GENOME_H_GUARD

#include <vector>
#include "Genetic_randoms.h"

class Genome {
    friend Genome crossover(const Genome&, const Genome&);
	friend bool operator<(const Genome&, const Genome&);
public:
    Genome(int, int, Genetic_randoms &);
	Genome(int, int, std::vector<int>, Genetic_randoms &);
	Genome &operator=(const Genome &);

    void mutate(double mutation_rate);
	int get_fitness();
    int score(const std::vector<int> &);
    void print() const;
private:
	int processors;
    int fitness;
    std::vector<int> chromosome;
	Genetic_randoms &rng;
};

#endif
