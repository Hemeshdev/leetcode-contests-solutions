class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int n = houses.size();
        int m = heaters.size();
        vector<int>temp(n,INT_MAX);
        for(int i=0,j=0;i<n && j<m;){
            if(heaters[j]>=houses[i]){
                temp[i] = heaters[j] - houses[i];
                i++;
            }else{
                j++;
            }
        }
        for(int i=n-1,j=m-1;i>=0 && j>=0;){
            if(heaters[j]<=houses[i]){
                temp[i] = min(temp[i],houses[i]-heaters[j]);
                i--;
            }else{
                j--;
            }
        }
        return *max_element(temp.begin(),temp.end());
      
        
    }
};
