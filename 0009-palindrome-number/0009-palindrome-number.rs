impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }

        if x < 10 {
            return true;
        }

        if x % 10 == 0 && x != 0 {
            return false;
        }

        let mut original = x;
        let mut reversed = 0;

        while original > reversed {
            reversed = reversed * 10 + original % 10;
            original /= 10;
        }

        original == reversed || original == reversed / 10
    }
}