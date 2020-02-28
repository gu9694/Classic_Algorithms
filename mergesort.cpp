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

void merge(vector<int>&A, int left, int right, int mid)
{
    vector<int> res(right-left+1);
    int pl=left;
    int pr=mid+1;
    int i=0;
    while (pl<=mid&&pr<=right) {
        if(A[pl]<=A[pr])
        {
            res[i]=A[pl];
            i++;
            pl++;
        }
        if(A[pr]<A[pl])
        {
            res[i]=A[pr];
            i++;
            pr++;
        }
        while (pl<=mid) {
            res[i++]=A[pl++];
        }
        while(pr<=right){
            res[i++]=A[pr++];
        }
        for(int j=0;j<right-left+1;j++)
        {
            A[j+left]=res[j];
        }
    }
}
void merge_sort(vector<int>&A, int left, int right)
{
    if (left==right)
        return ;
    int mid=(left+right)/2;
    merge_sort(A, left, mid);
    merge_sort(A, mid+1, right);
    merge(A,left,right,mid);
}

int main()
{
    vector<int> A{8,1,3,4,2,5,100};
    int len=A.size();
    merge_sort(A, 0, len-1);
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<endl;
    return 0;
}