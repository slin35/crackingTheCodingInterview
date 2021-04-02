#include <iostream>
#include <vector>

using namespace std;

/* search in rotated array (leecode 33):
 *  given a sorted array of n integers that have been rotated unknown number of times,
 *  find an element in the array asap 
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;
        
        int pivot = getPivot(nums, 0, nums.size() - 1);
        
        if (target <= nums[nums.size() - 1])
            return bsearch(nums, pivot, nums.size(), target);
        else
            return bsearch(nums, 0, pivot, target);
            
        return -1;
    }
    
    int getPivot(vector<int>& nums, int l, int r) {       
        while (l < r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
                
        }       
        return l;
    }
    
    int bsearch(vector<int>& nums, int l, int r, int target) {
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid;
            else
                return mid;
        }
        
        return -1;
    }
};