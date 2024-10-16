### Approach 1: Brute Force 

Time Complexity: O(N*N ) 
Space Complexity: O(1)

class Solution {
  public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(vector<long long> &hist) {
       long long maxArea = 0;
        int n = hist.size();
        for(int i=0;i<n;i++){
            long long minHeight = INT_MAX;
            for(int j=i;j<n;j++){
                  minHeight = min(minHeight,hist[j]);
                long long width = j-i+1;
             maxArea = max(maxArea,minHeight*width);
            }
        }
        return maxArea;
    }
};

### Approach 2: Stack + Next Smaller + prev Smaller

Time Complexity: O(5N)
Space Complexity: O(2N) + O(2N)

class Solution {
    private:
vector<int> nextSmaller(vector<long long> &hist)
{
    int n=hist.size();
    vector<int> nextS(n,n);
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() &&  hist[st.top()] > hist[i]){
            //that can be nge of next element
            nextS[i] = i;
            st.pop();
        }
        st.push(i);
    }
    return nextS;
}

vector<int> prevSmaller(vector<long long> &hist)
{
    int n = hist.size();
stack<int> st;
    vector<int> prevS(n,-1);
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && hist[st.top()] > hist[i])
        {
            st.top();
        }
        if(!st.empty()){
            prevS[i] = st.top();
        }
        st.push(i);
    }
    return prevS;
}
  public:
    
    long long getMaxArea(vector<long long> &hist) {
        vector<int> prevS = prevSmaller(hist);
        vector<int> nextS = nextSmaller(hist);
        int maxArea =0;
        for(int i=0;i<hist.size();i++){
            int width = nextS[i]-prevS[i]-1;
            int area = hist[i]*width;
        maxArea = max(maxArea,area );
        }
        return maxArea;
    }
};

### Approach 3 :  Single pass approach

# Time Complexity: O(n)  
# Space Complexity: O(n)

## Note
When we compute next smaller element, we pop an item from the stack and mark current item as next smaller of it.
One important observation here is the item below every item in stack is the previous smaller element.
So we do not need to explicitly compute previous smaller. 

#include <bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    int res = 0;
    int tp, curr;
    for (int i = 0; i < n; i++) {      
         
        while (!s.empty() && arr[s.top()] >= arr[i]) {
          
            // The popped item is to be considered as the 
            // smallest element of the histogram
            tp = s.top(); 
            s.pop();
          
            // For the popped item previous smaller element is 
            // just below it in the stack (or current stack top)
            // and next smaller element is i
            int width = s.empty() ? i : i - s.top() - 1;
          
            res = max(res,  arr[tp] * width);
        }
        s.push(i);
    }

    // For the remaining items in the stack, next smaller does
    // not exist. Previous smaller is the item just below in
    // stack.
    while (!s.empty()) {
        tp = s.top(); s.pop();
        curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
        res = max(res, curr);
    }

    return res;
}

int main() {
    vector<int> arr = {60, 20, 50, 40, 10, 50, 60};
    cout << getMaxArea(arr);
    return 0;
}
