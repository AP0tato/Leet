#include <iostream>
#include <set>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void traverse(TreeNode *root, set<int>&s)
    {
        if(root==NULL) 
            return;
        
        s.insert(root->val);
        traverse(root->left, s);
        traverse(root->right, s);
    }

    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        traverse(root, s);

        if(s.size()==1)
            return -1;
        else 
        {
            auto it = s.begin();
            it++;
            return (*it);
        }
        
    }
};

int main() {
    Solution s;
     TreeNode *l=new TreeNode(2), *rr=new TreeNode(7), *rl=new TreeNode(5), *r=new TreeNode(5,rl,rr), *root=new TreeNode(2,l,r);
    // TreeNode *l=new TreeNode(2), *r=new TreeNode(2), *root=new TreeNode(2, l, r);

    cout << s.findSecondMinimumValue(root);
}