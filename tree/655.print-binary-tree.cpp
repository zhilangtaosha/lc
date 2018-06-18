/*
 * [655] Print Binary Tree
 *
 * https://leetcode.com/problems/print-binary-tree
 *
 * Medium (52.04%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[1,2]'
 *
 * Print a binary tree in an m*n 2D string array following these rules: 
 * 
 * 
 * The row number m should be equal to the height of the given binary tree.
 * The column number n should always be an odd number.
 * The root node's value (in string format) should be put in the exactly middle
 * of the first row it can be put. The column and the row where the root node
 * belongs will separate the rest space into two parts (left-bottom part and
 * right-bottom part). You should print the left subtree in the left-bottom
 * part and print the right subtree in the right-bottom part. The left-bottom
 * part and the right-bottom part should have the same size. Even if one
 * subtree is none while the other is not, you don't need to print anything for
 * the none subtree but still need to leave the space as large as that for the
 * other subtree. However, if two subtrees are none, then you don't need to
 * leave space for both of them. 
 * Each unused space should contain an empty string "".
 * Print the subtrees following the same rules.
 * 
 * 
 * Example 1:
 * 
 * Input:
 * ⁠    1
 * ⁠   /
 * ⁠  2
 * Output:
 * [["", "1", ""],
 * ⁠["2", "", ""]]
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * ⁠    1
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \
 * ⁠    4
 * Output:
 * [["", "", "", "1", "", "", ""],
 * ⁠["", "2", "", "", "", "3", ""],
 * ⁠["", "", "4", "", "", "", ""]]
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:
 * ⁠     1
 * ⁠    / \
 * ⁠   2   5
 * ⁠  / 
 * ⁠ 3 
 * ⁠/ 
 * 4 
 * Output:
 * 
 * [["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 * ⁠["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 * ⁠["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 * ⁠["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
 *    7  2^3 - 1
 *    3  2^2 - 1
 *    1  2^1 - 1
 *    0  
 * Note:
 * The height of binary tree is in the range of [1, 10].
 * 
 */
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
    int height(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    // 层遍历
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> res;
        if(!root) return res;
        int h = height(root);
        
        for(int i = 0; i < h; i++) {
            vector<string> row("", pow(2, h+1) - 1);
            res.push_back(row);
        }
        
        queue<TreeNode*> q;
        q.push_back(root);
        int res = 1;
        while(!q.empty()) {
            int q_size = q.size();
            for(int i = 0; i < q_size; i++) {
                TreeNode* t = q.front();
                q.pop_front();
                if(t == nullptr) {
                    q.push_back(nullptr);
                    q.push_back(nullptr);
                    continue;
                }
                q.push_back(t->left? t->left : nullptr);
                q.push_back(t->right? t->right : nullptr);
            }
            while(q.back() == nullptr) {
                q.pop_back();
            }
            while(!q.empty() && q.front() == nullptr) {
                q.pop_front();
            }
            res = max(res, q.size());
        }
        return res;
    }
};
