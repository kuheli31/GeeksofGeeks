#include <bits/stdc++.h>
using namespace std;
// Brute force
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {

        sort(nums.begin(), nums.end());  // Sort the array for easier processing
        int maxFreq = 0;
        int n = nums.size();
        
        // Try to create a subarray starting from each element
        for (int start = 0; start < n; start++) 
        {
            int sum = 0;
            int freq = 1; // At least the current element itself
            for (int end = start + 1; end < n; end++) 
            {
                sum += (nums[end] - nums[end - 1]) * (end - start);  // Calculate how much it would take to make nums[end] equal to nums[start]
                
                // If the sum of differences exceeds k, break the loop
                if (sum > k) 
                {
                    break;
                }
                freq++; // Increment the frequency as we added nums[end] to the subarray
            }
            
            maxFreq = max(maxFreq, freq);  // Update maximum frequency found so far
        }
        
        return maxFreq;
    }
};

int main() {
    // Input
    int k = 5;
    vector<int> nums = {1, 2, 4};

    // Create an object of the Solution class and call the function
    Solution ob;
    int result = ob.maxFrequency(nums, k);

    // Output the result
    cout << "Maximum frequency: " << result << endl;

    return 0;
}
