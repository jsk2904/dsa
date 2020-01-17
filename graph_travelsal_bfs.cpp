#include<iostream>
#include<vector>
#include<list>
#include<cstring>
using namespace std;
void create(int a , int b ,vector<int>gra[])
{
    gra[a].push_back(b);
    gra[b].push_back(a);
}
void print(vector<int> gra[] , int size)
{
  for(int i =0 ; i < size ; i++)
  {
      cout<<" "<<i<<" -> ";
      for(auto a : gra[i])
       cout<<a<<" ";
    cout<<endl;
  }
}
void bfs(vector <int> gra[] , int visited[], int size)    ///creating bfs traversal function
{
  vector <int> node;
  for(int i = 0 ; i< size ; i++)
  {
     if(visited[i] == 0 && gra[i].size()!=0) node.push_back(i);    //creating vector insertion for the first element insertion
      for(auto a : gra[i])                                         //traversing gra[i][a] 
      {
         if(a == 0) node.push_back(a);                             //checking that if gra[i][a] is already inserted in vector or not
      }
      visited[i] = 1;                                             //marking i as visited because in graph's bfs traversal we mark that node as visited which 
                                                                  //we have traversed fully
  }
  for(auto a : node)  //printing nodes
  {
    cout<<a<<" ";      
  }
}
int main()
{
  int size = 7 ; // it's the size of biggest node
  vector <int> gra[size];
  int visited[size];
  memset(visited , 0 , sizeof(visited));
  create(1,2,gra);
  create(1,3,gra);
  create(2,4,gra);
  create(2,5,gra);
  create(3,5,gra);
  create(4,6,gra);
  create(4,5,gra);
  create(5,6,gra); 
  print(gra,7)  ;
  bfs(gra,visited,size);
}
