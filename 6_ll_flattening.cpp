#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode *next;
    ListNode *child;

    ListNode() : data(0), next(nullptr), child(nullptr) {};
    ListNode(int x) : data(x), next(nullptr), child(nullptr) {}
    ListNode(int x, ListNode *nextNode, ListNode *childNode) : data(x), next(nextNode), child(childNode) {}
};

//brute force - copy into array-> sort eles -> form ll
//optimal solution - merge sort algo

ListNode* merge(ListNode *list1, ListNode *list2){
    ListNode* dummyNode = new ListNode(-1);
    ListNode* res = dummyNode;

    while (list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->next;
        } else {
            res->child = list2;
            res = list2;
            list2 = list2->next;
        }
        res->next = NULL;
    }
    if(list1){
        res->child = list1;
    } else {
        res->child = list2;
    }

    if(dummyNode->child){
        dummyNode->child->next = NULL;
    }
    return dummyNode->child;
}
ListNode* flattenedLL(ListNode *head){
    if (head == nullptr || head->next == nullptr){
        return head;
    }

    ListNode* mergedhead = flattenedLL(head);
    head = merge(head, mergedhead);
    return head;
}

int main(){
    return 0;
}