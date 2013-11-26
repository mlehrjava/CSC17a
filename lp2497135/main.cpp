#include <iostream>
#include "SimpleVector.h"

using namespace std;

int main(){
	SimpleVector <int> vector(10);
	cout << "Original vector: " << endl;
	for (int i = 0; i < 10; i++)
		vector[i] = i;
	vector.print();

	cout << "Vector after pop: " << endl;
	vector.pop();
	vector.print();

	cout << "Vector after push: " << endl;
	vector.push(15);
	vector.print();
	cin.get();
	return 0;
}