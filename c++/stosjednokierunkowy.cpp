//Arkadiusz Kulesza 
#include <iostream>
#include <cassert>
using namespace std;

struct node { //element listy
	int data; // struktura przechowuje dane typu int
	node* next; // wskaznik na nastepny element 
};

class list
{
private:
	node* head, * tail; // utworzenie pierwszego (head) i ostatniego (tail) elementu listy
public:
	//konstruktor 
	list()
	{
		head = NULL; // elementom przypisane sa wartosci NULL poniewaz nie dodalismy jeszcze zadnego elementu do listy
		tail = NULL;
	}
	//DODAWANIE
	// funkcja dodajaca element na poczatek listy
	void createnode(int value) { 
		node* temp = new node; // rezerwowanie miejsca na element, temp wskazuje na pusty element node
		temp->data = value; // przypisanie wartosci, operator '->' odnosi sie do elementow skladowych obiektu temp
		temp->next = NULL; // przypisanie tymczasowej wartosci null nastepnemu elementowi temp

		if (head == NULL) { // warunek wykonywany jesli "nagłówek" a tym samym cała lista jest pusta
			head = temp; // przypisanie wartosci "naglowkowi" i "ogonowi"
			tail = temp;
		}
		else {// w innym wypadku przypisujemy wartosc tylko "ogonowi"
			tail->next = temp;
			tail = tail->next;
		}
	}

	//wstaw za węzeł
	void insertAfter(node* prev_node, int new_data) {
		if (prev_node == NULL) { 
			cout << "the given previous node cannot be NULL"; 
			return; 
		}
		node* new_node = new node();
		new_node->data = new_data;
		new_node->next = prev_node->next;
		prev_node->next = new_node; 
	}

	// wstaw na koniec
	void append( int new_data) {  
		node* new_node = new node(); 
		node* last = head; 
		new_node->data = new_data; 
		new_node->next = NULL; 
		if(head == NULL) { 
			head = new_node;       
			return; 
		} 
		while(last->next != NULL) 
			last = last->next; 
		last->next = new_node; 
		return; 
	}
	//USUWANIE
	// usuwanie "naglowka"
	void delete_node() { 
		node* temp = new node; //tymczasowa zmienna
		temp = head;// przypisanie zmiennej wartosci "naglowka"
		head = head->next; //"przewiniecie" wartosci (teraz naglowkiem jest druga wartosc)
		delete temp;// usuniecie danej wartosci
	}

	//
	void deleteNode(struct node** head_ref, int key)  { 
		// Store head node 
		struct node* temp = *head_ref, *prev; 
		// If head node itself holds the key to be deleted 
		if (temp != NULL && temp->data == key) { 
			*head_ref = temp->next; // Changed head 
			free(temp); // free old head 
			return; 
		} 
		// Search for the key to be deleted, keep track of the 
		// previous node as we need to change 'prev->next' 
		while (temp != NULL && temp->data != key) { 
			prev = temp; 
			temp = temp->next; 
		} 
		// If key was not present in linked list 
		if (temp == NULL) 
			return; 
		// Unlink the node from linked list 
		prev->next = temp->next; 
		free(temp); // Free memory  
	} 

	// usuwanie elementu o danym indeksie
	void deleteNode(struct node** head_ref, int position) { 
		// If linked list is empty 
		if (*head_ref == NULL) 
			return; 
		// Store head node 
		struct node* temp = *head_ref; 
		// If head needs to be removed 
		if (position == 0) {
			*head_ref = temp->next; // Change head 
			free(temp); // free old head 
			return; 
		} 
		// Find previous node of the node to be deleted 
		for (int i=0; temp!=NULL && i<position-1; i++) 
			temp = temp->next; 
		// If position is more than number of ndoes 
		if (temp == NULL || temp->next == NULL) 
			return; 
		// Node temp->next is the node to be deleted 
		// Store pointer to the next of node to be deleted 
		struct node *next = temp->next->next; 
		// Unlink the node from linked list 
		free(temp->next); // Free memory 
		temp->next = next; // Unlink the deleted node from list  
	}
	//SZUKANIE
	//szukanie iteracyjne
	bool search(node* head, int x)  { 
		node* current = head; // Initialize current 
		while (current != NULL) { 
			if (current->data == x) 
				return true; 
			current = current->next; 
		} 
		return false; 
	} 
	// GETTER 
	//zwracanie elementu o danym indeksie
	int GetNth(node* head, int index)  {
		node* current = head; 
		// the index of the  node we're currently looking at 
		int count = 0; 
		while (current != NULL) {  
			if (count == index) 
				return(current->data); 
			count++; 
			current = current->next; } 
		/* if we get to this line, the caller was asking 
		for a non-existent element  so we assert fail */
		assert(0);
	} 
	//DLUGOSC LISTY
	//Długość listy iteracyjnie
	int getCount(node* head)  { 
		int count = 0; // Initialize count 
		node* current = head; // Initialize current 
		while (current != NULL) { 
			count++; 
			current = current->next; 
		}
		return count; 
	} 
	//WYSWIETLANIE
	//wypisywanie wartosci listy
	void display() {
		node* temp = new node;//tymczasowa zmienna 
		temp = head;// przypisanie zmiennej wartosci "naglowka"
		while (temp != NULL) { // petla wypisujaca wszystkie wartosci do momenty az w liscie nie pozostanie zaden element 
			cout << temp->data << " ";
			temp = temp->next; //"przewiniecie" listy
		}
	}
};

int main()
{
	list lista;
	lista.createnode(1);
	lista.createnode(2);
	lista.createnode(3);
	lista.createnode(4);
	lista.display();
	lista.delete_node();
	cout << "\n";
	lista.display();
	lista.createnode(5);
	lista.delete_node();
	cout << "\n";
	lista.display();


}
