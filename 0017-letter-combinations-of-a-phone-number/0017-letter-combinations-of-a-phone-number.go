package main

func letterCombinations(digits string) []string {
    if len(digits) == 0 {
        return []string{}
    }

    phone := map[rune]string{
        '2': "abc",
        '3': "def",
        '4': "ghi",
        '5': "jkl",
        '6': "mno",
        '7': "pqrs",
        '8': "tuv",
        '9': "wxyz",
    }

    combinations := []string{""}
    for _, digit := range digits {
        var temp []string
        for _, combination := range combinations {
            for _, letter := range phone[digit] {
                temp = append(temp, combination+string(letter))
            }
        }
        combinations = temp
    }
    return combinations
}
