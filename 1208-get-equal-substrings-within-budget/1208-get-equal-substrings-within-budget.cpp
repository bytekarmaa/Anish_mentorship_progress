class Solution {
public:
    int equalSubstring(string s, string t, int maxcost) {
        int n = s.size();

        int mx_len = 0;

        int i = 0;

        int j = 0;

        while(j < n){
            maxcost -= abs(s[j]-t[j]);

            while(maxcost < 0){
               maxcost += abs(s[i]-t[i]);
                i++;
            }

            mx_len = max(mx_len,j-i+1);
            j++;
        }

        return mx_len;
    }
};