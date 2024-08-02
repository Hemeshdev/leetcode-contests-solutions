class Solution {
public:
    bool isvowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    bool doesAliceWin(string s) {
        int n  =s.size();
        int count = 0;
        for(int i=0;i<n;i++){
            if(isvowel(s[i])) count++;
        }
        if(count==0) return false;
        return true;

    }
};
