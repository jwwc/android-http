/*非递归实现*/
/*非递归实习是采用了动态规划的实现，时间复杂度为O(nk)*/
#include<iostream>
#include<vector>
using namespace std;
int lcs_dp(char a[],int a_length,char b[],int b_length)
{
    vector<vector<int> >value_table;
    value_table.resize(a_length+1,vector<int>(b_length,0));
    for(int i=0;i<=a_length;i++)
    {
        for(int j=0;j<=b_length;j++)
        {
            if(i==0||j==0)
            value_table[i][j]=0;
            else if(a[i-1]==b[j-1])
            value_table[i][j]=value_table[i-1][j-1]+1;
            else
            value_table[i][j]=max(value_table[i-1][j],value_table[i][j-1]);
        }
    }
    return value_table[a_length][b_length];
}
int main()
{
    char a[]="ABCDGH";
    char b[]="AEDFHR";
    cout<<lcs_dp(a,6,b,6)<<endl;
    return 0;
}

/*递归实现*/
#include<iostream>
using namespace std;
int lcs(char a[],int a_length,char b[],int b_length)
{
    if(a_length==0||b_length==0)
    {
        return 0;
    }
    else if(a[a_length-1]==b[b_length-1])
    {
        return 1+lcs(a,a_length-1,b,b_length-1); 
    }
    else {
        int a_next=lcs(a,a_length-1,b,b_length);
        int b_next=lcs(a,a_length,b,b_length-1);
        return max(a_next,b_next);
    }
}
int main()
{
    char a[]="ABCDGH";
    char b[]="AEDFHR";
    cout<<lcs(a,6,b,6)<<endl;
    return 0;
}

