#TREE

Trees are one of the most interesting 'non-linear' data structures in Programming. Apart from having common names such as sibling, leaves, parent, children's, etc.,
to represent them, trees can be used to solve some of the most challenging problems in competitive programming.
Unlike linear data structures, such as stacks or lists, where elements are stored in linear order, non-linear data structures store elements hierarchically. 
Thus the traversal of a tree or graph cannot be completed in a single run.

                                     ------
                                     | 50 |
                                     ------
                                    /      \
                                  /          \
                             ------           ------
                             | 40 |           | 60 |
                             ------           ------
                           /      \           /     \
                         /          \       /         \
                     ------      ------    ------     ------
                     | 30 |      | 45 |    | 55 |     | 70 |
                     ------      ------    ------     ------

The elements inside the Blocks are called the nodes of the tree. A binary tree is a data structure where every node has at most two children.
The topmost node is called the root node. A node with no children is called a leaf.
** Here the root node is at 50 **
** The height of the tree is defined as the longest path from the root to a leaf. **
** In the above example, the height of the tree is 2.

#Types of Trees

    Full binary tree
    Complete binary tree
    Perfect binary tree
    Balanced binary tree
    Binary search tree
    
#C/C++ Sturcture of Trees using "struct"   

    struct node 
    {
      int data;         //store integer DATA
      struct node *left;          //Reference to left child
      struct node *right;         //Reference to right child
    };
    
    
    
