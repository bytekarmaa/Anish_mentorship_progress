class TopVotedCandidate {
public:

    vector<int> res;
    vector<int> times;
    
    int n;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        n = persons.size();
        this->times = times;
        res.resize(n);
        unordered_map<int,int> mp;

        int person_num = 0;
        int maxFreq = 0;

        for(int i = 0; i < n; i++){
            mp[persons[i]]++;

            if(mp[persons[i]] >= maxFreq){
                maxFreq = mp[persons[i]];
                person_num = persons[i];
            }

            res[i] = person_num;
        }
    }
    
    int q(int t) {
    int ind = upper_bound(times.begin(), times.end(), t)  - times.begin();

    return res[ind - 1];
}
};

