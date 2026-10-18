class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();

        int i = 0;

        int j = n-1;

        int score = 0;

        int maxScore = 0;

        while(i <= j){
            


            if(tokens[i] <= power) {
                score++;
                power -= tokens[i];
                i++;
                maxScore = max(maxScore,score);
            }

            else{
                if(score == 0) break;
                score--;
                power += tokens[j];

                j--;
            }
        }

        return maxScore;
    }
};