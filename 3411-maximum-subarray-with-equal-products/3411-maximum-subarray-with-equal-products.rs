impl Solution {
    pub fn max_length(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut max_len = 1;

        for i in 0..n {
            let mut prod = 1u64;
            let mut g = 0u64;
            let mut l = 1u64;

            for j in i..n {
                let val = nums[j] as u64;
                prod *= val;
                
                // THE MAGIC BOUND:
                // Since max LCM is 2520 and max GCD is 10, their product is at most 25200.
                // If our product exceeds this, it can never equal lcm * gcd.
                if prod > 25200 {
                    break;
                }

                g = Self::gcd(g, val);
                l = Self::lcm(l, val);

                if prod == l * g {
                    max_len = max_len.max(j - i + 1);
                }
            }
        }
        max_len as i32
    }

    // Helper function for Greatest Common Divisor
    fn gcd(mut a: u64, mut b: u64) -> u64 {
        while b != 0 {
            let temp = b;
            b = a % b;
            a = temp;
        }
        a
    }

    // Helper function for Least Common Multiple
    fn lcm(a: u64, b: u64) -> u64 {
        if a == 0 || b == 0 { return 0; }
        a / Self::gcd(a, b) * b
    }
}