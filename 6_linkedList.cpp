#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
    
};

class singlyLinkedList {
    private:
        node* head;

        void printReversehelper(node* node){
            if (!node) return;
            printReversehelper(node->next);
            cout << node->data << " -> ";
        }
    public: 
        // Constructor that initializes the head to nullptr (empty list)
        singlyLinkedList() : head(nullptr) {}

        void addFront(int data) {
            node* newNode = new node{data, head};
            head = newNode;
            cout << data <<" inserted at front of list" <<endl;
        }
        //new - operator that dynamically allocates on heap or array of objects and returns a pointer to allocated memory

        void addLast(int data){
            node* newNode = new node{data, nullptr};
            if(!head) {
                head = newNode;
                return;
            }
            node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
            cout << data << " inserted at end of list" << endl;
        }    

        void addBefore (int data, int before){
            if (!head) return;
            if (head->data == before ){
                addFront(data);
                return;
            }
            node* temp = head;
            //search node before target
            while( temp->next && temp->next->data != before) { 
                temp = temp->next;
            }
            if(temp->next){
                node* newNode = new node {data, temp->next};
                temp->next = newNode;
            }
            cout << data << " inserted before " << before <<endl;
        }
        void addAfter(int data, int after){
            node* temp = head;
            //search node after target
            while (temp && temp->data != after){
                temp = temp->next;
            }
            if(temp->next)
            {
                node* newNode = new node{data,temp}; 
                
            }
            cout << data <<" inserted after " << after <<endl;
        }

        void deleteFront(){
            if(!head) return;
            node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deletion at front done" << endl;
        }

        void deleteLast(){
            if (!head) return;
            if(!head->next){
                delete head;
                head = nullptr;
                return;
            }
            node* temp = head;
            while( temp->next && temp->next->next){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
            cout << "Deletion at last done" <<endl;
        }

        void deleteBefore(int before){
            if (!head || !head->next || head->data == before) return;
            if (head->next->data == before ){
                deleteFront();
                return;
            }
            node* temp = head;
            while(temp ->next && temp->next->data != before)
                temp = temp->next;
            if(temp->next && temp->next->next){
                node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            }   
            cout << "Deletion before " << before <<" done" << endl; 
        }

        void deleteAfter(int after){
            node* temp = head;
            while (temp && temp->data != after){
                temp = temp->next;
            }
            if(temp && temp->next){
                node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            }
            cout << "Deletion after "<< after << "done" <<endl;
        }

        bool searchList( int target){
            node* temp = head;
            while (temp) {
                if(temp->data == target){
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

        void printList(){
            node* temp = head;
            if(!head) 
                cout << "nullptr" << endl ;
            if(head) {
                while(temp){
                cout << temp->data << "->" << endl;
                temp = temp->next;
            }
            }
        }

        void printBackwards(){
            printReversehelper(head);
            cout << "nullptr" << endl;
        
        }

        ~singlyLinkedList(){
            while (head){
                deleteFront();
            }
        }
  };


 int main(){
    singlyLinkedList list;

    int choice, data, target;
    do {
    cout << "Menu : \n1. Insertion at front \n2. Insertion at end \n3. Insertion after a given element \n4. Insertion before a given element \n5. Deletion at front \n6. Deletion at end \n7. Deletion after a given element \n8. Deletion before a given element \n9. Searching \n10. Display backwards \n11. Display forwards \n 0. Exit \n";
    cin >> choice;

    switch(choice)
    {
        case 1: cout << "Enter the element to be inserted : " ;
                cin >> data;
                list.addFront(data);
                break;
        case 2: cout << "Enter the element to be inserted : " ;
                cin >> data;
                list.addLast(data);
                break;
        case 3: cout << "Enter the element to be inserted : " ;
                cin >> data;
                int after;
                cout << "Enter the element after which it is to be inserted :";
                cin >> target;
                list.addAfter(data,target);
                break;
        case 4: cout << "Enter the element to be inserted : " ;
                cin >> data;
                int before;
                cout << "Enter the element before which it is to be inserted :";
                cin >> target;
                list.addBefore(data,target);
                break;
        case 5: list.deleteFront();
                break;
        case 6: list.deleteLast();
                break;
        case 7: cout << "Enter the element after which it is to be deleted :";
                cin >> target;
                list.deleteAfter(target);
                break;
        case 8: cout << "Enter the element before which it is to be deleted :";
                cin >> target;
                list.deleteBefore(target);
                break;
        case 9: cout << "Enter the element to be searched: ";
                cin >> target;
                if(list.searchList(target))
                    cout << "Element found in the list" << endl;
                else
                    cout << "Element not in the list" << endl;    
                break;
        case 10: list.printBackwards();
                break;
        case 11: list.printList();
                break;
        case 0: cout << "Exiting .." << endl;
                break;
        default : cout << "Invalid choice. Please try again";
                  break;
    }
 } while (choice != 0);
    
    return 0;
}


