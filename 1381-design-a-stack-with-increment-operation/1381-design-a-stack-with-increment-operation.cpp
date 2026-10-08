class CustomStack {
public:

vector<int> res;
vector<int> incriment;

int size;

    CustomStack(int maxSize) {
        size = maxSize;
        incriment.resize(size,0);
    }
    
    void push(int x) {
        if(res.size() == size) return;
        res.push_back(x);
    }
    
    int pop() {
        if(res.empty()) return -1;

        int n = res.size();

        int val = res.back();
        res.pop_back();

        val += incriment[n-1];

        if(n > 1) {
            incriment[n-2] += incriment[n-1];
        }

        incriment[n-1] = 0;

        return val;

    }
    
    void increment(int k, int val) {
        int n = res.size();
        int ind = min(n,k);
        if(ind > 0) incriment[ind-1] += val;

        return;
    }
};
