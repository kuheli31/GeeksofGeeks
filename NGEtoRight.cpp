#include <bits/stdc++.h>  // Including all standard C++ libraries
using namespace std;

class Solution {
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        stack<int> asc;  // Stack to store elements in increasing order
        stack<int> desc; // Temporary stack to reverse elements
        vector<int> v(n, 0); // Vector to store the count of greater elements for each index
        vector<int> ans; // Vector to store the final answer for queried indices
        
        // Iterate from right to left in the array
        for (int i = n - 1; i >= 0; i--) {
            int ele = arr[i]; // Current element

            // Remove elements from the 'asc' stack that are smaller than or equal to the current element
            while (!asc.empty() && ele >= asc.top()) {
                desc.push(asc.top()); // Move elements to 'desc' stack
                asc.pop();
            }

            desc.push(ele); // Push current element to 'desc' stack
            v[i] = asc.size(); // Store the count of greater elements in 'v' for index i

            // Restore elements back from 'desc' stack to 'asc' stack
            while (!desc.empty()) {
                asc.push(desc.top());
                desc.pop();
            }        
        }
        
        // Retrieve the results for the queried indices
        for (int i = 0; i < queries; i++) {
            ans.push_back(v[indices[i]]);
        }

        return ans; // Return the final result vector
    }
};

int main() {
    vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6}; // Input array
    int n = arr.size(); // Size of the array
    vector<int> indices = {0, 5}; // Indices to query
    int q = indices.size(); // Number of queries
    
    Solution obj; // Creating an instance of the Solution class
    vector<int> result = obj.count_NGE(n, arr, q, indices); // Call function to get results
    
    // Print the result
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
