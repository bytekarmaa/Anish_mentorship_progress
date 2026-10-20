class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(),arr.end());

        const int mod = 1e9 + 7;

        int count = 0;

        int j = 0;
        int k = n-1;

        for(int i = 0; i < n; i++){
            int sum = target - arr[i];

             j = i+1;
             k = n-1;

             while(j < k){
                if(arr[j] + arr[k] < sum) j++;
                else if(arr[j] + arr[k] > sum) k--;

                else{
                    int ind = j;
                    while(ind <= k && arr[j] == arr[ind]){
                        ind++;
                       }

                       int len = ind - j;

                    if(ind > k) {
                        int s = len * (len - 1) / 2;
                        count = (count % mod + (s) % mod) % mod;
                        break;
                       }

                       

                       j = ind;

                       ind = k;



                       while(ind >= j && arr[k] == arr[ind]){
                            ind--;
                       }

                       int len2 = k - ind;

                       count = (count % mod + (len * len2) % mod) % mod;

                       k = ind;
                }
             }
        }

        return count;
    }
};