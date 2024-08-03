class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x^y;
        return __builtin_popcount(temp);
    }
};
