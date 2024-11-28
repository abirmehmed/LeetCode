#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.size();
        int n = word2.size();
        
        // Create a DP table with (m+1) x (n+1)
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

        // Initialize base cases
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i; // Deleting all characters from word1
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j; // Inserting all characters to form word2
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // No operation needed
                } else {
                    dp[i][j] = std::min({ 
                        dp[i - 1][j] + 1,   // Deletion
                        dp[i][j - 1] + 1,   // Insertion
                        dp[i - 1][j - 1] + 1 // Replacement
                    });
                }
            }
        }

        return dp[m][n]; // The answer is in the bottom-right cell
    }
};