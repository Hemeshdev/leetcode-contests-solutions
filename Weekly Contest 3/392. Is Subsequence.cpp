class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        while(j<t.size()){
            if(t[j]==s[i]){
                i++;
            }
            j++;
        }
        return i==s.size();
    }
};
