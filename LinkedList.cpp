//USING DEVC++ COMPILER
#include<iostream>

using namespace std;
template<typename T>
class Node
{
private:
    T data;
    Node<T>* next;
    Node<T>* prev;

public:

    Node()
    {
        next = NULL;
        prev = NULL;
    }
    Node(T val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
    T getData() {
        return data;
    }
    void setData(T data) {
        this->data=data;
    }
    Node* getNext() {
        return next;
    }
    void setNext(Node<T> *next) {
        this->next=next;
    }
    Node* getPre() {
        return prev;
    }
    void setPrev(Node<T> *prev) {
        this->prev=prev;
    }

};

template<typename T>
class DEDL_List{
	private:
    Node<T> *head;
    Node<T> *tail;
public:
    T addStart(T v);
    T addend(T v);
    T removestart();
    T removeend();
    T removesecondlast();
    void insertAtSpecificLocation(T d, int loc);
    void display();


};

template<typename T>
T DEDL_List<T>::addStart(T v)
{
    Node<T> *newNode=new Node<T>(v);


    if(head==NULL) {

		head=newNode;
        tail=newNode;
        head->setNext(NULL);
        tail->setNext(NULL);
        head->setPrev(NULL);
        tail->setPrev(NULL);

    }
    else {

        newNode->setNext(head);
        head->setPrev(newNode);
	    head =newNode;
	    head->setPrev(tail);
	    tail->setNext(head);
	    cout<<"Element inserted"<<endl;

    }

}
template<typename T>
void DEDL_List<T>::display()
{
   cout<<"Display method"<<endl;
   Node<T>*temp=head;
   do{
       cout<<temp->getData()<<endl;
       temp = temp->getNext();
   }while (temp!=tail);
   cout<<temp->getData()<<endl;
}



template<typename T>
T DEDL_List<T>::removestart()
{

    if (head==NULL) {
        cout<<"The list is empty"<<endl;
    }
    else
    {
        Node<T>* temp=head;
        Node<T>* newNode=new Node<T>;
        head = head->getNext();
        head->setPrev(tail);
        tail->setNext(head);
        tail->setPrev(newNode);

        return temp->getData();
        delete temp;


    }
}
template<typename T>
T DEDL_List<T>::addend(T v)
{
   Node<T> *newNode=new Node<T>(v);
    newNode->setData(v);

    if(head==NULL) {
        head=newNode;
        tail=newNode;
        newNode->setPrev(tail);
        newNode->setNext(head);
    }
    else
    {
        newNode->setPrev(tail);
        tail->setNext(newNode);
        newNode->setNext(head);
        head->setPrev(newNode);
        tail=newNode;

    }
    return newNode->getData();
}
template<typename T>
T DEDL_List<T>::removeend()
{
	Node<T>* temp= tail;
	if (head==NULL)
	{
		cout<<"List is empty";
	}
	else {
		tail= tail->getPre();
		tail->setNext(head);
		head->setPrev(tail);
		return temp->getData();
		delete temp;

	}
}

template<typename T>
T DEDL_List<T>:: removesecondlast(){

if(head==NULL || tail==NULL)
{
cout<<"Underflow"<<endl;
}
else if(head == tail && head->next == head)
{
     delete head;
     head = NULL;
     tail = NULL;
     cout<<"Deleted from End"<<endl;
}
else
{
   Node<T> *t = tail;
   tail->getPre()->getNext() = tail->getNext();
   head->getPre() = tail->getPre();
   tail = tail->next;
   return tail->getData();
   delete t;
}

}
template <typename T>
void  DEDL_List<T>:: insertAtSpecificLocation(T d, int loc)
	{

		Node<T>* node = new Node<T>(d);
		if (head == NULL)
		{
			head = node;
			tail = node;
			tail->setNext(head);
			head->setPrev(tail);
		}
		else if (loc == 1)
		{
			node->setNext(head);
			head->setPrev(node);
			head = node;
			tail->setNext(head);
			head->setPrev(tail);
		}
		else
		{
			int ctr = 0;
			Node<T>* curr = head;

			while (curr->getNext() != head)
			{
				ctr++;
				if (ctr == loc)
				{
					node->setNext(curr);
					node->setPrev(curr->getPre());
					Node<T>* temp = curr->getPre();
					temp->setNext(node);
					curr->setPrev(node);

					break;
				}
				curr->setPrev(curr);
				curr = curr->getNext();
			}
		}

}

class DEQUE_string{
private:
    DEDL_List<string> data;
    int size;
public:
     void enquene_front(string V) {
     	size++;
     	data.addStart(V);
	 }
     void enquene_back(string V) {
     	size++;
     	data.addend(V);
	 }
 	 string dequene_front() {
 	 	size--;
 	 	return data.removestart();
	  }
     string dequene_back() {
     	size--;
     	return data.removeend();
	 }
     string peak_front() {
     	 string peek = data.removestart();
     	 data.addStart(peek);
     	 return peek;
	 }
     string	peak_back() {
     	 string peek = data.removeend();
     	 data.addend(peek);
     	 return peek;
	 }
	 int getSize() {
	  return size;
	 }


};
int main() {
    DEDL_List<int> l1;


   l1.addStart(2);
   l1.addStart(3);
   l1.display();
   l1.removeend();
   l1.display();
   l1.addStart(8);
   l1.display();
   l1.removestart();
   l1.display();
   l1.addend(4);
   l1.display();
   l1.insertAtSpecificLocation(5,1);
   l1.display();


   DEQUE_string l2;



   cout<< "Size: " << l2.getSize();

  /* l2.enquene_front("Ayesha");
   l2.enquene_back("Aleem");

   cout << "Front: " << l2.peak_front() << endl;

   cout << "Back: " << l2.peak_back() << endl;*/





}
