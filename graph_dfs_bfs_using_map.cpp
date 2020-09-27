#include<bits/stdc++.h>
using namespace std;
class graph{
  int v;
  list<int>*ad ;
  public:
  graph(int v);
  void addedge(int u , int v , bool bidir);
  void print();
  void dfs();
  void bfs();
};

graph::graph(int v){
 this->v = v;
 ad = new list<int>[v];
}

void graph::addedge(int u , int v , bool bidir){
 ad[u].push_back(v);
 if(bidir) ad[v].push_back(u);
}



int main(){
    graph a(4);
    a.addedge(0,1,false);
    a.addedge(0,2,false);
    a.addedge(1,3,false);
    a.addedge(1,4,false);
    a.addedge(2,6,false);
    a.addedge(3,5,false);
    a.addedge(4,2,false);
    a.addedge(4,3,false);
    a.addedge(4,5,false);
    //a.print();
    //a.bfs();
    return 0;
}
