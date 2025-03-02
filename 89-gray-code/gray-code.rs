impl Solution {
    pub fn gray_code(n: i32) -> Vec<i32> {
        let mut result = vec![0]; // Start with 0

        for i in 0..n {
            let mask = 1 << i; // Create a mask for the current bit
            let mut new_sequence = result.clone(); // Clone the current sequence
            new_sequence.reverse(); // Reverse the sequence
            for &num in &new_sequence {
                result.push(num | mask); // Prefix with 1 using bitwise OR
            }
        }

        result
    }
}