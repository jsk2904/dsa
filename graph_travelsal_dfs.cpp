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
void dfs(vector <int> gra[] , int visited[], int size)    ///creating dfs traversal function
{
  if(visited[size] == 0) visited[size] = 1;            //marking each node as visited in dfs visited is each node that we have visited or not have explored it
                                                       //fully yet
                                                       
                                                       // in dfs we mark visited to that which we have fully explored
  cout<<size<<" ";
  for(auto i = gra[size].begin() ; i != gra[size].end() ; i++) 
  {
    if(visited[*i] == 0)                              //this if is for the node that we are going to visit i.e. next gra[size][i] and pass it to recursive
                                                      //function dfs.
    {
        dfs(gra , visited , *i);
    }
  }
}
int main()
{
  int size = 7 ; // it's the size of biggest node
  vector <int> gra[size];
  int visited[size];
  memset(visited , 0 , sizeof(visited));
  create(2,0,gra);
  create(0,2,gra);
  create(2,3,gra);
  create(1,2,gra);
  create(0,1,gra);
  //create(4,6,gra);
  //create(4,5,gra);
  //create(5,6,gra); 
  print(gra,4)  ;
  dfs(gra,visited,2);
}
