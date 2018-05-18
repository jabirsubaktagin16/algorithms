#include<stdio.h>
#include<vector>

using namespace std;

int main(){
    vector<int> arr;

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;++i){
        int a;
        scanf("%d ", &a);
        arr.push_back(a);
    }

    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }
}
