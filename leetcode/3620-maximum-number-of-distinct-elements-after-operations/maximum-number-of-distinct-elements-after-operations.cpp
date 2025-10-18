class Solution {
private:
    struct Segment {
        int l, r;
    };
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        vector<Segment> segs;
        for (int num : nums) {
            segs.push_back({num - k, num + k});
        }
        sort(segs.begin(), segs.end(), [](const Segment &a, const Segment &b){
            if (a.r == b.r) return a.l < b.l;
            return a.r < b.r;
        });
        set<int> used; 
        int cnt = 0;
        for (int i = 0; i < segs.size(); i++) {
            int l = segs[i].l;
            int r = segs[i].r;
            int low = l, high = r;
            int pick = INT_MIN;
            while (low <= high) {
                int mid = low + (high - low)/2;
                if (!used.count(mid)) {
                    pick = mid;      
                    high = mid - 1;  
                } else {
                    low = mid + 1;
                }
            }
            // cout << "Assigning number " << pick << " to segment [" << segs[i].l << "," << segs[i].r << "]" << endl;
            if (pick != INT_MIN) {
                used.insert(pick);
                cnt++;
            }
        }
        return cnt;
    }
};