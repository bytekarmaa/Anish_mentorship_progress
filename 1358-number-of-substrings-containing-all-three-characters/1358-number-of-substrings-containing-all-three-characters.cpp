class Solution {
public:
    int numberOfSubstrings(string s) {
        int arr[3] = {0,0,0};

        int n = s.size();

        int i = 0;
        int j = 0;

        int res = 0;

        while(j < n){
           arr[s[j] - 'a']++;

            while(arr[0] > 0 && (arr[1] > 0 && arr[2] > 0)){
                res +=( n - j);
                arr[s[i] -'a']--;
            i++;
            }
            j++;
        }

        return res;
    }
};