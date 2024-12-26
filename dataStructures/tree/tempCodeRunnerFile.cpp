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


node *search(node *r,int v) 
{ 
    if(r==NULL || r->data==v) 
        return r; 
    else if(v<r->data) 
        return search(r->left,v); 
    else 
        return search(r->right,v); 
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

 void display( node*&root)
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
                addnode(root,val);
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
                node *result = search(root, val);
                if (result != NULL)
                    cout << "Node found: " << result->data << endl;
                else
                    cout << "Node not found" << endl;
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
                cout<<"PreOrder of Tree: ";
                print2(root);
                break;
            }
            case 9:
            {
                cout<<"In Order of Tree: ";
                print1(root);
                break;
            }
            case 10:
            {
                cout<<"Post Order of Tree: ";
                print3(root);  
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