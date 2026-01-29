class Solution {
    String answer = "123450";
    Map<String, Integer> memo = new HashMap<>();
    
    public int slidingPuzzle(int[][] board) {
        int x = -1;
        int y = -1;
        
        String state = "";
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == 0){
                    x = i;
                    y = j;
                }
                state += board[i][j];
            }
        }
        
        dfs(state, x, y, 0);
        if(memo.get(answer) == null)
            return -1;
        return memo.get(answer);
    }
    
    void dfs(String state, int i, int j, int move){
        if(memo.get(state) != null && move >= memo.get(state))
            return;
        
        int zero = i*3+j;
        memo.put(state, move);
        
        // left
        if(j > 0)
            dfs(swap(state, zero, zero-1), i, j-1, move+1);
        
        // right
        if(j < 2)
            dfs(swap(state, zero, zero+1), i, j+1, move+1);
        
        // up
        if(i > 0)
            dfs(swap(state, zero, zero-3), i-1, j, move+1);
        
        // down
        if(i < 1)
            dfs(swap(state, zero, zero+3), i+1, j, move+1);
    }
    
    String swap (String state, int zero, int notZero){
        char[] arr = state.toCharArray();
        arr[zero] = arr[notZero];
        arr[notZero] = '0';
        return new String(arr);
    }
}