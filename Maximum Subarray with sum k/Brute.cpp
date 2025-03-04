//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // Declare variables
        int i, j, p, n = arr.size(); // Initialize indices and array size
        int length = 0; // Initialize the maximum length of the subarray

        // Traverse the array starting with index i
        for (i = 0; i < n; i++) {
            // Traverse all subarrays starting from i to j
            for (j = i; j < n; j++) {
                int sum = 0; // Initialize sum for each subarray
                
                // Calculate the sum of the current subarray
                for (p = i; p <= j; p++) {
                    sum = sum + arr[p]; // Add each element in the range [i, j]
                }
                
                // Check if the sum equals k
                if (sum == k) {
                    // Update the maximum length of the subarray
                    length = max(length, j - i + 1);
                }
            }
        }
        // Return the length of the longest subarray with sum equal to k
        return length;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t; // Read the number of test cases
    cin.ignore(); // Ignore newline character after reading t

    while (t--) {
        vector<int> arr; // Initialize the input array
        int k; // Target sum
        string inputLine;

        getline(cin, inputLine); // Read the array input as a single line
        stringstream ss(inputLine); // Parse the input line using stringstream
        int value;
        while (ss >> value) { // Extract integers from the input line and add them to the array
            arr.push_back(value);
        }

        cin >> k; // Read the target sum
        cin.ignore(); // Ignore newline character after reading k

        Solution solution; // Create an instance of the Solution class
        cout << solution.longestSubarray(arr, k) << "\n"; // Output the result
        cout << "~\n"; // Print a delimiter for readability
    }

    return 0; // End of the program
}

// } Driver Code Ends
