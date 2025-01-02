class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> ans(m,vector<int>(n));
           int dir_x[8] = {0, 0, -1, 1, -1, -1, 1, 1};
            int dir_y[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum = 0;
                int count = 0;

                for(int k=0;k<8;k++){
                    int newx = dir_x[k] + i;
                    int newy = dir_y[k] + j;

                    if(newx >= 0 && newy >=0 && newx < m && newy < n){
                        sum += img[newx][newy];
                        count++;
                    }
                }

                sum += img[i][j];
                count++;

                ans[i][j] = sum/count;


            }
        }

        return ans;
    }
};