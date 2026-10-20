class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;

        for (int i = n - 1; i >= 0; i--) {
            int maxi = 0;

            for (int j = 1; j <= i; j++) {
                if (arr[j] > arr[maxi]) {
                    maxi = j;
                }
            }

            if (maxi == i) continue;

            if (maxi != 0) {
                reverse(arr.begin(), arr.begin() + maxi + 1);
                ans.push_back(maxi + 1);
            }

            reverse(arr.begin(), arr.begin() + i + 1);
            ans.push_back(i + 1);
        }

        return ans;
    }
};