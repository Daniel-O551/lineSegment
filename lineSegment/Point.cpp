#include "Point.h"

Point::Point(int _x, int _y) : x(_x), y(_y)
{
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

string Point::toString(bool doNewLine) const
{
	ostringstream ost;
	ost << "(" << x << ", " << y << ")";
	if (doNewLine) ost << endl;
	return ost.str();
}

bool Point::operator==(const Point& other) const
{
	return x == other.x && y == other.y;
}

bool Point::operator<(const Point& other) const
{
	return x < other.x || (x == other.x && y < other.y);
}

ostream& operator<<(ostream& outputStream, const Point& forwardedPoint)
{
	outputStream << forwardedPoint.toString();
	return outputStream;
}