#include <random>
#include "Genetic_randoms.h"
using namespace std;

Genetic_randoms::Genetic_randoms(int processors, int genes, int parents) : random_processor(0, processors - 1), 
random_gene(0, genes - 1), random_double(0.0, 1.0), 
random_parent1(0, parents - 1), random_parent2(0, parents - 2) {
	random_device rd;
	generator.seed(rd());
}

int Genetic_randoms::get_processor() {
	return random_processor(generator);	
}

int Genetic_randoms::get_gene() {
	return random_gene(generator);
}

double Genetic_randoms::get_double() {
	return random_double(generator);
}

int Genetic_randoms::get_parent1() {
	return random_parent1(generator);
}

int Genetic_randoms::get_parent2() {
	return random_parent2(generator);
}
