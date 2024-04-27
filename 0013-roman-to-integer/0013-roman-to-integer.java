class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> values = new HashMap<>();
        values.put('I', 1);
        values.put('V', 5);
        values.put('X', 10);
        values.put('L', 50);
        values.put('C', 100);
        values.put('D', 500);
        values.put('M', 1000);
        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && values.get(s.charAt(i)) > values.get(s.charAt(i - 1))) {
                result += values.get(s.charAt(i)) - 2 * values.get(s.charAt(i - 1));
            } else {
                result += values.get(s.charAt(i));
            }
        }

        return result;
    }
}
