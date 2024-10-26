#include <vector>
#include <iostream>

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
    int pairSum(ListNode* head) {
        vector<int> values;
        int maxSum = 0;
        while(head)
        {
            values.push_back(head->val);
            head = head->next;
        }

        int len = values.size();
        for(int i = 0; i < len/2; i++)
            maxSum = max(maxSum, values[i]+values[len-i-1]);

        return maxSum;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(5, new ListNode(4, new ListNode(2, new ListNode(1))));
    Solution *s;

    cout<<s->pairSum(head);
}
