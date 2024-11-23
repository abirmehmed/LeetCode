#include <iostream>
#include <sstream>
#include <vector>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack; // To keep track of valid directories
        std::stringstream ss(path);
        std::string token;

        // Split the path by '/'
        while (std::getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                // Ignore empty tokens and current directory references
                continue;
            } else if (token == "..") {
                // Go up to the parent directory if possible
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                // Push valid directory names onto the stack
                stack.push_back(token);
            }
        }

        // Construct the simplified path
        std::string simplifiedPath = "/";
        for (size_t i = 0; i < stack.size(); i++) {
            simplifiedPath += stack[i];
            if (i < stack.size() - 1) { // Avoid adding '/' at the end
                simplifiedPath += "/";
            }
        }

        return simplifiedPath;
    }
};
