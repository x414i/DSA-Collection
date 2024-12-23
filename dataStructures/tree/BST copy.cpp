#include <iostream>
using namespace std;

struct Node {
    string name;
    Node *left, *right;
};

class BST {
public:
    Node *root;

    BST() {
        root = NULL;
    }

    void insert(Node *&node, string name) {
        if (node == NULL) {
            node = new Node();
            node->name = name;
            node->left = node->right = NULL;
        } else if (name < node->name) {
            insert(node->left, name);
        } else {
            insert(node->right, name);
        }
    }

    void inorder(Node *node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->name << " ";
            inorder(node->right);
        }
    }

    void preOrder(Node *node) {
        if (node != NULL) {
            preOrder(node->left);
            preOrder(node->right);
            cout << node->name << " ";
        }
    }

    void postOrder(Node *node) {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->name << " ";
        }
    }

    void menu() {
        int choice;
        string name;
        while (true) {
            cout << "Enter 1 to insert, 2 for inorder, 3 for preorder, 4 for postorder, 0 to exit: ";
            cin >> choice;
            switch (choice) {
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


// #include <iostream>
// #include <string>

// using namespace std;

// struct Node
// {
//     string name;
//     Node *left;
//     Node *right;

//     Node(string n) : name(n), left(NULL), right(NULL) {}
// };

// class BST
// {
// private:
//     Node *root;

//     void insert(Node *&node, const string &name)
//     {
//         if (node == NULL)
//         {
//             node = new Node(name);
//         }
//         else if (name < node->name)
//         {
//             insert(node->left, name);
//         }
//         else
//         {
//             insert(node->right, name);
//         }
//     }

//     void inorder(Node *node)
//     {
//         if (node != NULL)
//         {
//             inorder(node->left);
//             cout << node->name << " ";
//             inorder(node->right);
//         }
//     }

//     void preOrder(Node *node)
//     {
//         if (node != NULL)
//         {
//             inorder(node->left);
//             inorder(node->right);
//             cout << node->name << " ";
//         }
//     }
//     void postOrder(Node *node)
//     {
//         if (node != NULL)
//         {
//             cout << node->name << " ";
//             inorder(node->left);
//             inorder(node->right);
//         }
//     }

// public:
//     BST() : root(NULL) {}

//     void insert(const string &name)
//     {
//         insert(root, name);
//     }

//     void displayInOrder()
//     {
//         inorder(root);
//         cout << endl;
//     }
//     void displaypostOrder()
//     {
//         postOrder(root);
//         cout << endl;
//     }
//     void displaypreOrder()
//     {
//         preOrder(root);
//         cout << endl;
//     }
// };

// int main()
// {
//     BST tree;

//     tree.insert("ahmed");
//     tree.insert("xzxzxzx");
//     tree.insert("zain");
//     tree.insert("bassem");
//     tree.insert("ali");

//     tree.insert("othman");
//     tree.insert("abdSalam");
//     tree.insert("yazin");
//     tree.insert("amin");
//     tree.insert("x414i");

//     tree.insert("ahmed");
//     tree.insert("xzxzxzx");
//     tree.insert("zain");
//     tree.insert("bassem");
//     tree.insert("ali");

//     cout << "Names in order: ";
//     tree.displayInOrder();
//     cout << "\nNames post order: ";
//     tree.displaypostOrder();
//     cout << "\nNames pre order: ";
//     tree.displaypreOrder();

//     return 0;
// }