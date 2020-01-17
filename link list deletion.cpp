#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node * nxt;
};
node *head = NULL;
node *ptr = NULL;
node *cur = NULL;
node *preptr = NULL;
void create(int d)
{
    //cout<<"here"<<endl;
  if(head == NULL)
  {
    ptr = new node();
    ptr->data = d;
    ptr->nxt = NULL;
    head = ptr;
    cur = head;
  }
  else
  {
     ptr = new node();
     ptr->data = d;
     ptr->nxt = NULL; 
   //  cout<<"here"<<endl;
     cur->nxt = ptr;
     cur = ptr;
  }
  
}
void prin()
{
    ptr = head;
    while(ptr != NULL)
    {
      cout<<ptr->data<<" ";
      ptr = ptr -> nxt;
    }
}
void inser(int ins , int aft)
{
    cur = head;
    while(cur->data!=aft)
    {
      cur = cur->nxt;
    }
   // cout<<endl<<cur->data<<endl;
    preptr = cur->nxt;
    ptr = new node();
    cur->nxt = ptr;
    ptr->nxt=preptr;
    ptr->data = ins;
}
int main()
{
    create(5);
    create(6);
    create(7);
    create(8); 
prin();
cout<<endl;
inser(2,6);
prin();
}
