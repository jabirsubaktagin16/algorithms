#include<bits/stdc++.h>

using namespace std;

int heapSize,n;

void printArray(int arr[])
{
    for(int i=1; i<=n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void MaxHeapify(int A[],int i)
{
    int largest=i;
    int l=2*i;
    int r=2*i+1;

    if(l<=heapSize && A[l]>A[largest])
        largest=l;
    if(r<=heapSize && A[r]>A[largest])
        largest=r;

    if(largest!=i)
    {
        swap(A[i],A[largest]);
        MaxHeapify(A,largest);
    }
}

void BuildMaxHeap(int A[])
{
    for(int i=(n+1)/2;i>0;i--)
        MaxHeapify(A,i);
}

void HeapSort(int A[])
{
    BuildMaxHeap(A);
    for(int i=1;i<=n;i++)
    {
        swap(A[1],A[heapSize]);
        heapSize=heapSize-1;
        MaxHeapify(A,1);
    }
}

int main()
{
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<endl;
    int arr[n+1];
    heapSize=n;
    cout<<"Enter elements : ";
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    HeapSort(arr);
    int i;
    cout<<"Sorted Elements : ";
    for(i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
