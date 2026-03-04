#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool myCompare(pair<int , int >p1 , pair<int,int>p2){
    return p1.first<p2.first;
}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    //method 1
    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
    } 

    //method 2
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout << *it << endl;
    }

    //method 3
    for(auto element:v){
        cout << element << endl;
    }

    v.pop_back();//removes the end element\

    vector<int> v2 (3,50);//the size will be 50 and all 3 elements will be 50

    swap(v,v2); // swapping 2 vectors


    pair<int,char> p;
    p.first = 3;
    p.second='f';
    
    //creating a pair vector 
    int arr[]={10,16,7,14,3,2,9};
    vector<pair <int,int> > v3;
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
        v3.push_back(make_pair(arr[i],i));
    }
    sort(v.begin(),v.end(),myCompare);
    for(int i=0;i<v.size();i++){
        
    }
    return 0;
}