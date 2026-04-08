class Solution {
    public int xorAfterQueries(int[] nums, int[][] query) {
        int n = query.length;
        long mod = 1000000000 + 7;
        for(int i = 0; i < n; ++i) {
            int l = query[i][0];
            int r = query[i][1];
            int k = query[i][2];
            int v = query[i][3];
            for(int j = l; j <= r; j += k) {
                nums[j] = (int)(((long)nums[j] * v) % mod);
            }
        }
        n = nums.length;
        int xorr = nums[0];
        for(int i = 1; i < n; ++i) {
            xorr = (xorr ^ nums[i]);
        }
        return xorr;
    }
}