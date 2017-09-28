#include <iostream>
#include <cstring>
#include "fire.h"

using namespace std;

const int		Fire::columnWidths[4] = { -1, -1, -1, -1 };

Fire::Fire(const District district, const char * const name,
	int latDeg, int latMin, int latSec, int longDeg, int longMin, int longSec)
{
	// your code here, or in this constructor's initialization list
}

Fire::Fire(const District district, const char * const name,
		   Coordinate latitude, Coordinate longitude)
{
	// your code here, or in this constructor's initialization list
}

Fire::~Fire()
{
	// your code here
}

void Fire::displayColumnHeadings(ostream& out)
{
	// your code here
}

std::ostream& operator<<(std::ostream& out, District district)
{
	// your code here

	return out;
}

ostream& operator<<(ostream& out, Fire* fire)
{
	// your code here

	return out;
}
