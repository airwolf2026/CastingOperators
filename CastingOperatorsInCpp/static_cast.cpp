#include <iostream>

using namespace std;

#pragma region sample1

// static_cast_Operator.cpp
// compile with: /LD
class B 
{
public:
	B(char b) 
	{ m_b = b; }

	void fun_in_base() { cout << "char in base class is :" << m_b << endl; }
	char m_b;
};

class D : public B 
{
public:
	D(char d):B(d) { m_d = d; }

	void fun_in_derived() { cout << "char in derived class is :" << m_d << endl; }
	char m_d;
};

void f(B* pb, D* pd) {
	D* pd2 = static_cast<D*>(pb);   // Not safe, D can have fields
									// and methods that are not in B.
	pd2->fun_in_derived();
	cout << "pd2's char is:" << pd2->m_d << endl;

	B* pb2 = static_cast<B*>(pd);   // Safe conversion, D always
									// contains all of B.


	std::cout << "In f function" << endl;
}

//int main()
//{
//	B b('B');
//	D d('D');
//	f(&b, &d);
//
//	std::cout << "In main";
//}

#pragma endregion


#pragma region sample2

// static_cast_Operator_2.cpp
// compile with: /LD /GR
class B_S2 {
public:
	virtual void Test() { cout << "fun in B_S2" << endl; }
};


class D_S2 : public B_S2 {
public:
	void Test_in_D_S2() { cout << "Test_in_D_S2" << endl; }

};

void f_S2(B_S2* pb) {
	D_S2* pd1 = dynamic_cast<D_S2*>(pb);
	D_S2* pd2 = static_cast<D_S2*>(pb);

	pd2->Test_in_D_S2();

	cout << "fun in f_S2" << endl;
}

int main()
{
	B_S2 bs2;
	f_S2(&bs2);

	D_S2 ds2;
	f_S2(&ds2);

	return 0;
}

#pragma  endregion


#pragma region sample3

#pragma  endregion


#pragma region sample4

#pragma  endregion



#pragma region sample5

#pragma  endregion