********   Linked List      **********


* A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations.

* The size of the arrays is fixed: So we must know the upper limit on the number of elements in advance. 
  Also, generally, the allocated memory is equal to the upper limit irrespective of the usage. 

* A linked list is represented by a pointer to the first node of the linked list. The first node is called the head. 
If the linked list is empty, then the value of the head points to NULL. 

* Each node in a list consists of at least two parts: 
  1) data (we can store integer, strings or any type of data).
  2) Pointer (Or Reference) to the next node (connects one node to another)
* In C/C++, we can represent a node using structures.


Structure OF Linked List
________________________________________________


    head part                                            tail part  
            
            
        +---+----+          +---+---+         +----+------+
        | 5 | o  |--------->| 8 | o |-------> | 2  | NULL |
        +---+----+          +---+---+         +----+------+ 
        ^       ^
        |       |
      Data      Pointer to next node.




OPERATIONS ON LINKED LIST........
________________________________________

* Traversal - access each element of the linked list.

* Insertion - adds a new element to the linked list.

* Deletion - removes the existing elements.

* Searching - find a node in the linked list.

* Sorting - sort the nodes of the linked list.

* Display list - Printing all the elements.

* Update - change the value of any node.

* Reverse the list - Reverse all the node by reversing pointer to the node.


FOUR TYPES OF LINKED LIST.........
__________________________________________

* Singly linked list.
* Circular linked list.
* Singly-Circular linked list.
* Doubly-Circular linked list.
