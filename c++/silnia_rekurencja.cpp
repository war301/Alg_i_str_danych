#include <iostream>
using namespace std;
int silnia(int n) {
	if (n == 0) {
		if (n <= -1)
			return 0;
		return 1;
	}
	else
		return n * silnia(n - 1);
}
void silniarek(int n) {
	int fact = 1;
	for (int i = 1; i <= n; i++) {
		fact = fact * i;
		cout <<"\n"<< "fact=" << fact;
	}
}
int tail_silnia(int n, int accumulator = 1) {
	if (n == 0)
		return accumulator;
	else
		return tail_silnia(n - 1, accumulator * n);
}
int factorial(int n) {
	int accumulator;
	return tail_silnia(n, accumulator = 1);
}
unsigned long int Fibo(int x){
	if(x < 2)
		return x;
	else
		return Fibo(x - 1) + Fibo(x - 2);
}
unsigned long int Fiboogo(int x,int a=0,int b=1) {
	if (x == 0)
		return a;
	if (x == 1)
		return b;
	return Fiboogo(x - 1,b,a+b);
}
unsigned long int Fiboogotest(int n) {
	return Fiboogo(n);
}
int main()
{
	int n;
	cout << "Enter a number:"<<"\n";
	cin >> n;
	cout << "silnia przy liczbie:" << silnia(n)<<"\n";
	cout << "silnia_rek :";
	silniarek(n);
	cout <<"\n"<< "n!=" << factorial(n);
	cout << "\n" << Fibo(n);
	cout <<"\n"<< Fiboogotest(n);
	return 0;
}
