#include <vector>;

class Solution {
public:

    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        
        // Input sanitozation:
        // Ensure nums1 has enough space
        if (nums1.size() < m + n) {
            throw std::invalid_argument("nums1 does not have enough space to hold both arrays.");
        }
        
        // Edge Case: If nums1 has no elements (m == 0), just copy nums2 into nums1
        if (m == 0) {
            std::copy(nums2.begin(), nums2.end(), nums1.begin());
            return;
        }
        
        // Main Loop --------------------------------------------->
        
        int idx_last = n + m - 1;  // Index for the last position to fill in nums1
        int idx1 = m - 1;          // Last element of the actual data in nums1
        int idx2 = n - 1;          // Last element of nums2
       

        while(idx1 >= 0 && idx2 >= 0){

            if(nums1[idx1] > nums2[idx2]){
                nums1[idx_last--] = nums1[idx1--]; 
            } else {
                nums1[idx_last--] = nums2[idx2--];
            } 
        } // for
        
        // If there are still elements in nums2, copy them over
        while(idx2 >= 0){
            nums1[idx_last--]=nums2[idx2--];
        } // while
    
    }
};