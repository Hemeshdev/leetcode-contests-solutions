//amazing approach


class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& r) {
        map<pair<int,int>,int>mp;
        for(auto i:r){
            mp[{i[0],i[1]}]++;
            mp[{i[2],i[3]}]++;
            mp[{i[0],i[3]}]--; // these two lines will remove the repeated points
            mp[{i[2],i[1]}]--;
        }
        int tot =0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second!=0){
                if(abs(it->second)!=1) return false;  //in overlap topright and bottom left condition causes append it to 2
                else tot++;
            }
        }
        return tot==4;
    }
};
