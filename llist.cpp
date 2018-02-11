// ====================================================
//Your name: Alejandro Monje
//Complier:  g++
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

//Constructor
//- initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.  The new list is empty.
llist::llist()
{
  Front = NULL; // set Front to NULL
  Rear = NULL;  // set Rear to NULL
  Count = 0;    // set Count to 0
  cout << "...In the llist constructor: " << endl;
}

//Destructor  
//- while the list is not empty, call deleteFront repeatedly to delete all nodes.
//- Please place a cout in this function "calling the llist desctructor."
llist::~llist()
{
  el_t a;// a will be used to delete the elements
  while(!isEmpty())//while the linked list isnt empty it will keep deleting
    {
      deleteFront(a);//call deleteFront
    }
  cout << "...In the llist destructor: " << endl;// displays a message to show that
                                                   // the destructor was called
}

//Purpose: returns true if Front and Rear are both NULL and Count is 0.
// else it returns false.
bool llist::isEmpty()
{
  //  - return true if Front and Rear are both pointing to NULL and Count is 0.
  //  - (all 3 conditions must be checked)
  if(Front == NULL && Rear == NULL && Count == 0) //if all three conditions are met the list 
    {
    return true;                                  // is empty and will return true.
    }
  else
    {                       
      return false;                                //else return false
    }
  
}


void llist::displayAll()
{
  //- Special case: if the list is empty, display [ empty ] ).
  //- Regular: 
  // displays each element of the list horizontally starting from Front in [ ].
  if(isEmpty())//if it is Empty then display [ Empty ]
    {
      cout << " [ Empty ] " << endl;
    }
  else         //else  display all the elements in the linked list
    {
      Node *P = Front; //P points to front
      cout << "[ ";
      while( P != NULL )// while P doesn't equal NULL
	{
          cout << P -> Elem << " "; //display the element in P
          
	  P = P -> Next;     // move P to get to the next element
	}
      cout << "]" << endl;
    }
}


void llist::addRear(el_t NewNum) 
{
  //2 cases:
  // - Special case: if this is going to be the very first node, you must
  //   create a new node and make Front and Rear point to it. Place NewNum and
  //   Count is updated.
  // - Regular: adds a new node at the rear and puts NewNum in the Elem field
  //   of this new node. Count is updated.
  
  if (isEmpty())// special case) if it is empty
    {
      Front = Rear = new Node;//front and rear point to a new node
      Rear -> Elem = NewNum;// set rear's elem = Newnum
      Rear -> Next = NULL;// set rear's next to NULL
      Count++; // increment count
    }
  else
    {
      //Regular case:
      Rear -> Next = new Node;//add a new node to the very end
      Rear = Rear -> Next; //rear now points to that new node
      Rear -> Elem = NewNum; // set rear's elem = Newnum
      Rear -> Next = NULL; //set rear's next to NULL
      Count++;// increment Count
    }
}


void llist::addFront(el_t NewNum)
{
//2 cases:
//- Special case: if this is going to be the very first node, you must
//   create a new node and make Front and Rear point to it. Place NewNum and
//   Count is updated.
//- Regular: add a new node to the front of the list and 
//  Count is updated.
  if(isEmpty())// if it is empty
    {
      Front = Rear = new Node;//front and rear point to a new node
      Front -> Elem = NewNum;// set front's elem = Newnum
      Front -> Next = NULL;// set front's next to NULL
      Count++;//increment count
    }
  else
    {
      //Regular case:
      Node *x; //X points to a node cell
      x = new Node; // X now points to a new node
      x->Next = Front; // X's next points to front
      Front = x;  // front now points to x
      Front->Elem = NewNum;// front's elem = newNum
      Count++;// increment count
    }
}


void llist::deleteFront(el_t& OldNum)
{
  //3 cases:
  //- Error case: if the List is empty, throw Underflow
  //- Special case: if currently only one Node,
  //   give back the front node element through OldNum (pass by reference) and
  //   make sure both Front and Rear become NULL. Count is updated.
  //- Regular: give back the front node element through OldNum (pass by reference)
  //  and also removes the front node.  Count is updated.
  
  if(isEmpty())//error case) if its empty
    {
      throw Underflow(); //throw an underflow
    }
  else if(Count == 1)//special case) only one node
    {
      OldNum = Front -> Elem;//oldNum gets the fronts elem
      delete Front; // delete front
      Front = Rear = NULL; // front and rear equal NULL
      Count--;  //decrement count
    }
  else 
    {
      //Regular case:
      OldNum = Front -> Elem;// oldNum gets front' elem
      Node *Second; // second points to a node cell
      Second = Front -> Next;// second points to front's next
      delete Front; // delete front
      Front = Second; //front points to second
      Count--; // decrement count
    }
}


