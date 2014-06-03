//Linked List

#include<iostream>

using namespace std;

//Create new datatype (Node)
//each node contains data itself and pointer ot the next node
//next is of type node* (pointer to a node)
struct node{
    int x;
    node* next;
};


int main()
{
    cout<<"Output the number of values you wish to Store in a linked list \n";
    
    int num_var,next_value;
    cin>>num_var;
    
    //pointers to node
    node *root=NULL; //pointer to initial memory location
    node *conductor; //pointer to current node (as list is traversed)
    for (int i=0; i<num_var; i++)
    {
        cin>>next_value;
        if (i==0)
        {
            root =new node;
            
            //ptr->next is equivalent to (*ptr).next
            root->next=0; //set address of next node to 0. This means that there is no currently assigned next node
            root->x=next_value; //set data of node(the int) to 12
            conductor = root; //conductor points to first node
            
        }
        else
        {
            
        }
        
        
        
        
    }
    
    
    //use new if you want object to remain in existence until deleted.
    //Otherwise it gets destroyed when it goes out of scope
    //however it is more expensive to use new
    
    
    //traverse until you reach the last node in the list
    if (conductor!=0){
        while (conductor->next!=0)
            conductor = conductor -> next;
    }
    conductor->next = new node;
    conductor = conductor -> next;
    conductor->next=0;
    conductor->x = 42;
    
}