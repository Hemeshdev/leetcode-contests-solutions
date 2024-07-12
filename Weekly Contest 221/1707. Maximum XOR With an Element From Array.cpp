struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }
    void put(int bit,Node* node){
        links[bit] = node;
    }
    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }

        void insert(int num){
            Node* node = root;
            for(int i=31;i>=0;i--){
                int bit = num>>i &1;
                if(!node->containsKey(bit)){
                    node->put(bit,new Node());
                }
                node = node->get(bit);
            }
        }

        int findMax(int num){
            Node* node=  root;
            int maxi = 0;
            for(int i=31;i>=0;i--){
                int bit = num>>i & 1;
                if(node->containsKey(1-bit)){
                    maxi = maxi | (1<<i);
                    node = node->get(1-bit);
                }
                else{
                    node = node->get(bit);
                }
            }
            return maxi;
        }

};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int n = queries.size();
        vector<int>ans(n,0);
        vector<pair<int,pair<int,int>>>offQue;
        for(int i=0;i<n;i++){
            offQue.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(offQue.begin(),offQue.end());
        Trie trie;
        int index =0;
        int m = nums.size();
        for(auto i:offQue){
            int mi = i.first;
            int xi = i.second.first;
            int ind = i.second.second;
            while(index<m && nums[index]<=mi){
                trie.insert(nums[index]);
                index++;
            }
            if(index!=0) ans[ind] = trie.findMax(xi);
            else{
                ans[ind] = -1;
            }
        }
        return ans;
    }
};