void llist::deleteRear(el_t& OldNum)
{
  //3 cases:
  //- Error case: if empty, throw Underflow
  //- Special case: if currently only one node,
  //  give back the rear node element through OldNum (pass by reference) and
  //  make sure both Front and Rear become NULL. Count is updated.
  //- Regular: give back the rear node element through OldNum (pass by reference)
  //  and also remove the rear node. Count is updated.
  
  
  Node *p;//P points to a node cell
  p = Front;
  //Make p go to the one right before rear (using while)
  //    delete Rear;
  if(isEmpty())//error case) if its empty
    {
      throw Underflow();// throw underflow
    }
  else if(Count == 1)//special case)// if only one node
    {
      OldNum = Rear -> Elem;//old num gets rear's elem
      delete Rear; // delete rear
      Front = Rear = NULL;// front and rear set to null
      Count--;//decrement NULL
      
    }
  else// else there is more than one node
    {
      OldNum = Rear -> Elem;// oldNum gets rear's elem
      while(p -> Next != Rear)//while P->next doesn't = rear
	{
	  p = p -> Next; // moves P to the node before rear
	}
      delete Rear;// delete rear
      Rear = p;// rear points to P
      Rear -> Next = NULL;//rear is set to null
      Count--;//decrement count
    }
  
  
}


void llist::deleteIth(int I, el_t& OldNum)
{
  //4 cases:
  //- Error case: 
  //  If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
  //- Special cases: this should simply call deleteFront when I is 1 or 
  // deleteRear when I is Count
  //- Regular: delete the Ith node (I starts out at 1).  Count is updated.
  //<see the template loops in the notes to move 2 pointers to the right nodes;
  //and make sure you indicate the purposes of these local pointers>
  if(I > Count || I < 1)//error case)// if bad value is entered
    {
      throw OutOfRange();//throws out of range
    }
  else if(I == 1)// if only one node
    {
      deleteFront(OldNum);//call deletefront
    }
  else if(I == Count)// if I is the == count
    {
      deleteRear(OldNum);// call deleterRear
    }
  else// the ith term  isnt the only node or the last
    {
      Node *P;//make P point to a node cell
      P = Front;//make P point to front
      for(int K = 1; K < I - 1; K++)//for loop that moves to the pos before ith
	{
	  P = P -> Next; //P keeps moving until before the ith position
	}
      Node *SP = P -> Next;// SP points to the ith term
      P -> Next = SP -> Next;// P points to the position after ith
      OldNum = SP -> Elem;// oldnum gets SP's elem
      delete SP;// delete SP
      Count--;// decrement count
    }
  
  
}     



void llist::addbeforeIth(int I, el_t newNum)
{
  //4 cases:
  //-  Error case:
  //   If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
  //-  Special cases: this should simply call addFront when I is 1 or addRear when
  //   I is Count+1
  //-  Regular: add right before the Ith node. Cout if updated.
  //<see the template loops in the notes to move 2 pointers to the right nodes
  //and make sure you indicate the purposes of these local pointers>
  
  if(I > (Count + 1) || I < 1)//error case) if a bad value is entered
    {
      throw OutOfRange();// throw an out of raange
    }
  else if(I == 1)// if only one node
    {
      addFront(newNum);// call addfront
    }
  else if(I == (Count + 1))// if I == count
    {
      addRear(newNum);// call addrear
    }
  else// else the ith isnt the only node and not the last
    {
      Node *P;// p points to a node cell
      P = Front;//P points to front
      for(int K = 1; K < I - 1; K++)// the for loop will move p to the postion
        {                            // before the ith
	  P = P -> Next;
        }
            // []  P[] [ith] []

      Node *SP = new Node;// SP points to a new node                            
      SP -> Next = P -> Next; //moves SP pointer to the ith term                        SP[]->
      P -> Next = SP; // p points to a new node that is now in front of ith        
      SP -> Elem = newNum; // SP -> elem gets NewNum
      Count++;// increment count
      
      
    }
}
