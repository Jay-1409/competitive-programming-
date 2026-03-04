func numSpecial(mat [][]int) int {
    n := len(mat);
    m := len(mat[0]);
    cnt := 0;
    for i := 0; i < n; i++ {
        for j:= 0; j < m; j++ {
            row := 0;
            col := 0;
            if mat[i][j] == 1 {
                for k := 0; k < n; k++ {
                    if mat[k][j] == 1 {
                        col++;
                    }
                }
                for k := 0; k < m; k++ {
                    if mat[i][k] == 1 {
                        row++;
                    }
                }
                if row == 1 && col == 1 {
                    cnt ++;
                }
            }
        }
    } 
    return cnt;
}