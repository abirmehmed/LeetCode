import java.util.ArrayList;
import java.util.List;

class Solution {
    public String getPermutation(int n, int k) {
        List<Integer> numbers = new ArrayList<>();
        int factorial = 1;
        for (int i = 1; i <= n; i++) {
            numbers.add(i);
            factorial *= i;
        }
        
        k--; // Convert k to zero-based index
        StringBuilder result = new StringBuilder();
        
        for (int i = 0; i < n; i++) {
            factorial /= (n - i);
            int index = k / factorial;
            result.append(numbers.get(index));
            numbers.remove(index);
            k %= factorial;
        }
        
        return result.toString();
    }
}
