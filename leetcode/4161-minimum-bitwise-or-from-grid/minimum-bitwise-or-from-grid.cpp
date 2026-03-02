class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        uint32_t X = 0;
        for (auto &row : grid)
            for (int a : row)
                X |= (uint32_t)a;
        auto feasible = [&](uint32_t mask) -> bool {
            for (auto &row : grid) {
                bool ok = false;
                for (int a : row) {
                    uint32_t ua = (uint32_t)a;
                    if ((ua & ~mask) == 0u) { 
                        ok = true;
                        break;
                    }
                }
                if (!ok) return false;
            }
            return true;
        };
        for (int b = 31; b >= 0; --b) {
            if ((X >> b) & 1u) {
                uint32_t X2 = X & ~(1u << b);
                if (feasible(X2)) X = X2;
            }
        }

        return (int)X;
    }
};