class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3)
            return false;
        bool containsVowel = false;
        bool containsConsonant = false;
        for(auto &it : word) {
            it = tolower(it);
            if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u')
                containsVowel = true;
            else if(it >= 'a' && it <= 'z')
                containsConsonant = true;
            else if(!(it >= '0' && it <= '9'))
                return false;
        }
        return containsVowel && containsConsonant;
    }
};