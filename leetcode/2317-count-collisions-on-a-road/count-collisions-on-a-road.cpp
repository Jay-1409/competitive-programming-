class Solution {
public:
    int countCollisions(string directions) {
        int cnt = 0;
        string s;
        int loc = 0;
        while(loc < (int)directions.size()) {
            if(directions[loc] == 'R') {
                loc--;
                loc = max(0, loc);
                break;  
            }
            if(directions[loc] == 'S') {
                // need to cnt immediate L's
                while(loc < (int)directions.size() && directions[loc] == 'S') {
                    loc++;
                }
                // loc++;
                while(loc < (int)directions.size() && directions[loc] == 'L') {
                    cnt++;
                    loc++;
                } 
            } 
            if(loc < (int)directions.size() && directions[loc] == 'R') {
                loc--;
                loc = max(0, loc);
                break;
            }
            if(loc < (int)directions.size() && directions[loc] == 'L')
                loc++;
            // loc++;
        }
        int roc = (int)directions.size() - 1;
        while(roc >= loc && directions[roc] == 'R') {
            roc--;
        }
        if (roc >= loc && directions[roc] == 'L') {
            int tcnt = 0;
            int tloc = roc;
            while (tloc >= loc && directions[tloc] == 'L') {
                tloc--;
                tcnt++;
            }
            if (tloc >= loc && directions[tloc] == 'S') {
                cnt += tcnt;
                roc = tloc;
            }
        }
        // cout << s << endl;
        // cout << cnt << endl;
        // cout << loc << endl;
        for(int i = loc; i <= roc; ++i) {
            s.push_back(directions[i]);
        }
        // cout << s << endl;
        int mode = 0;
        int load = 0;
        for(auto &i : s) {
            if(i == 'R') {
                if(mode == 2) {
                    load++;
                } else
                    load = 1;
                mode = 2;
            } else if(i == 'L') {
                if(mode == 1) {
                    cnt ++;
                } else if(mode == 2) {
                    cnt += 2;
                    cnt += max(0, load - 1);
                    mode = 1;
                }
            } else {
                // S
                if(mode == 2) {
                    cnt += load;
                    mode = 1;
                }
            }
        }
        return cnt;
    }
};
/**
you detect a RS, or RL, a collision happens, and then all L are counted once, and if a R comes then the effect of conting L ends. 
**/