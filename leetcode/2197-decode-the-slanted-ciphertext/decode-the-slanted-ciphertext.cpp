class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int col = (int)encodedText.size() / rows;
        vector<vector<char>> mat(rows,vector<char>(col + (rows - 1), ' '));
        int loc = 0;
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < col; ++j) {
                if(loc < (int)encodedText.size()) {
                    mat[i][j] = encodedText[loc++];
                }
            }
        }
        string ans;
        for(int i = 0; i < col + (rows - 1); ++i) {
            int x = i;
            for(int j = 0; j < rows && x < (col + (rows - 1)); ++j) {
                ans.push_back(mat[j][x++]);
            }
        }
        while(!ans.empty() && ans.back() == ' ')
            ans.pop_back();
        return ans;
    }
};