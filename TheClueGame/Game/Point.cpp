#include "Point.h"

//Constructor
Point::Point(int x, int y)		
{
	m_xc = x;
	m_yc = y;
}

//Copy Constructor
Point::Point(const Point& p)		
{
	m_xc = p.m_xc;					
	m_yc =p.m_yc;
}


void Point::inc_m_y()
{
	m_yc++;
}

void Point::dec_m_y()
{
	m_yc--;
}

void Point::inc_m_x()
{
	m_xc++;
}

void Point::dec_m_x()
{
	m_xc--;
}

Point Point::operator+(const Point& a) const
{
	return Point(m_xc + a.m_xc, m_yc + a.m_yc);
}

Point Point::operator-(const Point& a) const
{
	return Point(m_xc - a.m_xc, m_yc - a.m_yc);
}

Point& Point::operator+=(const Point& a)	
{
	m_xc += a.m_xc;							//add x cordinates
	m_yc += a.m_yc;							//add y cordinates
	return *this;
}

Point& Point::operator=(const Point& point)
{
	m_xc = point.m_xc;
	m_yc = point.m_yc;
	return *this;
}

//Compare between points
bool Point::operator<(const Point& point)const
{
	if (m_xc < point.m_xc && m_yc < point.m_yc)
		return true;
	return false;
}

//Chek Equality between points
bool Point::operator==(const Point& point)const
{
	if ((m_xc == point.m_xc) && (m_yc == point.m_yc))
		return true;
	return false;
}

int Point::get_x() const
{
	return m_xc;
}

int Point::get_y() const
{
	return m_yc;
}

void Point::print_point() const
{
	cout << "x:" << m_xc << endl;
	cout << "y:" << m_yc << endl;

}

ostream& operator<<(ostream& os, const Point& a)
{
	os << "("  << a.m_xc << "," << a.m_yc << ")";
	return os;
}

istream& operator >> (istream& is, Point& a)
{
	char c;
	is >> c >> a.m_xc >> c >> a.m_yc >> c;
	return is;
}
