class Solution {
public:

int n;

int solve(vector<string>& words,vector<int>& score,vector<int> &freq,int ind){
    if(ind >= n) return 0;

    vector<int> tempFreq = freq;

    int j = 0;

    int currScore = 0;

    while(j < words[ind].size()){
        char ch = words[ind][j];

        tempFreq[ch - 'a']--;


        if(tempFreq[ch-'a'] < 0){
            break;
        }

        currScore += score[ch - 'a'];
        j++;

    }


    int take = 0;

    

    if(j == words[ind].size()){
        take = currScore + solve(words,score,tempFreq,ind+1);
    }

    int not_take = solve(words,score,freq,ind+1);

    return max(take,not_take);
}

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();

        vector<int> freq(26,0);

        for(char ch : letters){
    freq[ch - 'a']++;
}


        return solve(words,score,freq,0);
    }
};