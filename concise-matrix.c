#include<iostream>
#include<vector>
using namespace std;
void reduction(int row[],int col[],int length,int vals[],int init_length)
{
    vector<vector<int> >vec;
    vec.resize(init_length,vector<int>(init_length,0));
    for(int i=0;i<length;i++)
    {
        vec[row[i]][col[i]]=vals[i];
    }
    for(int i=0;i<init_length;i++)
    {
        for(int j=0;j<init_length;j++)
        {
        cout<<vec[i][j];
        if(j==init_length-1)
        cout<<endl;
        }
    }
} 
int main()
{
    int row[]={2,3,5,6,7,4,7,8};
    int col[]={1,3,5,2,8,7,5,6};
    int vals[]={2,3,4,5,2,5,6,7};
    reduction(row,col,8,vals,9);
    
}

