#include <iostream>
using namespace std;
void bubble(int tab[]) {
	int n = sizeof(tab);
	for(int i = 1; i < n;i++)
		for(int j = n - 1; j >= i; j--)
			if(tab[j] < tab[j - 1])  { 
				int tmp=tab[j-1];
				tab[j-1]=tab[j];
				tab[j]=tmp;
			}
}
//#################################################
void InsertSort(int tab[]) {
	int n = sizeof(tab);
	for(int i = 1; i < n; i++)  {
		int j = i; 
		int temp=tab[j];
		while ((j>0) && (tab[j-1]>temp)) {
			tab[j]=tab[j-1];
			j--;
		}
		tab[j]=temp;
	}
}
//#################################################
// Swap two elements - Utility function  
void swap(int* a, int* b) 
{ int t = *a; 
*a = *b; 
*b = t;} 
// partition the array using last element as pivot
int partition (int arr[], int low, int high) 
{  int pivot = arr[high];    // pivot 
	int i = (low - 1);   
for (int j = low; j <= high- 1; j++) 
{  //if current element is smaller than pivot, increment the low element
   //swap elements at i and j
	if (arr[j] <= pivot) 
	{  i++;    // increment index of smaller element 
	swap(&arr[i], &arr[j]); } } 
swap(&arr[i + 1], &arr[high]); 
return (i + 1); } 
//quicksort algorithm
void quickSort(int arr[], int low, int high) 
{ if (low < high) 
{  //partition the array 
	int pivot = partition(arr, low, high); 
	//sort the sub arrays independently 
	quickSort(arr, low, pivot - 1); 
	quickSort(arr, pivot + 1, high);   } } 
void displayArray(int arr[], int size)
{     int i; 
	for (i=0; i < size; i++) 
	cout<<arr[i]<<"\t"; } 
//#################################################
const int N = 10; 
int T1[N] = { 4, 6, 4, 12, -3, 6, -6, 1, 8, 50 }; 
int T2[N];  // Tablica pomocnicza
void merge(int left, int mid, int right) {
	int i,j,k;
	for (i=left; i<=right; i++) 
		T2[i]=T1[i];  
	i=left; j=mid+1; k=left;  
	while (i<=mid && j<=right) {
		if (T2[i]<T2[j])
			T1[k++]=T2[i++];
		else
			T1[k++]=T2[j++];
	}
	while (i<=mid) T1[k++]=T2[i++];
}
void MergeSort(int left, int right) { 
	int mid; 
	if(left < right) { 
		mid = (left + right) / 2;       
		MergeSort(left, mid); 
		MergeSort(mid + 1, right);  
		merge(left, mid, right); } }
//#################################################
void kopiec(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		kopiec(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		kopiec(arr, n, i);
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		kopiec(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}
//#########################################
int main() 
{   int arr[] = {12,23,3,43,51,35,19,45}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
	cout<<"Input array"<<endl;
	displayArray(arr,n);
	cout<<endl;
	quickSort(arr, 0, n-1); 
	cout<<"Array sorted with quick sort"<<endl; 
	displayArray(arr,n); 
	//#########################################
	cout << "\n"<<"##########################" << "\n";

	int a[] = {4,3,2,1};
	cout << sizeof(a) << "\n";
	//sortowanieprzezpodstawianie
	//bubble(a);
	InsertSort(a);
	cout << sizeof((int)a) << "\n";
	for (int i = 0; i < sizeof((int) a); i++)
	{
		cout << a[i]<<"\n";
	}

	//#########################################
	cout << "\n" << "##########################" << "\n";
	int i, x; 
	cout << "Przed sortowaniem:\n"; 
	for(i = 0; i < N; i++) 
		cout << T1[i] << " "; 
	cout << endl; 
	MergeSort(0, N - 1); 
	cout << "Po sortowaniu:\n"; 
	for(i = 0; i < N; i++) 
		cout << T1[i] << " ";
	cout << endl; 

	//#########################################
	cout << "\n" << "##########################" << "\n";
	int arr1[] = { 2,3,5,4,1 };
	int n1 = sizeof(arr1) / sizeof(arr1[0]);

	heapSort(arr1, n1);

	cout << "Sorted array is \n";
	printArray(arr1, n1);
	
}

