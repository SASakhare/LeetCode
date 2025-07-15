class Solution {
public:
   bool isValid(const std::string& word) {
    int n = word.size();
    if (n < 3) {
        return false; // The word is too short
    }

    bool isVowel = false;
    bool isconso=false;
    for (char c : word) {
        if (std::isalpha(c) || std::isdigit(c)) { // Check if c is alphanumeric
            if (std::tolower(c) == 'a' || std::tolower(c) == 'e' || 
                std::tolower(c) == 'i' || std::tolower(c) == 'o' || 
                std::tolower(c) == 'u') {
                isVowel = true;
            }
            else if(std::isalpha(c)){
                isconso=true;
            }
        } else {
            return false; // Invalid character found
        }
    }

    return isVowel && isconso ; // True if it contains a vowel and all characters are valid
}
};