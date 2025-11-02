class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int grid[m][n];
        for(int i = 0; i < m; i++)
        memset(grid[i],0,sizeof(grid[i]));
        for(auto &i : guards){
            grid[i[0]][i[1]] = 1;
        }
        for(auto &i : walls){
            grid[i[0]][i[1]] = -1;
        }
        auto level = [&](int x,int y){
            // cout << "-----------" << endl;
            for(int i = x + 1; i < m; i++){
                // cout << x << " " << y << endl;
                if(grid[i][y] == -1 || grid[i][y] == 1){
                    break;
                }
                grid[i][y] = 2;
            }
            for(int i = y + 1; i < n; i++){
                if(grid[x][i] == -1 || grid[x][i] == 1){
                    break;
                }
                grid[x][i] = 2;
            }
            for(int i = x - 1; i >= 0; i--){
              if(grid[i][y] == -1 || grid[i][y] == 1){
                    break;
                }
                grid[i][y] = 2;
            }
            for(int i = y - 1; i >= 0; i--){
                if(grid[x][i] == -1 || grid[x][i] == 1){
                    break;
                }
                grid[x][i] = 2;
            }
        };
        for(auto &i : guards){
            level(i[0],i[1]);
        }
        
        int cnt = 0;
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ;j < n ; j++){
                // cout << grid[i][j] << " ";
                if(grid[i][j] == 0)cnt++;
            }
            // cout << endl;
        }
        return cnt;
    }
};