#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;
//class Node for binarytree
class Node{
public:
    int data;
    Node *left;
    Node *right;
    //constructor
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
//construction of Binary tree
Node *BuildTree(){
    int val;
    cin>>val;
     if(val==-1) return NULL;
     Node* root=new Node(val);
     root->left=BuildTree();
     root->right=BuildTree();
     return root;
}
//print preorder of binarytree
void RecPreorder(Node *root){
    if(root==NULL) return ;
    cout<<root->data<<" ";
    RecPreorder(root->left);
    RecPreorder(root->right);
    return;
}
void ItePreOrder(Node *root){
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node *reval=s.top();
        s.pop();
        cout<<reval->data<<" ";
        if(reval->right!=NULL) s.push(reval->right);
        if(reval->left!=NULL)  s.push(reval->left);
    }
    return;
}
//print postorder of binaryTree
void RecPostorder(Node *root){
    if(root==NULL) return;
     RecPostorder(root->left);
     RecPostorder(root->right);
     cout<<root->data<<" ";
     return;
}
void ItePostOrder(Node *root){
    stack<Node *> s;
    do{
        //first move pointer to last left node
        while(root!=NULL){
            if(root->right!=NULL) s.push(root->right);
            s.push(root);
            root=root->left;
        }
        Node *node=s.top();
        s.pop();
        //Now check right child exist or not if exist then work on right tree
        //Here we check top of stack is equal to node right child because it tell
        // right child is already traverse or not
        if(node->right!=NULL&&node->right==s.top()){
            s.pop();
            s.push(node);
            //work on right tree of node
            root=node->right;
        }
        else{
            cout<<node->data<<" ";
            //set current node null because right child does'nt exist
            root=NULL;
        }
    }while(!s.empty());
}
//print inoder of binaryTree
void RecInorder(Node *root){
    if(root==NULL) return;
    RecInorder(root->left);
    cout<<root->data<<" ";
    RecInorder(root->right);
    return;
}
void IteInOrder(Node *root){
    stack<Node*> s;
    do{
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
        Node *node=s.top();
        s.pop();
        cout<<node->data<<" ";
        root=node->right;
    }while(!s.empty());
    return;
}
//print level order of binaryTree
void RecPrintLevelOrder(Node *root,int k){
    if(root==NULL) return;
    if(k==0) cout<<root->data<<" ";
    RecPrintLevelOrder(root->left,k-1);
    RecPrintLevelOrder(root->right,k-1);
    return;
}
void IterLevelOrder(Node *root){
    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* reval=q.front();
        q.pop();
        cout<<reval->data<<" ";
        if(reval->left!=NULL) q.push(reval->left);
        if(reval->right!=NULL) q.push(reval->right);
    }
    return;
}
//Height of binaryTree
int height(Node *node){
    if(node==NULL) return -1;
    int lch=height(node->left);
    int rch=height(node->right);
    return max(lch,rch)+1;
}
//total no of node in binaryTree
int Total_Node(Node *node){
    if(node==NULL) return 0;
    int ltn=Total_Node(node->left);
    int rtn=Total_Node(node->right);
    return ltn+rtn+1;
}
//maxmium value in the binaryTree
int Max(Node *node){
    if(node=NULL)return 0;
    int lcm=Max(node->left);
    int rcm=Max(node->right);
    return max(max(lcm,rcm),node->data);
}
//minimum value of tree
int Min(Node *node){
    if(node=NULL)return 0;
    int lcm=Min(node->left);
    int rcm=Min(node->right);
    return min(min(lcm,rcm),node->data);
}
//total sum of node of binarytree
int Total_sum(Node *node){
    if(node==NULL) return 0;
    return node->data+Total_sum(node->left)+Total_sum(node->right);
}
int ReplaceChildSum(Node *root){
    //base case
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL&&root->right==NULL) return root->data;
    int leftsum=ReplaceChildSum(root->left);
    int rightsum=ReplaceChildSum(root->right);
    int sum=leftsum+rightsum;
    int temp=root->data;
    root->data=sum;
    return temp+sum;
}
Node * BuildLevelOrder(){
    int data;
    cin>>data;
    Node *newNode=new Node(data);
    queue<Node *> q;
    q.push(newNode);
    while(!q.empty()){
        Node *n=q.front();
        int a,b;
        cin>>a>>b;
        if(a!=-1){
            n->left=new Node(a);
            q.push(n->left);
        }
        if(b!=-1){
            n->right=new Node(b);
            q.push(n->right);
        }
        q.pop();
    }
    return newNode;
}
void Mirror_BinaryTree(Node *root){
    if(root==NULL) return ;
    swap(root->left,root->right);
    Mirror_BinaryTree((root->left));
    Mirror_BinaryTree((root->right));
    return;
}
//check our binary  tree is balanced or not
pair<int,bool> isBalanced_BT(Node *root){
    //base case
    pair<int,bool> b,left,right;
    if(root==NULL){
        b.first=0;
        b.second=true;
        return b;
    }
    left=isBalanced_BT(root->left);
    right=isBalanced_BT(root->right);
    int h=max(left.first,right.first) +1;
    if(abs(left.first-right.first)<=1&&left.second&&right.second){
        return make_pair(h,true);
    }
    return make_pair(h,false);
}

int main(){
    Node*root = BuildLevelOrder();//buildRec();
    ItePreOrder(root);
    cout<<endl;
    cout<<Total_Node(root)<<endl;
    cout<<height(root)<<endl;
    //printAtLevelK(root,2);

    //replaceChildSum(root);
    //printPre(root);

}
