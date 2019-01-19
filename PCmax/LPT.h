#ifndef LPT_H_GUARD
#define LPT_H_GUARD

#include <vector>
#include <utility>

/**
*   list algorithm for PCmax problem
*   returns result(time)
*/
int list_algorithm(int processors, const std::vector<int> &jobs);
int lpt(int processors, std::vector<int> jobs);

#endif
