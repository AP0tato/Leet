#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *pointer = root;
        if(!root)
        {
            root = new TreeNode(val);
            return root;
        }

        while(true)
        {
            if(val<root->val)
            {
                if(root->left)
                    root = root->left;
                else
                {
                    root->left = new TreeNode(val);
                    break;
                }
            }
            else if(val>root->val)
            {
                if(root->right)
                    root = root->right;
                else
                {
                    root->right = new TreeNode(val);
                    break;
                }
            }
        }
        return pointer;
    }
};

int main()
{
    vector<int> v = {4, 2, 7, 1, 3};
    int k = 5;
}