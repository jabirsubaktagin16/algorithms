#include<stdio.h>
#include<vector>

using namespace std ;

int main()
{
    vector<int>arr;
    int N,K;
    bool x=false;
    while(scanf("%d %d", &N, &K))
    {
        x = false;
        for(int i = 0; i< N ; i++)
        {
            int a ;
            scanf("%d",&a);
            arr.push_back(a);
        }
        for(int i = 0; i< N ; i++)
        {
            for(int j =0 ; j<N; j++)
            {
                if(i!=j)
                {
                    if(arr[i]+arr[j]==K)
                    {
                        x=true;
                        break;
                    }
                }
            }
        }
        if(x==true)
            printf("YES\n");
        else
            printf("NO\n");

        arr.clear();
    }
    return 0;
}



