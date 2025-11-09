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

// Time Complexity : O((n+m)log(n+m)) and Space Complexity : O(n+m)
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        vector<int> ans;
        ListNode *temp = list1;
        while (temp != nullptr)
        {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        ListNode *temp1 = list2;
        while (temp1 != nullptr)
        {
            ans.push_back(temp1->val);
            temp1 = temp1->next;
        }
        if (ans.empty())
            return nullptr;
        sort(ans.begin(), ans.end());

        ListNode *head = new ListNode(ans[0]);
        ListNode *curr = head;

        for (int i = 1; i < ans.size(); i++)
        {
            curr->next = new ListNode(ans[i]);
            curr = curr->next;
        }
        return head;
    }
};
int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    Solution s;
    ListNode *mergedList = s.mergeTwoLists(list1, list2);
    cout << "Merged Sorted List: ";
    while (mergedList != nullptr)
    {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    return 0;
}