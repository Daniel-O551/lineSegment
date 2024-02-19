#pragma once
#include <sstream>
#include <vector>
#include "Point.h"

using namespace std;

class Line
{
	Point startPoint, endPoint;
public:
	// Constructor with Point parameters
	Line(Point p1, Point p2);
	// Constructor with x and y parameters
	Line(int _x1, int _y1, int _x2, int _y2);
	// Checks if the line either is vertical or horizontal
	bool inLineConditionIO();
	// Pushes the coordinates on the line into the result vector
	void getCoordinatesOnLine(vector<Point>& result, bool debugFlag=false);
	// Returns a string with the content of the line
	string toString(bool doNewLine = true) const;
	// Output operator that sends the output of toString() directly to the respective stream
	friend ostream& operator<<(ostream& outputStream, const Line& forwardedLine);
};

