#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// Function to find all subarrays whose sum = target, and the length of the longest one
pair<vector<vector<int>>, int> solve(vector<int> &A, const int &target) {
    int i = 0, j = 0, n = A.size();
    int sum = 0;  // This holds the current window sum
    vector<vector<int>> store;  // To store all subarrays whose sum == target
    int mx = 0;  // Initialize mx to 0 instead of INT_MIN

    // Loop through the array with sliding window approach
    while (j < n) {
        sum += A[j];  // Add current element to the window sum

        // CASE 1: sum < target ? expand window to the right
        if (sum < target) {
            j++;  // Move right pointer
        }
        // CASE 2: sum == target ? store the subarray and update max length
        else if (sum == target) {
            // Extract the subarray from index i to j (inclusive) and store it
            store.push_back(vector<int>(A.begin() + i, A.begin() + j + 1));

            // Update the maximum subarray length
            mx = max(mx, j - i + 1);

            j++;  // Expand the window
        }
        // CASE 3: sum > target ? shrink window from the left
        else if (sum > target) {
            // Keep shrinking from the left while sum is too large
            while (sum > target && i <= j) {
                sum -= A[i];  // Remove A[i] from sum
                i++;          // Shrink window from left
            }

            // After shrinking, if sum == target, store it as well
            if (sum == target) {
                store.push_back(vector<int>(A.begin() + i, A.begin() + j + 1));
                mx = max(mx, j - i + 1);
            }

            j++;  // Move right pointer
        }
    }

    // If no valid subarrays are found, mx will be 0, which is meaningful
    return {store, mx};
}

int main() {
    // Sample input array and target sum
    vector<int> A{4, 1, 1, 1, 2, 3, 5};
    int target = 5;

    // Call the solve function and get the result
    pair<vector<vector<int>>, int> result = solve(A, target);

    // Output the result to the console
    cout << "Max Length of Subarray with sum " << target << ": " << result.second << endl;
    cout << "Subarrays with sum " << target << ":\n";

    // If no subarrays found, result.second will be 0, so we handle this case
    if (result.second == 0) {
        cout << "No subarrays found with the given sum.\n";
    } else {
        // Print each subarray
        for (auto &sub : result.first) {
            cout << "[ ";
            for (int x : sub)
                cout << x << " ";
            cout << "]\n";
        }
    }

    return 0;
}
