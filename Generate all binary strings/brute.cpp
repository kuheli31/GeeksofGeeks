class Solution{
    public:
         vector<string> generateBinaryStrings(int n) {
            vector<string> res;
            
            // Base case
            res.push_back("0");
            res.push_back("1");
            if (n == 1) return res;
    
            for (int i = 2; i <= n; i++) {
                vector<string> temp;
                for (string str : res) {
                    if (str.back() == '0') {
                        temp.push_back(str + '0');
                        temp.push_back(str + '1');
                    } else {
                        temp.push_back(str + '0');
                    }
                }
                res = temp;
            }
    
            return res;
    }
};