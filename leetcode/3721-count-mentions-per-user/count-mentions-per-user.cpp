class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentionsCnt(numberOfUsers, 0);
        vector<int> onlineUntil(numberOfUsers, -1); 
        sort(events.begin(), events.end(), [](const vector<string> &a, const vector<string> &b) {
            int x = stoi(a[1]);
            int y = stoi(b[1]);
            if (x == y) {
                return a[0] > b[0];
            }
            return x < y;
        });

        for (const auto &i : events) {
            string type = i[0];
            int timestamp = stoi(i[1]);
            if (type == "OFFLINE") {
                int id = stoi(i[2]);
                onlineUntil[id] = timestamp + 60;
            } else if (type == "MESSAGE") {
                string mentions = i[2];
                if (mentions == "HERE") {
                    // for(auto &i : onlineUntil){
                    //     cout << i <<  " ";
                    // }
                    for (int i = 0; i < numberOfUsers; ++i) {
                            // cout << i << " " << timestamp << " " << onlineUntil[i] << endl;

                        if (timestamp >= onlineUntil[i]) {
                            mentionsCnt[i]++;
                        }
                    }
                }else
                if (mentions == "ALL") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        mentionsCnt[i]++;
                    }
                }else {
                    istringstream stream(mentions);
                    string str;
                    while (stream >> str) {
                        if (str.substr(0, 2) == "id") {
                            int userId = stoi(str.substr(2)); 
                            mentionsCnt[userId]++;
                        }
                    }
                }
            }
        }

        return mentionsCnt;
    }
};
