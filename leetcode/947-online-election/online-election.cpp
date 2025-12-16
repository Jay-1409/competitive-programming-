class TopVotedCandidate {
public:
    static constexpr int M = 5000;
    vector<vector<int>> candidates{M};
    map<int,int> mp;
    vector<int> time;
    vector<int> candidate;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        int overallHighestVotedCandidate = -1;
        int overallMaxe = INT_MIN;
        for(int i = 0; i < n; ++i) {
            if(mp.find(persons[i]) == mp.end()){
                mp[persons[i]] = 0;
            }
            mp[persons[i]]++;
            if(mp[persons[i]] >= overallMaxe) {
                overallHighestVotedCandidate = persons[i];
                overallMaxe = mp[persons[i]];
            }
            time.push_back(times[i]);
            candidate.push_back(overallHighestVotedCandidate);
            }
    }    
    int q(int t) {
        auto it = upper_bound(time.begin(), time.end(), t);
        int idx = it - time.begin() - 1;
        return candidate[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */