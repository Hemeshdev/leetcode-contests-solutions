class Solution {
public:
    void rec(vector<string>& ans, string &temp,int n,int last){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back('1');
        rec(ans,temp,n,1);
        temp.pop_back();
        if(last==1){
            temp.push_back('0');
            rec(ans,temp,n,0);
            temp.pop_back();
        }

    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        string temp1 = "0",temp2 = "1";
        rec(ans,temp1,n,0);
        rec(ans,temp2,n,1);
        return ans;
    }
};
