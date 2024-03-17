class Solution {
public:
    bool isSubstringPresent(string s) {
        string temp = s;
        reverse(s.begin(),s.end());
        unordered_set<string>q;
        for(int i=0;i<s.size()-1;i++){
            q.insert(s.substr(i,2));
        }
        for(int i=0;i<temp.size()-1;i++){
            string t = temp.substr(i,2);
            if(q.find(t)!=q.end()) return true;
        }
        return false;
    }
};
