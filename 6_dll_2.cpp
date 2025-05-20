#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list (forward direction)
    Node* back;     // Pointer to the previous node in the list (backward direction)

    // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
    Node(int data1, Node* next1 = nullptr, Node* back1 = nullptr) {
        data = data1;
        next = next1;
        back = back1;
    }
};

// Function to convert an array to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
    if (arr.empty()) return nullptr;

    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    // Initialize 'prev' to the head node
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the array and set its 'back' pointer to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        // Update the 'next' pointer of the previous node to point to the new node
        prev->next = temp;
        // Move 'prev' to the newly created node for the next iteration
        prev = temp;
    }
    // Return the head of the doubly linked list
    return head;
}

// Function to print the elements of the doubly linked list
void print(Node* head) {
    while (head != nullptr) {
        // Print the data in the current node
        cout << head->data << " ";
        // Move to the next node
        head = head->next;
    }
    cout << endl;
}

// Function to delete the head of the doubly linked list
Node* deleteHead(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        // Return NULL if the list is empty or contains only one element
        return nullptr;
    }

    // Store the current head as 'prev'
    Node* prev = head;
    // Move 'head' to the next node
    head = head->next;
    // Set 'back' pointer of the new head to nullptr
    head->back = nullptr;
    // Set 'next' pointer of 'prev' to nullptr
    prev->next = nullptr;
    // Free memory of the deleted node
    delete prev;

    // Return the new head
    return head;
}

// Function to delete the tail of the doubly linked list
Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        // If the list is empty or has only one node, return null
        return nullptr;
    }

    Node* tail = head;
    while (tail->next != nullptr) {
        // Traverse to the last node (tail)
        tail = tail->next;
    }

    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    // Free memory of the deleted node
    delete tail;

    return head;
}

// Function to insert a node at the end of the doubly linked list
Node* insert(Node* head, int x) {
    if (head == nullptr) {
        return new Node(x);
    }
    Node* n = new Node(x);

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = n;
    n->back = temp;

    return head;
}

// Function to print the doubly linked list with validation
void printList(Node* head) {
    Node* temp = head;
    if (temp != nullptr) {
        int ct1 = 0, ct2 = 0;
        while (temp->next != nullptr) {
            temp = temp->next;
            ct1++;
        }
        while (temp->back != nullptr) {
            temp = temp->back;
            ct2++;
        }
        if (ct1 != ct2) {
            cout << -1 << "\n";
            return;
        }
    }
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to add a node at a specific position in the doubly linked list
void addNode(Node* head, int pos, int data) {
    Node* temp = head;
    while (temp != nullptr && --pos) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        Node* newNode = new Node(data);
        newNode->back = temp;
        newNode->next = temp->next;

        if (temp->next != nullptr) {
            temp->next->back = newNode;
        }
        temp->next = newNode;
    }
}

//brute force - use satck to store and rewrite on dll
//optimal solution - change direction of pointers
Node* reverseDLL(Node* head){
    if(!head || !head->next){
        return nullptr;
    }
    Node* prev = nullptr;
    Node* temp = head;
     
    while(temp){
        //swapping back and next of nodes
        prev = temp->back;
        temp->back = temp->next;
        temp->next = prev; 
        //moving to next ele which now at back
        temp = temp->back;
    }

    return prev->back;
}
int main() {
    // Test the functions
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2DLL(arr);

    cout << "Original list: ";
    print(head);

    head = deleteHead(head);
    cout << "After deleting head: ";
    print(head);

    head = deleteTail(head);
    cout << "After deleting tail: ";
    print(head);

    head = insert(head, 6);
    cout << "After inserting 6 at the end: ";
    print(head);

    addNode(head, 2, 7);
    cout << "After adding 7 at position 2: ";
    print(head);

    head = reverseDLL(head);
    cout << "After reversal :";
    print(head);
    return 0;
}
