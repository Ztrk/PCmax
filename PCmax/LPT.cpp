#include <vector>
#include <algorithm>
#include <functional>
#include "LPT.h"
using namespace std;


int list_algorithm(int processors, const vector<int> &jobs) {
	vector<int> processor_time(processors, 0);

	for (unsigned i = 0; i < jobs.size(); ++i) {
		*min_element(processor_time.begin(), processor_time.end()) += jobs[i];
	}

	return *max_element(processor_time.begin(), processor_time.end());
}	

int lpt(int processors, vector<int> jobs) {
	sort(jobs.begin(), jobs.end(), greater<int>());	
	return list_algorithm(processors, jobs);
}
