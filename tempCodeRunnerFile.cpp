#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate trapped rainwater using the optimal two-pointer approach
    int trap(vector<int>& height) {
        int n = height.size();
        
        // Initialize two pointers at both ends of the array
        int left = 0;
        int right = n - 1;
        
        // Variables to track the maximum height to the left and right
        int maxLeft = 0;
        int maxRight = 0;
        
        // Variable to store total trapped water
        int totalWater = 0;
        
       
        while (left <right) {
            maxLeft =max(maxLeft,height[left] );
            maxRight =max(maxRight,height[right] );
            if (height[left] < height[right]) {
               
                    totalWater += maxLeft - height[left];
                    left++;
            }
            else {
               
                    totalWater += maxRight - height[right];
                    right--;
                }
                 
            
        }
        
        // Return total trapped water
        return totalWater;
    }
};

// Driver code
int main() {
    // Input elevation map
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    // Create Solution object
    Solution sol;
    
    // Calculate trapped water
    int result = sol.trap(height);
    
    // Print the result
    cout << "Trapped Rainwater: " << result << endl;
    
    return 0;
}
