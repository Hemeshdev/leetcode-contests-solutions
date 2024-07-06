class Solution {
public:
    long long maximumPoints(vector<int>& ee, int ce) {
        sort(ee.begin(),ee.end());
        long long ans = 0;
        if(ce<ee[0]) return ans;
        int i =0;
        int j =ee.size()-1;
        long long temp = ce;
        while(j>=0){
            if(temp>=ee[i]){
                ans+=temp/ee[i];
                temp = temp%ee[i];
            }else{
                temp+=ee[j];
                j--;
            }
            
        }
        return ans;

    }
};
