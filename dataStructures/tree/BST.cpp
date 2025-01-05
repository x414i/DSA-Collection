#include <iostream> 
#include <queue>
#include <string>
using namespace std; 

struct node
{ 
    int data; 
    node *left; 
    node *right; 
}; 


//in order function || lVR 
void print1(node *r) 
{ 
    if(r!=NULL) 
    { 
        print1(r->left); 
        cout<<r->data<<" "; 
        print1(r->right); 
    } 
} 

// pre order function || VLR 
void print2(node *r) 
{ 
    if(r!=NULL) 
    { 
        cout<<r->data<<" "; 
        print2(r->left); 
        print2(r->right); 
    } 
} 

//post order function || LRV 
void print3(node *r) 
{ 
    if(r!=NULL) 
    { 
        print3(r->left); 
        print3(r->right); 
        cout<<r->data<<" "; 
    } 
} 

int sizeoftree(node *r) 
{ 
    if(r==NULL) 
        return 0; 
    else return sizeoftree(r->left)+1+sizeoftree(r->right); 
} 

node *addnode(node *r,int v) 
{ 
    if(r==NULL) 
    { 
       node *cn=new node; 
        cn->data=v; 
        cn->left=NULL; 
        cn->right=NULL; 
        return cn; 
    } 
    else if(v<=r->data) 
    r->left=addnode(r->left,v); 
    else 
    r->right=addnode(r->right,v); 
    return r; 
} 

node *serach(node *r,int v) 
{ 
    if(r==NULL || r->data==v) 
        return r; 
    else if(v<r->data) 
        return serach(r->left,v); 
    else 
        return serach(r->right,v); 
} 

int getmax(node *r) 
{ 
   // node *t=r; 
    while(r->right!=NULL) 
        r=r->right; 
    return r->data; 
} 

node *getmin(node *root) 
{ 
   // node *t=r; 
    while(root->left!=NULL) 
        root=root->left; 
    return root; 
} 

node *del(int v,node *root) 
{ 
    if(root==NULL) 
        return root; 

    else if(v<root->data) 
        root->left=del(v,root->left); 

    else if(v>root->data) 
        root->right=del(v,root->right); 

    else if(root->left==NULL && root->right==NULL) 
    { 
        free(root); 
        return NULL; 
    } 
    else if(root->left==NULL) 
    { 
        node *t=root->right; 
        free(root); 
        return t; 
    } 
    else if(root->right==NULL) 
    { 
        node *t=root->left; 
        free(root); 
        return t; 
    } 
    else 
    { 
        node *t=getmin(root->right); 
        root->data=t->data; 
        root->right=del(t->data,root->right); 
    } 
    return root; 
} 

int treeDepth(node *r) 
{ 
    int leftDepth =0; int rightDepth =0 ; 
        if (r == NULL) 
        return 0; 
    leftDepth += treeDepth(r->left); 
    rightDepth += treeDepth(r->right); 
    int macDepth = leftDepth>=rightDepth?leftDepth:rightDepth; 
    /* 
     if(leftDepth>= rightDepth) 
  macDepth = leftDepth; 
  else 
   int macDepth = rightDepth; 
     */ 
    return 1 + macDepth; 
} 

void traverseLevel(node* root, int targetLevel, int currentLevel, int result[], int& index)
{
        if (!root) return;

        if (currentLevel == targetLevel) 
        {
            result[index++] = root->data; 
        }
        else 
        {
            traverseLevel(root->left, targetLevel, currentLevel + 1, result, index);
            traverseLevel(root->right, targetLevel, currentLevel + 1, result, index);
        }
    }

bool findPath(node* root, int path[], int& pathLen, int k) 
    {
        if (root == NULL) return false;

        path[pathLen] = root->data;
        pathLen++;

        if (root->data == k) return true;

        if ((root->left && findPath(root->left, path, pathLen, k)) ||
            (root->right && findPath(root->right, path, pathLen, k))) 
        {
            return true;
        }

        pathLen--;
        return false;
    }

int numberOfEdges(node *r) 
    { 
    return sizeoftree(r) > 0 ? sizeoftree(r) - 1 : 0; 
    }

bool isAVL(node* root)
{
    if (root == NULL) return true;

    int LD = treeDepth(root->left);
    int RD = treeDepth(root->right);

    if (abs(LD - RD) > 1)
        return false;

    return isAVL(root->left) && isAVL(root->right);
}

// complate tree

int countNodes(node* root)
{
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isComplete(node* root, int index, int numberNodes)
{
    if (root == NULL) return true;
    if (index >= numberNodes) return false;
    return isComplete(root->left, 2 * index + 1, numberNodes) &&
           isComplete(root->right, 2 * index + 2, numberNodes);
}

bool isCompleteTree(node* root) 
{
    int numberNodes = countNodes(root);
    return isComplete(root, 0, numberNodes);
}

void invertTree(node* root)
{
    if (root == NULL) return;

    node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);
}

