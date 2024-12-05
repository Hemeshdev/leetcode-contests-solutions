class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        if (k==0) {
            return vector<int>(edges1.size() + 1, 1);
        }
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> mp1(n), mp2(m); 
        for (auto edge : edges1) {
            mp1[edge[0]].push_back(edge[1]);
            mp1[edge[1]].push_back(edge[0]);
        }
        for (auto edge : edges2) {
            mp2[edge[0]].push_back(edge[1]);
            mp2[edge[1]].push_back(edge[0]);
        }
        auto bfs = [](vector<vector<int>>& mp, int k) {
            int n = mp.size();
            vector<int> tot(n, 0); 
            for (int ind = 0; ind < n; ++ind) {
                vector<bool> vis(n, false); 
                queue<int> q;
                q.push(ind);
                vis[ind] = true;
                int level = 0;
                while (!q.empty() && level < k) {
                    int qsize = q.size();
                    level++;

                    for (int i = 0; i < qsize; ++i) {
                        int top = q.front();
                        q.pop();
                        for (auto adjnode : mp[top]) {
                            if (!vis[adjnode]) {
                                vis[adjnode] = true;
                                q.push(adjnode);
                            }
                        }
                    }
                }
                tot[ind] = count(vis.begin(), vis.end(), true);
            }
            return tot;
        };
        vector<int> tot1 = bfs(mp1, k);
        vector<int> tot2 = bfs(mp2, k - 1);
        int maxi = *max_element(tot2.begin(), tot2.end());
        vector<int> ans(tot1.size(), 0);
        for (int i = 0; i < tot1.size(); ++i) {
            ans[i] = tot1[i] + maxi;
        }
        return ans;
    }
};
