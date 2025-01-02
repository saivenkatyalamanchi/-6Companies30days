class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> dup = nums;
        int n = nums.size();
        sort(dup.begin(),dup.end());

        int right = (n+1)/2;
        int left = right-1;
        int end = n-1;


       for(int i=0;i<n;i++){
        if(i%2 ==0){
            nums[i] = dup[left--];
            
        }if(i%2 == 1){
            nums[i] = dup[end--];
        }
       }
        return;
        

    }
};