class Solution {
public:
    int minChanges(int n, int k) {
        if (n == k) return 0;
        string temp = "";
        while (n > 0) {
            int t = n & 1;
            temp.push_back(to_string(t)[0]);
            n = n >> 1;
        }
        string temp2 = "";
        while (k > 0) {
            int t = k & 1;
            temp2.push_back(to_string(t)[0]);
            k = k >> 1;
        }
        int ans = 0;
        int size = temp.size() - temp2.size();
        if (size < 0) return -1;
        string str = string(size, '0');
        temp2 += str;
        for (int i = 0; i < min(temp.size(), temp2.size()); i++) {
            if (temp[i] == '1' && temp2[i] == '0') ans++;
            else if (temp[i] == '0' && temp2[i] == '1') return -1;
        }
        return ans;
    }
};
