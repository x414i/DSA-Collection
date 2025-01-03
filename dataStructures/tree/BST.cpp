#include <iostream> 
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


//find the size of the tree 
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


node *getmin(node *r) 
{ 
   // node *t=r; 
    while(r->left!=NULL) 
        r=r->left; 
 
    return r; 
} 

node *del(int v,node *r) 
{ 
    if(r==NULL) 
        return r; 
    else if(v<r->data) 
        r->left=del(v,r->left); 
    else if(v>r->data) 
        r->right=del(v,r->right); 
    else if(r->left==NULL && r->right==NULL) 
    { 
        free(r); 
        return NULL; 
    } 
    else if(r->left==NULL) 
    { 
        node *t=r->right; 
        free(r); 
        return t; 
    } 
 
    else if(r->right==NULL) 
    { 
        node *t=r->left; 
        free(r); 
        return t; 
    } 
 
    else { 
        node *t=getmin(r->right); 
        r->data=t->data; 
        r->right=del(t->data,r->right); 
    } 
 
    return r; 
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
        cout<<"0. Exit"<<endl;
            cout<<"\n\t***\n";

 }

void traverseLevel(node* root, int targetLevel, int currentLevel, int result[], int& index) {
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