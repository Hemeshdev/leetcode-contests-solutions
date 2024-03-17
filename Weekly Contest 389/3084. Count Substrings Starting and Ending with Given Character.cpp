class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long ans =0, temp= 0;
        for(auto i:s){
            if(i==c) temp++;
        }
        return temp*(temp+1)/2;
    }
};
