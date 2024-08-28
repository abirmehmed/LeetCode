class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        vector<int> result(len1 + len2, 0);

        // Reverse both numbers to facilitate multiplication from right to left
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j] += sum / 10;
                result[i + j + 1] = sum % 10;
            }
        }

        // Convert the result vector to a string
        string resultStr;
        for (int num : result) {
            if (!(resultStr.empty() && num == 0)) {
                resultStr.push_back(num + '0');
            }
        }

        return resultStr.empty() ? "0" : resultStr;
    }
};
