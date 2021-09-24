#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

void insertAfter(Node *node, int new_data)
{
    if (node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = node->next;
    node->next = new_node;
}

void push(Node **head, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void append(Node **head, int data)
{
    Node *node = new Node();
    Node *last = *head;
    node->data = data;
    node->next = NULL;
    if (*head == NULL)
    {
        *head = node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = node;
    return;
}

int main(int argc, char const *argv[])
{
    Node *head = new Node();
    Node *node2 = new Node();
    Node *node3 = new Node();
    Node *node4 = new Node();

    head->data = 1;
    head->next = node2;

    node2->data = 2;
    node2->next = node3;

    node3->data = 3;
    node3->next = node4;

    node4->data = 4;
    node4->next = NULL;

    printList(head);

    insertAfter(node4, 5);

    printList(head);

    return 0;
}
