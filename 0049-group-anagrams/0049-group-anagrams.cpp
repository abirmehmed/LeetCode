class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        
        for (const string& str : strs) {
            // Create a sorted key for the current string
            string key = str;
            sort(key.begin(), key.end());
            
            // Add the string to the corresponding anagram group
            anagramGroups[key].push_back(str);
        }
        
        // Extract the anagram groups from the hash map
        vector<vector<string>> result;
        for (const auto& entry : anagramGroups) {
            result.push_back(entry.second);
        }
        
        return result;
    }
};
