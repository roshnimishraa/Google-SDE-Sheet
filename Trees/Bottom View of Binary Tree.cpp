### Approach : Queue + map 

Time Complexity: O(N)
Space Complexity: O(N)

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        // {vertical index, nodes}
        map<int,int> mp;
        
    // {node, vertical index}
        queue<pair<Node*,int>> q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
        Node* node = it.first;
        int line = it.second;
  
        // Update the map with the node's data
            // for the current vertical position
        mp[line] = node->data;
  
  if(node->left != NULL)
  {
      q.push({node->left, line-1});
  }
  if(node->right != NULL)
  {
      q.push({node->right, line + 1});
  }
   }
   
 // Transfer values from the
        // map to the result vector
        for(auto it: mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
