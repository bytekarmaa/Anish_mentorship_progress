class Solution {
public:
    int minimumLength(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j && s[i] == s[j]) {
            char ch = s[i];

            // Move i forward
            while (i <= j && s[i] == ch) i++;

            // Move j backward
            while (j >= i && s[j] == ch) j--;
        }

     
        return j - i + 1;
    }
};
