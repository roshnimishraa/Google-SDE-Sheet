### Approach : Using Binary Search

Time Complexity: O(log(min(n1,n2))), where n1 and n2 are the sizes of two given arrays.
Reason: We are applying binary search on the range [0, min(n1, n2)].

Space Complexity: O(1) as no extra space is used.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2 = nums2.size();
        if(n1 > n2) 
        {
            return findMedianSortedArrays(nums2,nums1);
        }
        int n=n1+n2;
// calculate left partition size
int left = (n1+n2+1)/2;
int low=0, high=n1;
while(low <= high)
{
    // calculate mid index for nums1
    int mid1= low+(high-low)/2;
    // calculate mid index for nums2
    int mid2 = left-mid1;
    int l1=INT_MIN, l2=INT_MIN;
    int r1 = INT_MAX, r2=INT_MAX;
    // determine values of l1,l2,r1 and r2
if(mid1 < n1)
r1 = nums1[mid1];
if(mid2 < n2)
r2 = nums2[mid2];
if(mid1 - 1 >=0)
l1 = nums1[mid1-1];
if(mid2 - 1>=0)
l2 = nums2[mid2-1];

if(l1 <= r2 && l2 <= r1)
{
    if(n%2 == 1)
    return max(l1,l2);
    else 
    return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
}
    else if(l1 > l2){
        high = mid1-1;
    }
    else{
        low = mid1+1;
    }
}
return 0;
    }
};
