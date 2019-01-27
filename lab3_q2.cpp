#include<iostream>
using namespace std;

//class of nodes
class node{
	
	//type
	public:
		//data type
		int data;
		//pointer to the next node
		node*next;
		//constructor
		node(int value){
			next=NULL;
			data=value;
			
		}
};


//class of circular linked lists
class cirLL{
	
	//type
	public:
		
	    //	head->node type pointer
	    node*head;
		//constructor
		cirLL(){
			head=NULL;
		} 


//inserting elements
void insert(int value){
	
	node*temp= new node(value);
	if(head==NULL){
		head=temp;
	}
	else{
		node*current=head;
		while(current->next!=head)
		current=current->next;
		current->next=temp;
	    }
	    temp->next=head;
}

//display of elements
void display(){
	
	node*current=head;
	if(current==NULL){
		cout<<"no elements"<<endl;
		return;
	}
	while(current->next!=head){
	
	//stop at head
	cout<<current->data<<"->";
	current=current->next;
    }
    
    //printing the last element
    cout<<current->data;
    cout<<endl;
}
	
	


//to insert at a position
void insertAt(int value,int pos){
	node*current=head;

//reach position before the pos
int i=1;
while(i<pos-1){
	current=current->next;
	i++;
	
}
	node*temp=new node(value);
	temp->next=current->next;
	current->next=temp;
	
	}



//to delete at a position
void deleteAt(int pos){
	node*current=head;

//reach position before the pos
int i=1;
while(i<pos-1){
	current=current->next;
	i++;
	}
	node*temp; 
	temp=current->next;
	current->next=current->next->next;
	delete temp;
}
//to count the number of elements in the list
	void count(){
		node*current=head;
		
		if(head==NULL){
			cout<<"0"<<endl;
			
		}
		else{
			int i=1;
			while(current->next!=head){
			
				current=current->next;
					i++;
			}
		
		cout<<i<<endl;
	     }
	}
	
};

int main(){
	cirLL cl1;
	cl1.insert(1);
	cl1.insert(2);
	cl1.insert(3);
	cl1.insert(4);
	cl1.insert(5);
	cl1.display();
	cl1.insertAt(7,2);
	cl1.display();
	cl1.deleteAt(4);
	cl1.display();
	cl1.count();
	return 0;
}




