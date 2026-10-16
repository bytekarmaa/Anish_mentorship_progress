class Solution {
public:

int subarray(vector<int> &nums, int k){
    int result = 0;
    unordered_map<int,int> mp;

    int i = 0;

    for(int j = 0; j < nums.size(); j++){
        mp[nums[j]]++;

       while(mp.size() > k){
        mp[nums[i]]--;
        if(mp[nums[i]] == 0) mp.erase(nums[i]);
        i++;
       }

       result += (j-i+1);
    }

    return result;
}


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarray(nums,k) - subarray(nums,k-1);
    }
};