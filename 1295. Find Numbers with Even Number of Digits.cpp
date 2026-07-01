class Solution {
public:
    int countDigit(int n) {
        
         int digit = 0;
        while(n > 0){
            digit++;
            n=n / 10;

        }
        return digit;


    }
    int findNumbers(vector<int>&nums){
        int count =0;
        for (int n : nums){
            int digit = countDigit(n);
            if (digit % 2 == 0){
                count++;
            }

        }
        return count;
    }
};
    
