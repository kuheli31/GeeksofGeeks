class Solution {
    public:
      string reverseString(string& s) 
      {
          // code here
          char B[9990000];
          int i,j;
          for(i=0;s[i]!='\0';i++);
          
          i=i-1;
          for(j=0; i>=0 ; i--,j++)
          {
              B[j]=s[i];
          }
          
          B[j]='\0';
          return string(B);
      }
  };
  