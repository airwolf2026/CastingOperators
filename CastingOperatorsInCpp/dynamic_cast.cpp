#include <iostream>

using namespace std;

#pragma region sample1

//If type - id is a pointer to an unambiguous accessible direct or indirect base class of expression, 
//a pointer to the unique subobject of type type - id is the result.For example :
// compile with: /c
class B { };
class C : public B { };
class D : public C { };

void f(D* pd) {
	C* pc = dynamic_cast<C*>(pd);   // ok: C is a direct base class
									// pc points to C subobject of pd
	B* pb = dynamic_cast<B*>(pd);   // ok: B is an indirect base class
									// pb points to B subobject of pd
}


#pragma  endregion


#pragma region sample2

//If type-id is void*, a run-time check is made to determine the actual type of expression. 
// The result is a pointer to the complete object pointed to by expression. For example:

class A_S2 { virtual void f() {}; };
class B_S2 { virtual void f() {}; };

void f_S2() {
	A_S2* pa = new A_S2;
	B_S2* pb = new B_S2;
	void* pv = dynamic_cast<void*>(pa);
	// pv now points to an object of type A

	pv = dynamic_cast<void*>(pb);
	// pv now points to an object of type B

	return;
	//typoraCracker
}

#pragma region sample3

//If the type of expression is a base class of the type of type-id, 
//a run-time check is made to see if expression actually points to a complete object of the type of type-id.
//If this is true, the result is a pointer to a complete object of the type of type-id. For example:

// dynamic_cast_3.cpp
// compile with: /c /GR
class B_S3 { virtual void f() {}; };
class D_S3 : public B_S3 { virtual void f() {}; };

void f() {
	B_S3* pb = new D_S3;  // unclear but ok
	B_S3* pb2 = new B_S3;

	D_S3* pd = dynamic_cast<D_S3*>(pb);   // ok: pb actually points to a D
	D_S3* pd2 = dynamic_cast<D_S3*>(pb2);   // pb2 points to a B not a D
}

#pragma  endregion

//int main()
//{
//	f_S2();
//
//	return 0;
//}

#pragma  endregion

