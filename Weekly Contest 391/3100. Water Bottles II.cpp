class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans =0;
        int temp = numBottles;
        int t = numExchange;
        int empty =0;
        while(temp || empty ){
            if(temp){
                ans+=temp;
                empty+=temp;
                temp =0;
            }
            else{
                if(empty>=t){
                    temp+=1;
                    empty-=t;
                    t++;
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};
