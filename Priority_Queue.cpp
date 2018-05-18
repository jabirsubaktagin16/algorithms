#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

int main(){

    priority_queue<int> pq;

    pq.push(10);
    pq.push(100);
    pq.push(-10);
    pq.push(27);
    pq.push(25);
    pq.push(35);

    while(!pq.empty()){
        int curr=pq.top();
        pq.pop();

        cout <<curr<<endl;
    }
}
