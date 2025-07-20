// Projekt.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "Projekt.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	int* tablica;
	Arrays::create(tablica, 5, 10);
	Arrays::print(tablica, 5);
	cout << "\n";
	delete[] tablica;
}
