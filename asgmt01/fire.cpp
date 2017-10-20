#include <iostream>
#include <cstring>
#include "fire.h"
#include "iomanip"

using namespace std;

const int		Fire::columnWidths[4] = { -1, -1, -1, -1 };

const char distName[][20] = {"Astoria", "Columbia_City", "Dallas", "Forest_Grove",
                         "Molalla", "Philomath", "Santiam", "Tillamook",
                         "Toledo"};

Fire::Fire(const District district, const char * const name,
	int latDeg, int latMin, int latSec, int longDeg, int longMin, int longSec) :
    district{district}, latitude{latDeg, latMin, latSec},
    longitude{longDeg, longMin, longSec}
{
    if (!name)
        this->name = new char{0};
    else{
        
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        
    }
}

Fire::Fire(const District district, const char * const name,
		   Coordinate latitude, Coordinate longitude) :
           district{district},  latitude{latitude},
           longitude{longitude}
{
    if (!name)
        this->name = new char{0};
    else{
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    }
	// your code here, or in this constructor's initialization list
}

Fire::~Fire()
{
    delete[] name;
}

void Fire::displayColumnHeadings(ostream& out)
{
    out << std::left <<  std::setw(25) << "name" << std::setw(15) << "district" <<
    std::setw(15) << "longitude" << std::setw(15) << "latitude" << std::endl;
    out << setw(25) << "----------------------";
    out << setw(15) << "-------------";
    out << setw(15) << "--------------";
    out << setw(15) << "-------------";
    
    out << std::endl; 
}

std::ostream& operator<<(std::ostream& out, District district)
{
    //out << district  << "\t\t";

	return out;
}

ostream& operator<<(ostream& out, Fire* fire)
{
    Coordinate longi = fire->getLongitude();
    Coordinate lati = fire->getLatitude();
    out << std::left << std::setw(25) << fire->getName() << std::setw(15) << distName[(int)fire->getDistrict()];
    out << longi  << lati;
	return out;
}
