class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n = apples.size();
        int ans = 0;
        int i =0;
        while(i<n || pq.size()){
            if(i<n && apples[i]>0) pq.push({i+days[i]-1,apples[i]});
            while(pq.size() && pq.top().first<i ) pq.pop();
            if(pq.size()){
                auto temp =pq.top();
                pq.pop();
                if(temp.second>1) pq.push({temp.first,temp.second-1});
                ans++;
            } 
            i++;
        }
        return ans;
    }
};
