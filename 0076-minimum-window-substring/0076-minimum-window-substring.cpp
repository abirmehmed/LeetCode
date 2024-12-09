#include <string>
#include <unordered_map>
#include <limits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty()) return "";

        // Count characters in t
        std::unordered_map<char, int> charCount;
        for (char c : t) {
            charCount[c]++;
        }

        int required = charCount.size(); // Number of unique characters in t
        int formed = 0; // To track how many unique characters in t are currently in the window
        std::unordered_map<char, int> windowCounts; // Current window character counts

        int left = 0, right = 0; // Pointers for the sliding window
        int minLength = std::numeric_limits<int>::max(); // Initialize minLength to positive infinity
        int minLeft = 0; // Start index of the minimum window

        while (right < s.length()) {
            char c = s[right];
            windowCounts[c]++;

            // Only count when the character is part of t
            if (charCount.count(c) > 0 && windowCounts[c] == charCount[c]) {
                formed++;
            }

            // Try to contract the window until it ceases to be 'desirable'
            while (left <= right && formed == required) {
                c = s[left];

                // Update minimum window if this window is smaller
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minLeft = left;
                }

                // The character at the position pointed by `left` is no longer a part of the window
                windowCounts[c]--;
                if (charCount.count(c) > 0 && windowCounts[c] < charCount[c]) {
                    formed--;
                }

                left++; // Move left pointer to shrink the window
            }

            right++; // Move right pointer to expand the window
        }

        return minLength == std::numeric_limits<int>::max() ? "" : s.substr(minLeft, minLength);
    }
};