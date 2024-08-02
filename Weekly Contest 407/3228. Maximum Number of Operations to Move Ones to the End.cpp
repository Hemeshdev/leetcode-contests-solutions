class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int ans = 0;
        int count = 0;
        int i=0;
        while(i<n){
            if(s[i]=='1'){
                count++;
                i++;
            }else if(s[i]=='0'){
                while(s[i]=='0'){
                    i++;
                }
                ans+=count;
            }
            
        }
        return ans;

    }
};
