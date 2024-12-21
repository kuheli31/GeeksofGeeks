class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int rem,counter=0;
        int num=n;
        string numStr = to_string(n);
        while(n>0)
        {
            rem=n%10;
            n=n/10;
        
        if(rem!=0 && num%rem==0)
        {
            counter++;
        }
        }
        return counter;
    }
};