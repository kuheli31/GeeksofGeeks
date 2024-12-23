#include <bits/stdc++.h>
using namespace std;

class Solution 
{
  public:
    vector<long long> factorialNumbers(long long n) 
    {
        vector<long long> v;
        long long i , fact = 1;

        for (i = 1; i <= n; i++) 
        {
            fact = fact * i;
            v.push_back(fact);
            if (v[i-1] > n) 
            {
                v.pop_back();
                break;
            }
        }
        return v;
    }
};

int main() 
{
    Solution sol;
    long long n;
    cout << "Enter a number: ";
    cin >> n;

    vector<long long> result = sol.factorialNumbers(n);
    cout << "Factorial numbers less than or equal to " << n << " are: ";
    
    for (long long num : result) 
    {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
