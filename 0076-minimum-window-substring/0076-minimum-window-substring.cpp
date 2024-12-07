#include <string>
#include <vector>
#include <limits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty()) return "";

        // Count characters in t
        std::vector<int> charCount(128, 0); // Assuming ASCII characters
        for (char c : t) {
            charCount[c]++;
        }

        int required = t.size();
        int left = 0, right = 0;
        int minLength = std::numeric_limits<int>::max();
        int minLeft = 0;
        
        int formed = 0; // To track how many unique characters in t are currently in the window
        std::vector<int> windowCounts(128, 0); // Current window character counts

        while (right < s.length()) {
            char c = s[right];
            windowCounts[c]++;

            // Only count when the character is part of t
            if (charCount[c] > 0 && windowCounts[c] <= charCount[c]) {
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
                if (charCount[c] > 0 && windowCounts[c] < charCount[c]) {
                    formed--;
                }

                left++;
            }

            // Keep expanding the right side of the window
            right++;
        }

        return minLength == std::numeric_limits<int>::max() ? "" : s.substr(minLeft, minLength);
    }
};