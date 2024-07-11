class Solution {
public:
    bool isvowel(char c){
        vector<char>temp = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        if(find(temp.begin(),temp.end(),c)!=temp.end()) return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int one = 0, two = 0;
        int n = s.size();
        for(int i=0;i<s.size()/2;i++){
            if(isvowel(s[i])){
                one++;
            }
            if(isvowel(s[i+n/2])){
                two++;
            }
        }
        return one==two;
    }
};
