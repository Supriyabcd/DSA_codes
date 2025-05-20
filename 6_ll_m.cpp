#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*Middle Node - 
brute force - find length -traversal once,
mid = length/2-1
traverse again to find mid*/

//optimal - tortoiseHare method
ListNode* middle_node(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//reverse ll - iterative
// brute force - copy it backwards to new ll
//iterative approach, T - O(N), S - O(1) 
   ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *temp = head;
        while (temp != NULL) {
            ListNode *next = temp->next;
            temp->next = prev;

            prev = temp;
            temp = next;
        }
        return prev;
    }

//reverse ll - recursive
// T - O(N), S - O(1)

ListNode* reverseLinkedList(ListNode* head) {
    // Base case:
    // If the linked list is empty or has only one node,
    // return the head as it is already reversed.
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursive step:
    // Reverse the linked list starting 
    // from the second node (head->next).
    ListNode* newHead = reverseLinkedList(head->next);
    
    // Save a reference to the node following
    // the current 'head' node.
    ListNode* front = head->next;
    
    // Make the 'front' node point to the current
    // 'head' node in the reversed order.
    front->next = head;
    
    // Break the link from the current 'head' node
    // to the 'front' node to avoid cycles.
    head->next = NULL;
    
    // Return the 'newHead,' which is the new
    // head of the reversed linked list.
    return newHead;
}

//merge to sorted ll
//brute force - put all elements to arr, sort, then create new ll
//optimal - one head pointer for new ll, two pointers to given ll
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;
        
        while(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if(list1 != NULL){
            temp->next = list1;
            list1 = list1->next;
        }

        if(list2 != NULL){
            temp->next = list2;
            list2 = list2->next;
        }
        return head->next;
    }

//add 2 nos. in ll (of size m and n resp.)
//soln - ele. maths
//T - O(max(m,n)), S - O(max(m,n))
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(); 
        ListNode *temp = head; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return head -> next; 
    }

//remove kth node from end
//brute force - delete (L-N+1)th node from head
//T - O(L)+O(L-K), S - O(1)
ListNode* deleteKthFromEnd(ListNode* head, int k){
    //first - find L- length of ll
    if (head == NULL) {
        return NULL;
    }
    int cnt = 0;
    ListNode* temp = head;

    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    //delete (l-k+1)th node
    
    //
    if (cnt == k) {
        ListNode* newhead = head->next;
        delete (head);
        return newhead;
    }

    // Calculate the position of the node to delete (res)
    int res = cnt - k;
    temp = head;

    // Traverse to the node just before the one to delete
    while (temp != NULL) {
        res--;
        if (res == 0) {
            break;
        }
        temp = temp->next;
    }

    // Delete the kth node from the end
    ListNode* delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
}

//optimal - slow and fast pointers
//T - O(k), S - O(1)
ListNode* DeletekthFromEnd(ListNode* head, int k){
    ListNode *fast = head;
    ListNode *slow = head;

    for(int i = 0; i < k; i++) {
        fast = fast->next;
    }

    if (fast == NULL)
        return head->next;

    while(fast->next != NULL){
        slow = slow ->next;
        fast = fast->next;
    }

    ListNode* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}

//detect loop in ll
//brute force - store elements in hashmap
bool detectLoop(ListNode* head) {
    ListNode* temp = head;  
    
    unordered_map<ListNode*, int> nodeMap;  

    while (temp != nullptr) {
        if (nodeMap.find(temp) != nodeMap.end()) {
            return true;
        }
        nodeMap[temp] = 1;
        temp = temp->next;  
    }
    return false;
}

//optimal - fast, slow pointers
bool detectCycle(ListNode* head){
    ListNode *slow = head;
    ListNode *fast = head;

    while(fast != NULL && fast != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow) return true;
    }
    return false;
}

//starting point of loop in ll
//brute force - store eles in hashmap
//optimal soln - fast & slow pointer
ListNode *firstCycleNode(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
    }
    return nullptr;
}

//sort ll
//brute force - copy eles to array -> sort array -> form ll
//optimal soln - merge sort alogrithm 
ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
    
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next; 
    }

    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    return dummyNode->next;
}
ListNode* findMiddle(ListNode* head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
ListNode* sortLL(ListNode* head){
    // Base case: if the list is empty or has only one node
    // it is already sorted, so return the head
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* middle = findMiddle(head);
   
    ListNode* right = middle->next;
    middle->next = nullptr;
    ListNode* left = head;

    left = sortLL(left);
    right = sortLL(right);
    
    return mergeTwoSortedLinkedLists(left, right);
}

//palindrome check
//brute force - store in stack = reverse of ll -> compare stack with ll
//T - O(2*n), S - O(n)
//optimal - tortoise-hare algo. = reverse 2nd half-> compare with both halves
//T -O(2*n) , S - O(1) 
bool LLpalindromeCheck(ListNode* head){
    if(head == NULL|| head->next == NULL){
        return true;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    //find the middle node
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;  
        fast = fast->next->next;  
    }
    // Reverse the second half 
    ListNode* newHead = reverseLinkedList(slow->next);
    // Pointer to the first half
    ListNode* first = head;  
     // Pointer to the reversed second half
    ListNode* second = newHead; 
    //compare 1st half and 2nd reversed half
    while (second != NULL) {
        if (first->val != second->val) {
            reverseLinkedList(newHead);  
            return false;
        }
        first = first->next; 
        second = second->next;  
    }
    reverseLinkedList(newHead);  
    return true; 
}

//intersection of two ll
//brute force - 2 pointers - increment one when other becomes null and reiterate till same or none left to compare
ListNode* intersectBrute(ListNode* head1, ListNode* head2){
    while(head2!= NULL){
        ListNode* temp = head1;
        while(temp != NULL){
            if(temp == head2) 
                return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    return NULL;
}

//better soln 1 - hashing 
ListNode* intersectHashing(ListNode* headA, ListNode* headB){
    unordered_set<ListNode*> st;
    while(headA != NULL) {
       st.insert(headA);
       headA = headA->next;
    }
    while(headB != NULL) {
        if(st.find(headB) != st.end()) return headB;
        headB = headB->next;
    }
    return NULL;
}
//better soln 2- length diff - move headA by length diff ahead and then move both hA and hB together
//T - O()
int getLengthDiff(ListNode* headA, ListNode* headB){
    int len1 = 0, len2 = 0;
    if(!headA || !headB){
        if(!headA){
            ++len1;
            headA = headA->next;
        }
        if(!headB){
            ++len2;
            headB = headB->next;
        }
    }
    return len1-len2;
}
ListNode* intersectLenDiff(ListNode* headA, ListNode* headB){
    int lenDiff = getLengthDiff(headA, headB);
    if(lenDiff < 0){
        while (lenDiff++ != 0){
            headB = headB->next;
        }
    }    
    else while(lenDiff-- != 0){
        headA = headA->next;
    }
    while(headA){
        if(headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}
//optimised soln 
//T - O(N*c), S - O(1)
ListNode* intersectOptimized(ListNode* headA, ListNode* headB){
    ListNode* d1 = headA;
    ListNode* d2 = headB;

    while(d1 != d2){
        if(!d1)
            d1 = d1->next;
        else 
            d1 = headB;
        if(!d2)
            d2 = d2->next; 
        else 
            d2 = headA;
    }
    return d1;
}
int main(){
    return 0;
}
