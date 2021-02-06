#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

void printList(Node*);
void insert(Node*, int);
void insert(Node*, int, int);
Node insertfront(Node**, int);

int main(int argc, const char** argv) {
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();
    Node *fifth = new Node();

    head->data = 1;
    head -> next = second;
    
    second->data=2;
    second->next=third;

    third->data=3;
    third->next=fourth;

    fourth->data=4;
    fourth->next=fifth;

    fifth->data=5;
    fifth->next=NULL;

    printList(head);

    insert(head,6);
    
    printList(head);
    
    insert(head, 3, 2);
    printList(head);
    insertfront(&head,0);
    printList(head);
}

void printList(Node *n){
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout<<endl;
}

void insert(Node *node, int data){
    while (node->next != NULL)
    {
        node = node->next;
    }
     
    Node *newnode = new Node();

    newnode ->data=data;
    node ->next = newnode;
    newnode ->next=NULL;
    
}

void insert(Node *node, int data, int position){
    int i=0;
    while (i!=position)
    {
        node = node->next;
        i++;
    }
     
    Node *newnode = new Node();
    newnode->data=data;
    Node *tmp = node;
    node=node->next;

    tmp->next=newnode;
    newnode->next=node;
    
}

Node insertfront(Node** head_ref, int data){
    Node* new_node = new Node();  
    new_node->data = data;  
    new_node->next = (*head_ref);  
    (*head_ref) = new_node;
}