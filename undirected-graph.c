#include<iostream>
using namespace std;
#define MaxNum 10
typedef char Vertex;
typedef int Edge;
struct Graph{
    Vertex vexs[MaxNum];
    Edge edges[MaxNum][MaxNum];
    int n,e;
};
void createGraph(Graph*G)
{
    int i,j,k,w;
    char ch;
    cout<<"请输入顶点的个数和边数"<<endl;
    cin>>G->n;
    cin>>G->e;
    cout<<"请输入顶点的信息"<<endl;
    for(i=0;i<G->n;i++){
        cin>>G->vexs[i];
    }
    cout<<G->n<<"          =="<<endl;
    for(i=0;i<G->n;i++)
        for(j=0;j<G->n;j++)
            G->edges[i][j]=0;
     cout<<"请输入每条边的顶点的序号"<<endl;
     for(k=0;k<G->e;k++)
     {
         cin>>i>>j;
         G->edges[i][j];
     }
}
int main()
{
Graph *graph;
createGraph(graph);
}
有向图一般可以用邻接矩阵存储；有向图一般用邻接表存储，但是也看具体边和点的关系，哪个存储方式跟省空间，更方便
