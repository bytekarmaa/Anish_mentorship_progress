class DataStream {
public:
int prev;
int pointer;
int val;
int K;
    DataStream(int value, int k) {
        val = value;
        prev = 0;
        pointer = 1;
        K = k;
    }
    
    bool consec(int num) {
        if(num != val){
            prev = pointer;
        }

         pointer++;

        return (pointer - prev - 1 >= K);
    }
};

