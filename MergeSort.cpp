#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void Merge(int A[],int S,int m,int E)
{
    int n1=m-S+1;
    int n2=E-m;
    int L[n1];
    int R[n2];

    for(int i=1;i<=n1;i++)
    {
        L[i]=A[S+i-1];
    }
    for(int j=1;j<=n2;j++)
    {
        R[j]=A[m+j];
    }

    L[n1+1]=INT_MAX;
    R[n2+1]=INT_MAX;

    int i=1;
    int j=1;

    for(int k=S;k<=E;k++)
    {
        if(L[i]<R[j])
        {
            A[k]=L[i];
            i=i+1;
        }
        else
        {
            A[k]=R[j];
            j=j+1;
        }
    }

}

void MergeSort(int A[],int S,int E)
{
    if(S<E)
    {
        int mid=(S+E)/2;
        MergeSort(A,S,mid);
        MergeSort(A,mid+1,E);
        Merge(A,S,mid,E);
    }
}

int main()
{
    int n;
    cin>>n;
    int A[n-1];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    MergeSort(A,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}
