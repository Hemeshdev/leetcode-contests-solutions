class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> mp;
        for (auto i : s) mp[i]++;
        
        string num[10] = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<char> dist_char = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i'};
        vector<int> nums = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        
        string ans = "";
        for (int i = 0; i < 10; i++) {
            string temp = num[i];
            int count = mp[dist_char[i]];
            for (auto j : temp) {
                mp[j] -= count;
            }
            for (int k = 0; k < count; k++) {
                ans += to_string(nums[i]);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
