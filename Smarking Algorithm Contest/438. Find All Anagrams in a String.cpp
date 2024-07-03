class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,long>mp1,mp2;
        for(auto i:p)mp2[i]++;
        long long i=0;
        long long j=0;
        vector<int>ans;
        while(j<s.size()){
            mp1[s[j]]++;
            while(mp1[s[j]]>mp2[s[j]]){
                
                mp1[s[i]]--;
                if(mp1[s[i]]==0) mp1.erase(s[i]);
                i++;
            }
            if(mp1==mp2) ans.push_back(i);
            j++;
        }
        return ans;
    }
};
