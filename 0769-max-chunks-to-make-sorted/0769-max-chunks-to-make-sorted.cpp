class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int count = 0;

        int maxEle = -1;

        for(int i = 0; i < n; i++){
            maxEle = max(maxEle,arr[i]);

            if(maxEle == i) count++;
        }

        return count;
    }
};