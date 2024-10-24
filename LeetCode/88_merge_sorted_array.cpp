#include <vector>;

class Solution {
public:

    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        
        // Input sanitozation:
        // Ensure nums1 has enough space
        if (nums1.size() < m + n) {
            throw std::invalid_argument("nums1 does not have enough space to hold both arrays.");
        }
        
       // Edge Cases ----------------------------------------->
        if(n == 0)
            return;
         
        // Main Loop ------------------------------------------>
        int currentIndex = n+m-1;
        int idx1{m-1}, idx2{n-1};
        
        // Start from the end of nums1
        while(idx1 >= 0 && idx2 >= 0){
            
            if(nums1[idx1] > nums2[idx2]){
               nums1[currentIndex--] = nums1[idx1--];
            } else {
               nums1[currentIndex--] = nums2[idx2--];
            }
        }
        
        while(idx2>=0){
            nums1[idx2] = nums2[idx2];
            idx2--;
        }
        
        return;
    }
};
