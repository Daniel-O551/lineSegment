#include "Line.h"

Line::Line(Point p1, Point p2) : startPoint(p1), endPoint(p2)
{
}

Line::Line(int _x1, int _y1, int _x2, int _y2) : startPoint(_x1, _y1), endPoint(_x2, _y2)
{
}

bool Line::inLineConditionIO()
{
	if ((this->startPoint.getX() == this->endPoint.getX()) || (this->startPoint.getY() == this->endPoint.getY()))
		return true;
	else
		return false;
}

void Line::getCoordinatesOnLine(vector<Point>& result, bool debugFlag)
{
	if (inLineConditionIO()){
        // Horizontal line
        if (this->startPoint.getY() == this->endPoint.getY()) {
            int minX = min(this->startPoint.getX(), this->endPoint.getX());
            int maxX = max(this->startPoint.getX(), this->endPoint.getX());
            for (int x = minX; x <= maxX; ++x) {
                result.push_back(Point(x, this->startPoint.getY()));
            }
        }
        // Vertical line
        else if (this->startPoint.getX() == this->endPoint.getX()) {
            int minY = min(this->startPoint.getY(), this->endPoint.getY());
            int maxY = max(this->startPoint.getY(), this->endPoint.getY());
            for (int y = minY; y <= maxY; ++y) {
                result.push_back(Point(this->startPoint.getX(), y));
            }
        }
	}
    else {
        if (debugFlag)
            cerr << "Ignored diagonal line , line:" << this->toString();
    }
}

string Line::toString(bool doNewLine) const
{
    ostringstream ost;
    ost << "(" << startPoint.toString(false) << ", " << endPoint.toString(false) << ")";
    if (doNewLine) ost << endl;
    return ost.str();
}

ostream& operator<<(ostream& outputStream, const Line& forwardedLine)
{
    outputStream << forwardedLine.toString();
    return outputStream;
}
