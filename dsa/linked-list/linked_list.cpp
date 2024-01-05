#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node {
public:
    // Data stored in the Node
    int data;   
    
    // Pointer to the next Node in the list
    Node* next;      

    // Constructor with both data and
    // next Node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1=0) {
        data = data1;
        next = nullptr;
    }
};

// ^ Reverse a linked list

Node* reverseLinkedList(Node *head)
{
   // Initialize'temp' at
   // head of linked list
   Node* temp = head;  
   
   // Initialize pointer 'prev' to NULL,
   // representing the previous Node
   Node* prev = NULL;  
   
   // Traverse the list, continue till
   // 'temp' reaches the end (NULL)
   while(temp != NULL){  
       // Store the next Node in
       // 'front' to preserve the reference
       Node* front = temp->next;  
       
       // Reverse the direction of the
       // current Node's 'next' pointer
       // to point to 'prev'
       temp->next = prev;  
       
        // Move 'prev' to the current
        // Node for the next iteration
       prev = temp;  
       
        // Move 'temp' to the 'front' Node
        // advancing the traversal
       temp = front; 
   }
   
   // Return the new head of
   // the reversed linked list
   return prev;  
}

// ^ Find middle element in a Linked List

Node* middleNode(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next)
        slow = slow->next, fast = fast->next->next;
    return slow;
}

// ^ Merge two sorted Linked Lists

Node* mergeTwoLists(Node* l1, Node* l2) {
    // when list1 is empty then 
    // our output will be same as list2
    if(l1 == NULL) return l2; 

    // when list2 is empty then our output 
    // will be same as list1
    if(l2 == NULL) return l1;

    // pointing l1 and l2 to smallest and greatest one
    if(l1->data > l2->data) swap(l1,l2);

    // act as head of resultant merged list
    Node* res = l1;

    while(l1 != NULL && l2 != NULL) {

        Node* temp = NULL;

        while(l1 != NULL && l1->data <= l2->data) {

            temp = l1;//storing last sorted Node  
            l1 = l1->next;
        }

        // link previous sorted Node with 
        // next larger Node in list2
        temp->next = l2;
        swap(l1,l2);
    }

    return res;
}

// ^ Remove N-th Node from the end of a Linked List

Node* removeNthFromEnd(Node* head, int n) {
    Node * start = new Node();
    start -> next = head;
    Node* fast = start;
    Node* slow = start;     

    for(int i = 1; i <= n; ++i)
        fast = fast->next;

    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    slow->next = slow->next->next;
    
    return start->next;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node *dummy = new Node(); 
    Node *temp = dummy; 
    int carry = 0;
    while( (l1 != NULL || l2 != NULL) || carry) {
        int sum = 0; 
        if(l1 != NULL) {
            sum += l1->data; 
            l1 = l1 -> next; 
        }
        
        if(l2 != NULL) {
            sum += l2 -> data; 
            l2 = l2 -> next; 
        }
        
        sum += carry; 
        carry = sum / 10; 
        Node * n = new Node(sum % 10); 
        temp -> next = n; 
        temp = temp -> next; 
    }
    return dummy -> next; 
}

// ^ Delete given Node in a Linked List : O(1) approach

void deleteNode(Node* t) {
    t->data = t->next->data;
    t->next = t->next->next;
    return;
}

int main(){
    return 0;
}