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

//we can also do this by bit manipulation and also by sum of all t chars into number - sum of all s chars into nums
