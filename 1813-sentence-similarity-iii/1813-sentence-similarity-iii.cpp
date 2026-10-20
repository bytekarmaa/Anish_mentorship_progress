class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> a, b;
        string word;

        stringstream ss1(sentence1), ss2(sentence2);

        while (ss1 >> word) a.push_back(word);
        while (ss2 >> word) b.push_back(word);

        // Keep a as the shorter sentence
        if (a.size() > b.size()) swap(a, b);

        int n = a.size();
        int m = b.size();

        int i = 0;

        // Match the prefix
        while (i < n && a[i] == b[i]) {
            i++;
        }

        int j = 0;

        // Match the suffix without overlapping the prefix
        while (i + j < n &&
               a[n - 1 - j] == b[m - 1 - j]) {
            j++;
        }

        return i + j == n;
    }
};