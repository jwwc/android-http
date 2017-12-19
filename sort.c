#include<iostream>
#include <algorithm>
using namespace std;
void quick_sort(int a[],int begin,int end)
{
    if(begin>=end)
    return ;
    int left=begin,right=end;
    int mid_value=a[left];
    while(left<right)
    {
        if(a[left+1]<mid_value){
        a[left]=a[left+1];
        left++;
    }
    else{
        swap(a[left+1],a[right]);
        right--;
    }
    }
    a[left]=mid_value;
    quick_sort(a,begin,left-1);
    quick_sort(a,left+1,end);
    
}
int main()
{
    int array[]={2,4,5,2,7,4,8,1,4};
    quick_sort(array,0,8);
    for(int i=0;i<9;i++)
    {
        cout<<array[i];
    }
    
}

