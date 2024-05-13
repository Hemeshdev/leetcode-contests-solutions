class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int>temp(26,0);
        int n = s.size();
        for(int i=0;i<n;i++){
            temp[s[i]-'a']= abs(temp[s[i]-'a']-i);
            temp[t[i]-'a']= abs(temp[t[i]-'a']-i);
        }
        return accumulate(temp.begin(),temp.end(),0);
    }
};
