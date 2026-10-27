class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,int>> ele_ind;

        for(int i = 0; i < n; i++){
            ele_ind.push_back({nums[i],i});
        }

        sort(ele_ind.begin(),ele_ind.end());


        int first = -1;
        int last = -1;

        for(int i = 0; i < n; i++){
            int req_Val = ele_ind[i].first;

            if(req_Val != nums[i]){
                if(first == -1) first = i;
                last = i;
            }
        }

        if(first == -1) return 0;

        return last - first + 1;
    }
};