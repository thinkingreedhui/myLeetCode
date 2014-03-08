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
    int BFS(TreeNode* root){//BFS������������㷨�����Ƚ��ȳ�����queueʵ��
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
            if(!BFS(node->left)){ //��ǰ�ڵ����������Ϊ��
                node.left->val = node.val + 1;
                q.push(*node.left);
            }
            if(!BFS(node.right)){//��ǰ�ڵ����������Ϊ��
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
