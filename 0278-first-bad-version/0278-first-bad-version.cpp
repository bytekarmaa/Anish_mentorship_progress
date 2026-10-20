

class Solution {
public:

    int firstBadVersion(int n) {
        int i = 1;
        int j = n;

        int ind = -1;

        while(i <= j){
            int mid = i + (j - i ) / 2;

            if(isBadVersion(mid)){
                j = mid - 1;
                ind = mid;
            }

            else{
                i = mid + 1;
            }
        }

        return ind;
    }
};