#include <iostream>
#include <list>
using namespace std;
//##############################podejście rekurencyjne
int binarySearchrek(int arr[], int l, int r, int x) {
	if(r >= l) {
		int mid = l + (r - l) / 2; 
		if(arr[mid] == x) 
			return mid; 
		if(arr[mid] > x) 
			return binarySearchrek(arr, l, mid - 1, x); 
		// Else 
		return binarySearchrek(arr, mid + 1, r, x); 
	} 
	// We reach here when element is not present in array 
	return -1; 
} 
//##############################podejście iteracyjne
int binarySearchite(int arr[], int l, int r, int x){
	while(l <= r) { 
		int m = l + (r - l) / 2; 
		if(arr[m] == x) 
			return m; 
		if(arr[m] < x) 
			l = m + 1; 
		else
			r = m - 1; 
	} 
	// if we reach here, then element was not present 
	return -1; 
}
//#############################funkcja haszująca
int hash(const string& key, int max){
	int hashVal = 0; 
	for(int i = 0; i < key.length();  i++) { 
		hashVal += key[i]; 
	}
	hashVal %= max; 
	return hashVal; 
}
//#############################tablice haszująca
class Hash { 
	int BUCKET; // No. of buckets 
	// Pointer to an array containing buckets 
	list<int> *table; 
	public: 
	Hash(int V); // Constructor 
	// inserts a key into hash table 
	void insertItem(int x); 
	// deletes a key from hash table 
	void deleteItem(int key); 
	// hash function to map values to key 
	int hashFunction(int x) { 
		return (x % BUCKET); 
	} 
	void shrItem(int key);
	
	void displayHash();  
};
//############################konstruktor
Hash::Hash(int b) { 
	this->BUCKET = b; 
	table = new list<int>[BUCKET]; 
}
//#############################wstawianie elementów 
void Hash::insertItem(int key) { 
	int index = hashFunction(key); 
	table[index].push_back(key); 
}
//#############################usuwanie elementów
void Hash::deleteItem(int key) { 
	int index = hashFunction(key); 
	list <int> ::iterator i; 
	for(i = table[index].begin();i != table[index].end(); i++) { 
		if(*i == key) 
			break; 
	} 
	if(i != table[index].end()) 
		table[index].erase(i); 
}
//#############################wyświetlanie zawartości listy 
void Hash::displayHash() { 
	for(int i = 0; i < BUCKET; i++) { 
		cout << i; 
		for(auto x : table[i]) 
			cout << " --> " << x; 
		cout << endl; 
	} 
}
//#############################wyszukiewanie elementów
void Hash::shrItem(int key) {
	int index = hashFunction(key);
	list <int> ::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++) {
		if (*i == key)
			cout <<"Znalazlem liczbe:"<< *i<<"\n";
			break;
	}
}
int main()
{
	//#############################tablica haszująca
	int a[] = { 15, 11, 27, 8, 12 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	Hash h(7); 
	for(int i = 0; i < n; i++) 
		h.insertItem(a[i]); 
	h.deleteItem(12); 
	h.shrItem(11);
	h.displayHash(); 
	return 0; 
}

