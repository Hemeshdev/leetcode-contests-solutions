class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        vector<int>temp;
        for(auto i :rectangles){
            int r= min(i[0],i[1]);
            temp.push_back(r);
        }
        int maxi  =*max_element(temp.begin(),temp.end());
        int ans =0;
        for(auto i : temp){
            if(i==maxi) ans++;
        }
        return ans;
    }
};
