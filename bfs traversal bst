#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node * left;
    node * right;
};
queue <struct node*> current;
vector<int> values;
node * insert(node *root,int data)
{
  if(root == NULL)
  {
    root = (struct node*)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right= NULL;
    return root;
  }
  else
  {
      if(data > root->data)
      {
          root->right = insert(root->right,data);
      }
      else
      {
          root->left = insert(root->left,data);
      }
      
  }
  
}
void preorder(node * root) /*printing tree*/
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void dfs (node *root , vector<int>& values)
{
while(current.front()!= NULL)
{
  cout<<endl<<"inside dfs"<<endl;
  values.push_back(current.front()->data);
  //cout<<endl<<values[0]<<endl;
  //dfs(current.front(),values);
    if(current.front()->left!=NULL && current.front()->right!=NULL)
    {
       // cout<<"iside if return"<<endl;
        current.push(current.front()->left);
        current.push(current.front()->right);
       // continue;
       //return;
    }
    else if(current.front()->right!=NULL && current.front()->left==NULL)
    {
       current.push(current.front()->right);
       //continue;
    }
    else if(current.front()->right==NULL && current.front()->left!=NULL)
    {
       current.push(current.front()->left);
      // continue;
    }
cout<<"before pop "<<current.front()->data<<endl;
if(current.size()==1) return;
  current.pop();
cout<<"after pop "<<current.front()->data<<endl;
cout<<"size of queue "<<current.size()<<endl;
}    
  // queue <struct node*>::iterator it = current.front() 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    node *root = NULL;
    root = insert(root,5);
    insert(root,6);
    insert(root,3);
    insert(root,1);
    insert(root,4);
    insert(root,9);
    preorder(root);
    current.push(root);
    //cout<<"inside main"<<current.front()->data<<endl;
    dfs(root,values);
  //  cout<<values[0]<<endl;
    cout<<endl;
for(auto i= values.begin();i != values.end();i++)
{
    cout<<*i<<" ";
}
}
