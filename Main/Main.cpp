#include <iostream>
#include <Windows.h>
using namespace std;
//Zadatak01
/*struktura pixel koja sadrži x,y koordinate te numerièki iznos složenosti puta do željene toèke*/
struct pixel {
	int x;
	int y;
	int weight;

	pixel(int x, int y, int w) {
		this->x = x;
		this->y = y;
		this->weight = w;
	}
};


int main() {

	setlocale(LC_CTYPE, "croatian");
	char two_dim_array[20][40];
	pixel pix_start(0, 0, 0), pix_destination(0, 0, 0), pix_count(0, 0, 0);

	/*unos koordinata*/
	cout << "A x-kooridnata: ";
	cin >> pix_start.x;
	cout << "A y-koordinata: ";
	cin >> pix_start.y;
	cout << "B x-kooridanta: ";
	cin >> pix_destination.x;
	cout << "B y-koordinata: ";
	cin >> pix_destination.y;

	cout << "Pregled toèaka: " << endl;

	for (unsigned short int i = 0; i < 20; i++) {
		for (unsigned short int j = 0; j < 40; j++) {
			if (j == pix_start.x && i == pix_start.y) {
				cout << "A";
				two_dim_array[i][j] = 'A';
			}
			else if (j == pix_destination.x && i == pix_destination.y) {
				cout << "B";
				two_dim_array[i][j] = 'B';
			}
			else {
				cout << "-";
				two_dim_array[i][j] = '-';
			}
		}
		cout << endl;
	}

	/*za svaki pojedini piksel izraèunaj složenost i pohrani koordinate te složenost u strukturu pix_count*/
	unsigned short int sum = 0;
	for (unsigned i = pix_start.x; i <= pix_destination.x; i++) {
		for (unsigned j = pix_start.y; j <= pix_destination.y; j++) {
			sum = 0;
			sum += (i - pix_start.x); sum += (j - pix_start.y);
			pix_count.x = i;
			pix_count.y = j;
			pix_count.weight = sum;
		}
	}

	/*Ispis koraka*/
	pix_count.x = pix_destination.x - pix_start.x;
	pix_count.y = pix_destination.y - pix_start.y;
	cout << "Koraka potrebno po x osi: " << pix_count.x << endl;
	cout << "Koraka potrebno po y osi: " << pix_count.y << endl;
	cout << "\n\n" << endl;
	cout << "\t\tIspis putanje\t\t" << endl;
	cout << "===================================================" << endl;
	/*Iscrtavanje najbrže putanje*/

	/*
	A
		B
	*/
	if (pix_count.x > 0 && pix_count.y > 0) {
		//red
		for (int i = pix_start.x; i < pix_destination.x; i++) {
			two_dim_array[pix_destination.y][i] = 'X';
		}

		//stupac
		for (int i = pix_start.y + 1; i <= pix_destination.y; i++) {
			two_dim_array[i][pix_start.x] = 'X';
		}
	}

	/*
		B
	A
	*/
	else if (pix_count.x > 0 && pix_count.y < 0) {
		//red
		for (int i = pix_start.x; i < pix_destination.x; i++) {
			two_dim_array[pix_destination.y][i] = 'X';
		}

		//stupac
		for (int i = pix_start.y - 1; i >= pix_destination.y; i--) {
			two_dim_array[i][pix_start.x] = 'X';
		}
	}

	/*
	B
		A
	*/

	else if (pix_count.x < 0 && pix_count.y < 0) {
		//red
		for (int i = pix_destination.x + 1; i <= pix_start.x; i++) {
			two_dim_array[pix_destination.y][i] = 'X';
		}

		//stupac
		for (int i = pix_destination.y + 1; i < pix_start.y; i++) {
			two_dim_array[i][pix_start.x] = 'X';
		}
	}

	/*
		B
	A
	*/
	else if (pix_count.x < 0 && pix_count.y > 0) {
		//red
		for (int i = pix_destination.x; i < pix_start.x; i++) {
			two_dim_array[pix_start.y][i] = 'X';
		}
		//stupac
		for (int i = pix_start.y; i < pix_destination.y; i++) {
			two_dim_array[i][pix_destination.x] = 'X';
		}
	}

	/*
	A	B
	*/
	else if (pix_count.y == 0 && pix_count.x > 0) {
		//red
		for (int i = pix_start.x + 1; i < pix_destination.x; i++) {
			two_dim_array[pix_start.y][i] = 'X';
		}
	}

	/*
	B	A
	*/
	else if (pix_count.y == 0 && pix_count.x < 0) {
		//red
		for (int i = pix_destination.x + 1; i < pix_start.x; i++) {
			two_dim_array[pix_destination.y][i] = 'X';
		}
	}

	/*
	A
	B
	*/
	else if (pix_count.x == 0 && pix_count.y > 0) {
		for (int i = pix_start.y + 1; i < pix_destination.y; i++) {
			two_dim_array[i][pix_start.x] = 'X';
		}
	}

	/*
	B
	A
	*/
	else {
		for (int i = pix_destination.y + 1; i < pix_start.y; i++) {
			two_dim_array[i][pix_start.x] = 'X';
		}
	}

	for (unsigned short int i = 0; i < 20; i++) {
		for (unsigned short int j = 0; j < 40; j++) {
			cout << two_dim_array[i][j];
		}
		cout << endl;
	}

	system("PAUSE");
}