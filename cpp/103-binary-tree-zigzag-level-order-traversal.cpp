/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        deque<TreeNode*> q;
        q.push_front(root);
        int depth = 0;
        while(!q.empty()){
            vector<int> now ;
            int s = q.size();
            if(depth%2==0){
                for(int i=0;i<s;i++){
                    TreeNode* nowNode = q.front();
                    q.pop_front();
                    if(nowNode==nullptr) continue;
                    int v = nowNode->val;
                    now.push_back(v);
                    q.push_back(nowNode->left);
                    q.push_back(nowNode->right);
                }
            }else {
                for(int i=0;i<s;i++){
                    TreeNode* nowNode = q.back();
                    q.pop_back();
                     if(nowNode==nullptr) continue;
                    int v = nowNode->val;
                    now.push_back(v);
                    q.push_front(nowNode->right);
                    q.push_front(nowNode->left);
                }
            }
            depth++;
            if(now.size()>0)
            ans.push_back(now);
        }
        return ans;
    }
};
