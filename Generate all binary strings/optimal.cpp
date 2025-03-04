#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateStrings(int n, string curr, vector<string>& result) {
        // Base case: if the string reaches size N, add to result
        if (curr.size() == n) {
            result.push_back(curr);
            return;
        }

        // Always add '0'
        generateStrings(n, curr + '0', result);

        // Add '1' only if the last character is not '1' (to avoid consecutive 1s)
        if (curr.empty() || curr.back() != '1') {
            generateStrings(n, curr + '1', result);
        }
    }

    vector<string> generateBinaryStrings(int n) {
        vector<string> result;
        generateStrings(n, "", result);
        return result;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int n;
        cin >> n;

        Solution obj;
        vector<string> v = obj.generateBinaryStrings(n);
        
        for (const auto &s : v) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
