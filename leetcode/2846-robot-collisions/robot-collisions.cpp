class Solution {
public:
    struct Robot {
        int pos;
        int health;
        int ogidx;
        char dxn;
        Robot(int p, int h, int o, char d) {
            pos = p;
            health = h;
            ogidx = o;
            dxn = d;
        }
    };  
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robos;
        for(int i = 0; i < n; ++i){
            Robot cur_robo = Robot(positions[i], healths[i], i, directions[i]);
            robos.push_back(cur_robo);
        }
        sort(robos.begin(), robos.end(), [](const Robot &a, const Robot &b){
            return a.pos < b.pos;
        });
        stack<Robot> stk;
        for(auto &i : robos) {
            //cout << i.pos << " " << i.health << " " << i.ogidx << " " << i.dxn << endl;
            if(stk.empty()) {
                stk.push(i);
            } else {
                while (!stk.empty() && stk.top().dxn == 'R' && i.dxn == 'L') {
                    if (stk.top().health > i.health) {
                        auto u = stk.top();
                        stk.pop();
                        u.health--;
                        if (u.health > 0)
                            stk.push(u);
                        i.health = 0;
                        break;
                    } else if (stk.top().health < i.health) {
                        stk.pop();
                        i.health--;
                    } else {
                        stk.pop();
                        i.health = 0;
                        break;
                    }
                }
                if (i.health > 0) {
                    stk.push(i);
                }
            }
        }
        vector<pair<int,int>> pans;
        while(!stk.empty()) {
            pans.push_back({stk.top().ogidx, stk.top().health});
            stk.pop();
        }
        sort(pans.begin(), pans.end());
        vector<int> ans;
        for(auto &i : pans) {
            ans.push_back(i.second);
        }
        return ans;
    }
};