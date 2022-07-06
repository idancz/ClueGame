#ifndef  _Point_
#define  _Point_

#include <stdio.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW


class Point
{
private:
	int m_xc;
	int m_yc;
public:
	Point(int x=0,int y=0);									//constructor
	Point(const Point&);									//copy constructor
	Point operator+(const Point&)const;						//operator+
	Point& operator+=(const Point&);						//operator+=
	Point& operator=(const Point& );						//operator=
	bool operator<(const Point&)const;						//operator<
	bool operator==(const Point&)const;						//operator==
	int get_x() const;										//get x
	int get_y() const;										//get y
	void print_point() const;								//print point
	friend ostream& operator<<(ostream&, const Point&);		//operator<<
	friend istream& operator>> (istream&, Point&);			//operator>>
	Point operator-(const Point& a) const;					//operator-
	void inc_m_y();
	void dec_m_y();
	void inc_m_x();
	void dec_m_x();

};
#endif
