class Solution {
public:
void generate(string ref,vector<string> &res,int open,int close,int n){
    if(close == n){
        res.push_back(ref);
        return;
    }
    if(open < n) generate(ref+'(',res,open+1,close,n);
    if(close < open) generate(ref+')',res,open,close+1,n);
}
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        generate("",res,0,0,n);
        return res;
    }
};