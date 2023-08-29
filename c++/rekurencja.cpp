#include <iostream>
#include <graphics.h>

using namespace std;
void  swap(int& a, int& b) {
	int  temp = a;
	a = b;
	b = temp;
}
void  odwroc(int* tab,int  left,int  right) {
	if (left < right) {
		swap(tab[left], tab[right]);
		odwroc(tab, left + 1, right - 1);
	}
} 
int  szukaj_rec(int* tab, int  x, int  left, int  right) {
	if (left > right)
		return  -1;
	else {
		int  mid = (left + right) / 2;
		if (tab[mid] == x)
			return  mid;
		else if (x < tab[mid])
			return  szukaj_rec(tab, x, left, mid - 1);
		else
			return  szukaj_rec(tab, x, mid + 1, right);
	}
}
void  post_dw(unsigned  long int  n) {
	if (n != 0) {
		post_dw(n / 2);
		cout << n % 2;
	}
}
void  trojkaty(double  n, double  lg, double  x, double  y) {
	if (n > 0) {
		double  a = lg / n;
		double  h = a * sqrt(3) / 2.0;
		LineTo(x - a / 2.0, y - h);
		trojkaty(n - 1, lg - a, x - a / 2.0, y - h);
		LineTo(x + a / 2.0, y - h);
		for (double i = 1; i < n; i++) {
			lineto(x + (i - 1) * a / 2.0, y - (i + 1) * h);
			lineto(x + (i + 1) * a / 2.0, y - (i + 1) * h);
		}
		lineto(x,y);
	}
}
int  nwd(int  a, int  b) {
	if (b == 0)
		return  a;
	else
		nwd(b,a % b);
}
int silnia(int a) {
	for (int i = 5; i >= 1; i--) {
		a = a * i;
	}
	return a;
}
int  main() {
	//zad1
	int  tabl[8] = { 1,2,3,4,5,6,7,8 };
	for (int i = 0; i < 8; i++)
		cout << tabl[i] << " ";
	cout << endl;
	odwroc(tabl, 0, 7);
	for (int i = 0; i < 8; i++)
		cout << tabl[i] << " ";
	cout << endl;
	//zad4
	moveto(getmaxx() / 2, getmaxy()); 
	trojkaty(6, getmaxx() / 2, getx(), gety()); 
	getch();
	//zad5
	cout << " nwd(l2,3) = " << nwd(12,3) << endl;
	cout << "nwd(24,30) = " << nwd(24,30) << endl; 
	cout << "nwd(5,7) = " << nwd(5,7) << endl; 
	cout << " nwd(54,69) = " << nwd(54, 69) << endl;
}
