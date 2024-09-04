impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len();
        
        // Transpose the matrix
        for i in 0..n {
            for j in i+1..n {
                let temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        // Reverse each row
        for i in 0..n {
            matrix[i].reverse();
        }
    }
}
