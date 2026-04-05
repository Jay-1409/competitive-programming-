class Solution {
    public int distanceTraveled(int mainTank, int additionalTank) {
        int total = 0;
        int cnt = 0;
        while(mainTank > 0) {
            total += 10;
            mainTank--;
            cnt++;
            if(cnt % 5 == 0 && additionalTank > 0) {
                mainTank++;
                additionalTank--;
            }
        }
        return total;
    }
}