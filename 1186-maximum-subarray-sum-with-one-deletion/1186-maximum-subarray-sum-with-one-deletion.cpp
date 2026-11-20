class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        vector<int> kdane(n,0);

        vector<int> right(n,0);

         int maxSum = arr[0];

        int sum = INT_MIN + 100000;

        for(int i = 0; i < n; i++){
            int newSum = max(sum + arr[i],arr[i]);
            kdane[i] = newSum;

            maxSum = max(maxSum,kdane[i]);

            sum = newSum;
        }

        sum = INT_MIN + 100000;

        for(int i = n-1; i >= 0; i--){
            int newSum = max(sum + arr[i],arr[i]);
            right[i] = newSum;
            maxSum = max(maxSum,right[i]);

            sum = newSum;
        }

       

        for(int i = 1; i < n-1; i++){
            int leftSum = kdane[i-1];
            int rightSum = right[i+1];

            maxSum = max({maxSum,leftSum + rightSum});
        }

        return maxSum;
    }
};



// class Solution {
// public:
//     int maximumSum(vector<int>& arr) {
//         int n = arr.size();

//         int neg = 0;

//         int i = 0;
//         int j = 0;

//         int sum = 0;
//         int negSum = 0;

//         int maxSum = INT_MIN;

//         while(j < n){
//            if(arr[i] >= 0) sum += arr[j];

//            else {
//             negSum += arr[j];
//             neg++;
//            }

//            while(neg > 1 && sum + abs(negSum)){

//                 if(arr[i] >= 0) sum -= arr[i];
//                 else {
//                     neg--;
//                     negSum += (abs(arr[i]));
//                 }

//                 i++;

//            }

//            maxSum = max(maxSum,sum + negSum);

//            j++;


//         }

//         return maxSum;
//     }
// };