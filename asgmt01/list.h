// make NO CHANGES to this file

#ifndef _LIST_H_
#define _LIST_H_

#include <ostream>
#include "fire.h"

class List
{
public:
	static const char	YOUR_NAME[];	// used for printing out programmer's name

	List(void);				// constructor
	virtual ~List(void);	// destructor

	// Print out the fires in alphabetical order by name,
	// by calling Fire's operator<< for each fire.
	void displayByName(std::ostream& out) const;

	// Print out the fires by district,
	// by calling Fire's operator<< for each fire
	// (PREMIUM: and by name within district).
	void displayByDistrict(std::ostream& out) const;

	// Insert a fire into both the names and districts threads.
	// The names thread should be in alphabetical order by name.
	// The district thread should be in order alphabetically by
	// district name (PREMIUM: and within that by fire name).
	void insert(const Fire& fire);

	// Return a const pointer to the fire instance it finds in
	// the list, or nullptr if it didn't find a fire with that name.
	// Because the pointer is declared const, there is no danger
	// that find's caller will be able to use the returned pointer
	// to change the instance of fire.
	Fire* const find(const char * const name) const;

	// Remove the fire with the specified name from both the name
	// thread and the district thread. Returns true if it found and
	// removed the fire, false if it did not find the fire.
	bool remove(const char * const name);

private:
	struct Node
	{
		Node(const Fire& fire);			// constructor
		Fire item;						// an instance of Fire
										// (NOT a pointer to an instance)
		Node *nextByName;				// next node in the name thread
		Node *nextByDistrict;			// next node in the district thread
	};

	Node *headByName;					// first node in the name thread
	Node *headByDistrict;				// first node in the district thread
};

#endif // _LIST_H_
