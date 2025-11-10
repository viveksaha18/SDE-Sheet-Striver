#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int k = arr.size();
        arr.erase(arr.begin() + (k - n));
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        for(int i = 0; i < arr.size(); i++) {

                tail->next = new ListNode(arr[i]);
                tail = tail->next;
        }

        return dummy->next;
       
    }   
};
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;
    Solution sol;
    ListNode* modifiedHead = sol.removeNthFromEnd(head, n);
    ListNode* temp = modifiedHead;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}