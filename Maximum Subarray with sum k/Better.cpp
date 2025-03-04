//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // Declare a map to store prefix sums and their earliest indices
        map<long long, int> preSumMap;
        
        long long sum = 0; // Initialize the cumulative sum
        int maxLen = 0;    // Initialize the maximum length of subarray

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i]; // Add the current element to the cumulative sum

            // If the cumulative sum equals k, update maxLen
            if (sum == k) {
                maxLen = max(maxLen, i + 1);
            }

            // Calculate the remaining sum needed to form k
            long long rem = sum - k;

            // Check if the remaining sum is in the map
            if (preSumMap.find(rem) != preSumMap.end()) {
                // Calculate the length of the subarray
                int len = i - preSumMap[rem];
                // Update maxLen if a longer subarray is found
                maxLen = max(maxLen, len);
            }

            // Store the current sum and its index if it's not already in the map
            if (preSumMap.find(sum) == preSumMap.end()) {
                preSumMap[sum] = i;
            }
        }
        return maxLen; // Return the length of the longest subarray
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t; // Read the number of test cases
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr; // Initialize the input array
        int k; // Target sum
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine); // Parse the input line
        int value;
        while (ss >> value) { // Extract integers from the line and add to the array
            arr.push_back(value);
        }

        cin >> k; // Read the target sum
        cin.ignore(); // Ignore newline character after k input

        Solution solution; // Create an instance of the Solution class
        cout << solution.longestSubarray(arr, k) << "\n"; // Output the result
        cout << "~\n"; // Print a delimiter for better readability
    }

    return 0; // End of the program
}

// } Driver Code Ends
