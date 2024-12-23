#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string name;
    Node *left;
    Node *right;

    Node(string n) : name(n), left(NULL), right(NULL) {}
};

class BST
{
private:
    Node *root;

    void insert(Node *&node, const string &name)
    {
        if (node == NULL)
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
        if (node != NULL)
        {
            inorder(node->left);
            cout << node->name << " ";
            inorder(node->right);
        }
    }

    void preOrder(Node *node)
    {
        if (node != NULL)
        {
            inorder(node->left);
            inorder(node->right);
            cout << node->name << " ";
        }
    }
    
    void postOrder(Node *node)
    {
        if (node != NULL)
        {
            cout << node->name << " ";
            inorder(node->left);
            inorder(node->right);
        }
    }

public:
    BST() : root(NULL) {}

    void insert(string &name)
    {
        insert(root, name);
    }
    
    Node* findMin(Node* node) {
        while (node->left != NULL) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, string name) {
        if (node == NULL) return node;
        if (name < node->name) {
            node->left = deleteNode(node->left, name);
        } else if (name > node->name) {
            node->right = deleteNode(node->right, name);
        } else {
            if (node->left == NULL) {
                Node *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->name = temp->name;
            node->right = deleteNode(node->right, temp->name);
        }
        return node;
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
    
    void menu() 
    {
        int choice;
        string name;
        while (true) 
        {
            cout << "Enter 1 to insert, 2 for inorder, 3 for preorder, 4 for postorder, 0 to exit: ";
            cin >> choice;
            switch (choice) 
            {
                case 1:
                    cout << "Enter name to insert: ";
                    cin >> name;
                    insert(root, name);
                    break;
                case 2:
                    inorder(root);
                    cout << endl;
                    break;
                case 3:
                    preOrder(root);
                    cout << endl;
                    break;
                case 4:
                    postOrder(root);
                    cout << endl;
                    break;
                case 0:
                    return;
                default:
                    cout << "Invalid choice, please try again." << endl;
            }
        }
    }
};

int main()
{
    BST tree;
    tree.menu();
    return 0;
}