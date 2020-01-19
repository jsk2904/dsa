#include<iostream>
#include<list>
#include<cstring>
#include<vector>
using namespace std;
void insert(list <int> gra[] , int a , int b)
{
  gra[a].push_back(b);
}


void topological(list <int> gra[] , list <int> & traversal , int visited[], int v ,int start)
{
      for(int in : gra[start])
      {
          if(visited[in] == 0) 
          {
              topological(gra , traversal , visited , v ,in);
          }
      } 
      if(visited[start] == 0){visited[start] = 1;}             // this is a visited node which have been marked visited after traversing it whole
      traversal.push_front(start);                             // because it won't be completly visited till you traverse it
}                                                              //and once you traverse it you are done you have to just push it in stack

void print(list <int> gra[] , int v)
{
  for(int i = 0 ; i<v ; i++)
  {
    cout<<i<<"-> ";
    for(auto a : gra[i])
    {
      cout<< a <<" ";
    }
    cout<<endl;
  }
}
int main()
{
    int v = 6;
    list <int> gra[v];
    int visit[v];
    memset(visit , 0 , sizeof(visit));
    list <int> traversal;
    insert(gra , 5, 2); 
    insert(gra ,5, 0); 
    insert(gra ,4, 0); 
    insert(gra ,4, 1); 
    insert(gra ,2, 3); 
    insert(gra ,3, 1); 
    print(gra , v);
    topological(gra , traversal , visit , v , 1);
    for(int i = 0 ; i<v ; i++){if(visit[i] == 0) topological(gra , traversal , visit , v ,i);}  // this is in case of if you have an unvisited node and you don't have it in your stack
    for(auto i : traversal) cout<<i<<" ";                                                       //this will traverse visited array and call unvisited node in topological function
    cout<<endl;                                                                                 
//e.g -
//0-> 
//1-> 
//2-> 3 
//3-> 1 
//4-> 0 1 
//5-> 2 0
//in this if we call topological (gra , traversal , visit , v , 5) we will miss the 4 and will never get 4 in our stack so the above for loop will call topological function for 4 also.
}
