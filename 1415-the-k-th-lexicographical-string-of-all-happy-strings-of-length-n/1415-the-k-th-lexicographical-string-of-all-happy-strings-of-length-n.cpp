class Solution {
public:

string res = "";

void solve(int n, int &k, int ind,string &tem,char prev){

    if(k <= 0) return;

    if(ind == n){
        if(k == 1) res = tem;
        k--;
        return;
    }


    for(char ch : {'a','b','c'}){
        if(ch == prev) continue;
        tem.push_back(ch);
        solve(n,k,ind+1,tem,ch);
        tem.pop_back();
    }

    return;
}


    string getHappyString(int n, int k) {
        if(3 * (1 << (n-1)) < k) return  "";

        string tem = "";

        solve(n,k,0,tem,'_');

        return res;
    }
};