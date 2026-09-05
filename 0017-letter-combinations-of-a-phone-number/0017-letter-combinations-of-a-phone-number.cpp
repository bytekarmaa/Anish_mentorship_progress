class Solution {
public:

void generate(string & digits, int ind, vector<string> &combination, unordered_map<int,string> &mp, string ref){
    if(ind == digits.size()){
        combination.push_back(ref);
        return;
    }

        for(auto ele : mp[digits[ind] - '0']){
            ref.push_back(ele);
            generate(digits,ind+1,combination,mp,ref);
            ref.pop_back();
        }
    
}

    vector<string> letterCombinations(string digits) {
        vector<string>combination;
        if(digits.size() == 0) return combination;
        unordered_map<int,string> mp;

        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        
        generate(digits,0,combination,mp,"");
        return combination;
    }
};