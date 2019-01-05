#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include "LPT.h"
using namespace std;


int list_algorithm(int processors, const vector<int> &jobs) {
	priority_queue<int, vector<int>, greater<int>> processor_time(greater<int>(), vector<int>(processors, 0));

	int result = 0;
	for (unsigned i = 0; i < jobs.size(); ++i) {
		int min_proc = processor_time.top();
		processor_time.pop();
		processor_time.push(min_proc + jobs[i]);
		result = max(result, min_proc + jobs[i]);
	}

	return result;
}	

int lpt(int processors, vector<int> jobs) {
	sort(jobs.begin(), jobs.end(), greater<int>());	
	return list_algorithm(processors, jobs);
}
