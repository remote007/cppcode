#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left,*right;
    
    Node(int val)
    {
        data= val;
        left=right= NULL;
    }
};

class BST
{
    public:
    Node *root;
    
    BST()
    {
        root= NULL;
    }
    
    Node* leftRotate(Node *current)
    {
       Node *x= current;
       Node *y= x->right;
       Node *alpha= y->left;
       
       y->left= x;
       x->right= alpha;
       
       return y;
    }
    
    Node* rightRotate(Node *current)
    {
       Node *x= current;
       Node *y= x->left;
       Node *alpha= y->right;
       
       y->right= x;
       x->left= alpha;
       
       return y;
    }
    
    Node* addNode(Node *current,int val)
    {
        if(!current)
        {
            Node *n1= new Node(val);
            
            if(!root)
            root= n1;
            
            return n1;
        }
        
        //Left
        if(val < current->data)
        current->left=  addNode(current->left,val);
        //Right
        else
        current->right= addNode(current->right,val);
        
        int BF= bf(current);
        
        if(BF < -1)
        {
            
            return leftRotate(current);
            
        }
        
        else if(BF > 1)
        {
            if(current->left->data<val)
               current->left=leftRotate(current->left);
            return rightRotate(current);
            
        }
        
        return current;
    }
    
    int htOfNode(Node *current)
    {
        if(!current)
        return -1;
        
        return 1+max(htOfNode(current->left),htOfNode(current->right));
    }
    
    int bf(Node *current)
    {
        int left= current->left ?  htOfNode(current->left)+1:0;
        int right= current->right ? htOfNode(current->right)+1:0; 
       
        return  left-right;
    }
    
    void preorder(Node *current)
    {
        if(!current)
        return;
        
        cout<<current->data<<" bf:"<<bf(current)<<endl;
        preorder(current->left);
        preorder(current->right);
        
    }
    
    
};

int main()
{
    BST t1;
    
    t1.root= t1.addNode(t1.root,10);
    // t1.root= t1.addNode(t1.root,20);
    // t1.root= t1.addNode(t1.root,30);
    // t1.root= t1.addNode(t1.root,40);
    // t1.root= t1.addNode(t1.root,50);
    t1.root= t1.addNode(t1.root,5);
    t1.root= t1.addNode(t1.root,8);
    
    t1.preorder(t1.root);
    
   
    return 0;
}


