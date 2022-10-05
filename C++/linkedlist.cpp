// This program will contain all the basic information needed to learn about linkedlist Data Structure.
//Functions included are:
/*1. Creating structure of a node in linked list.
2. Function to insert a node at the head/start of a linked list.
3. Insert node at the end of linked list .
4. Function to display a linked list.
5. Function to reverse k nodes of a linked list using three pointers in a single linked list.
6. Function to make a linked list into a cycle from k nodes.
7. Function to detect a cycle.
8. Function to remove the cycle in the linked list.
9. Function to add k nodes at the head.
10. Function to calculate the length of a linked list.
11. Function to find a intersection of two lists.
12. Function to join two linked list at the end of another list.
13. Function to recursively merge two linked list.
*/


#include <bits/stdc++.h>
using namespace std;


// creating structure of a node in linked list
class node
{
public:
    int data;   // data at a node
    node *next; // pointer to the next node
    // base contructor
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

// function to insert a node at the head/start of a linked list
void insertAtHead(node *&head, int val)
{

    node *n = new node(val); // declaring a new node

    n->next = head; // declaring new node's next to the head node of the linked list
    head = n;       // new head is new node
}

// insert node at the end of linked list
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    { // if there is an empty linked list then add the value to head
        head = n;
        return;
    }
    node *temp = head;         // declaring a temporary pointer to traverse thru the linked list
    while (temp->next != NULL) // determining the last position before null
    {
        temp = temp->next;
    }
    temp->next = n; // pointing to the new node and adding value to it.
}

//Function to display we need to declare a new pointer then traverse thru the list with that pointer and simultaneously print the value
void display(node *head)
{
    
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "Null" << endl;
}

//function to reverse k nodes of a linked list using three pointers in a single linked list
node *revk(node *&head, int k)
{
    // REV the first sub part using iterative function
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;
    int count = 0;
    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if (nextptr != NULL)
    {
        head->next = revk(nextptr, k);
    }
    return prevptr;
}

//Function to make a linked list into a cycle from k nodes
// basically we will be pointing the kth node to the head of the linked list
void makeCycle(node *&head, int k)
{
    node *temp = head;
    node *cycStart;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == k)
        {
            temp = cycStart;
        }

        temp = temp->next;
        count++;
    }
    temp->next = cycStart;
}

//Function to detect a cycle:
//Using two pointers one moves one node at a time other two nodes at a time.
//If they coincide after starting then linked list is a cycle
bool detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

//Fucntion to remove the cycle :
//Simply using the same two pointers that we used to detect cycled linked list,
//The node at which they will coincide will be pointed to null
void removeCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            break;
        }
    }
    while (fast->next != slow)
    {

        fast = fast->next;
    }
    fast->next = NULL;
}

//Function to add k nodes at the head
void addknodestostart(node *&head, int k)
{
    node *ptr1 = head;
    node *ptr2 = head;
    int pos = 1;
    while (ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
        pos++;
    }
    pos = (pos - k) - 1;
    while (pos > 0)
    {
        pos--;
        ptr2 = ptr2->next;
    }
    ptr1->next = head;
    head = ptr2->next;
    ptr2->next = NULL;
}

//Fucntion to calculate the length of a linked list
int length(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

//Fucntion to find a intersection of two lists:
void intersectionpointof2(node *&head1, node *&head2)
{
    // brute force : traverse one by one matching
    // better : hashing smaller list node address and matching it with the other nodes
    // optimal: travesring p1 till null then traversing p1 through ll2 till p1 and p2 point to same node
    if (head1 == NULL || head2 == NULL)
        cout << "null" << endl;

    node *a = head1;
    node *b = head2;
    while (a != b)
    {
        a = a == NULL ? head2 : a->next;
        b = b == NULL ? head1 : b->next;
    }
    cout << a->data << a->next->data << endl;
}

//Function to join two linked list at the end of another list
void intersect(node *head1, node *&head2, int pos)
{

    node *ptr1 = head1;
    while (pos--)
    {
        ptr1 = ptr1->next;
    }
    node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = ptr1;
}

//Function to merge two linked list recursively.
node *mergerecur(node *&head, node *&head2)
{

    if (head == NULL)
    {
        return head2;
    }
    else
    {
        return head;
    }

    node *result;
    if (head->data < head2->data)
    {
        result = head;
        result->next = mergerecur(head->next, head);
    }
    else
    {
        result = head2;
        result->next = mergerecur(head, head2->next);
    }
    return result;
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 5);
    node *head2 = NULL;
    insertAtTail(head2, 2);
    insertAtTail(head2, 4);
    insertAtTail(head2, 6);
    insertAtTail(head2, 7);
    // intersect(head,head2,3);
    // display(head);
    // display(head2);
    // intersectionpointof2(head,head2);
    // revknodes(head,2);
    // int k =2;
    // node* newhead =revk(head,k);
    // makeCycle(head,3);
    // cout<<detectCycle(head)<<endl;
    // removeCycle(head);
    // display(head);
    // addknodestostart(head,3);
    // display(head);
    display(mergerecur(head, head2));

    return 0;
}