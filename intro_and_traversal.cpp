#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " " << endl;
    inOrderTraversal(root->right);
}
void preOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " " << endl;
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
}
void postOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
    cout << root->data << " " << endl;
}
int main()
{
    node *root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1
    cout << "Printing using Level order traversal" << endl;
    levelOrderTraversal(root);
    cout << "Printing the values using inOrder tRaversal" << endl;
    inOrderTraversal(root);
    cout << "Printing using preOrder Traversal" << endl;
    preOrderTraversal(root);
    cout << "printing using postorder traversal" << endl;
    postOrderTraversal(root);
    return 0;
}
