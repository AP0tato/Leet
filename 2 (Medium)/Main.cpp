#include <iostream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *result = new ListNode();
        ListNode *r = result;
        bool fh1 = true;
        bool fh2 = true;
        int carry = 0;

        while (true)
        {
            result->val = (fh1 ? l1->val : 0) + (fh2 ? l2->val : 0) + carry;
            carry = result->val / 10;
            result->val = result->val % 10;

            if (l1->next != nullptr)
            {
                l1 = l1->next;
            }
            else
            {
                fh1 = false;
            }
            if (l2->next != nullptr)
            {
                l2 = l2->next;
            }
            else
            {
                fh2 = false;
            }
            if(!fh1 && !fh2 && carry == 0)
            {
                break;
            }
            result->next = new ListNode();
            result = result->next;
        }
        return r;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *a = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *b = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution s;
    ListNode *result = s.addTwoNumbers(a, b);
    while(result != nullptr)
    {
        std::cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
