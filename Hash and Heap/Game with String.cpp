### Approach: Max heap

Time Complexity: O(n + k) where n is the length of the string and k is the number of operations.
Space Complexity: O(1) (constant space).

class Solution {
  public:
    int minValue(string s, int k) {
        vector<int> freq(26,0);
        // max heap 
        priority_queue<int> pq;
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(freq[i] != 0)
            {
                pq.push(freq[i]);
            }
        }
        while(k--)
        {
            int top = pq.top();
            pq.pop();
            pq.push(top-1);
        }
        int res=0;
        while(!pq.empty())
        {
            int x = pq.top();
            pq.pop();
            res += (x*x);
        }
        return res;
    }
};
