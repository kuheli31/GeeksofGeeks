#include <bits/stdc++.h>
using namespace std;

int sumOfSeries(int n) 
{
        // code here
        if(n==0)
        {
            return 0;
        }
        else
        {
             return pow(n, 3) + sumOfSeries(n - 1);
        }
}
int main()
{
    int x=5;
    cout<<sumOfSeries(x);
}