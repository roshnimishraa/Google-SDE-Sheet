### Approach 1: Brute Force (Nested Loops)

Time Complexity: O(N2), where N = size of the given array.
Space Complexity: O(1) as we are not using any extra space to solve this problem.
  
int numberOfInversions(vector<int>&a, int n) {

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) cnt++;
        }
    }
    return cnt;
}

### Approach 2: Merge Sort (Recursion) 

Time Complexity: O(N*logN), where N = size of the given array.
Reason: We are not changing the merge sort algorithm except by adding a variable to it. So, the time complexity is as same as the merge sort.
Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order.
  
class Solution {
   int merge(vector<int> &arr,int low,int mid,int high)
 {
     mid = low+(high - low) /2;
   int inversion_count =0;
    
    int len1 = mid - low +1;
    int len2 = high- mid;
vector<int>first(len1);
vector<int> second(len2);

// main array index 
int k=low;
for(int i=0;i<len1; i++){
    first[i]=arr[k++];
}


k=mid +1;
for(int i=0;i<len2;i++){
    second[i] = arr[k++];
}

int index1 =0;
int index2 =0;
k=low;
while(index1 < len1 && index2 <len2){
    if(first[index1] <= second[index2])
    {
        arr[k++]=first[index1++];
    }
    else{
        arr[k++] = second[index2++];
        inversion_count += len1 - index1;
    }
}
while(index1 <len1){
     arr[k++]=first[index1++];
}
while(index2 <len2){
    arr[k++] = second[index2++];
}
return inversion_count;
 }
 
 
 int mergeSort(vector<int> &arr,
int low, int high)
{
    int mid = low + (high - low)/2;
      int count = 0;
    if(low<high)
    {
     count += mergeSort(arr,low,mid);
     count += mergeSort(arr,mid+1,high);
    count +=  merge(arr,low,mid,high);
    }
    return count;
}
public:
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return mergeSort(arr, 0, n-1);
    }
};
