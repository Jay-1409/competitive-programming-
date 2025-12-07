class Solution {
public:
    double getProbability(vector<int>& balls) {
        int k = balls.size();
        int totalBalls = 0;
        for (int b : balls) totalBalls += b;

        int half = totalBalls / 2;

        vector<vector<double>> C(51, vector<double>(51, 0));
        for (int i = 0; i <= 50; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++)
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }

        double totalWays = C[totalBalls][half];

        double ans = 0;
        vector<int> pick(k, 0);

        function<void(int,int)> dfs = [&](int idx, int used) {
            if (idx == k) {
                if (used != half) return;

                int distinctA = 0, distinctB = 0;
                double ways = 1;

                for (int i = 0; i < k; i++) {
                    int a = pick[i];
                    int b = balls[i] - a;

                    if (a > 0) distinctA++;
                    if (b > 0) distinctB++;

                    ways *= C[balls[i]][a];
                }

                if (distinctA == distinctB) {
                    ans += ways / totalWays;  
                }

                return;
            }

            for (int take = 0; take <= balls[idx]; take++) {
                if (used + take > half) break;
                pick[idx] = take;
                dfs(idx + 1, used + take);
            }
        };

        dfs(0, 0);

        return ans;
    }
};


/**
PROMPT GIVEN 

- ways to select the 2n balls from n balls would be 2nCn
- ways to distribute the balls from n balls into two baskets should be the same of selecting n balls from 2n balls correct? 
- need to find the probabilyt that the two boxes have the same number of distinct balls 
- now we have some balls with different labels on them.. we can choose ways in which we will make one of the partiton i.e what balls we will put in one of the baskets such that the number of distint betwen both basket remais the same wen you dump the rest of the balls into the other basket 
- for exampple you have 2n balls, 1 2 3 4 , n = 4
- you can make the pairs such like 
- 1 2 | 3 4, 1 3 | 2 4 and many more.. 

- lets use backtracking to get all such combinations that we can form 
- now for each such combination that we have, we will simply have to find  ways to make that combination. 

- now out of a pool or say x a's and y b's how do you get 2 a's and 3 b's?
    - esy as it looks xC2 * yC3 
- now we can get the probabilty of getting that particular conbination as
    - (ways to get that comb) / (total number of ways)
- we just take the sum of all sch probabilityes to get our final probability. 

**/