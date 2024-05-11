class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n=s.size();
        map<int,vector<char>>mp;
        for(int i=0;i<n;i++){
            mp[max(abs(points[i][0]),abs(points[i][1]))].push_back(s[i]);
        }
        unordered_set<char>st;
        int ans =0,count=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            for(auto i:it->second){
                if(st.find(i)!=st.end()) return st.size();
                else {
                    count++;
                    st.insert(i);
                }
            }
            ans =count;
        }
        return ans;
    }
};
