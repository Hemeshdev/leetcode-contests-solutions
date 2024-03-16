class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        for(auto i:t){
            mp[i]++;
        }
        for(auto i:s){
            mp[i]--;
            if(mp[i]==0) mp.erase(i);
        }
        return mp.begin()->first;
    }
};
