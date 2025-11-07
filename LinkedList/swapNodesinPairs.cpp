#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        vector<int> duplicate;
        ListNode* temp = head;
        while (temp != nullptr) {
            duplicate.push_back(temp->val);
            temp = temp->next;
        }
        int n = duplicate.size();
        int idxLimit = n / 2;
        int i = 0, j = 1, k = 0;
        while (k < idxLimit) {
            k++;
            swap(duplicate[i], duplicate[j]);
            i += 2;
            j += 2;
        }
        temp = head;
        int z = 0;
        while (temp != nullptr) {
            temp->val = duplicate[z];
            z++;
            temp = temp->next;
        }
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution s;
    ListNode* result = s.swapPairs(head);

    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
