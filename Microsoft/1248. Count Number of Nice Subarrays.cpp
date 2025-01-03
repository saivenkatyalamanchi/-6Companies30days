class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int m = 0;

        int odd = 0;
        int count = 0;

        for(int r=0;r<n;r++){
            if(nums[r] % 2 == 1){
                odd++;
            }

            
            while(odd > k){
                if(nums[l] % 2 == 1){
                    odd--;
                }

                l+=1;
                m = l;
            }
            


            if(odd == k){
                while(nums[m] % 2 == 0){
                    m++;
                }

                count += ((m-l) + 1);
            }
        }

        return count;
    }
};