class ThroneInheritance {
public:

unordered_map<string,vector<string>> mp;

unordered_map<string,bool> is_alive;

string king;

void Successor(string curr, vector<string> &res){
     if(is_alive[curr]) res.push_back(curr);

    for(string &child : mp[curr]){
        Successor(child,res);
    }

    return;
}

    ThroneInheritance(string kingName) {
        king = kingName;
        is_alive[kingName] = true;
    }
    
    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);
        is_alive[childName] = true;
    }
    
    void death(string name) {
        is_alive[name] = false;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        Successor(king,res);
        return res;
    }
};
