class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int minEleInd = -1;

        int maxEleInd = -1;

        int maxEle = INT_MIN;

        for(int i = 0; i < n; i++){
            if(maxEle <= nums[i]){
                maxEle = nums[i];
            }
            
            else maxEleInd = i;
        }

        int minEle = INT_MAX;

        for(int i = n-1; i >= 0; i--){
            if(minEle >= nums[i]){
                minEle = nums[i];
            }
            
            else minEleInd = i;
        }

        if(minEleInd == -1) return 0;

        return maxEleInd - minEleInd + 1;


    }
};