// =======================================================
// Your name: Alejandro Monje
// Compiler:  g++ 
// File type: headher file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t;  // elements will be **

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist          
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};   // thron when linked list underflows.
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //Purpose: returns true if Front and Rear are both NULL and Count is 0.
  // else it returns false.
  bool isEmpty();
    
  //Purpose: will check to see if the linked list is empty if it is then [ Empty ] will
  // be dispalyed else all the elements in the linked list will be displayed. 
  void displayAll();

  //Purpose: will check to see if it is empty. If it is empty them a new node will be made
  //else it will add to the front of the linked list.
  //Parameter: Provide the element to be added to the front 
  void addFront(el_t);
    
  //Purpose: will check to see if it is empty if it is then a new node will be made
  // else it will add to the rear of the linked list.
  //Parameter: Provide the element to be added to the rear
  void addRear(el_t);

  //Purpose: will check to see if the list is empty and if it is then it will throw an
  // underflow because there is nothing in the list. else if count == 1 meaning there is 
  // only one node then the front will be deleted else it will go to the front node and 
  // then delete it.
  //Parameter: provide a holder(OldNum) for the element and pass it by refrence.
  void deleteFront(el_t&);
    
  //Purpose: will check to see if it is empty and if it is throw an underflow. if there 
  // is only one node in the linked list than delete is else go to the rear and delete the
  // rear node
  //Parameter: provide a holder(OldNum) for the element and pass it by refrence.
  void deleteRear(el_t&);
    
  //Purpose: will check to see if bad values are entered if there are than throw 
  // outOfRange else if I is one then just call deleteFront. else if I is count then 
  // call deletRear else move the two pointer to the correct nodes and delete the ith node.
  //Parameters: int I and provide a holder(OldNum) for the element and paas by ref.
  void deleteIth(int, el_t&);

  //Purpose: will check to see if there are bad values entered if there are
  // then throw OutOfRange. else if I is 1 then call addFront else if I is count then just 
  // call addRear. else move two pointers to the correct nodes and add a node before the
  // ith node.
  //Parameter: int I and provide a holder(NewNum) for the element and pass by ref.
  void addbeforeIth(int, el_t);
    
};
