#include "HeaderFiles/Helper.h"

char xToLabel(int x) {
    char label = '1';
    label += x;
    return label;
}
 
char yToLabel(int y) {
    char label = 'a';
    label += y;
    return label;
}
 
int labelToX(char x) {
    int val = (int)x;
    val -= '1';
    return val;
}
 
int labelToY(char y) {
    int val = (int)y;
    val -= 'a';
    return val;
}

std::string cleanInput(const std::string& s) {
    std::string result;
 
    // Check if user entered a sentence or multiple words
    bool multiple_words = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            multiple_words = true;
        }
    }
 
    // If the user did input multiple words, just use the last word
    if (multiple_words) {
        int pos = s.find_last_of(' ');
        result = s.substr(pos + 1);
 
    } else {
 
        // Else, if only one word was entered, use it
        result = s;
    }
 
    for (int i = 0; i < result.length(); i++) {
 
        // Erase punctuation from the word
        if (ispunct(result[i])) result.erase(i--, 1);
 
        // Set the result to all lowercase
        result[i] = tolower(result[i]);
    }
 
    return result;
}