#include <iostream>
#include <vector>

using namespace std;

int main() {
	//create an integer vector with the size of 5 and print all elements of it
	vector <int> vect;

	vect.push_back(53);
	vect.push_back(42);
	vect.push_back(65);
	vect.push_back(13);
	vect.push_back(5);
	for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << endl;

  return 0;
}

