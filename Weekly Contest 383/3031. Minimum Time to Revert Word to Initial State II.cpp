// learning about z-function is important here
class Solution {
public:
    vector<int> z_function(string s){
        int n =s.size();
        vector<int>z(n);
        for(int i=1,l=0,r=0;i<n;i++){
            if(i<r){
                z[i] = min(r-i,z[i-l]);
            }
            while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
                z[i]++;
            }
            if(i+z[i]>r){
                l=i;
                r=i+z[i];
            }
        }
        return z;
    }
    int minimumTimeToInitialState(string word, int k) {
        vector<int>z = z_function(word);
        int ans =0;
        int n = word.size();
        for(int i = 1; i < n; i++)
        {
            if(z[i] == n-i && i %k == 0)
            {
                ans = (i+k-1)/k;
                break;
            }

            if(i == n-1) ans = (n+k-1)/k;
        }

        return ans;
    }
};
