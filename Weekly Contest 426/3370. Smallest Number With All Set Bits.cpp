class Solution {
public:
    int smallestNumber(int n) {
        int num = 1;
        int iter = 1;
        while(num<n){
            num = pow(2,iter)-1;
            iter++;
        }
        return num;
    }
};
