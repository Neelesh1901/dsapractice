#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next =NULL;
    }

};
void insertattail(node* &head, int val){
    
    node* n =new node(val);
    
    if(head == NULL)
    {
        head = n;
        return;
    }
    node*temp =head;
    while(temp->next!=NULL){

    temp=temp ->next;
    }
    temp->next=n;
    
}

void display(node* head)
{
   node* temp =head;
   while(temp!=NULL){
       cout<<temp->data<<"->";
       temp=temp->next;
   }
   cout<<"NULL"<<endl;
}
node* reversek(node* &head, int k){
    node* pre=NULL;
    node* cur=head;
    node* nextptr;
    int count=0;
    while (cur!=NULL && count<k)
    {
        nextptr=cur->next;
        cur->next=pre;
        pre=cur;
        cur=nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next = reversek(nextptr,k);
    }
    return pre;
}
int main()
{   node* head=NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    insertattail(head,6);
    display(head);
    int k=2;
    node* newhead=reversek(head,k);
    display(newhead);
    return 0;
}