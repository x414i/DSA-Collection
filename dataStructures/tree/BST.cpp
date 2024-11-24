#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string name;
    Node *left;
    Node *right;

    Node(string n) : name(n), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *root;

    void insert(Node *&node, const string &name)
    {
        if (node == nullptr)
        {
            node = new Node(name);
        }
        else if (name < node->name)
        {
            insert(node->left, name);
        }
        else
        {
            insert(node->right, name);
        }
    }

    void inorder(Node *node)
    {
        if (node != nullptr)
        {
            inorder(node->left);
            cout << node->name << " ";
            inorder(node->right);
        }
    }

    void preOrder(Node *node)
    {
        if (node != nullptr)
        {
            inorder(node->left);
            inorder(node->right);
            cout << node->name << " ";
        }
    }
    void postOrder(Node *node)
    {
        if (node != nullptr)
        {
            cout << node->name << " ";
            inorder(node->left);
            inorder(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(const string &name)
    {
        insert(root, name);
    }

    void displayInOrder()
    {
        inorder(root);
        cout << endl;
    }
    void displaypostOrder()
    {
        postOrder(root);
        cout << endl;
    }
    void displaypreOrder()
    {
        preOrder(root);
        cout << endl;
    }
};

int main()
{
    BST tree;

    tree.insert("ahmed");
    tree.insert("xzxzxzx");
    tree.insert("zain");
    tree.insert("bassem");
    tree.insert("ali");

    tree.insert("othman");
    tree.insert("abdSalam");
    tree.insert("yazin");
    tree.insert("amin");
    tree.insert("x414i");

    tree.insert("ahmed");
    tree.insert("xzxzxzx");
    tree.insert("zain");
    tree.insert("bassem");
    tree.insert("ali");

    cout << "Names in order: ";
    tree.displayInOrder();
    cout << "\nNames post order: ";
    tree.displaypostOrder();
    cout << "\nNames pre order: ";
    tree.displaypreOrder();

    return 0;
}