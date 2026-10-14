class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int max_len = 0;

        int i = 0;

        int j = 0;

        unordered_map<int,int> mp;

        while(i < n){
            mp[fruits[i]]++;

            while(mp.size() > 2 && j < i){
                mp[fruits[j]]--;

                if(mp[fruits[j]] == 0) mp.erase(fruits[j]);
                j++;
            }

            max_len = max(max_len,(i-j+1));

            i++;
        }


        return max_len;


    }
};