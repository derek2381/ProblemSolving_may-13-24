// problem link
// https://leetcode.com/problems/score-after-flipping-matrix/description/?envType=daily-question&envId=2024-05-13

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0;i < m;i++){
            int setVal = 0, unsetVal = 0, k = 0;
            for(int j = n-1;j >= 0;j--){
                if(grid[i][j] == 1){
                    setVal += 1 << k;
                }else{
                    unsetVal += 1 << k;
                }
                k++;
            }

            if(unsetVal > setVal){
                for(int j = 0;j < n;j++){
                    if(grid[i][j] == 1){
                        grid[i][j] = 0;
                    }else{
                        grid[i][j] = 1;
                    }
                }
            }
        }


        for(int j = 0;j < n;j++){
            int count0 = 0, count1 = 0;

            for(int i = 0;i < m;i++){
                if(grid[i][j] == 1){
                    count1++;
                }else{
                    count0++;
                }
            }

            if(count0 > count1){
                for(int i = 0;i < m;i++){
                    if(grid[i][j] == 1){
                        grid[i][j] = 0;
                    }else{
                        grid[i][j] = 1;
                    }
                }
            }
        }
        int total_val = 0;

        for(int i = 0;i < m;i++){
            int k = 0;
            for(int j = n-1;j >= 0;j--){
                if(grid[i][j] == 1){
                    total_val += 1 << k;
                }
                k++;
            }

        }

        return total_val;
    }
};
