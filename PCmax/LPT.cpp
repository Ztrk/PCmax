#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include "LPT.h"
using namespace std;


pair<int, vector<int>> list_algorithm(int processors, const vector<int> &jobs) {
	vector<int> processor_time(processors, 0);
	vector<int> jobs_assignment(jobs.size());

	for (unsigned i = 0; i < jobs.size(); ++i) {
		int job = jobs[i];

		int min_val = 0;
		for (int j = 0; j < processors; ++j) {
			if (processor_time[min_val] > processor_time[j]) {
				min_val = j;
			}
		}

		processor_time[min_val] += job;
		jobs_assignment[i] = min_val;
	}

	int max_val = 0;
	for (int i = 0; i < processors; ++i) {
		if (processor_time[max_val] < processor_time[i]) {
			max_val = i;
		}
	}
	
	return { processor_time[max_val], jobs_assignment };
}	

pair<int, vector<int>> lpt(int processors, vector<int> jobs) {
	sort(jobs.begin(), jobs.end(), greater<int>());	
	return list_algorithm(processors, jobs);
}
