class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        List<Integer> list = new ArrayList<>();
        int n = points.length;
        TreeSet<Integer> set = new TreeSet<>();
        for(int i = 0; i < n; ++i) {
            if(!set.contains(points[i][0])) {
                set.add(points[i][0]);
                list.add(points[i][0]);
            }
        }
        Collections.sort(list);
        int m = list.size();
        int ans = 0;
        for(int i = 0; i < m - 1; ++i) {
            ans = Math.max(Math.abs(list.get(i) - list.get(i + 1)), ans);
        }
        return ans;
    }
}