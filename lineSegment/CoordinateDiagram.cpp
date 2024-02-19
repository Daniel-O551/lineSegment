#include "CoordinateDiagram.h"

CoordinateDiagram::CoordinateDiagram(Point p)
{
	addPointToDiagram(p);
}

CoordinateDiagram::CoordinateDiagram(Line l)
{
	addLineToDiagram(l);
}

CoordinateDiagram::CoordinateDiagram(vector<Line> lineVector)
{
	addLinesToDiagram(lineVector);
}

map<Point, int> CoordinateDiagram::getCoordinateSystem() const
{
	return this->coordinateSystem;
}

int CoordinateDiagram::addPointToDiagram(Point p)
{
	if (p.getX() > maxX) maxX = p.getX();
	if (p.getY() > maxY) maxY = p.getY();
	if (p.getX() < minX) minX = p.getX();
	if (p.getY() < minY) minY = p.getY();

	return(++this->coordinateSystem[p]);
}

void CoordinateDiagram::addLineToDiagram(Line l)
{
	vector<Point> pointVector;
	l.getCoordinatesOnLine(pointVector);
	for (Point p : pointVector)
		addPointToDiagram(p);
}

void CoordinateDiagram::addLinesToDiagram(vector<Line> lineVector)
{
	for (Line l : lineVector)
		addLineToDiagram(l);
}

char CoordinateDiagram::coordinateValueToChar(int value) const
{
	if (value == 0)
		return '.';
	else if ((value > 0) && (value <= 9))
		return (value + '0');
	else {
		cerr << "Warning: Coordinate must be a positive value and maximum value is '9', got " << value;
		return '!';
	}
}

string CoordinateDiagram::toString(const int tlx, const int tly, const int brx, const int bry, bool doNewLine) const
{
	vector<vector<char>> matrix;
	matrix.resize(bry - tly + 2, vector<char>(brx - tlx + 1, '.'));
	unsigned int duplicatePoints = 0;
	for (const auto& entry : this->coordinateSystem) {
		const Point& p = entry.first;
		const int value = entry.second;
		if (value > 1) duplicatePoints++;
		matrix[p.getY() - tly][p.getX() - tlx] = coordinateValueToChar(value);
	}
	stringstream ost;
	ost << "Duplicate points: " << duplicatePoints << endl;
	ost << "Plotting diagram from (" << tlx << ", " << tly << ") to (" << brx << ", " << bry << ")" << endl;
	for (const auto& row : matrix) {
		for (char ch : row) {
			ost << ch;
		}
		ost << endl;
	}
	
	if (doNewLine) ost << endl;
	return ost.str();
}

string CoordinateDiagram::toString(bool doNewLine) const
{
	return toString(minX, minY, maxX, maxY, doNewLine);
}

string CoordinateDiagram::toString(Point topLeft, Point buttomRight, bool doNewLine) const
{
	return toString(topLeft.getX(), topLeft.getY(), buttomRight.getX(), buttomRight.getY(), doNewLine);
}

ostream& operator<<(ostream& outputStream, const CoordinateDiagram& forwardedCoordinateDiagram)
{
	outputStream << forwardedCoordinateDiagram.toString();
	return outputStream;
}
