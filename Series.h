#ifndef SERIES_H
#define SERIES_H
#include <iostream>
#include <string>
using namespace std;

class Series {
public:
	void geometricSeries();
	void p_Series();
	bool wholeNumber(double);

};
class Stack
{
private:
	double *data;	// stack itself
	int depth;	// number of elements
public:
	Stack(int size)
	{
		data = new double[size];
		depth = 0;
	}
	void push(double val)
	{
		data[depth++] = val;
	}
	double pop()
	{
		return data[--depth];
	}
	double top()
	{
		return data[depth];
	}
	bool empty()
	{
		return depth == 0;
	}
};

#endif
