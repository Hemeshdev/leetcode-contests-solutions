//time complexity : O(2n) 
//space complexity : O(2n) 

class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        int part = n/k;
        unordered_map<string,int>mp;
        for(int i=0;i<=n-part;i+=part){
            string str = s.substr(i,part);
            mp[str]++;
        }
        for(int i=0;i<=n-part;i+=part){
            string str = t.substr(i,part);
            if(mp.find(str)==mp.end()){
                return false;
            }
            mp[str]--;
            if(mp[str]<=0){
                mp.erase(str);
            }
        }
        return mp.size()==0;
    }
};
