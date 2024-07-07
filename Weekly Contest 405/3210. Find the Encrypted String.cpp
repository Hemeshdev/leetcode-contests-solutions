class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans = s;
        int n = s.size();
        for(int i=0;i<n;i++){
            ans[i] = s[(i+k)%n];
        }
        return ans;
    }
};
