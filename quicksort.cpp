#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <queue>
#include <memory>
#include <algorithm>
using namespace std;

int Partition(vector<int>&A, int left, int right)
{
    int split=left-1;
    int pivot=A[right];
    for(int i=left;i<=right-1;i++)
    {
        if(A[i]<=pivot)
        {
            split++;
            swap(A[split],A[i]);
        }
    }
    swap(A[split+1],A[right]);
    return (split+1);
}

void QuickSort(vector<int>& A, int left, int right)
{
    if(left<right)
    {
        int mid=Partition(A, left, right);
        QuickSort(A,left,mid-1);
        QuickSort(A, mid+1, right);
    }
    return;
}

int main()
{
    vector<int> A{3,4,2,2,3,1,100};
    QuickSort(A, 0, A.size()-1);
    for_each(A.begin(), A.end(), [](int x){cout<<x<<endl;});
    return 0;
}
