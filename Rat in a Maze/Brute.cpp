#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(int i, int j, vector<vector<int>>& mat, int n, vector<string>& ans, string move, vector<vector<int>>& vis) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }

        vis[i][j] = 1;

        // Down
        if (i + 1 < n && !vis[i + 1][j] && mat[i + 1][j] == 1) {
            solve(i + 1, j, mat, n, ans, move + 'D', vis);
        }

        // Left
        if (j - 1 >= 0 && !vis[i][j - 1] && mat[i][j - 1] == 1) {
            solve(i, j - 1, mat, n, ans, move + 'L', vis);
        }

        // Right
        if (j + 1 < n && !vis[i][j + 1] && mat[i][j + 1] == 1) {
            solve(i, j + 1, mat, n, ans, move + 'R', vis);
        }

        // Up
        if (i - 1 >= 0 && !vis[i - 1][j] && mat[i - 1][j] == 1) {
            solve(i - 1, j, mat, n, ans, move + 'U', vis);
        }

        vis[i][j] = 0;
    }

    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        int n = mat.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if (mat[0][0] == 1)
            solve(0, 0, mat, n, ans, "", vis);

        sort(ans.begin(), ans.end()); // Lexicographically sort the result
        return ans;
    }
};

// Example usage
int main() {
    Solution obj;
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> result = obj.findPath(mat);

    if (result.empty()) {
        cout << "No path found." << endl;
    } else {
        for (string s : result) {
            cout << s << endl;
        }
    }

    return 0;
}
