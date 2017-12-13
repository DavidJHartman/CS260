#include "gcs.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

GCS::GCS(char const * const name)
{
    this->name = new char[ strlen(name) + 1 ];
    strcpy(this->name, name);
}

GCS::~GCS()
{
    delete[] name;
}

GCS& GCS::operator=(const GCS& gcs)
{
	return *this;
}

GCS::GCS(const GCS& source)
{
    this->name = new char[ strlen(source.name) + 1 ];
    strcpy(this->name, source.name);
}

void GCS::setName(char const * const name)
{
    this->name = new char[ strlen( name ) ];
    strcpy( this->name, name );
}

bool operator<(const GCS& gcs1, const GCS& gcs2)
{
    int result =  strcmp(gcs1.name, gcs2.name);

    if ( result < 0 )
        return true;
	return false;
}

bool operator==(const GCS& gcs1, const GCS& gcs2)
{
    int result = strcmp(gcs1.name, gcs2.name);

    if ( result == 0 )
        return true;
    return false;
}

ostream& operator<<(ostream& out, const GCS& gcs)
{
    out << gcs.name;
	return out;
}
