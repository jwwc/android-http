#include<iostream>
using namespace std;
unsigned long long fib_dp(int n)
{
    if(n<2)
    return n;
    unsigned long long*value_table=new unsigned long long[n+1];
    value_table[0]=0;
    value_table[1]=1;
    for(int i=2;i<=n;i++)
    {
        value_table[i]=value_table[i-1]+value_table[i-2];
    }
    return value_table[n];
}
int main()
{
        cout<<fib_dp(3)<<endl;

}
