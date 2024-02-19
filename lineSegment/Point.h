#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Point
{
	int x;
	int y;
public:
	// Constructor with x and y parameters
	Point(int _x, int _y);
	// Get x value
	int getX() const;
	// Get y value
	int getY() const;
	// Returns a string with the content of the point
	string toString(bool doNewLine = true) const;
	// Compare two points used for sorting in maps
	bool operator==(const Point& other) const;
	bool operator< (const Point& other) const;
	// Output operator that sends the output of toString() directly to the respective stream
	friend ostream& operator<<(ostream& outputStream, const Point& forwardedPoint);
};