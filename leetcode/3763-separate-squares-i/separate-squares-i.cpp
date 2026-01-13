class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        // basicc lineswp
        int n = squares.size();
        vector<pair<double, double>> events;
        for (auto& i : squares) {
            events.push_back({i[1], i[2]});
            events.push_back({i[1] + i[2], -i[2]});
        }
        sort(events.begin(), events.end(),
             [](const pair<double, double>& a, const pair<double, double>& b) {
                 if (a.first != b.first)
                     return a.first < b.first;
                 return a.second > b.second;
             });
        double total = 0;
        for (auto& i : squares) {
            total += (long long)i[2] * i[2];
        }
        double curoverlap = 0;
        double prev = events[0].first;
        double width = 0;
        int m = events.size();
        for (int i = 0; i < m; i++) {
            int gap = events[i].first - prev;
            if (i != 0) {
                curoverlap += width * (gap);
            }
            if (curoverlap >= total / 2.0) {
                double areaadd = (long long)width * (gap);
                double rem = total / 2.0 - (curoverlap - areaadd);
                double temp = rem / width;
                return prev + temp;
            } else {
                width += events[i].second;
                prev = events[i].first;
            }
        }
        return 0;
    }
};