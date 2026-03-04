#include<iostream>
#include<set>
using namespace std;
bool checkLetter(string s,char x){
    for(int i=0;i<sizeof(s);i++){
        if(s[i]==x){
            return true;
        }
    }
}
int countLetter(string s,char x){
    int count;
    for(int i=0;i<sizeof(s);i++){
        if(s[i]==x){       
        count++;
        }
    }
    return count;
}
int main(){
    int t;
    cin >> t;
    for(int test=0;test<t;test++){
char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int time;
    cin >> time;
    string questions;
    getline(cin,questions);
    int count[26];
    int occupancy=0;
    for(int i=0;i<26;i++){
        if(checkLetter(questions,letters[i])){
            occupancy++;
            count[i]=countLetter(questions,letters[i]);
        }
    }
;
}
}