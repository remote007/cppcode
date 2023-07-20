/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node(int val)
  {
      data = val;
      next = NULL;
  }
};

void insertAtHead(Node* &head , int val)
{
     Node* n1 = new Node(val);
     if(!head)
        head = n1;
     else
        {
            n1->next = head;
            head = n1;
        }
}  
  
void insertAtTail(Node* &head, int val)
{
    Node* n1 = new  Node(val)  ;
    if(!head)
    //   head = n1;
         insertAtHead(head,val);
    else
    {
           Node* temp = head ;
           while(temp->next)
                 temp = temp->next;
           temp->next =n1;
    }
  }
 
void insertAtPosition(Node* &head , int val , int position)
{
     int cnt = 1 ;
     if(position==1)
        insertAtHead(head,val);
     Node* n1 = new Node(val);
     Node* temp = head;
     while(cnt<position-1)
     {
        temp = temp->next;
        cnt++;
     }
     n1->next = temp->next;
     temp->next = n1;
}  
  
void traverseList(Node* head)
{
           Node* temp = head ;
           while(temp)
             {    
                 cout<<temp->data<<"->";
                 temp = temp->next;
             }
             cout<<"NULL"<<endl;
  }

bool searchNode(Node* head , int val)
{
    Node* temp = head;
    while(temp)
        if(temp->data==val)
            return true;
        else
            temp=temp->next;
    return false;
}

bool deleteNodeByValue(Node* &head , int val)
{
    if(searchNode(head,val) && head)
    {
        Node* temp = head;
        if(temp->data!=val)
        {
            while(temp->next->data!=val)
                temp= temp->next;
            temp->next=temp->next->next;
        }
        else 
        {
            head = temp->next;
        }
        return true;
    }
    return false;
}

bool deletePosition(Node* &head , int position)
{
     Node* temp = head;
    
     if(position==1)   
     {
         head = temp->next;
         return true;
     }
     else
     {
         int cnt = 1;
         
         while(cnt<position-1)
         {
             temp=temp->next;
             cnt++;
         }
         temp->next=temp->next->next;
         return true;
     }
     return false;
}

int main()
{
    Node* head = NULL;
    // insertAtTail(head,2);
    insertAtTail(head,3);
    // insertAtTail(head,4);
    insertAtHead(head,1);
    insertAtHead(head,0);
    insertAtPosition(head,2,3);
    insertAtPosition(head,4,5);
    traverseList(head);
    cout<<deleteNodeByValue(head,0)<<endl;
    cout<<searchNode(head,0)<<endl;
    cout<<deletePosition(head,1)<<endl;
    traverseList(head);
    return 0;
}
