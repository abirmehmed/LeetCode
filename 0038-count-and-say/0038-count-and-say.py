class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 1:
            return "1"
        
        # Start with the base case
        result = "1"
        
        # Generate the sequence up to the nth term
        for _ in range(1, n):
            current = ""
            count = 1
            char = result[0]
            
            for i in range(1, len(result)):
                if result[i] == char:
                    count += 1
                else:
                    current += str(count) + char
                    char = result[i]
                    count = 1
            
            current += str(count) + char
            result = current
        
        return result
