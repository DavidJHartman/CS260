#include <iostream>
#include "coordinate.h"
#include "iomanip"

using namespace std;

Coordinate::Coordinate(int degrees, int minutes, int secondsTenths) :
    degrees{degrees}, minutes{minutes}, secondsTenths{secondsTenths}
{
	// your code here, or in this constructor's initialization list
}

Coordinate::Coordinate(void)
{
	// your code here, or in this constructor's initialization list
}

Coordinate::~Coordinate(void)
{
	// your code here
}

ostream& operator<<(ostream& out, Coordinate& coord)
{
	out << std::setw(3) << coord.degrees << coord.degreeChar
    << std::right << std::setw(3) << coord.minutes << "\' " << 
    std::setw(2) << std::right << (coord.secondsTenths/10) << "." <<
    (coord.secondsTenths-(coord.secondsTenths/10*10)) << "\""; 

	return out;
}
