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
    vector<int> get_val(vector<TreeNode*> level){
        vector<int> res;
        for(auto &u: level) {
            res.push_back(u -> val);
        }
        return res;
    }
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<TreeNode*> level;
        level.push_back(root);
        res.push_back(get_val(level));
        bool zigzag = true;
        while(true){
            vector<TreeNode*> newLevel;
            for(auto &u : level){
                if(u -> left) newLevel.push_back(u -> left);
                if(u -> right) newLevel.push_back(u -> right);
            }
            if(newLevel.size())
            {
                vector<int> temp = get_val(newLevel);
                if(zigzag){
                    reverse(temp.begin(), temp.end());
                }
                res.push_back(temp);
                level = newLevel;
            }else {
                break;
            }
            zigzag = !zigzag;
        }
        return res;
    }
};