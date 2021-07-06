#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;


    Node(){
        prev= next = NULL ;
    };
//    Node(int input){
//        data = input ;
//        Prev =Next = NULL ;
//
//    }
};
class LinkedList
{
private:
    Node *Head, *Tail;
    static int instanceSize ;
public :

    //initiate head and tail in order to know if linkedlist is empty or not
    LinkedList(){
        Head  = Tail = NULL ;
    }

    //create anew node in the heap instead of stack + initiate its values + returns it
    static Node* create(int data){
        Node* NodeObjAddress  ;
        NodeObjAddress  = new Node();
        NodeObjAddress->data = data ;
        return NodeObjAddress ;
    };

    //
    void add(Node *NodeObjAddress) {
        //check if linked list is empty
        if (Head == NULL && Tail ==NULL)
        {
          Head = Tail = NodeObjAddress ;
        }
        else{
            //we catch previous node by tail value so we change it in the very end of else block
            Tail->next = NodeObjAddress ;
            NodeObjAddress-> prev= Tail ;
            Tail = NodeObjAddress ;
        }

    }
    //displaying data member value of all node objects that are inside the linked list
    void displayData(){
        // we create a pointer carries the same address that  Head carry & we didn't use head itself to avoid changing it
        Node* iteratorPointer = Head ;

        //check if the next node of the current node equals null = check if the linked list is ended
        while(iteratorPointer != NULL )
            {
                cout<<endl<<iteratorPointer->data ;
                iteratorPointer =iteratorPointer->next;
            }
    }

    //searching for specified  data member value of in all node objects that are inside the linked list
    //like display but we only return nodes that meets the condition
    int calcInstanceSize(){
        Node* iteratorPointer = Head ;
        int instanceSize = 0 ;
        while (iteratorPointer != NULL)
            {
                instanceSize++ ;
                iteratorPointer = iteratorPointer->next ;

            }

        return instanceSize ;
    }

    //returns a pointer to array of pointers of all nodes available for instance in the linkedlist
    //so you can use it as an array for instance
    //notice : you must pass it apointer to array of pointers of node with the same size of the linkedlist
    //ex :Node * arr[x.calcInstanceSize()]
    Node** actAsArray(Node* arr[]){

        Node* iteratorPointer = Head ;
        int iteration = 0 ;
        while (iteratorPointer != NULL)
            {
                arr[iteration] = iteratorPointer;
                iteration++ ;
                iteratorPointer = iteratorPointer->next ;

            }
        return arr ;

    }
    // returns a linked list that have all nodes which thier data match the input
    LinkedList searchForList(int dataInp){
        LinkedList *matched = new LinkedList()  ;
        Node* iteratorPointer = Head ;

        while (iteratorPointer != NULL)
            {
                if(iteratorPointer->data == dataInp){

                       matched->add(LinkedList::create(dataInp));

                    }

                iteratorPointer = iteratorPointer->next ;
            }
            matched->displayData();

        return *matched;
    }

    //returns the first node that its data matches the input
    Node* Search(int data)
    {
        Node *current = Head;

        while(current != NULL)
        {
            if(current->data == data)
                return current;

            current = current->next;
        }

        return NULL;
    }
  // after you search for a node by its data, you can delete it
   void Delete (Node *deleted) {
        //if there was one node in the tree
        if(deleted == Head && deleted ==Tail)
            {
            Head=Tail =NULL ;
            }
        else if(deleted ==Tail){
            Tail = deleted->prev ;
            deleted->prev->next = NULL;
        }
        else if (deleted == Head){
            Head = deleted->next ;
            deleted->next->prev = NULL;
        }
        else
        {
            deleted->prev->next = deleted->next ;
            deleted->next->prev = deleted->prev ;

        }
    deleted->next = NULL;
    deleted->prev = NULL;
   }
   //reset linkedlist =delete all nodes on the linked list
   void deleteAll(){
       Node * iteratorNode = Head ;
      while(iteratorNode != NULL)  {
//        iteratorNode->data =
        iteratorNode->prev= NULL;
        Node* nextNode = iteratorNode->next ;
        iteratorNode->next  = NULL;
        Head = NULL ;
        iteratorNode = nextNode;
      }
        Tail =NULL ;
   }


    //insert after
    //display

};


int main()
{
    LinkedList x ;
   x.add(LinkedList::create(10));
   x.add(LinkedList::create(20));
   x.add(LinkedList::create(20));
//    x.displayData();
//    Node** ptr = x.search(20) ;
Node * arr[x.calcInstanceSize()] ;
Node **arrOfLinkedList = x.actAsArray(arr);
cout<<arrOfLinkedList[0]->data<<endl;

cout <<x.calcInstanceSize()<< endl;

LinkedList newList = x.searchForList(10);
cout <<newList.calcInstanceSize()<< endl;

Node * y =x.Search(20) ;
x.Delete(y);
x.displayData();
//y.displayData();
    return 0;
}
