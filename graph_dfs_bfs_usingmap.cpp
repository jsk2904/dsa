#include<bits/stdc++.h>
using namespace std;

int maximum = INT_MIN;
int minimum = INT_MAX;

class graph{
unordered_map<int , list<int> > gra;
queue<int>nodes;
vector<bool>visited;
public:
 void addedge(int a , int b , bool bidi);
 void print();
 void bfs(int target);
 void visit(int size);
 void dfs(int target);
 void refresh(int size);
};
//***************************************************************************************************************
void graph::refresh(int size){
 for(int i = minimum ; i <= maximum ; i++){
  visited[i]=false;
 }
}
//***************************************************************************************************************
void graph::visit(int size){
 for(int i = 0 ; i<size ; i++){
  visited.push_back(false);
 }
return;
}
//***************************************************************************************************************
void graph::addedge(int a,int b,bool bidi){
 gra[a].push_back(b);
 if(bidi) gra[b].push_back(a);
maximum = max(maximum,max(a,b));
minimum = min(minimum,min(a,b));
return;
}
//***************************************************************************************************************
void graph::print(){
	for(auto ele : gra){
          cout<<ele.first<<" -> ";
           for(auto a : ele.second){
             cout<<a<<" ";
            }
          cout<<endl;
	}
return;
}
//*****************************************************************************************************************(BFS)
void graph::bfs(int target){
  if(gra.find(target)!=gra.end() && visited[target]==false){ 
//condition 1 : we are iterating graph and if key does not exist in our map (gra) then we don't iterate over it rather
//              we print that element in else part by marking it visited

//condition 2 : this is to check whether the element is already visited or already printed so we doesn't print it again
//              eg: if we remove 2nd statement then we are going to print already visited and printed nodes again
//              remove that to see demo
   nodes.push(target);
   while(!nodes.empty()){
    cout<<nodes.front()<<" ";//printing nodes present at the begning of queue
  
    auto ptr = gra.find(nodes.front());
    visited[nodes.front()]=true;
    if(ptr!=gra.end()){
	    for(auto ele : ptr->second) // pushing all nodes that can reached from current node into queue
	     if(!visited[ele]){         //if it is not visited means we haven't it in list so we need to visit it
                     nodes.push(ele);
                     visited[ele]=true; //if it comes into queue mark visited so we can't print it once more
             }
         }
    nodes.pop();//pop starting of queue we have visited and printed it
   }
  }
  else{
   if(!visited[target])cout<<target<<" ";
   visited[target]=true;        // if the elment such that it have out degree of 0 then we need else part to print it
                                // because there is no nodes that can be visited from it so we can't traverse any element
                                // after printing it mark it visited because we don't need to print it once again
  }
return;
}

//*******************************************************************************************************************(DFS)

void graph::dfs(int target){
 auto ptr = gra.find(target);
 if(ptr!=gra.end() && visited[target]==false){
  cout<<ptr->first<<" ";
  visited[ptr->first] = true;
  for(auto ele : ptr->second){
   dfs(ele);
  }
 }
 else{
  if(!visited[target])cout<<target<<" ";
  visited[target]=true;
 }
return;
}

//********************************************************************************************************************
int main(){
 graph a;
    a.addedge(0,1,false);
    a.addedge(0,2,false);
    a.addedge(1,3,false);
    a.addedge(1,4,false);
    a.addedge(3,5,false);
    a.addedge(4,2,false);
    a.addedge(4,3,false);
    a.addedge(4,5,false);
    a.print();
    a.visit(maximum-minimum+1);
    //cout<<"size is "<<maximum-minimum+1<<endl;
    int size = maximum-minimum;
    for(int i = minimum ; i <=maximum ; i++){
     a.bfs(i);
    }
   cout<<endl;
   a.refresh(size);
   for(int i = minimum ; i <= maximum ; i++){
    a.dfs(i);
   }
}
