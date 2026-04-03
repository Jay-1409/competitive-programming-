class Solution {
    public int minimumFlips(int n) {
        List<Integer> lst = new ArrayList<>();
        int val = 0;
        for(int i = 0; i < 32 && val < n; i += 1) {
            int cur_bit = ((n >> i) & 1);
            lst.add(cur_bit);
            val += (1 << i);
        }
        int len = lst.size();
        int cnt = 0;
        for(int i = 0; i < len; i += 1) {
            if(lst.get(i) != lst.get(len - i - 1))
                cnt += 1;
        }
        return cnt;
    }
}