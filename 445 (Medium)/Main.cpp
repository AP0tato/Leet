struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            l1 = reverse(l1);
            l2 = reverse(l2);
            ListNode* ans = new ListNode();
            ListNode* a = ans;
    
            int t;
            int c = 0;
            while( (l1!=nullptr||l2!=nullptr) )
            {
                t = 0;
                if(l1!=nullptr)
                {
                    t += l1->val;
                    l1 = l1->next;
                }
                if(l2!=nullptr)
                {
                    t += l2->val;
                    l2 = l2->next;
                }
                if(c != 0)
                {
                    t += c;
                    c = 0;
                }
                ans->val = t%10;
                if(t>9)
                    c = t/10;
                ans->next = new ListNode();
                ans = ans->next;
            }
            if(c!=0)
            {
                a = reverse(a);
                a->val = a->val+c;
            }
            else
            {
                a = reverse(a);
                a = a->next;
            }
            return a;
        }
    
        ListNode* reverse(ListNode* l)
        {
            // Initialize current, previous and next pointers
            ListNode* current = l;
            ListNode *prev = nullptr, *next = nullptr;
     
            while (current != nullptr) {
                // Store next
                next = current->next;
                // Reverse current node's pointer
                current->next = prev;
                // Move pointers one position ahead.
                prev = current;
                current = next;
            }
            l = prev;
            return l;
        }
    };