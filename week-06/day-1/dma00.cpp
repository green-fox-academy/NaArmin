#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {

	int *pa = NULL;
	int *ps = NULL;
	string *pn = NULL;
	pa = new int;
	ps = new int;
	pn = new string;
	*pa = 33;
	*ps = 6;
	*pn = "Armin";
	cout << "My name is " << *pn << ", " << *pa << " years old, I can eat " << *ps << " pizza slices.";
	delete pa, ps , pn;

  return 0;
}

