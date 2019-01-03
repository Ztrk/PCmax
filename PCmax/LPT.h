#ifndef LPT_H_GUARD
#define LPT_H_GUARD

#include <vector>
#include <utility>

/**
*   list algorithm for PCmax problem
*   returns result(time) and 
*   assigment vector - on which processor the given job is executed
*/
std::pair<int, std::vector<int>> list_algorithm(int processors, const std::vector<int> &jobs);
std::pair<int, std::vector<int>> lpt(int processors, std::vector<int> jobs);

#endif
