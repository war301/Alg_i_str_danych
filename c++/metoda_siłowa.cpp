#include <iostream>
#include <string.h>

using namespace std;
//#####################################################
int szukaj(char w[], char t[]) {
	int i = 0, j = 0, M = strlen(w), N = strlen(t);

	while ((j < M) && (i < N)) {
		if (t[i] != w[j]) {
			i -= j - 1;
			j = -1;
		}
		i++;
		j++;
	}
	if (j == M)
		return i - M;
	else
		return -1;
}
//#####################################################
const int K = 26 * 2 + 2 * 2 + 1;// znaki ASCII + polskie litery + odstęp
int shift[K];
//-------------------------------------------------------
int indeks(char c) {
	switch (c) {
		/* //obsuga polskich znakow
	  case ' ':return 0;      	// odstep=0
	  case 'ę':return 53;
	  case 'Ę':return 54;     	// polskie litery
	  case 'ł':return 55;
	  case 'Ł':return 56;     	// itd. dla pozostałych polskich liter
	   */
	default:
		if (islower(c)) 		// czy c jest mala litera alfabetu
			return c - 'a' + 1;
		else
			return c - 'A' + 27;
	}
}
//-------------------------------------------------------
void init_shifts(char w[]) {
	int M = strlen(w);
	for (int i = 0; i < K; i++)
		shift[i] = M;
	for (int i = 0; i < M; i++)
		shift[indeks(w[i])] = M - i - 1;
}

//-------------------------------------------------------
int bm(char w[], char t[]) {

	init_shifts(w);

	int i, j, N = strlen(t), M = strlen(w);
	for (i = M - 1, j = M - 1; j >= 0; i--, j--)
		while (t[i] != w[j]) {
			int x = shift[t[i]];
			if (M - j > x)
				i += M - j;
			else
				i += x;
			if (i >= N)
				return -1;
			j = M - 1;
		}
	return i + 1;
}
//#####################################################
const long p = 33554393;
const int b = 64;

int rk(char w[], char t[]) {
	unsigned long i, bM_1 = 1, Hw = 0, Ht = 0, M = strlen(w), N = strlen(t);
	for (i = 0; i < M; i++) {
		Hw = (Hw * b + indeks(w[i])) % p;
		Ht = (Ht * b + indeks(t[i])) % p;
	}

	for (i = 1; i < M; i++)
		bM_1 = (b * bM_1) % p;
	for (i = 0; Hw != Ht; i++) {
		Ht = (Ht + b * p - indeks(t[i]) * bM_1) % p;
		Ht = (Ht * b + indeks(t[i + M])) % p;
		if (i > N - M)
			return -1;
	}
	return i;
}

int main() {
	char g[] = "abrakadabra", w[] = "rak";
	cout << szukaj(w, g) << endl;
	cout << szukaj((char*)"mrakadabra", g) << endl;
	cout << "//#####################################################"<<"\n";
	char t[] = "Z pamietnika mlodej lekarki";
	cout << "Z pamietnika mlodej lekarki" << endl;
	cout << "012345678901234567890123456789" << endl;
	cout << "Wynik poszukiwan slowa 'lek'=" << bm((char*)"lek", t) << endl;
	cout << "Wynik poszukiwan slowa \'er\'=" << bm((char*)"er", t) << endl;
	cout << "Wynik poszukiwan slowa \'kir\'=" << bm((char*)"kir", t) << endl;
	cout << "Wynik poszukiwan calego zdania=" << bm((char*)"Z pamietnika mlodej lekarki", t) << endl;
	cout << "//#####################################################"<<"\n"
		;
	char j[] = "Z pamietnika mlodej lekarki";
	cout << "Wynik poszukiwan=" << rk((char*)"lek", (char*)j) << endl;


	return 0;
}

