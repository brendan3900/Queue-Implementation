//Brendan Li

#include <iostream>
using namespace std;

//AQueue, circular array
class AQueue {
private: //declaring private variables
    int QCapacity; // maz size of the queue
    int* items; //pointer to the array holding the queue's items
    int front; //index to front of queue
    int back; //index to back of queue
    int count; //number of items currently in queue

public:
    //class constructor
    AQueue(int c){
        //set QCapacity to given c, and create dynamic array
        QCapacity=c;
        items = new int[QCapacity];
        //inialize other variable defaults
        front=0;
        count=0;
        back=QCapacity-1;
    }

    //class destructor, deletes dynamic items
    ~AQueue(){
        delete items;
    }

    //returns true if the queue is empty
    bool isEmpty() const{
        return count==0;//return whether or not count == 0
    }

    //adds newItem to the back of the queue
    bool enqueue(const int newItem){
        //result boolean
        bool result = false;
        //if count isn't at the limit
        if(count<QCapacity){
            //update back
            back = (back+1)%QCapacity;
            items[back]=newItem;//add the new item to the back
            //update the count and the result bool
            count++;
            result=true;
        }
        return result;//return
    }

    //removes the item at the front of the queue
    bool dequeue(){
        //result boolean
        bool result = false;
        //if the queue is empty
        if(!isEmpty()){
            //update front
            front = (front+1)%QCapacity;
            //update count and result bool
            count--;
            result=true;
        }
        return result;//return
    }

    //returns the value of the item at the front of the queue
    int peekFront() const{
        return items[front];
    }
};


//PQueue, minheap data structure, Priority Queue
class PQueue {
private: //declaring private variables
    int QCapacity; // maz size of the queue
    int* items; //pointer to the array holding the queue's items
    int count; //number of items currently in queue
    //heapRebuild, transform semiheap rooted at rootIndex into minheap
    void heapRebuild(int rootIndex){
        //if the item is a leaf, nothing needs to be done
        if(rootIndex<=(((count-1)/2))&&rootIndex>=0){
            //keep track of smaller child index
            int smallerCI=2*rootIndex+1;
            //if the root has a right child
            if((2*rootIndex+2)<count){
                //then if the right child is less than the smaller, update index
                if(items[2*rootIndex+2]<items[smallerCI]){smallerCI=2*rootIndex+2;}
            }
            //if the root is greater than the index of the smaller child
            if(items[rootIndex]>items[smallerCI]){
                //swap and recursive call
                swap(items[rootIndex], items[smallerCI]);
                heapRebuild(smallerCI);
            }
        }
    }

public:
    //class constructor
    PQueue(int c){
        //set capacity to c, create dynamic array and set default count
        QCapacity=c;
        items = new int[QCapacity];
        count=0;
    }

    //class destructor
    ~PQueue(){
        delete items;//delete dynamic memory
    }

    //returns true if the queue is empty
    bool isEmpty() const{
        return count==0;//return whether or not count==0
    }

    //adds newItem to the back of the queue
    bool enqueue(const int newItem){
        //if the count is at the limit, return false already
        if(count==QCapacity){return false;}
        //set next item to the newItem
        items[count]=newItem;
        //set the newItem's index
        int newDataIndex=count;
        //boolean for while loop
        bool inPlace=false;
        int parentIndex;//index of the parent
        //while the index isn't 0 and not found place yet
        while((newDataIndex>0) && !inPlace){
            //find the parent index
            parentIndex=(newDataIndex-1)/2;
            //if the parent index is less than new, you found the place
            if(items[newDataIndex]>items[parentIndex]){inPlace=true;}
            //if not, swap the items and new index
            else{
                swap(items[newDataIndex], items[parentIndex]);
                newDataIndex=parentIndex;
            }
        }
        //update count and return
        count++;
        return true;
    }

    //removes the item at the front of the queue
    bool dequeue(){
        //copy last element to the root
        items[0]=items[count-1];
        //update the count
        count--;
        //rebuild the semi heap
        heapRebuild(0);
        return true;
    }

    //returns the value of the item at the front of the queue
    int peekFront() const{
        return items[0];
    }
};


//Test main function
int main() {
    int items[10] = { 90, 30, 20, 40, 50, 80, 70, 60, 10, 90 };
    int n = 10;
    AQueue myAQ(15);
    PQueue myPQ(15);
    for (int i = 0; i < n; i++){
        myAQ.enqueue(items[i]);
        myPQ.enqueue(items[i]); }
    cout << "1st round: Dequeuing the regular queue: ";
    while (!myAQ.isEmpty()) {
        cout << myAQ.peekFront() << "  ";
        myAQ.dequeue(); }
    cout << "\n1st round: Dequeuing the priority queue: ";
    while (!myPQ.isEmpty()) {
        cout << myPQ.peekFront() << "  ";
        myPQ.dequeue(); }
    for (int i = 0; i < n; i++) {
        myAQ.enqueue(2 * items[i]);
        myPQ.enqueue(2 * items[i]); }
    cout << "\n2nd round: Dequeuing the regular queue: ";
    while (!myAQ.isEmpty()) {
        cout << myAQ.peekFront() << "  ";
        myAQ.dequeue(); }
    cout << "\n2nd round: Dequeuing the priority queue: ";
    while (!myPQ.isEmpty()) {
        cout << myPQ.peekFront() << "  ";
        myPQ.dequeue();  }
    return 0;
}
