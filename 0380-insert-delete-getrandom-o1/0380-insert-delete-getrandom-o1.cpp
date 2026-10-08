class RandomizedSet {
public:

unordered_map<int,int> mp; // val -> index
vector<int> nums;
    
    bool insert(int val) {
        if(mp.count(val)) return false;

        int ind = nums.size();

        mp[val] = ind;

        nums.push_back(val);

        return true;
    }
    
    bool remove(int val) {
       if(!mp.count(val)) return false;

       int ind = mp[val];

       int last_val = nums.back();

       nums[ind] = last_val;

       mp[last_val] = ind;

       mp.erase(val);

       nums.pop_back();

       return true;
    }
    
    int getRandom() {
       int n = nums.size();

       return nums[rand() % n];
    }
};

