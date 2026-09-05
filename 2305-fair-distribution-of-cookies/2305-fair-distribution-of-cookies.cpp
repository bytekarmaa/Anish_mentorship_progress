// class Solution {
// public:
//     int distributeCookies(vector<int>& cookies, int k) {
        
//     }
// };



class Solution {
public:

int min_unfairness  = INT_MAX;


int n;



void solve(vector<int>& cookies,int ind, vector<int> &children){
    if(ind >= n){
        int max_ele = *max_element(children.begin(),children.end());

        min_unfairness = min(min_unfairness,max_ele);

        return;
    }

    for(int i = 0; i < children.size(); i++){
        children[i] += cookies[ind];
        solve(cookies,ind+1,children);
        children[i] -= cookies[ind];
    }

    return;
}

    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();

        vector<int> children(k,0);

        solve(cookies,0,children);

        return min_unfairness; 
    }
};