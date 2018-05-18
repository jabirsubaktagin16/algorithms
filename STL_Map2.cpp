#include<stdio.h>
#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
    map<string,int> arr;

    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        string name;
        int mark;

        cin>>name>>mark;
        arr[name]=mark;
    }
    string str;
    cin>>str;

    if(arr[str]){
        cout<<arr[str]<<endl;
    }
    else{
        cout<<"No student found"<<endl;
    }
}

