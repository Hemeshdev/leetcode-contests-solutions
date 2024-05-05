class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        vector<int>temp;
        for(int i=1;i*i<=n;i++){
            if(n%i==0) temp.push_back(i); temp.push_back(n/i);
        }
        int ans =s.size();
        for(auto i:temp){
            string t = s.substr(0,i);
            sort(t.begin(),t.end());
            bool flag = true;
            for(int j=i;j<n;j+=i){
                string k =s.substr(j,i);
                sort(k.begin(),k.end());
                if(t!=k){
                    flag =false;
                    break;
                }
            }
            if(flag==true) ans =min(ans,i);
        }
        return ans;
    }
};
