class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";

        auto &arr = mp[key];

        int ind = upper_bound(
            arr.begin(), arr.end(), timestamp,
            [](int t, const pair<int, string>& p) {
                return t < p.first;
            }
        ) - arr.begin();

        if (ind == 0) return "";

        return arr[ind - 1].second;
    }
};