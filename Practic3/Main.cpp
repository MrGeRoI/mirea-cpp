#include <iostream>

/*	Иерарихия:

	   A1

	B1 B2 B3

	  C1 C2
*/

#define CONSTRUCTOR

#define PRINT_VAR(VARNAME) std::cout << #VARNAME" = " << VARNAME << std::endl;

#define PRINT_FUNC(CLASSNAME) \
virtual void Print() \
{ \
	std::cout << #CLASSNAME << std::endl; \
} \

class A1
{
protected:
	int a1;

public:
	A1()
	{
		a1 = 1;
	}

	PRINT_FUNC(A1)

	virtual void Show()
	{
		PRINT_VAR(a1)
	}
};

class B1 : virtual public A1
{
protected:
	int b1;

public:
	B1() : A1()
	{
		b1 = 1;
	}

	PRINT_FUNC(B1)

	virtual void Show()
	{
		PRINT_VAR(a1)
		PRINT_VAR(b1)
	}
};

class B2 : virtual public A1
{
protected:
	int b2;

public:
	B2() : A1()
	{
		b2 = 1;
	}

	PRINT_FUNC(B2)

	virtual void Show()
	{
		PRINT_VAR(a1)
		PRINT_VAR(b2)
	}
};

class C1 : virtual public B1 ,virtual public B2
{
protected:
	int c1;

public:
	C1() : B1(), B2()
	{
		c1 = 1;
	}

	PRINT_FUNC(B2)

	virtual void Show()
	{
		PRINT_VAR(a1)
		PRINT_VAR(b2)
	}
};
int main()
{
	B1 b;
	b.Print();
	return 0;
}