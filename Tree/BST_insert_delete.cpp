/* BINARY SEARCH TREE (Properties) */

//The left subtree of a node contains only nodes with keys lesser than the node’s key.
//The right subtree of a node contains only nodes with keys greater than the node’s key.
//The left and right subtree each must also be a binary search tree.

//first we create BST (insertion) and then preforming deletion.
//Traversal :- InOrder , PreOrder , PostOrder.

#include<iostream>
using namespace std;

class BST {
    
    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;

    node* makeEmpty(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t)    // find min element in BST i.e left skewed last node
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t)    // find max element in BST i.e right skewed last node
	{
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t) 
	{
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node* t) 
	{
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }
    void preorder(node* t) 
	{
        if(t == NULL)
            return;
        cout << t->data << " ";
        inorder(t->left);
        inorder(t->right);
    }
    void postorder(node* t) 
	{
        if(t == NULL)
            return;
        inorder(t->left);
        inorder(t->right);
        cout << t->data << " ";
    }
    

    node* find(node* t, int x) 
	{
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(int x) {    //insertion
        root = insert(x, root);
    }

    void remove(int x) {     //deletion
        root = remove(x, root);
    }

    void display() {      //print InOrder traversal of BST.
    	cout<<"The InOrder traversal of BST : ";
        inorder(root);
        cout << endl<<"The preorder traversal of BST : ";
        preorder(root);
        cout<<endl << "The postorder traversal of BST : ";
        postorder(root);
        cout<<endl;
    }

    void search(int x) {    //searching in BST
        root = find(root, x);
    }
};

int main() 
{
	int n,x;
	char c;
    BST t;
    cout<<"Enter the no. of elements in BST : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
	    t.insert(x);
	}
	
	t.display();
	
    cout<<"Do you want to delete any elements ? (y/n)\n";
    cin>>c;
    while(c == 'y')
    {
   		cout<<"Enter data for deletion : ";
		cin>>x;
		t.remove(x);
		t.display();     
		cout<<"Do you want to delete Again? (y/n)";
		cin>>c;
	}
    	
    return 0; 
}
