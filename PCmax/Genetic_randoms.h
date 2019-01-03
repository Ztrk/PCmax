#ifndef GENETIC_RANDOMS_H_GUARD 
#define GENETIC_RANDOMS_H_GUARD 

#include <random>

class Genetic_randoms {
private:
    std::mt19937 generator;
    std::uniform_int_distribution<int> random_processor;
    std::uniform_int_distribution<int> random_gene;
	std::uniform_real_distribution<double> random_double;
	std::uniform_int_distribution<int> random_parent1;
	std::uniform_int_distribution<int> random_parent2;
public:
	Genetic_randoms(int processors, int genes, int parents);
	
	int get_processor();
	int get_gene();
	double get_double();
	int get_parent1();
	int get_parent2();
	std::mt19937 get_generator();
};

#endif
