//Arkadiusz Kulesza 
#include <iostream>
using namespace std;

struct node {//element listy
	int data;// struktura przechowuje dane typu int
	node* next;// wskaznik na nastepny element
	node* prev;//wskaznik na poprzedni element
};
class list {
private:
	node* head, * tail;
public:
	list() {
		head = NULL; //elementom przypisane sa wartosci NULL poniewaz nie dodalismy jeszcze zadnego elementu do listy
		tail = NULL;
	}
	//WSTAWIANIE ######################################
	void add_node_at_head(int value) {// dodawanie wartosci na poczatku listy
		node* temp = new node; // tymczasowa zmienna 
		temp->data = value;//przypisanie wartosci
		temp->next = NULL;//przypisanie wartosci NULL nastepnemu elementowi temp
		if (head == NULL) {// warunek wykonywany jesli naglowek a tym samym cala lista jest pusta
			head = temp;//przypisujemy watrosci naglowkowi i ogonowi
			tail = temp;
		}
		else {
			temp->next = head; //przypisanie wartosci naglowka jako element nastepujacy po zmiennej temp
			head->prev = temp; //przypisanie wartosci poprzedzajacej zmienna
			head = temp; //przypisanie naglowkowi wartosci zmiennej temp
		}
	}
	void add_node_at_tail(int value) {//dodanie wartosci na koncu listy 
		node* temp = new node;// reszta jest wykonana analogicznie jak w powyzszej funkcji
		temp->data = value;
		temp->next = NULL;
		if (tail == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
	}
	void insertAfter(node* prev_node, int new_data)
	{
		/*1. check if the given prev_node is NULL */
		if (prev_node == NULL)
		{
			cout << "the given previous node cannot be NULL";
			return;
		}

		/* 2. allocate new node */
		node* new_node = new node();

		/* 3. put in the data */
		new_node->data = new_data;

		/* 4. Make next of new node as next of prev_node */
		new_node->next = prev_node->next;

		/* 5. Make the next of prev_node as new_node */
		prev_node->next = new_node;

		/* 6. Make prev_node as previous of new_node */
		new_node->prev = prev_node;

		/* 7. Change previous of new_node's next node */
		if (new_node->next != NULL)
			new_node->next->prev = new_node;
	}
	void insertBefore(struct Node** head_ref, struct Node* next_node, int new_data)
	{
		/*1. check if the given next_node is NULL */
		if (next_node == NULL) {
			printf("the given next node cannot be NULL");
			return;
		}

		/* 2. allocate new node */
		struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

		/* 3. put in the data */
		new_node->data = new_data;

		/* 4. Make prev of new node as prev of next_node */
		new_node->prev = next_node->prev;

		/* 5. Make the prev of next_node as new_node */
		next_node->prev = new_node;

		/* 6. Make next_node as next of new_node */
		new_node->next = next_node;

		/* 7. Change next of new_node's previous node */
		if (new_node->prev != NULL)
			new_node->prev->next = new_node;
		/* 8. If the prev of new_node is NULL, it will be
		the new head node */
		else
			(*head_ref) = new_node;

	}

	//USUWANIE ######################################
	void delete_head() { // usuwanie wartosci z poczatku listy
		head = head->next; //"przewiniecie" naglowka
		if (head == NULL) {//jesli naglowek jest pusty usuwamy tez ogon
			tail = NULL;
		}
		else {
			head->prev = NULL;// wyczyszczenie wartosci poprzedzajacej naglowek
		}

	}
	void delete_tail() {//usuwanie wartosci z konca listy 
		tail = tail->prev;
		if (tail == NULL) {
			head = NULL;
		}
		else {
			tail->next = NULL;
		}

	}
	void deleteNodeAtGivenPos(struct Node** head_ref, int n)
	{
		/* if list in NULL or invalid position is given */
		if (*head_ref == NULL || n <= 0)
			return;

		struct Node* current = *head_ref;
		int i;

		/* traverse up to the node at position 'n' from
		   the beginning */
		for (int i = 1; current != NULL && i < n; i++)
			current = current->next;

		/* if 'n' is greater than the number of nodes
		   in the doubly linked list */
		if (current == NULL)
			return;

		/* delete the node pointed to by 'current' */
		deleteNode(head_ref, current);
	}


	//WYŚWIETLANIE ############################
	void display() {//wyswietlanie zawartosci listy 
		node* temp = head;//tymczasowa zmienna,przypisanie zmiennej wartosci naglowka

		while (temp != NULL) {//petla wypisujaca wszystkie wartosci do momentu az w liscie nie pozostanie zaden element
			cout << temp->data << " ";
			temp = temp->next;//"przewiniecie" listy
		}
		free(temp);
	}
};


int main()
{
	list lista;
	lista.add_node_at_head(1);
	lista.add_node_at_head(2);
	lista.add_node_at_tail(3);
	lista.add_node_at_tail(12);
	lista.display();
	cout << "\n";
	lista.add_node_at_tail(22);
	lista.add_node_at_head(5);
	lista.display();
	cout << "\n";
	lista.delete_head();
	lista.delete_tail();
	lista.display();
}
