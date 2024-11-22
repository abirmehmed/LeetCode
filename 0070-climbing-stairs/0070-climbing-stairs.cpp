class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1; // Base case: only one way to climb one step
        if (n == 2) return 2; // Base case: two ways to climb two steps

        int first = 1; // Ways to reach step 1
        int second = 2; // Ways to reach step 2
        int current;

        // Calculate ways for steps 3 to n
        for (int i = 3; i <= n; i++) {
            current = first + second; // Current ways is the sum of the last two
            first = second; // Move up the ladder
            second = current; // Update second to current
        }

        return second; // The result is in second (ways to reach step n)
    }
};