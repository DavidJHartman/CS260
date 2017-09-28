// make NO CHANGES to this file

#ifndef _COORDINATE_H_
#define _COORDINATE_H_

#include <iostream>

class Coordinate
{
public:
	Coordinate(int degrees, int minutes, int secondsTenths);
	Coordinate(void);		// default constructor
	~Coordinate(void);

	// print a coordinate
	friend std::ostream& operator<<(std::ostream& out, Coordinate& coord);

private:
	static const unsigned char		degreeChar{0xB0};
};

#endif // _COORDINATE_H_
