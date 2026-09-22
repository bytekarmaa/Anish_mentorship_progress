class Solution {
public:

int mod = 1e9 + 7;

    int countOrders(int n) {
        long long res = 1;

        for(int i = 2; i <= n; i++){
            int spaces = (i - 1) * 2 + 1;

            spaces = spaces * (spaces + 1) / 2;

            res = ((res % mod) * (spaces % mod)) % mod;
        }

        return res;
    }
};