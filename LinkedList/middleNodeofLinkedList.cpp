#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Time Complexity : O(n) and Space Complexity : O(1)
ListNode* bruteForceAproachMiddleNode(ListNode* head) {
    int len = 0;
        ListNode* mover = head;
        while( head != NULL){
            len++;
            head = head->next;
        }
        int mid = len / 2;
        for(int i = 0; i < mid; i++){
            mover = mover->next;
        }
        return mover;
}

// Time Complexity : O(n/2) and Space Complexity : O(1)
ListNode* optimalVersionMiddleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* ans = bruteForceAproachMiddleNode(head);
    cout << "Middle Node Value (Brute Force): " << ans->val << endl;
    ListNode* res = optimalVersionMiddleNode(head);
    cout << "Middle Node Value (Optimal): " << res->val << endl;

    return 0;
}