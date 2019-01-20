//Doubly linked list 

#include<iostream>
using namespace std;

//class node
class node{
	
    public:
    //data
	int data;
	//pointers
	node * next;
 	node * prev;
	//constructer 
 	node(int value){
		
		prev = NULL;
		next = NULL;
		data = value;
	}
};

class dLL{
	public:
	//pointers
	node * head;
	//constructer
	dLL(){
		head = NULL;
	}




// insert
void insert(int value){
//creation of node
node * temp = new node(value);

    //for a single node
    if(head==NULL)
	{
    head = temp;
    }
    
    //for multiple nodes
    else
	{
    node * current = head;
         while(current->next!=NULL)
		 {
         current=current->next;
         }
    current->next=temp;
    temp->prev=current;
    }
}




// insert at a position

void InsertAt(int pos ,int value){
node * current = head;
int i=1;
 
    //reach place before position
    while(i<pos-1){
    current=current->next;
    i++;
    }
    //create node
    node * temp = new node(value);
    
    

temp->next = current->next;
current->next = temp;
temp->prev = current;
temp->next->prev = temp;

}


// delete at position
void DeleteAt(int pos){
node * current = head;
int i=1;

   //reach place before position
   while(i<pos-1){
   current=current->next;
   i++;
   }
   
   

current->next = current->next->next;
current->next->prev->prev=current;
}



// Deletion of last element.
void Del(){

     node * current = head;
     node * temp; 
     
    if(head == NULL){}
    else if (head -> next == NULL){ head = NULL;}
    else{
    	
    //reach the place before position
     while(current->next->next != NULL){
     current=current->next;
     }
     
current->next = temp;
current->next=NULL;
delete temp;
}
};


// Count
void count(){
node * current = head;
int i;
      while(current!=NULL){
      current=current->next;
      i++;
}
cout<<i <<endl;
}


// display
void display(){

node * current = head;
node * last;
cout<<"Print ";
//loop
while(current!=NULL){
cout<<current->data<<"->";
//store current in last
last = current;
//move forward
current=current->next;
}
cout<<endl;
cout<<"Print in reverse order : ";
while(last!=NULL){
cout <<last->data<< "->";


            // Move backwards 
            last = last->prev;
		}
		cout << endl; 
}	};





int main(){
	dLL dll1;
	for(int i= 1; i < 10; i++){
        dll1.insert(i);
    }
	dll1.display();
	dll1.InsertAt(5,12);
	dll1.display();
	dll1.Del();
	dll1.display();	
	dll1.DeleteAt(6);
	dll1.display();
	dll1.count();
	
	return 0;
}


