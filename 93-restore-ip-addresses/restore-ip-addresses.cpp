#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string current;
        backtrack(s, 0, 0, current, result);
        return result;
    }
    
private:
    void backtrack(const string& s, int start, int segments, string& current, vector<string>& result) {
        // If we've placed all 3 dots and used all characters
        if (segments == 4 && start == s.length()) {
            result.push_back(current);
            return;
        }
        
        // If we've placed all 3 dots but haven't used all characters
        if (segments == 4 || start == s.length()) {
            return;
        }
        
        // Try all possible segment lengths (1 to 3 digits)
        for (int len = 1; len <= 3 && start + len <= s.length(); len++) {
            string segment = s.substr(start, len);
            
            // Check if segment is valid
            if (isValidSegment(segment)) {
                // Save current length to backtrack
                int originalLength = current.length();
                
                // Add segment to current IP
                if (segments > 0) {
                    current += ".";
                }
                current += segment;
                
                // Recurse
                backtrack(s, start + len, segments + 1, current, result);
                
                // Backtrack
                current.resize(originalLength);
            }
        }
    }
    
    bool isValidSegment(const string& segment) {
        // Segment can't be empty or too long
        if (segment.empty() || segment.size() > 3) {
            return false;
        }
        
        // Segment can't have leading zero unless it's "0"
        if (segment[0] == '0' && segment.size() > 1) {
            return false;
        }
        
        // Segment must be between 0 and 255
        int value = stoi(segment);
        return value >= 0 && value <= 255;
    }
};