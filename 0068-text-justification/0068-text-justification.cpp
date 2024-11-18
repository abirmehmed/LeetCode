#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> justifiedText;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLength = 0;
            std::vector<std::string> lineWords;

            // Greedily add words to the line until maxWidth is exceeded
            while (i < n && lineLength + words[i].length() + lineWords.size() <= maxWidth) {
                lineWords.push_back(words[i]);
                lineLength += words[i].length();
                i++;
            }

            // Create the justified line
            std::string line;
            int spacesNeeded = maxWidth - lineLength;

            // If it's the last line or a single word, left-justify
            if (i >= n || lineWords.size() == 1) {
                for (int j = 0; j < lineWords.size(); j++) {
                    line += lineWords[j];
                    if (j < lineWords.size() - 1) { // Add a space after each word except the last
                        line += ' ';
                    }
                }
                // Add remaining spaces to the end
                while (line.length() < maxWidth) {
                    line += ' ';
                }
            } else {
                // Distribute spaces between words
                int gaps = lineWords.size() - 1; // Number of gaps between words
                int evenSpaces = spacesNeeded / gaps; // Base number of spaces per gap
                int extraSpaces = spacesNeeded % gaps; // Extra spaces to distribute

                for (int j = 0; j < lineWords.size(); j++) {
                    line += lineWords[j];
                    if (j < gaps) { // Add spaces only between words
                        int spaceToAdd = evenSpaces + (j < extraSpaces ? 1 : 0); // Add an extra space if needed
                        line.append(spaceToAdd, ' ');
                    }
                }
            }

            justifiedText.push_back(line);
        }

        return justifiedText;
    }
};

