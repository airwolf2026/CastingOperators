#include <iostream>

using namespace std;

#pragma region sample

//One practical use of reinterpret_cast is in a hash function, 
//which maps a value to an index in such a way that two distinct values rarely end up with the same index

// Returns a hash code based on an address
unsigned short Hash(void* p) {
	unsigned int val = reinterpret_cast<unsigned int>(p);

	return (unsigned short)(val ^ (val >> 16));
}

using namespace std;
int main() {
	int a[20];
	for (int i = 0; i < 20; i++)
		cout << Hash(a + i) << endl;
}

#pragma  endregion

