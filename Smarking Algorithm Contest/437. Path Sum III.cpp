/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void rec(TreeNode* root,int target,unordered_map<long,int>&mp,int & ans,long sum){
        if(root==NULL) return;
        sum+=root->val;
        if(sum==target) ans++;
        long temp = sum-target;
        ans+=mp[temp];
        mp[sum]++;
        rec(root->left,target,mp,ans,sum);
        rec(root->right,target,mp,ans,sum);
        mp[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long,int>mp;
        int sum =0;
        int ans=0;
        rec(root,targetSum,mp,ans,sum);
        return ans;
    }
};
