#include "hashmap.h"

using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	HashMap::YOUR_NAME[] = "I. Forgot";

HashMap::HashMap(int capacity)
{
}

HashMap::~HashMap(void)
{
}

bool HashMap::get(char const * const symbol, Stock& s,
				  unsigned int& symbolHash, unsigned int& hashIndex,
				  unsigned int& usedIndex, unsigned int& seqLength)
	 const
{
	// If the symbol is not found, this function is required
	// to set usedIndex to -1 before it returns false.

	// recode these to return the right things
	symbolHash = 0xFFFFFFFF;
	hashIndex =  0xFFFFFFFF;
	usedIndex =  0xFFFFFFFF;
	seqLength =  0xFFFFFFFF;

	return false;
}

bool HashMap::put(const Stock& s,
				  unsigned int& symbolHash, unsigned int& hashIndex,
				  unsigned int& usedIndex, unsigned int& seqLength)
{
	// recode these to return the right things
	symbolHash = 0xFFFFFFFF;
	hashIndex =  0xFFFFFFFF;
	usedIndex =  0xFFFFFFFF;
	seqLength =  0xFFFFFFFF;

	return false;
}

bool HashMap::remove(char const * const symbol, Stock& s,
					 unsigned int& symbolHash, unsigned int& hashIndex,
					 unsigned int& usedIndex, unsigned int& seqLength)
{
	// recode these to return the right things
	symbolHash = 0xFFFFFFFF;
	hashIndex =  0xFFFFFFFF;
	usedIndex =  0xFFFFFFFF;
	seqLength =  0xFFFFFFFF;

	return false;
}

unsigned int HashMap::hashStr(char const * const s)
{
	// Hash C string argument using the formula in java.lang.String.hashCode():
	//
	//   s[0]*(31^(n-1)) + s[1]*(31^(n-2)) + ... + s[n-1]
	//
	// s is the array of characters, n is the number of characters in the string,
	// and 31^n means 31 to the nth power.
	//
	// This function is declared static because its result depends
	// only on the characters in the string. You will need to apply
	// the modulo operator to the result of this function to generate
	// the required table index. The place to do this is in the functions
	// that call this function.
	//
	// You can and should do this computation entirely with integers. In other
	// words, there is no need to use floating point values. In particular, you
	// should not use the pow() function from <math.h> in this lab.

	return 0;
}

ostream& operator<<(ostream& out, const HashMap &h)
{
	out << "<print the contents of the HashMap>" << endl;
	return out;
}
