class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        
        // Look at the string in pairs: (0,1), (2,3), (4,5)...
        for (int i = 0; i < s.length(); i += 2) {
            // If the two characters in the pair don't match, we need 1 change
            if (s[i] != s[i + 1]) {
                changes++;
            }
        }
        
        return changes;
    }
};