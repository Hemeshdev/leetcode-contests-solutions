class Solution {
public:
    int getNodesAtDistance(int curr,int k,unordered_map<int,vector<int>>&tree,vector<int>&dist){
        int cnt = 0;
        queue<int> q;
        unordered_map<int, bool> visited;
        visited[curr] = true;
        q.push(curr);
        dist[curr] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : tree[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    dist[it] = dist[node] + 1; 
                    q.push(it);
                    if (dist[it] % 2 == k) {
                        cnt++; 
                    }
                }
            }
        }
        return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>>tree1,tree2;
        int n1 = INT_MIN, n2 = INT_MIN;
        for (auto& edge : edges1) {
            tree1[edge[0]].push_back(edge[1]);
            tree1[edge[1]].push_back(edge[0]);
            n1 = max(n1, max(edge[0], edge[1]));
        }
        for (auto& edge : edges2) {
            tree2[edge[0]].push_back(edge[1]);
            tree2[edge[1]].push_back(edge[0]);
            n2 = max(n2, max(edge[0], edge[1]));
        }
        vector<int>ans(n1+1,0);
        vector<int>distInTree1(n1+1,-1),distInTree2(n2+1,-1);
        int oddInTree2 = getNodesAtDistance(0,1,tree2,distInTree2);
        int maxInTree2 = 0;
        for(int i=0;i<=n2;i++){
            int currDist = distInTree2[i];
            int canVisit = 0;
            if(currDist%2==0){
                canVisit = oddInTree2;
            } else {
                canVisit = n2 + 1 - oddInTree2;
            }
            maxInTree2 = max(maxInTree2,canVisit);
        }
        int evenInTree1 = 1 + getNodesAtDistance(0,0,tree1,distInTree1);
        for(int i=0;i<=n1;i++){
            int currDist = distInTree1[i];
            int canVisit = 0;
            if(currDist % 2== 0){
                canVisit = evenInTree1;
            } else {
                canVisit = n1 + 1 - evenInTree1;
            }
            ans[i] = canVisit + maxInTree2;
        }
        return ans;
    }
};
