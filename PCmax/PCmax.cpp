#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdexcept>

#include "LPT.h"
#include "Genetic_algorithm.h"
using namespace std;

int main(int argc, char **argv) {
	unsigned population = 50, best_chosen = 10, random_chosen = 15, time = 2;
	double mutation_rate = 0.01;

	if (argc >= 7 && strcmp(argv[1], "-p") ==  0) {
		try {
			population = stoul(argv[2]);
			best_chosen = stoul(argv[3]);
			random_chosen = stoul(argv[4]);
			mutation_rate = stod(argv[5]);
			time = stoul(argv[6]);
			if (best_chosen + random_chosen > population)
				throw invalid_argument("Populatiion must be greater or equal than best chosen + random chosen");
		}
		catch(logic_error &e) {
			cerr << e.what() << endl;
			cerr << "Using default values" << endl;
			population = 50, best_chosen = 10, random_chosen = 15, mutation_rate = 0.01, time = 2;
		}
	}

	int p, n, sum = 0;
	cin >> p >> n;
	vector<int> jobs(n);

	for (int i = 0; i < n; ++i) {
		cin >> jobs[i];
		sum += jobs[i];
	}


	//double lower_bound = max(static_cast<double>(sum)/p, static_cast<double>(*max_element(jobs.begin(), jobs.end())));

	Genetic_algorithm ga(p, jobs, population, best_chosen, random_chosen, mutation_rate);
	
	//cout << "List algorithm: " << list_algorithm(p, jobs) << endl;

	//cout << "LPT: " << lpt(p, jobs) << endl;
	//cout << "Lower bound: " << lower_bound << endl;
	
	//cout << "Genetic algorithm." << endl;
	cout << ga.solve(time) << endl;
	
	return 0;
}
