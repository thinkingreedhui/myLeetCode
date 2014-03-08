#ifndef MAXDEPTH_H_INCLUDED
#define MAXDEPTH_H_INCLUDED
#include<queue>
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  Definition for binary tree
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int BFS(TreeNode* root){//BFS广度优先搜索算法，用先进先出队列queue实现
        if(root == NULL)
            return 0;
        root->val = 1;
        queue<TreeNode> q;
        q.push(root);
        while(!q.empty()){
            TreeNode  node = q.front();
            q.pop();
            if( q.size()==1 && !BFS(node.left) && !BFS(node.right))
                return node.val;
            if(!BFS(node->left)){ //当前节点的左子树不为空
                node.left->val = node.val + 1;
                q.push(*node.left);
            }
            if(!BFS(node.right)){//当前节点的右子树不为空
                node.right->val = node.val +1;
                q.push(*node.right);
            }

        }
    }
    int maxDepth(TreeNode *root) {

        return BFS(root);
    }
};


#endif // MAXDEPTH_H_INCLUDED
