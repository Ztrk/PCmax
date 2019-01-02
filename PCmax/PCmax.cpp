#include <vector>
#include <iostream>
#include <random>
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

	Genetic_algorithm ga(p, jobs);
	
	cout << "List algorithm: " << list_algorithm(p, jobs).first << endl;


	cout << "LPT: " << lpt(p, jobs).first << endl;
	cout << "Lower bound: " << sum/p << endl;
	
	cout << "Genetic algorithm." << endl;
	cout << ga.solve(5) << endl;
	//ga.test();
	
	/*random_device rd;
	mt19937 gen(rd());
	for (int i = 0; i < 10000; ++i) {
		shuffle(jobs.begin(), jobs.end(), gen);	
		int tmp = list_algorithm(p, jobs); 
		cout << tmp << endl;
	}*/
	
	return 0;
}
