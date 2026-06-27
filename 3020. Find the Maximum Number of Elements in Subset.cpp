
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        int max_len = 1;
        
        if (freq.count(1)) {
            int count_1 = freq[1];
            if (count_1 % 2 == 0) {
                max_len = max(max_len, count_1 - 1);
            } else {
                max_len = max(max_len, count_1);
            }
        }
        
        for (auto const& [key, val] : freq) {
            long long x = key;
            if (x == 1) continue;
            
            long long curr = x;
            int curr_len = 0;
            
            while (freq.count(curr) && freq[curr] >= 2 && freq.count(curr * curr)) {
                curr_len += 2;
                curr = curr * curr;
            }
            
            if (freq.count(curr)) {
                curr_len += 1;
            } else {
                curr_len -= 1; 
            }
            
            max_len = max(max_len, curr_len);
        }
        
        return max_len;
    }
};
