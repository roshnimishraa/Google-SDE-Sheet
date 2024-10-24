Time Complexity: O(N + M), In the worst case, each node and each edge are visited once. Here N is a number of nodes (vertices) and M is a number of edges.
Space Complexity: O(N), To store the result.


// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
public:
unordered_map<Node*,Node*> copies;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
    
// If the node is not present in the map, create a copy of it
    if(copies.find(node) == copies.end())
    {
       // Create a new node with the same value as the original node
      copies[node] = new Node(node->val, {});
     
    // copy the neighbors of the original node recursively
for(Node* neighbor : node->neighbors)
{
    copies[node]->neighbors.push_back(cloneGraph(neighbor));
}
    }
    return copies[node];
    }
};
