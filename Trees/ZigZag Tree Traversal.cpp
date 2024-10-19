Time Complexity: O(N)
Space Complexity: O(N)

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
    if(root == NULL) return ans;
   q.push(root);     
        
    int count =0;
        
        while(!q.empty()){
            vector<int> level;
            int n=q.size();
            
        for(int i=0;i<n;i++)
        {
         TreeNode *curr = q.front();
            
        q.pop();
            
       if(curr->left != NULL)
                q.push(curr->left);
          
            if(curr->right != NULL)
               q.push(curr->right);
       
        level.push_back(curr->val);
    
        }
        if(count % 2 ==1 ){
            reverse(level.begin(),level.end()); //R to L
        }
            ans.push_back(level);
            count++;
        }
        return ans;
    }
};
