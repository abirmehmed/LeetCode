import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>(); // To store the final combinations
        List<Integer> combination = new ArrayList<>(); // To store the current combination
        backtrack(result, combination, n, k, 1); // Start backtracking from 1
        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> combination, int n, int k, int start) {
        // If the combination is of the right size, add it to the results
        if (combination.size() == k) {
            result.add(new ArrayList<>(combination)); // Add a copy of the current combination
            return;
        }

        // Iterate through the numbers from 'start' to 'n'
        for (int i = start; i <= n; i++) {
            combination.add(i); // Add the number to the current combination
            backtrack(result, combination, n, k, i + 1); // Recur with the next number
            combination.remove(combination.size() - 1); // Remove the last added number to backtrack
        }
    }
}
