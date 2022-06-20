#include <iostream>

using namespace std;

#pragma region sample

class CCTest {
public:
	void setNumber(int);
	void printNumber() const;
private:
	int number;
};

void CCTest::setNumber(int num) { number = num; }

//On the line containing the const_cast, the data type of the this pointer is const CCTest *. 
//The const_cast operator changes the data type of the this pointer to CCTest *, 
//allowing the member number to be modified. The cast lasts only for the remainder of the statement in which it appears.

void CCTest::printNumber() const {
	cout << "\nBefore: " << number;
	const_cast<CCTest*>(this)->number--;
	cout << "\nAfter: " << number;
}

//int main() {
//	CCTest X;
//	X.setNumber(8);
//	X.printNumber();
//}



#pragma  endregion


