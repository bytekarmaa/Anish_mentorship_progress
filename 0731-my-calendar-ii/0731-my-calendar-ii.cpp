class MyCalendarTwo {
public:
   
   map<int,int> mp;
    
    bool book(int startTime, int endTime) {
        mp[startTime]++;

        mp[endTime]--;

        int count = 0;

        for(auto &ele : mp){
            count += ele.second;

            if(count > 2){
                mp[startTime]--;
                mp[endTime]++;

                return false;
            }
        }

        return true;

    }
};

