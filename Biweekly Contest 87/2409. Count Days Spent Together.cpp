class Solution {
public:
    int countDaysTogether(string aa, string la, string ab, string lb) {
        int arr[12] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        for(int i=1;i<12;i++) arr[i] = arr[i]+arr[i-1];
        unordered_set<int>set;
        int start1 = arr[stoi(aa.substr(0,2))-1]+stoi(aa.substr(3,2));
        int end1 = arr[stoi(la.substr(0,2))-1]+stoi(la.substr(3,2));
        int start2 = arr[stoi(ab.substr(0,2))-1]+stoi(ab.substr(3,2));
        int end2 = arr[stoi(lb.substr(0,2))-1]+stoi(lb.substr(3,2));
        for(int i = start1;i<=end1;i++) set.insert(i);
        int ans = 0;
        for(int i = start2;i<=end2;i++) if(set.find(i)!=set.end()) ans++;
        return ans;
        
    }
};
