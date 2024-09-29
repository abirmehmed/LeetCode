class Solution {
    public boolean isNumber(String s) {
        boolean seenDigit = false;
        boolean seenDot = false;
        boolean seenExponent = false;
        boolean numAfterE = true;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (Character.isDigit(c)) {
                seenDigit = true;
                numAfterE = true;
            } else if (c == '+' || c == '-') {
                // Sign can only appear at the start or immediately after an 'e' or 'E'
                if (i > 0 && s.charAt(i - 1) != 'e' && s.charAt(i - 1) != 'E') {
                    return false;
                }
                // There must be something after the sign
                if (i == s.length() - 1) {
                    return false;
                }
            } else if (c == '.') {
                // Dot can only appear once and not after an exponent
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } else if (c == 'e' || c == 'E') {
                // Exponent can only appear once and must follow a digit
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                numAfterE = false; // Reset for checking digits after 'e'
            } else {
                return false; // Invalid character
            }
        }

        return seenDigit && numAfterE;
    }
}
