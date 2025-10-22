class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            maxReach[left] = max(maxReach[left], right);
        }
        int tapsUsed = 0;
        int currEnd = 0;    
        int farthest = 0;   
        for (int i = 0; i <= n; ++i) {
            // cout << i << " " << farthest << endl;
            if (i > farthest) 
                return -1;  
            farthest = max(farthest, maxReach[i]);
            if (i == currEnd && i != n) {       
                // already covered that point n in current_END so since there is no new segment after this pooint we dont need to open any other new tap   
                tapsUsed++;
                currEnd = farthest;
            }
        }
        return tapsUsed;
    }
};


/**
NOTES
# Preparation 
- Sort the ranges by the first coordinate 
# Reccursion 

- Take not take over the ranges
- just validate at the end 
- return the number of choose
- take the minimum 

#Apply Memoization 

- Take the states as [last_choosen_range]

#Convert to greedy 

- you iterate normally 
- you keep the track of the furthets point at each instant
- incase you go to the next position you have to check if position <= furthest_i_could_reach_before
- incase you see that u see that the ending point of ur previously choosen sequence has been passes through and you need to choose another segment u have to update the ending point of the new segment as the furthest point that u can currenlty cover
- this is why it is important to iterate through the entire points and not just the seg.left

**/