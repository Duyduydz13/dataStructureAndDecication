#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct linkedList{
    Node* head;
    Node* tail;
};

Node* createNode(int data){
    Node* node=new Node;
    node->data=data;
    node->next=NULL;
    return node;
}

void createList(linkedList &l){
    l.head=NULL;
    l.tail=NULL;
}
void printList(linkedList &l){
    if (l.head!=NULL){
        Node* node;
        node=l.head;
        while (node!=NULL)
        {
            cout<<node->data<<" ";
           node=node->next;
        }
        
    }
}

void addTail(linkedList &l,Node* node){
    if (l.head==NULL){
        l.head=node;
        l.tail=node;
    }
    else {
        l.tail->next=node;
        l.tail=node;
    }
}

Node* getMid(linkedList &l){
    Node* p1=l.head;
    Node* p2=l.head;
    while ( p2->next->next){
        p1=p1->next;
        p2=p2->next->next;
    }
    return p1;
}
void removeHead(linkedList &l){
    if (l.head!=NULL){
        Node *node=l.head;
        l.head=node->next;
        delete node;
        if (l.head==NULL){
            l.tail==NULL;
        } 
    }
}
 
linkedList Merge(linkedList &l1,linkedList &l2){
    linkedList l;
    createList(l);

while(l1.head && l2.head){
   if ( (l1.head->data) <= (l2.head->data) ){
    int data=l1.head->data;
    Node* node;
    node=createNode(data);
    addTail(l,node);
    removeHead(l1);
   }
    else {
    int data=l2.head->data;
    Node* node;
    node=createNode(data);
    addTail(l,node);
    removeHead(l2);
   }
    }
if(!l1.head){
    while(l2.head)	{
    int data=l2.head->data;
    Node* node;
    node=createNode(data);
    addTail(l,node);
    removeHead(l2);
	}
}
else if(!l2.head){
    while (l1.head){
    int data=l2.head->data;
    Node* node;
    node=createNode(data);
    addTail(l,node);
    removeHead(l1);
	} 
}
	return l ;
}
void mergeSort(){}
int main(){
  linkedList list1;
  createList(list1);
  Node* node1;
  int n;
  int *l1=new int[n];
  cout<<"Nhap so luong node list1 :"<<endl;
  cin>>n;
for (int i=0;i<n;i++){
    cin>>l1[i];
   node1=createNode(l1[i]);
 addTail(list1,node1);
 }
 printList(list1);
 //


  linkedList list2;
  createList(list2);
  Node* node2;
   int m;
  int *l2=new int[m];
  cout<<"\nNhap so luong node list2 :"<<endl;
  cin>>m;
for (int i=0;i<m;i++){
    cin>>l2[i];
   node2=createNode(l2[i]);
 addTail(list2,node2);
 }
 cout<<endl;
printList(list2);

linkedList list;
createList(list);
list=Merge(list1,list2);
cout<<endl;
printList(list);
 return 0;
}