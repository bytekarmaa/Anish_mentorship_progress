class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      int n = nums.size();

      nums.insert(nums.end(),nums.begin(),nums.end());

      int m = nums.size();

      stack<int> st;

      st.push(nums[m-1]);
      nums[m-1] = -1;

      int j = m-2;

      while(j >= 0){
        int val = nums[j];

        while(!st.empty() && st.top() <= nums[j]) st.pop();

        if(st.empty()) nums[j] = -1;
        else nums[j] = st.top();

        st.push(val);

        j--;
      }

      vector<int> res(nums.begin(),nums.begin() + n);

        return res;
    }
};