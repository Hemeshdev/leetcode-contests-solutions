class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        map<string,int>mp;
        int n = word.size();
        for(int i=0;i<n;i+=k){
            mp[word.substr(i,k)]++;
        }
        int maxi =-1;
        string t ="";
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second>maxi){
                maxi = it->second;
                t = it->first;
            }
        }
        int temp = word.size()/k;
        return temp-maxi;

    }
};
