#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
#include<climits>
using namespace std;
struct edge_node{
  int dest_id;
  int weight;
  
  edge_node(int dest_id, int weight)
    :dest_id(dest_id), weight(weight) {}

};

struct graph_ad_list{
   vector<list<edge_node> > ad_list;

  //n is the number of nodes
  graph_ad_list(int n):ad_list(n) {} 

  void add_edge(int source, int dest, int weight){
    edge_node new_edge(dest, weight);
    ad_list[source].push_back(new_edge); 
  }

  void dump(){
    //for each node
    for(int i = 0; i < ad_list.size(); i ++){
      //for each edge
      for(list<edge_node>::iterator     pos = ad_list[i].begin(); pos!=ad_list[i].end(); pos++){
        cout << "edge from " << i << " to " << pos->dest_id;
           cout << " weight: " << pos->weight << endl;
      }
    }
  }
}; 

struct node{
    int id;
    int dist;
    int prev;
    bool processed;
    node():dist(INT_MAX),prev(-1),processed(false){}
};
struct compare_node{
    bool operator()(node&a,node&b)
    {
        return a.dist>b.dist;
    }
};
vector<node> dijkstra(graph_ad_list &g,int source)
{
    /*传入一个链接表，把表中的每一个节点取出，存放在vector集合中*/ 
    int node_count = g.ad_list.size();
    vector<node> nodes(node_count);
    for(int i=0;i<node_count;i++)
    {
        nodes[i].id=i;
    }
    nodes[source].dist=0;
    /*采用优先级队列，把队列从出发点，到当前位置距离最短的点，放在对头*/ 
    priority_queue<node,vector<node>,compare_node> node_pq;
    node_pq.push(nodes[source]);
    while(!node_pq.empty())
    {
        node current_node = node_pq.top();
        node_pq.pop();
        if(current_node.processed)
        continue;
        list<edge_node> edge_nodes = g.ad_list[current_node.id];
        /*遍历链接表中每一列*/ 
        for(list<edge_node>::iterator edge_pos=edge_nodes.begin();edge_pos!=edge_nodes.end();edge_pos++){
            /*取出当前结点的下一个结点*/ 
            node& dest_node = nodes[edge_pos->dest_id];
            /*判断该节点加上该节点到下一个点的距离，是否大于下一个节点的，最小距离*/ 
            if(current_node.dist+edge_pos->weight<dest_node.dist)
            {
                dest_node.dist = current_node.dist+edge_pos->weight;
                dest_node.prev = current_node.id;
                node_pq.push(dest_node);
            }
        }
        current_node.processed= true;
    }
    return nodes;
}
void print_path(vector<node>&nodes,int node_id)
{
    if(nodes[node_id].prev==-1)
    {
        cout<<"path:"<<node_id;
    }else
    {
        print_path(nodes,nodes[node_id].prev);
        cout<<"->"<<node_id;
    }
}
int main()
{
    graph_ad_list g(9);
    g.add_edge(0,1,2);
    g.add_edge(0,3,9);
    g.add_edge(0,4,6);
    g.add_edge(1,2,1);
    g.add_edge(1,4,3);
    g.add_edge(2,6,6);
    g.add_edge(3,7,4);
    g.add_edge(4,3,2);
    g.add_edge(4,5,9);
    g.add_edge(5,6,5);
    g.add_edge(5,8,1);
    g.add_edge(6,8,5);
    vector<node> result = dijkstra(g,0);
    for(int i=0;i<result.size();i++)
    {
        cout<<"print path and dist for node"<< result[i].id<<endl;
        print_path(result,result[i].id);
        cout<<endl<<"Dist"<<result[i].dist<<endl;
    }
    return 0;    
}
