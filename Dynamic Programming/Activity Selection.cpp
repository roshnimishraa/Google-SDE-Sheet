### Approach : Greedy

# Time Complexity: O(n) to iterate through every position and insert them in a data structure. O(n log n)  to sort the data structure in ascending order of end time. O(n)  to iterate through the positions and check which meeting can be performed.
Overall : O(n) +O(n log n) + O(n) ~O(n log n)
# Space Complexity: O(n)  since we used an additional data structure for storing the start time, end time, and meeting no.

struct meeting {
   int start;
   int end;
   int pos;
};
class Solution
{
 bool static comparator(meeting m1, meeting m2)
 {
    //  sort acc. to end time
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.pos < m2.pos) return true;
    else
    return false;
 }
    public:

    int activitySelection(vector<int> start, vector<int> end, int n)
    {
       struct meeting meet[n];
      for(int i=0;i<n;i++)
      {
          meet[i].start =start[i];
          meet[i].end = end[i];
          meet[i].pos = i+1; //1 based indexing
      }
    //   sort acc. to end time
    sort(meet, meet+n, comparator);
   
    int limit = meet[0].end;
   int count = 1;
    for(int i=1;i<n;i++)
    {
        if(meet[i].start > limit)
        {
            limit = meet[i].end;
            count++;
        }
    }
    return count;
    }
};
