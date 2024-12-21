class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) 
    {
        // code here
        int i,gcd=1;
        int limit=min(a,b);
        
        for(i=1;i<=limit;i++)
        {
            if(a%i==0 && b%i==0)
            {
                gcd=i;
            }
        }
        //Calculate LCM using the formula: LCM(a, b) = (a * b) / GCD(a, b)
        int lcm = (a / gcd) * b;

        
        return {lcm,gcd};
    }
};