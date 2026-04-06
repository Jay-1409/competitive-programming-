class Solution {
    public int helper(Map<Integer, TreeSet<Integer>> set, int fixed_val, int cur_val, int gap, char op) {
        /*
        Returns the position where we end up after moving,
        while respecting the nearest obstacle.
        */
        TreeSet<Integer> obstacles = set.get(fixed_val);
        if (obstacles == null) {
            return op == '+' ? cur_val + gap : cur_val - gap;
        }
        if (op == '+') {
            Integer next = obstacles.higher(cur_val); // strictly greater obstacle
            if (next == null) {
                return cur_val + gap;
            }
            return Math.min(next - 1, cur_val + gap);
        } else {
            Integer prev = obstacles.lower(cur_val); // strictly smaller obstacle
            if (prev == null) {
                return cur_val - gap;
            }
            return Math.max(prev + 1, cur_val - gap);
        }
    }
    public int get_distance(int x, int y) {
        return x * x + y * y;
    }
    public int robotSim(int[] commands, int[][] obstacles) {
        int ans = 0;
        int n = commands.length;
        int x = 0;
        int y = 0;
        Map<Integer, TreeSet<Integer>> xst = new HashMap<>();
        Map<Integer, TreeSet<Integer>> yst = new HashMap<>();
        int p = obstacles.length;
        int q = 0;
        if(p > 0)
            q = obstacles[0].length;
        for(int i = 0; i < p; ++i) {
            int ox = obstacles[i][0];
            int oy = obstacles[i][1];
            xst.putIfAbsent(ox, new TreeSet<>());
            xst.get(ox).add(oy);
            yst.putIfAbsent(oy, new TreeSet<>());
            yst.get(oy).add(ox);
        }
        int dxn = 1 ;
        //[1 - > north, 2 -> east, 3 -> south, 4 -> west]
        for(int i = 0; i < n; ++i) {
            if(commands[i] == -1) {
                dxn = (dxn + 1) % 4;
            } else if (commands[i] == -2) {
                dxn = (dxn - 1 + 4) % 4;
            } else {
                if(dxn == 1) { 
                    y = helper(xst, x, y, commands[i], '+');
                } else if(dxn == 2) {
                    x = helper(yst, y, x, commands[i], '+');
                } else if(dxn == 3) {
                    y = helper(xst, x, y, commands[i], '-');
                } else {
                    x = helper(yst, y, x, commands[i], '-');
                }
            }
            ans = Math.max(get_distance(x, y), ans);
        }
        return ans;
    }
}