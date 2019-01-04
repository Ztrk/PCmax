#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

#include "LPT.h"
#include "Genetic_algorithm.h"
using namespace std;

int main() {
	int p, n, sum = 0;
	cin >> p >> n;
	vector<int> jobs(n);

	for (int i = 0; i < n; ++i) {
		cin >> jobs[i];
		sum += jobs[i];
	}

	int lower_bound = max(sum/p, *max_element(jobs.begin(), jobs.end()));

	Genetic_algorithm ga(p, jobs);
	
	cout << "List algorithm: " << list_algorithm(p, jobs) << endl;

	cout << "LPT: " << lpt(p, jobs) << endl;
	cout << "Lower bound: " << lower_bound << endl;
	
	cout << "Genetic algorithm." << endl;
	cout << ga.solve(15) << endl;
	
	return 0;
}
