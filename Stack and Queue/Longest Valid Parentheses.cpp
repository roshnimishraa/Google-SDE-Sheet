### Approach : Using Stack

Time Complexity: O(n), where n is the size of string.
Auxiliary Space: O(n)
  
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxLen=0;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            if(ch == '('){
                st.push(i);
            }
            else{
                st.pop(); //close

                if(st.empty())
                {
            st.push(i); //current next index as valid index
                }
                else{
                    // update maxLen
            maxLen = max(maxLen, i-st.top());
                }
            }
        }
        return maxLen;
    }
};


### Approach 2: Using Two Traversals 

Time Complexity: O(n)
Space Complexity: O(1)

## Note
Left to right traversal ensures that every valid substring that ends at the rightmost closing parenthesis is counted.
Right to left traversal ensures that every valid substring that starts from the leftmost opening parenthesis is counted.

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen =0;
        int open=0, close=0;
    int n = s.length();
// left to right traversal
        for(auto &it: s)
        {
            if(it == '(')
            {
                open++;
            }
            else if(it == ')'){
                close++;
            }
            if(open == close)
            {
                // valid substring
                maxLen = max(maxLen, 2*close);
            }
            else if(close > open){
                close=open =0;
            }
        }

        // right to left traversal
    open = close = 0;
    for(int i=n-1;i>=0;i--)
    {
       if(s[i] == '('){
        open++;
       }
       else if(s[i] == ')'){
        close++;
       }
       if(open == close)
       {
        maxLen = max(maxLen, 2*open);
       }
       else if(open > close){
        open = close = 0;
       }
    }
    return maxLen;
    }
};
