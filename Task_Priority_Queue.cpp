#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

struct student{
    string name;
    float cgpa;

    student(string _name,float _cgpa){
        name=_name;
        cgpa=_cgpa;
    }

    bool operator <(student a) const{
        if(cgpa==a.cgpa){
        return a.name<name;
        }
        else{
            return cgpa<a.cgpa;
        }
    }
};
int main(){
    priority_queue<student> pq;

    pq.push(student("Arif",3.5));
    pq.push(student("Aniqua",3.65));
    pq.push(student("Arafath",3.55));
    pq.push(student("Robiul",3.55));

    while(!pq.empty()){
        student curr=pq.top();
        pq.pop();

        cout <<curr.name<<" "<<curr.cgpa<<endl;
    }
}
