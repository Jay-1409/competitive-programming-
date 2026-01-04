class Solution {
public:
    string largestEven(string s) {
        string news="";
        string temp, x;
        for(auto &i : s) {
            temp.push_back(i);
            if(i == '0' || i == '2' || i == '4' || i == '6' || i == '8') {
                news += temp;
                temp = x;
            }
        }
        return news;
    }
};