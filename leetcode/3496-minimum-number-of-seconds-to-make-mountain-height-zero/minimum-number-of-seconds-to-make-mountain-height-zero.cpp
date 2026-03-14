class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();
        /**
            decrease the height by x, amount it will take time *(1 + 2 + .... + x);
            sum_of(1->x) = x * (x + 1) / 2;
        **/
        auto get_max = [&]() -> long long {
            long long mine = 0LL;
            for(auto &i : workerTimes) {
                mine = max(mine, 1LL * i * (1LL * mountainHeight * (1LL * mountainHeight + 1) / 2LL));
            }
            return mine;
        };
        long long lo = 0;
        long long hi = get_max();
        long long bes = LLONG_MAX;
        while(lo <= hi) {
            long long mid = (hi + lo) / 2;
            int covered_height = 0;
            for(auto &i : workerTimes) {
                int low = 0;
                int high = mountainHeight;
                int best = 0;
                while(low <= high) {
                    int middle = (high + low) / 2;
                    long long time_required = 1LL * i * (1LL * middle * (1LL * middle + 1) / 2LL);
                    if(time_required > mid) {
                        high = middle - 1;
                    } else {
                        best = max(best, middle);
                        low = middle + 1;
                    }
                }
                covered_height += best;
            }
            if(covered_height >= mountainHeight) {
                bes = min(bes, mid);
                hi = mid -1 ;
            } else {
                lo = mid + 1;
            }
        }
        return bes;
    }
};