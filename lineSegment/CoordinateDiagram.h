#pragma once
#include <map>
#include <vector>
#include "Line.h"

using namespace std;

class CoordinateDiagram
{
	map<Point, int> coordinateSystem;
	int minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN;
public:
	// Default constructor
	CoordinateDiagram() = default;
	// Constructor with Point parameter
	CoordinateDiagram(Point p);
	// Constructor with Line parameter
	CoordinateDiagram(Line l);
	// Constructor with vector of Line parameter
	CoordinateDiagram(vector<Line> lineVector);
	// Returns the coordinateSystem map
	map<Point, int> getCoordinateSystem() const;
	// Add Point to diagram
	int addPointToDiagram(Point p);
	// Add Line to diagram
	void addLineToDiagram(Line l);
	// Add vector of Line to diagram
	void addLinesToDiagram(vector<Line> lineVector);
	// Converts the value of the coordinate to a char
	char coordinateValueToChar(int value) const;
	// Creates a string with the content of the diagram in the specified limits
	string toString(int tlx, int tly, int brx, int bry, bool doNewLine = true) const;
	// Creates a string with the content of the diagram in the default limits
	string toString(bool doNewLine = true) const;
	// Creates a string with the content of the diagram in the specified limits
	string toString(Point topLeft, Point buttomRight, bool doNewLine = true) const;
	// Output operator that sends the output of toString() directly to the respective stream
	friend ostream& operator<<(ostream& outputStream, const CoordinateDiagram& forwardedCoordinateDiagram);
};

