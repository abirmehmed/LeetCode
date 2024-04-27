class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> result;
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(digits, 0, "", result, mapping);
        return result;
    }

private:
    void backtrack(string& digits, int index, string current, vector<string>& result, vector<string>& mapping) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        string letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            backtrack(digits, index + 1, current + c, result, mapping);
        }
    }
};
