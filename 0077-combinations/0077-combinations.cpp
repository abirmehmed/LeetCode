#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result; // To store the final combinations
        std::vector<int> combination; // To store the current combination
        backtrack(result, combination, n, k, 1); // Start backtracking from 1
        return result;
    }

private:
    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& combination, int n, int k, int start) {
        // If the combination is of the right size, add it to the results
        if (combination.size() == k) {
            result.push_back(combination);
            return;
        }

        // Iterate through the numbers from 'start' to 'n'
        for (int i = start; i <= n; ++i) {
            combination.push_back(i); // Add the number to the current combination
            backtrack(result, combination, n, k, i + 1); // Recur with the next number
            combination.pop_back(); // Remove the last added number to backtrack
        }
    }
};
