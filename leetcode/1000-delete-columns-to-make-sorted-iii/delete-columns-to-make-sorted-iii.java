class Solution {
    public boolean check(int x, int y, String[] strs) {
        int n = strs.length;
        for(int i = 0; i < n; ++i) {
            if(strs[i].charAt(x) > strs[i].charAt(y))
                return false;
        }
        return true;
    }
    public int minDeletionSize(String[] strs) {
        int n = strs.length;
        int m = strs[0].length();
        int[] dp = new int[m];
        for(int i = 0; i < m; ++i) 
            dp[i] = 1;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < i; ++j) {
                if(check(j, i, strs)) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
        for(int i = 1; i < m; ++i) {
            dp[i] = Math.max(dp[i], dp[i - 1]);
        }
        return m - dp[m - 1];
    }
}