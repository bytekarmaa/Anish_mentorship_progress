class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i][i] == '0') {
                ans += '1';
            } else {
                ans += '0';
            }
        }
        return ans;
    }
};





// staright forward backtracking


// class Solution {
// public:

// unordered_map<string,int> mp;

// bool find(string ref, string &res,int n){
//     if(ref.size() == n){
//         if(!mp.count(ref)){
//             res = ref;
//             return true;
//         }

//         return false;
//     }

//     bool x = find(ref+'0',res,n);

//     if(x) return x;

//     bool y = find(ref + '1',res,n);

//     if(y) return y;

//     return x || y;
    
// }

//     string findDifferentBinaryString(vector<string>& nums) {
//         for(int i = 0; i < nums.size(); i++) mp[nums[i]];
//          string res = "";

//       find("",res, nums.size());

//       return res;
//     }

// };