class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        sort(nums.begin(),nums.end());

        int left = 0;
        int right = n-1;

        while(left < right){
            ans += abs(nums[left] - nums[right]);
            left++;
            right--;
        }

        return ans;
    }
};