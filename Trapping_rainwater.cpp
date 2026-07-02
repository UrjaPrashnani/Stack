// Brute approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate trapped rainwater using brute force approach
    int trap(vector<int>& height) {
        int n = height.size();
        
        // Variable to store total trapped water
        int totalWater = 0;
        
        // Iterate over each bar in the elevation map
        for (int i = 0; i < n; i++) {
            // Initialize max heights to the left and right of current bar
            int maxLeft = 0;
            int maxRight = 0;
            
            // Find maximum height to the left of current bar
            for (int j = 0; j <= i; j++) {
                if (height[j] > maxLeft) {
                    maxLeft = height[j];
                }
            }
            
            // Find maximum height to the right of current bar
            for (int j = i; j < n; j++) {
                if (height[j] > maxRight) {
                    maxRight = height[j];
                }
            }
            
            // Water trapped on current bar is min of maxLeft and maxRight minus current height
            totalWater += min(maxLeft, maxRight) - height[i];
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



// Better approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> maxLeft(n,0);
        vector<int> maxRight (n,0);
        maxLeft[0]=height[0];
        maxRight[n-1] = height[n-1];
        // Variable to store total trapped water
        int totalWater = 0;
        
        for (int i = 1; i < n; i++) {
           maxLeft[i]=max(maxLeft[i-1],height[i]);
            
        }
        for (int i = n-2; i >= 0; i--){
           maxRight[i]=max(maxRight[i+1],height[i]) ;
        }
        for (int i = 0; i < n; i++){
  
            totalWater += (min(maxLeft[i], maxRight[i]) - height[i]);
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



// Optimal approach
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
