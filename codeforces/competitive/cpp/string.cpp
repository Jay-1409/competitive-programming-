#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main(){
    // string str;
    // getline(cin,str);
    // cout <<  str;
    // return 0;
    // string s1="Jay";
    // string s2="Shah";
    // s1=s1.append(s2);
    // cout << s1 << endl;
    // s1=s1+s2;
    // cout << s1 << endl;
    // return 0;
    // string s3="JHFHFK J,H EKRJHE RKJHR HWERHR ";
    // s3.clear();//clears all the content of the string
    // cout << s3;
    // s1.clear();
    // if(s3.empty()){//checks if the string is empty or not !!
    //     cout << "The string is empty";
    // }
    // string s1="Amazing";
    // s1.erase(1,3);
    // cout << s1 << endl;//prints Aing removing the middle letters
    // cout << s1.find("ng") << endl;//returns the index of n in the string

    // string s2="Lol";
    // s1.insert(2,s2);
    // cout << s1 << endl;
    // cout << s1.length() << endl;
    // string s3="1342342";
    // int x=stoi(s3);//string to integer!!
    // cout << x << endl;
    // cout << to_string(x) << endl;// from integer to string

    // string s1="ajrdfkjheekhekjhw";
    // sort(s1.begin(),s1.end());
    // cout << s1;

    //UPPER CASE LOWER CASE CONVERSION 
    // string str;
    // cin >> str;
    // //cout << 'a'-'A';//gives the ascii difference between both's ascii
    // for(int i=0;i<str.size();i++){
    //     if(str[i]>='a'&&str[i]<='z'){
    //         str[i]=str[i]-32;
    //     }
    // }
    // cout << str << endl;
    // // now again converting back to lowe case
    // for(int i=0;i<str.size();i++){
    //     if(str[i]>='A'&&str[i]<='Z'){
    //         str[i]=str[i]+32;
    //     }
    // }
    // cout << str << endl;
    // doing the same with inbuilt function 
    // string s="eriqisijOIAI";
    // transform(s.begin(),s.end(),s.begin(),::toupper);
    // cout << s << endl;
    // transform(s.begin(),s.end(),s.begin(),::towlower);
    // cout << s << endl;

    //TO FORM THE BIGGEST NUMBER FORM A NUMERIC STRING 
    // string s;
    // cin >> s;
    // sort(s.begin(),s.end(),greater<int>());
    // cout << s << endl;

    //COUNTING THE MAXIMUM OCCURANCES
    string s;
    getline(cin,s);
    int arr[s.size()];
    for(int i=0;i<s.size();i++){
        arr[i]=s[i];
    }
    int check=arr[0];
    int count=0;
    int max=0;
    for(int j=0;j<s.size();j++){
    for(int i=0;i<s.size();i++){
        if(check==arr[i]){
            count++;
        }
    }
    max=count;
    count=0;
    }
    cout << max << endl;

}

