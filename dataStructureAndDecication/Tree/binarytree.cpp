/*Cây nhị phân tìm kiếm là cây nhị phân mà trong đó, 
các phần tử của cây con bên trái đều nhỏ hơn phần tử hiện hành 
và các phần tử của cây con bên phải đều lớn hơn phần tử hiện hành*/
#include <iostream>

using namespace std;


struct Node
{
    int value;
    Node* left = NULL;
    Node* right = NULL;
};
typedef Node* Tree;


Node* createNode(int data){
  Node* node=new Node;
  node->value=data;
  node->right=NULL;
  node->left=NULL;
  return node;
}

void createTree(Tree &root){
    root=NULL;
}

//Duyệt tiền tự(NLR)
void printTreeNLR(Tree &root){
    if (root)
    {
        cout<<root->value<<"\t";
        printTreeNLR(root->left);
        printTreeNLR(root->right);
    }
}
//Duyệt trung tự(LNR)
void printTreeLNR(Tree &root){
    if (root)
    {
        printTreeLNR(root->left);
        cout<<root->value<<"\t";
        printTreeLNR(root->right);
    }
}
//Duyệt hậu tự(LRN)
void printTreeLRN(Tree &root){
    if (root)
    {
        cout<<root->value<<"\t";
        printTreeLRN(root->left);
        printTreeLRN(root->right);
    }
}
//hủy cây
void DestroyTree(Tree &root)
{
    if (root)
    {
        DestroyTree(root->left);
        DestroyTree(root->right);
        delete root;
    }
}
//thêm nút cho cây nhi phân tìm kiếm
void addNode(Tree &root,Node*node){
    if (root){
        if (root->value==node->value){
            return;
        }
        else if (root->value<node->value){
            addNode(root->left,node);
        }
        else{
            addNode(root->right,node);
        }
    }
    else {
        root=node;
    }
}
//Tìm một phần tử trong cây nhị phân tìm kiếm
Node* fineNode(Tree &root,int data){
    if (root){
        if (root->value==data){
            return root;
        }
        else if (data<root->value){
            fineNode(root->left,data);

        }
        else {
            fineNode(root->right,data);
        }
    }
        return NULL;
}
// Hủy nút trên cây nhị phân tìm kiếm
// TH1 :Xoá Node có một con là Node lá
void delNode1(Tree &root,int data){
    if (root == NULL)
    {
        return; // kết thúc hàm
    }
    else{
        if (data < root->value){
            delNode1(root->right,data);
        }
        else if (data > root->value){
            delNode1(root->right,data);
        }
        else {
            Node* node=root;
            
            if (root->left==NULL){
                root=root->right;
            }
            else if (root->right==NULL){
                root=root->left;
            }
            delete node;
        }
    }
}

int main(){
    Tree tree;
    createTree(tree);
    Node* node1=createNode(19);
    Node* node2=createNode(23);
    Node* node3=createNode(13);
    Node* node4=createNode(16);
    Node* node5=createNode(20);
    Node* node6=createNode(24);
    Node* node7=createNode(17);
    Node* node8=createNode(35);
    Node* node9=createNode(9);
    Node* node10=createNode(10);
    addNode(tree,node1);
    addNode(tree,node2);
    addNode(tree,node3);
    addNode(tree,node4);
    addNode(tree,node5);
    addNode(tree,node6);
    addNode(tree,node7);
    addNode(tree,node8);
    addNode(tree,node9);
    addNode(tree,node10);
    
    printTreeLNR(tree);
    cout<<"\n";
    delNode1(tree,35);
    printTreeLNR(tree);
    return 0;
}