#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;
struct edge
{
int  node;
int weight;
edge(int node ,int weight):node(node),weight(weight)
{

}
} ;
struct Graph_list
{
vector<list<edge> > graph_list;
Graph_list(int n):graph_list(n){

}
void add_edge(int  sourse,int desc,int weight)
{
edge new_edge(desc,weight);
graph_list[sourse].push_back(new_edge);
}
void dump()
{
for(int i=0;i<graph_list.size();i++)
{
for(list<edge>::iterator pos=graph_list[i].begin();pos!=graph_list[i].end();pos++)
{
cout<<"node     "<<pos->node;
cout<<"weight   "<<pos->weight<<endl;
}
}

}
};
struct disjoint_set
{
disjoint_set *parent;
int rank;
disjoint_set()
{
parent=this;
rank=0;
}
disjoint_set*find_parent()
{
if(parent==this)
return this;
else
return find_parent();
}
void Uoion(disjoint_set*other)
{
disjoint_set * thisRoot=find_parent();
disjoint_set * thatRoot=other->find_parent();
if(thisRoot=thatRoot)
{
   return ;
}
else if(thisRoot->rank>thatRoot->rank)
{
thatRoot->parent=thisRoot;
}
else if(thisRoot->rank<thatRoot->rank)
{
this->parent=thatRoot;
}
else{
      thatRoot->parent = thisRoot;
      thisRoot->rank = thatRoot->rank + 1;
    }
}
};
struct Edge
{
int sourse ,desc,weight;
Edge(int sourse,int desc,int weight):sourse(sourse),desc(desc),weight(weight){

}
};
bool compare(Edge a,Edge b)
{
return a.weight<b.weight;
}
Graph_list kruskal(Graph_list &g)
{
vector<disjoint_set*> sub_sets(g.graph_list.size());
for(int i=0;i<g.graph_list.size();i++)
{
sub_sets[i]=new disjoint_set;
}
vector<Edge> vec;
for(int i=0;i<g.graph_list.size();i++)
{
for(list<edge>::iterator pos=g.graph_list[i].begin();pos!=g.graph_list[i].end();pos++)
{
Edge Edge(i,pos->node,pos->weight);
vec.push_back(Edge);
}
}
sort(vec.begin(),vec.end(),compare);
Graph_list result(g.graph_list.size()); 
for(int i=0;i<vec.size();i++)
{
Edge e=vec[i];
if(sub_sets[e.sourse]->find_parent()!=sub_sets[e.desc]->find_parent())
{
result.add_edge(e.sourse, e.desc,e.weight);
sub_sets[e.sourse]->Uoion(sub_sets[e.desc]);
}
}
return result;

}
int main()
{
Graph_list g(5);
g.add_edge(0, 4, 1);
    g.add_edge(0, 1, 3);
    g.add_edge(1, 4, 4);
    g.add_edge(1, 2, 5);
    g.add_edge(2, 4, 6);
    g.add_edge(2, 3, 2);
    g.add_edge(3, 4, 7);
    
    Graph_list min_span_tree = kruskal(g);
    min_span_tree.dump();
    return 0;

}
首先用一个结构体来存储一个表节点
用vector<list<edge> >graph_list来建立一个邻接表
再用一个结构体把表中的节点重新全部取出经行排序
然后并查集判断这个边是够联通，把已经联通的最小边集保存在result邻接表中

