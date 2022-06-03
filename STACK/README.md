#STACK

A stack is an Abstract Data Type (ADT) and it is a linear data structure in which all the insertion and deletion of data or you can say its values are done at 
one end only, rather than in the middle.
The same end which is called the "TOP" of the stack.

REAL-LIFE_EXAMPLE...

Let us suppose take the real-life example of a stack of plates or a pile of books etc. As the item in this form of 
data structure can be removed or added from the top only which means the last item to be added to the stack is the first 
item to be removed. So you can say that the stack follows the Last In First Out (LIFO) structure.
We can implement stack using Array as well as linked list.

APPLICATIONS...

The stack is mostly used in converting and evaluating expressions in Polish notations, i.e.:

	Infix
	Prefix
	Postfix
	
Stack Sturcture
     
		pop()  --->       <--- push()
				   
				.			.	<-- TOP 
				.			.
				.	 		.
				+-----------+
				| 			|
				+-----------+
				| 			|
				+-----------+
				| 			|
				+-----------+
				| 	200		|
				+-----------+
				| 	100		|	<-- index 0
				+-----------+
    

Basic Operations ...

	push() − Pushing (storing) an element on the stack.
	pop() − Removing (accessing) an element from the top of the stack.
	peek() − get the top data element of the stack, without removing it.
	isFull() − check if stack is full.
	isEmpty() − check if stack is empty.

