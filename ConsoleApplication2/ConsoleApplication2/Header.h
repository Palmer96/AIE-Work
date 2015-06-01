#ifndef _HEADER_H
#define _HEADER_H


template < typename T >
T Add(T a, T b)
{
	return a + b;
}

template < typename T >
T Min(T a, T b)
{
	if (a < b)
		return a;
	else
		return b;

}

template < typename T >
T Max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;

}

template < typename T >
T Clamp(T Min, T Max, T val)
{
	if (val < Min)
		val = Min;
	else if (val > Max)
		val = Max;
	return val;
}

template < typename T >
T MinP(T* a, T* b)
{
	if (a < b)
		return a;
	else
		return b;

}

template < typename T >
T MaxP(T* a, T* b)
{
	if (a > b)
		return a;
	else
		return b;

}


/*
template < typename T >
class Container
{
public:

	T Constructor();
	T Deconstructor();
	T Add();
	T Expand();
	T Operator();

private:
	T m_heap[100];


};

template < typename T >
T Constructor()
{
	new T m_heap;
}
template < typename T >
T Deconstructor()
{
	delete T m_heap;
}
template < typename T >
T Add()
{

}
template < typename T >
T Expand()
{

}
template < typename T >
T Operator()
{

}
*/





#endif