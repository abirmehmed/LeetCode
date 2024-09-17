impl Solution {
    pub fn get_permutation(n: i32, k: i32) -> String {
        let n = n as usize;
        let mut numbers: Vec<i32> = (1..=n as i32).collect();
        let mut factorial = (1..=n).product::<usize>();
        let mut k = k as usize - 1; // Convert k to zero-based index
        let mut result = String::new();
        
        for i in 0..n {
            factorial /= n - i;
            let index = k / factorial;
            result.push_str(&numbers[index].to_string());
            numbers.remove(index);
            k %= factorial;
        }
        
        result
    }
}
