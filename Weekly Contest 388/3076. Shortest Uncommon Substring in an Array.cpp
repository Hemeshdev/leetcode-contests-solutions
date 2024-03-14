class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        auto generateSubstrings = [](const string& s) {
            vector<string> subs;
            for (int i = 0; i < s.size(); ++i) {
                string sub;
                for (int j = i; j < s.size(); ++j) {
                    sub += s[j];
                    subs.push_back(sub);
                }
            }
            sort(subs.begin(), subs.end(), [](const string& a, const string& b) {
                return a.size() < b.size() || (a.size() == b.size() && a < b);
            });
            return subs;
        };

        int n = arr.size();
        vector<string> ans(n, "");

        for (int i = 0; i < n; ++i) {
            auto allSubs = generateSubstrings(arr[i]);
            for (const auto& sub : allSubs) {
                bool unique = true;
                for (int j = 0; j < n; ++j) {
                    if (i != j && arr[j].find(sub) != string::npos) {
                        unique = false;
                        break;
                    }
                }
                if (unique) {
                    ans[i] = sub;
                    break;
                }
            }
        }
        return ans;
    }
};



//first attempt code
// class Solution {
// public:
//     vector<string> substring(string s){
//         vector<string>temp;
//         for(int i=0;i<s.size();i++){
//             for(int j=1;j<=s.size();j++){
//                 temp.push_back(s.substr(i,j));
//             }
//         }
//         sort(temp.begin(),temp.end());
//         return temp;
//     }
//     vector<string> shortestSubstrings(vector<string>& arr) {
//         unordered_map<string,vector<string>>mp;
//         for(int i=0;i<arr.size();i++){
//             vector<string>temp1 = substring(arr[i]);
//             mp[arr[i]] = temp1;
//         }
//         vector<string>ans;
//         for(auto i:arr){
//             vector<string>temp3 = mp[i];
//             unordered_map<int,vector<string>>mp2;
//             for(auto j:temp3){
//                 bool flag= true;
//                 for(auto it=mp.begin();it!=mp.end(),it->first!=i;it++){
//                     if(find(it->second.begin(),it->second.end(),j)!=it->second.end()){
//                         flag  =false;
//                         break;
//                     }
//                 }
//                 if(flag){
//                     mp2[j.size()].push_back(j);
//                 }
//             }
//             if(mp2.size()==0) ans.push_back("");
//             else{
//                 ans.push_back(mp2.begin()->second[0]);
//             }
//         }
//         return ans;
//     }
// };
