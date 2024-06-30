class Solution {
public:
    int helper(int red, int blue)
    {
        int i = 1;
        int ans = 0;
        bool flag = true;
        while(red > 0 || blue > 0)
        {
            if(flag == true)
            {
                if(i > red) break;
                red -= i++;
                flag = !flag;
            }
            else
            {
                if(i > blue) break;
                blue -= i++;
                flag = !flag;
            }
            ans++;
        }
        return ans;
    }

    int maxHeightOfTriangle(int red, int blue) {
        return max(helper(red, blue), helper(blue, red));
        
    }
};