void printPath(node* root, int path[], int pathLen) 
{
    if (root == NULL) return;

    path[pathLen] = root->data;
    pathLen++;

   if (root->left == NULL && root->right == NULL) {
        cout << "Path: ";
        for (int i = 0; i < pathLen; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        
        printPath(root->left, path, pathLen);
        printPath(root->right, path, pathLen);
    }
}

void printPaths(node* root) 
{
    int path[1000]; 
     printPath(root, path, 0);
}

// Convert AVL TREE

int height(node* n) 
{
    if (n == NULL) return 0;
    return max(height(n->left), height(n->right)) + 1;
}

int balanceFactor(node* n) 
{
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

node* rotateRight(node* y) 
{
    node* x = y->left;
    node* T = x->right;

    // Perform rotation
    x->right = y;
    y->left = T;

    return x;
}

node* rotateLeft(node* x) 
{
    node* y = x->right;
    node* T = y->left;

    // Perform rotation
    y->left = x;
    x->right = T;

    return y;
}

node* balanceTree(node* root) 
{
    if (root == NULL) return root;

    // Balance the left and right subtrees
    root->left = balanceTree(root->left);
    root->right = balanceTree(root->right);

    // Get the balance factor
    int bf = balanceFactor(root);

    // Left-heavy
    if (bf > 1) {
        if (balanceFactor(root->left) < 0) {
            root->left = rotateLeft(root->left); // Left-Right case
        }
        return rotateRight(root); // Left-Left case
    }

    // Right-heavy
    if (bf < -1) {
        if (balanceFactor(root->right) > 0) {
            root->right = rotateRight(root->right); // Right-Left case
        }
        return rotateLeft(root); // Right-Right case
    }

    return root; // No imbalance
}

node* convertToAVL(node* root) 
{
    if (root == NULL) return NULL;
    return balanceTree(root);
}

void menu()
    {
    cout<<"\n\t***\n";
        cout<<"1. Add Node"<<endl;
        cout<<"2. Delete Node"<<endl;
        cout<<"3. Search Node"<<endl;
        cout<<"4. Get Max Node"<<endl;
        cout<<"5. Get Min Node"<<endl;
        cout<<"6. Get Size of Tree"<<endl;
        cout<<"7. Get Depth of Tree"<<endl;
        cout<<"8. Print PreOrder "<<endl;
        cout<<"9. Print inOrder "<<endl;
        cout<<"10. Print PostOrder "<<endl;
        cout<<"11. Target Level "<<endl;
        cout <<"12. Get Number of Edges" << endl; 
        cout <<"13. Is AVL" << endl; 
        cout <<"14. Is COMLPTE " << endl; 
        cout <<"15. Revers Tree " << endl;
        cout <<"16. Print ALL Path Tree " << endl; 
        cout <<"17. Convert Tree To AVL " << endl; 
        cout<<"0. Exit"<<endl;
            cout<<"\n\t***\n";

 }

void display( node*root)
{
    int op = -1;
    while(op != 0 )
    {
        menu();
        cout<<"Enter Option: ";
        cin>>op;
        switch(op)
        {
            case 1:
            {
                int val;
                cout<<"Enter Value: ";
                cin>>val;
                root = addnode(root, val); 
                break;
            }
            case 2:
            {
                int val;
                cout<<"Enter Value: ";
                cin>>val;
                del(val,root);
                break;
            }
            case 3:
            {
                int val;
                cout<<"Enter Value: ";
                cin>>val;
                cout<<serach(root,val);
                break;
            }
            case 4:
            {
                cout<<"Max Value: "<<getmax(root)<<endl;
                break;
            }
            case 5:
            {
                cout<<"Min Value: "<<getmin(root)<<endl;
                break;
            }
            case 6:
            {
                cout<<"Size of Tree: "<<sizeoftree(root)<<endl;
                break;
            }
            case 7:
            {
                cout<<"Depth of Tree: "<<treeDepth(root)<<endl;
                break;
            }
            case 8:
            {
                cout<<"\n\n\t *** \n";
                cout<<"PreOrder of Tree: ";
                cout<<"\n [LVR] [";
                print2(root);
                cout<<"]\n";
                cout<<"\n\n\t *** \n";

                break;
            }
            case 9:
            {
            cout<<"\n\n\t *** \n";
                cout<<"In Order of Tree: ";
            cout<<"\n [VLR] [";
                print1(root);
                cout<<"]\n";
                cout<<"\n\n\t *** \n";

                break;
            }
            case 10:
            {
                cout<<"\n\n\t *** \n";
                cout<<"Post Order of Tree: ";
                cout<<"\n [LRV] [";
                print3(root);  
                cout<<"]\n";
                cout<<"\n\n\t *** \n";
                break;
            }
            case 11:
            {
            const int maxNodes = 10; 
            int result[maxNodes];
            int index = 0,targetLevel;
            cout<<"Enter Target Level : ";cin>>targetLevel;
            traverseLevel(root, targetLevel, 0, result, index);
            cout << "Nodes at level [" << targetLevel << "] : ";
                for (int i = 0; i < index; i++) {
                    cout << result[i] << " ";
                }
                cout << endl;
            break;
            }
            case 12:  
            {
    cout << "Number of Edges : " << numberOfEdges(root) << endl;
    break;
}
            case 13:  
            {
    string AVL = isAVL(root) ? "[ IS AVL ]" : "[ Not AVL ]";
    cout << "AVL  : " << AVL << endl;
    break;
}
            case 14: 
            {
    string completeness = isCompleteTree(root) ? "[ IS COMPLETE ]" : "[ Not Complete ]";
    cout << "Completeness  : " << completeness << endl;
    break;
}
            case 15:  
            {
    invertTree(root);
    cout << " [ Revers DONE ] " << endl;
    break;
}
            case 16:  
            {
            cout << "Paths is Tree :" << endl;
            printPaths(root);
            break;
        }
            case 17:
            {
                root = convertToAVL(root);
                cout << "Tree has been converted to AVL" << endl;
                break;
            }
            case 0:
            {
                cout<<"Exiting..."<<endl;
                break;
            }
            default:
            {
                cout<<"Invalid Option"<<endl;
                break;
            }
        }
    }
}

int main() 
{ 
    node *root=NULL; 
    display(root);
    return 0; 
}