class Solution {
public:
    int countSegments(string s) {
        vector<string> words;
        int n = s.length();
        string temp = "";
        for(int i=0; i<n; i++){
            if(s[i] != ' '){
                temp.push_back(s[i]);
            }
            if(s[i] == ' '){
                if(temp !=  ""){
                    words.push_back(temp);
                    temp = "";
                }
            }
        }
        if(temp != ""){
            words.push_back(temp);
        }

        return words.size();
    }
};
