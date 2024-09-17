/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getPermutation = function(n, k) {
    let numbers = [];
    let factorial = 1;
    for (let i = 1; i <= n; i++) {
        numbers.push(i);
        factorial *= i;
    }
    
    k--; // Convert k to zero-based index
    let result = '';
    
    for (let i = 0; i < n; i++) {
        factorial = Math.floor(factorial / (n - i));
        let index = Math.floor(k / factorial);
        result += numbers[index];
        numbers.splice(index, 1);
        k %= factorial;
    }
    
    return result;
};
