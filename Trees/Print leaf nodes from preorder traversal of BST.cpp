### Approach : Stack 

Time Complexity: O(N)
Space Complexity: O(N)

class Solution {
  public:
    vector<int> leafNodes(int arr[],int N) {
        vector<int> ans;
        stack<int> st;
        st.push(arr[0]);
        for(int i=1;i<N;i++)
        {
            if(arr[i] < st.top()){
                st.push(arr[i]);
            }
            else{
                int curr =st.top();
                st.pop();
                if(!st.empty() && arr[i] > st.top())
                {
                    while(!st.empty() && arr[i]>st.top())
                    {
                        st.pop();
                    }
                    ans.push_back(curr);
                }
                st.push(arr[i]);
            }
        }
        ans.push_back(arr[N-1]);
        return ans;
    }
};


