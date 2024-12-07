#include <string>
#include <vector>
#include <limits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty()) return "";

     
        std::vector<int> charCount(128, 0); // Assuming ASCII characters
        for (char c : t) {
            charCount[c]++;
        }

        int required = t.size();
        int left = 0, right = 0;
        int minLength = std::numeric_limits<int>::max();
        int minLeft = 0;
        
        int formed = 0; 
        std::vector<int> windowCounts(128, 0); // Current window character counts

        while (right < s.length()) {
            char c = s[right];
            windowCounts[c]++;

           
            if (charCount[c] > 0 && windowCounts[c] <= charCount[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                c = s[left];

                
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minLeft = left;
                }

                windowCounts[c]--;
                if (charCount[c] > 0 && windowCounts[c] < charCount[c]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        return minLength == std::numeric_limits<int>::max() ? "" : s.substr(minLeft, minLength);
    }
};