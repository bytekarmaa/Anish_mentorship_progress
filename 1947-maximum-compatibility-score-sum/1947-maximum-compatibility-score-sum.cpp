class Solution {
public:

int n;

int get_score(vector<int> &student, vector<int> &mentor){
    int m = student.size();

    int score = 0;

    for(int i = 0; i < m; i++){
        if(student[i] == mentor[i]) score++;
    }

    return score;
}

int solve(vector<vector<int>>& students, vector<vector<int>>& mentors,int ind, int bitMask){
    if(ind == n) return 0;

    int maxScore = 0;

    for(int i = 0; i < n; i++){
        int bit = (1 << i);
        if(!(bitMask & bit)){
            bitMask |= bit;

            int currScore = get_score(students[ind],mentors[i]);
            
            maxScore = max(maxScore,currScore + solve(students,mentors,ind+1,bitMask));

            bitMask ^= bit;
        }
    }

    return maxScore;
}

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        n = students.size();

        int bitMask = 0;

        return solve(students,mentors,0,bitMask);

    }
};