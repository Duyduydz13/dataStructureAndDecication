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
    
    tree=node1;
    tree->left=node2;
    tree->right=node3;
    node2->left=node4;
    node2->right=node5;
    node3->left=node6;
    node3->right=node7;
    node4->left=node8;
    node4->right=node9;
    node5->left=node10;
    
    printTreeNLR(tree);
    return 0;
}