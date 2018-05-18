#include<stdio.h>
#include<string>
#include<map>

using namespace std;

int main(){
    map<string,int> arr;

    arr["Arif"]=7;
    arr["Aniqua"]=8;
    arr["Arafath"]=8;

    printf("%d\n",arr["Arif"]);

}
