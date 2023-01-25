#include <iostream>
#include <stack>
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

void TravelTreeMid(TreeNode *root)
{
    if (root == nullptr)
    {
        // cout << "# ";
        return;
    }
    TravelTreeMid(root->left);
    cout << root->val << " ";
    TravelTreeMid(root->right);
}

void TravelTreeFront(TreeNode *root)
{
    if (root == nullptr)
    {
        // cout << "# ";
        return;
    }
    cout << root->val << " ";
    TravelTreeFront(root->left);
    TravelTreeFront(root->right);
}

void TravelTreeBack(TreeNode *root)
{
    if (root == nullptr)
    {
        // cout << "# ";
        return;
    }
    TravelTreeBack(root->left);
    TravelTreeBack(root->right);
    cout << root->val << " ";
}

void CycleTravelMid(TreeNode *root)
{
    stack<TreeNode *> nodeStack;
    while (!nodeStack.empty() || root != nullptr)
    {
        while (root != nullptr)
        {
            nodeStack.push(root);
            root = root->left;
        }
        root = nodeStack.top();
        nodeStack.pop();
        cout << root->val << " ";
        root = root->right;
    }
}

void CycleTravelFront(TreeNode *root)
{
    stack<TreeNode *> nodeStack;
    while (!nodeStack.empty() || root != nullptr)
    {
        while (root != nullptr)
        {
            cout << root->val << " ";
            nodeStack.push(root);
            root = root->left;
        }
        root = nodeStack.top();
        nodeStack.pop();
        root = root->right;
    }
}

void CyecleTravelBack(TreeNode* root){
    stack<TreeNode*> nodeStack;
    TreeNode* tagNode = nullptr;
    while(!nodeStack.empty() || root != nullptr){
        while(root != nullptr){
            nodeStack.push(root);
            root = root ->left;
        }
        root = nodeStack.top();
        if (root->right == nullptr || root->right == tagNode){
            cout << root->val << " ";
            nodeStack.pop();        
            tagNode = root;
            root = nullptr;
        } else {
            root = root->right;
        }
    }
}

int main()
{
    string input = "51##43##6##";
    string input2 = "ABDH#K###E##CFI###G#J##";
    int index = 0;
    TreeNode *root = CreateTree(input2, index);
    TravelTreeBack(root);
    cout << endl;
    CyecleTravelBack(root);
    return 0;
}