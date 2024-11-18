import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> justifiedText = new ArrayList<>();
        int n = words.length;
        int i = 0;

        while (i < n) {
            int lineLength = 0;
            List<String> lineWords = new ArrayList<>();

            // Greedily add words to the line until maxWidth is exceeded
            while (i < n && lineLength + words[i].length() + lineWords.size() <= maxWidth) {
                lineWords.add(words[i]);
                lineLength += words[i].length();
                i++;
            }

            // Create the justified line
            StringBuilder line = new StringBuilder();
            int spacesNeeded = maxWidth - lineLength;

            // If it's the last line or a single word, left-justify
            if (i >= n || lineWords.size() == 1) {
                for (int j = 0; j < lineWords.size(); j++) {
                    line.append(lineWords.get(j));
                    if (j < lineWords.size() - 1) { // Add a space after each word except the last
                        line.append(' ');
                    }
                }
                // Add remaining spaces to the end
                while (line.length() < maxWidth) {
                    line.append(' ');
                }
            } else {
                // Distribute spaces between words
                int gaps = lineWords.size() - 1; // Number of gaps between words
                int evenSpaces = spacesNeeded / gaps; // Base number of spaces per gap
                int extraSpaces = spacesNeeded % gaps; // Extra spaces to distribute

                for (int j = 0; j < lineWords.size(); j++) {
                    line.append(lineWords.get(j));
                    if (j < gaps) { // Add spaces only between words
                        int spaceToAdd = evenSpaces + (j < extraSpaces ? 1 : 0); // Add an extra space if needed
                        for (int k = 0; k < spaceToAdd; k++) {
                            line.append(' ');
                        }
                    }
                }
            }

            justifiedText.add(line.toString());
        }

        return justifiedText;
    }
}

 