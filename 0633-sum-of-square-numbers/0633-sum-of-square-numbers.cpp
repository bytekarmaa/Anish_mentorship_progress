class Solution {
public:
    bool judgeSquareSum(int c) {
        long long hi = sqrt(c);

        long long lo = 0;

        while(lo <= hi){
            long long val = lo * lo + hi * hi;

            if(val == c) return true;

            else if(val < c) lo++;

            else hi--;
        }

        return false;
    }
};