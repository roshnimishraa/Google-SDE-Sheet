Time Complexity: O(N)
Space Complexity: O(N)

class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
       unordered_map<string, int> mp;
       for(int i=0;i<n;i++){
           mp[arr[i]]++;
       }
       int maxi=0;
       for(auto it: mp){
           if(maxi <= it.second)
           maxi = it.second;
       }
       string temp="";
       for(auto it: mp){
           if(it.second == maxi){
               if(temp=="")
               temp = it.first;
               else
               {
                   if(it.first < temp)
                   temp = it.first;
               }
           }
       }
       vector<string> ans;
       ans.push_back(temp);
       ans.push_back(to_string(maxi));
       return ans;
    }
};
