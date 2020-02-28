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

void insertion_sort(vector<int>&A)
{
    int len=A.size();
    for(int i=1;i<len;i++)
    {
        int key=A[i];
        int j=i-1;
        while(j>=0&&A[j]>key)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

int main()
{
    vector<int> A{1,4,5,2,34,1,50,100,3};
    insertion_sort(A);
    for_each(A.begin(), A.end(), [](int x){cout<<x<<endl;});
}