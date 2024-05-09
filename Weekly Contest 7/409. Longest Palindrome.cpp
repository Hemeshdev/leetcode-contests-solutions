class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        int ans =0;
        bool flag =false;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans+=((it->second)/2)*2;
            if(it->second%2!=0) flag = true;
        }
        if(flag) ans++;
        return ans;

    }
};
