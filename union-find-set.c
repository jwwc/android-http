求一个集群里面有多少个联通网络，只要有一个公共点，就说明这两个网络是联通的，也就是可以合成一个网络
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1010;
int father [N];
int isRoot[N]={0};
int course[N]={0};
int findFather(int x)
{
while(x!=father[x])
{
x=father[x];
}
return x;
}
void Union(int a,int b)
{
int faA = findFather(a);
int faB = findFather(b);
if(faA!=faB)
{
father[faA]=faB;
}
}
void init(int n)
{
for(int i=1;i<=n;i++)
{
father[i]=i;
isRoot[i]=false;
}
}
bool cmp(int a,int b)
{
return a>b;
}
int main()
{
int n,k,h;
printf("请输入人数\n"); 
scanf("%d",&n);
init(n);
for(int i=1;i<=n;i++)
{
printf("请输入活动数\n"); 
scanf("%d:",&k);
for(int j=0;j<k;j++)
{
printf("请输入活动号\n");
scanf("%d:",&h);
if(course[h] ==0 )
{
course[h]=i;
}
Union(i,findFather(course[h]));
}

}
for(int i=1;i<=n;i++)
{
isRoot[findFather(i)]++;
}
int ans=0;
for(int i=1;i<=n;i++)
{
if(isRoot[i]!=0)
{
ans++;
}
}
printf("网络数为%d:\n",ans);
sort(isRoot+1,isRoot+n+1,cmp);
for(int i=1;i<=ans;i++)
{
printf("%d----",isRoot[i]);
if(i<ans)
printf(" ");
}
return 0;
}
