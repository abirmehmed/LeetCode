class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        StringBuilder result = new StringBuilder();
        int step = 2 * numRows - 2;

        for (int row = 0; row < numRows; row++) {
            for (int i = row; i < s.length(); i += step) {
                result.append(s.charAt(i));
                if (row > 0 && row < numRows - 1 && i + step - 2 * row < s.length()) {
                    result.append(s.charAt(i + step - 2 * row));
                }
            }
        }

        return result.toString();
    }
}
