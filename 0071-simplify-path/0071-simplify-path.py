class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = []  # Stack to keep track of valid directories
        tokens = path.split("/")  # Split the path by '/'

        for token in tokens:
            if token == "" or token == ".":  # Ignore empty tokens and current directory references
                continue
            elif token == "..":  # Go up to the parent directory if possible
                if stack:
                    stack.pop()
            else:  # Push valid directory names onto the stack
                stack.append(token)

        # Construct the simplified path
        simplified_path = "/" + "/".join(stack)  # Join the directories with a single '/'
        
        return simplified_path

