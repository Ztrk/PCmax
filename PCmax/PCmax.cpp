#include <vector>
#include <iostream>
#include <algorithm>

#include "LPT.h"
#include "Genetic_algorithm.h"
using namespace std;

int main() {
	unsigned population = 50, best_chosen = 10, random_chosen = 15, mutation_rate = 0.01;

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
	cout << ga.solve(2) << endl;
	
	return 0;
}
