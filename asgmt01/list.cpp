#include <cstring>
#include "list.h"

using namespace std;

const char	List::YOUR_NAME[]{"I. Forgot"};

List::List()
{
	// your code here, or in this constructor's initialization list
}

List::~List()
{
	// your code here
}

/*
You will need to uncomment this constructor and write the code for it.
*/
/*
List::Node::Node(const Fire& fire) :
	// your initialization list here
{
	// your code here
}
*/

void List::displayByName(ostream& out) const
{
	// your code here
}

void List::displayByDistrict(ostream& out) const
{
	// your code here
}

void List::insert(const Fire& fire)
{
	// your code here
}

Fire* const List::find(const char * const name) const
{
	// your code here, return the appropriate value

	return nullptr;
}

bool List::remove(const char * const name)
{
	// your code here, return the appropriate value

	return false;
}
