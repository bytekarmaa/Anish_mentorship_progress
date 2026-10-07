class SmallestInfiniteSet {
public:

    int pointer;

    set<int> st;

    SmallestInfiniteSet() {
        pointer = 1;
    }
    
    int popSmallest() {
        if(st.empty()) return pointer++;

        else {
           int val = *st.begin();
           st.erase(val);
           return val;
        }
    }
    
    void addBack(int num) {
        if(st.count(num) || num >= pointer) return;
        st.insert(num);
        return;
    }
};
