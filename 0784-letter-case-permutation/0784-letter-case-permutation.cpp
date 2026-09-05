class Solution {
public:

vector<string> res;

void solve(string &s, int ind){
    if(ind == s.size()){
        res.push_back(s);
        return;
    }

    solve(s,ind+1);  // skip

    if(isalpha(s[ind])){

        if(isupper(s[ind])){
            s[ind] = tolower(s[ind]);

            solve(s,ind+1);

            s[ind] = toupper(s[ind]);
        }

        else{
            
            s[ind] = toupper(s[ind]);
            
            solve(s,ind+1);

            s[ind] = tolower(s[ind]);

        }

    }

    return;
}

    vector<string> letterCasePermutation(string s) {

        int ind = 0;

        solve(s,ind);

        return res;
    }
};