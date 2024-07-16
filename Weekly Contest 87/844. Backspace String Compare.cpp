class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temp1 = "";
        string temp2 = "";
        for(auto i:s){
            if(i=='#' && temp1!="") temp1.pop_back();
            else if(i!='#'){
                temp1.push_back(i);
            }
        }
        for(auto i:t){
            if(i=='#' && temp2!="") temp2.pop_back();
            else if(i!='#'){
                temp2.push_back(i);
            }
        }
        return temp1==temp2;
        
    }
};
