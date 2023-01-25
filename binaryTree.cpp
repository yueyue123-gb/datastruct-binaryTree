#include <iostream>

using namespace std;

struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char v)
    {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode *CreateTree(string input, int &index)
{
    if (index >= input.size())
    {
        return nullptr;
    }
    char curC = input[index];
    if (curC == '#')
    {
        ++index;
        return nullptr;
    }
    ++index;
    TreeNode *root = new TreeNode(curC);
    root->left = CreateTree(input, index);
    root->right = CreateTree(input, index);
    return root;
}

void TravelTree(TreeNode* root){
    if(root == nullptr){
        // cout << "# ";
        return;
    }
    TravelTree(root->left);
    cout << root->val << " ";
    TravelTree(root->right);
}

int main()
{
    string input = "ab#d##c##";
    int index = 0;
    TreeNode* root = CreateTree(input, index);
    TravelTree(root);
    return 0;
}