class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto i:arr){
            mp[i]++;
        }
        unordered_set<int>s;
        bool flag = true;
        for(auto i:mp){
            if(s.find(i.second)!=s.end()){
                flag = false;
                break;
            }else{
                s.insert(i.second);
            }
        }
        return flag;
    }
};
