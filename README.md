# Queue-Implementation
This program implements a regular FIFO queue using a circular array (AQueue Classe) as well as a priority queue using a minheap (PQueue Class).


Summary of Approach

---->AQueue Class: 
To create the AQueue class, the private attributes were created first. This includes the QCapacity, items, front, back, and count (all int values except items is int*). Next, the public components of this class were created: 
   First the class constructor was created, which took an int value as a parameter. This constructor initializes the queue attributes and dynamically creates the empty items       array to the proper size. The QCapacity attribute was set to the input parameter. 
  
   Next, the class destructor was created, which deletes the memory allocated to the items array. 
  
   Next, the isEmpty() function was created. This is a bool function that returns true if the queue is empty and false if the queue is not empty. 
  
   Next, the enqueue(const int newItem) function was created. This function takes a const int as a parameter and adds the input parameter to the back of the queue, as long as       the queue isn’t at its capacity. To do this, an if statement was used to compare the count and QCapacity; if the condition was met, back and count were updated the new item     was added to the back index of the queue. 
  
   Next, the dequeue() function was created. This function removes the item at the front of the queue. To do this an if statement was used to make sure the queue wasn’t already     empty; if this condition was met, front was moved up a place and the count was decremented. 
  
   Finally, the peekFront() function was created. This function returns the value of the item at the front of the queue. 

---->PQueue Class: 
To create the PQueue class, the private attributes were created first. This includes the QCapacity, items, and count (all int values except items is int*). Additionally, a private function called heapRebuild(int rootIndex) was created. This function transforms a semiheap rooted at the input parameter into a minheap structure. Next, the public components of this class were created: 
   First, the class constructor was created, which took an int value as a parameter. This constructor initializes the queue attributes and dynamically creates the empty items       array to the proper size. The QCapacity attribute was set to the input parameter. 
  
   Next, the class destructor was created, which deletes the memory allocated to the items array. 
  
   Next, the isEmpty() function was created. This is a bool function that returns true if the queue is empty and false if the queue is not empty. 
  
   Next, the enqueue(const int newItem) function was created. This function takes a const int as a parameter and adds the input parameter to the correct location in the queue,     as long as the queue isn’t at its capacity. To do this a while loop was used; as long as the place of the new item isn’t already correct and the new item’s index is greater     than the root, the while loop will keep going. As a result, the new item is placed in the correct order of this priority queue. 
  
   Next, the dequeue() function was created. This function removes the item at the front of the queue. To do this, the last element is copied to the root, the count is updated,     and the heapRebuild function is invoked. 
  
   Finally, the peekFront() function was created. This function returns the value of the item at the front of the queue. 
