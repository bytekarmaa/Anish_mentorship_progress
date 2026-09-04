// class Solution {
// public:
//     // Memoization map: maps a specific 'needs' state to its minimum cost
//     map<vector<int>, int> memo;
    
//     int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
//         // Agar ye state pehle compute ho chuki hai, to direct return karo
//         if (memo.count(needs)) {
//             return memo[needs];
//         }
        
//         // Option 1: Buy everything without any special offer
//         int min_cost = 0;
//         for (int i = 0; i < needs.size(); i++) {
//             min_cost += needs[i] * price[i];
//         }
        
//         // Option 2: Try every valid special offer
//         for (int i = 0; i < special.size(); i++) {
//             vector<int> clone_needs = needs;
//             bool isValidOffer = true;
            
//             // Check if the offer is valid and update clone_needs
//             for (int j = 0; j < needs.size(); j++) {
//                 if (special[i][j] > clone_needs[j]) {
//                     isValidOffer = false;
//                     break;
//                 }
//                 clone_needs[j] -= special[i][j];
//             }
            
//             // If offer is valid, take it and solve for remaining needs
//             if (isValidOffer) {
//                 // special[i].back() is the price of the offer
//                 int current_cost = special[i].back() + shoppingOffers(price, special, clone_needs);
//                 min_cost = min(min_cost, current_cost);
//             }
//         }
        
//         // Store in memo and return
//         return memo[needs] = min_cost;
//     }
// };




class Solution {
public:
    unordered_map<string, int> memo;
    
    string getKey(vector<int>& needs) {
    string key = "";
    for (int count : needs) {
        // Kyunki count single digit hota hai, hum direct char me convert kar sakte hain
        // Commas lagane ki bhi zaroorat nahi hai. Example: [1, 2, 0] ban jayega "120"
        key += to_string(count); 
    }
    return key;
}


    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        string key = getKey(needs);
        
        if (memo.count(key)) {
            return memo[key];
        }
        
        int min_cost = 0;
        for (int i = 0; i < needs.size(); i++) {
            min_cost += needs[i] * price[i];
        }
        
        for (int i = 0; i < special.size(); i++) {
            vector<int> clone_needs = needs;
            bool isValidOffer = true;
            
            for (int j = 0; j < needs.size(); j++) {
                if (special[i][j] > clone_needs[j]) {
                    isValidOffer = false;
                    break;
                }
                clone_needs[j] -= special[i][j];
            }
            
            if (isValidOffer) {
                int current_cost = special[i].back() + shoppingOffers(price, special, clone_needs);
                min_cost = min(min_cost, current_cost);
            }
        }
        
        return memo[key] = min_cost;
    }
};