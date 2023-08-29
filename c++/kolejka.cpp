
#include <iostream>
#include <stack>
using namespace std;

class MinHeap {

	int* harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap
public:

	// Constructor
	MinHeap(int capacity);

	// to heapify a subtree with the root at given index
	void MinHeapify(int);

	int parent(int i) { return (i - 1) / 2; }

	// to get index of left child of node at index i
	int left(int i) { return (2 * i + 1); }

	// to get index of right child of node at index i
	int right(int i) { return (2 * i + 2); };
	// to extract the root which is the minimum element
	int extractMin();

	// Decreases key value of key at index i to new_val
	void decreaseKey(int i, int new_val);

	// Returns the minimum key (key at root) from min heap
	int getMin() { return harr[0]; }

	// Deletes a key stored at index i
	void deleteKey(int i);

	// Inserts a new key 'k'
	void insertKey(int k);
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

void swap(int* x, int* y) { int temp = *x; *x = *y; *y = temp; }

void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] <
		harr[smallest])
		smallest = r;
	if (smallest != i){
		 swap(&harr[i], &harr[smallest]);
		 MinHeapify(smallest); }
}
void MinHeap::insertKey(int k)
{
	if (heap_size == capacity){
		 cout << "\nOverflow: Could not insertKey\n"; 
		 return; 
	}
		
	// First insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;
		
	 // Fix the min heap property if it is violated
	while (i != 0 && harr[parent(i)] > harr[i]){
		swap(&harr[i], &harr[parent(i)]); 
		i =parent(i); 
	}
}
void MinHeap::decreaseKey(int i, int new_val){
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i]){ 
		swap(&harr[i], &harr[parent(i)]); 
		i =parent(i); 
	}
}
int MinHeap::extractMin(){
	if (heap_size <= 0) return INT_MAX;
	if (heap_size == 1){ 
		heap_size--; return harr[0]; 
	}	
	 // Store the minimum value, and remove it from heap
	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MinHeapify(0);
	return root;
}
//##############################################kopcowanie
void heapify(int arr[], int n, int i){
	int largest = i; // Initialize largest as root
		int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
		{ swap(arr[i], arr[largest]);
		heapify(arr, n, largest); 
	}
}
void heapSort(int arr[], int n){
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i > 0; i--){
		swap(arr[0], arr[i]); heapify(arr, i,0); 
	}
}
//#######################################kalkulator
bool isOperand(char c)
{
	// If the character is a digit then it must
	// be an operand
	return isdigit(c);
}

double evaluatePrefix(string exprsn)
{
	stack<double> Stack;

	for (int j = exprsn.size() - 1; j >= 0; j--) {

		// Push operand to Stack
		// To convert exprsn[j] to digit subtract
		// '0' from exprsn[j].
		if (isOperand(exprsn[j]))
			Stack.push(exprsn[j] - '0');

		else {

			// Operator encountered
			// Pop two elements from Stack
			double o1 = Stack.top();
			Stack.pop();
			double o2 = Stack.top();
			Stack.pop();

			// Use switch case to operate on o1
			// and o2 and perform o1 O o2.
			switch (exprsn[j]) {
			case '+':
				Stack.push(o1 + o2);
				break;
			case '-':
				Stack.push(o1 - o2);
				break;
			case '*':
				Stack.push(o1 * o2);
				break;
			case '/':
				Stack.push(o1 / o2);
				break;
			}
		}
	}

	return Stack.top();
}

int main() {
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, n);
	for (int i=0; i < (sizeof(arr)/4); i++) {
		cout << " "<< arr[i];
	}
	//#######################################kalkulator
	string exprsn = "+9*26";
	cout << evaluatePrefix(exprsn) << endl;
	return 0;
}
