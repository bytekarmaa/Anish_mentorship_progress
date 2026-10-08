class SeatManager {
public:
int pointer;
set<int> st;
    SeatManager(int n) {
        pointer = 1;
    }
    
    int reserve() {
        if(st.empty()) return pointer++;
        else {
            int val = *st.begin();
            st.erase(st.begin());
            return val;
        }
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber);
    }
};

