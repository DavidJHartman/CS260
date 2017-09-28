// make NO CHANGES to this file

#include <cstring>
#include <iostream>
#include "fire.h"
#include "list.h"

using namespace std;

static List		*fires;

// Asks List to insert a fire into the doubly-threaded linked list.
// Note what this function does with memory, which has implications for
// how you will (and will not) be able to use the fire instance that's
// passed to fires->insert.
static void insertFire(District district, char* name,
					   int latDeg, int latMin, int latSec,
					   int longDeg, int longMin, int longSec)
{
	Fire	*f;
	char	*nm{new char[strlen(name) + 1]};
	
	strcpy(nm, name);
	f = new Fire(district, nm, latDeg, latMin, latSec, longDeg, longMin, longSec);
	fires->insert(*f);
	delete[] nm;
	delete f;
}

// Display all fires in the list, first in order by name,
// then in order by district (PREMIUM: and by name within district).
static void displayFires(ostream& out)
{
	out << "+++ list by name" << endl;
	fires->displayByName(out);
	out << endl << "+++ list by district" << endl;
	fires->displayByDistrict(out);
}

int main(int argc, char **argv)
{
	if (argc > 1)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	Fire	*fPtr;

    cout << "CS260 - Assignment 1 - " << List::YOUR_NAME << endl << endl;

    fires = new List();

	insertFire(District::Tillamook, "Strawberry Lane Fire", 45, 35, 212, 123, 57, 7);
	insertFire(District::Tillamook, "Bob Straub", 45, 11, 463, 123, 57, 580);
	insertFire(District::Astoria, "Mosquito Fire", 46, 9, 215, 123, 57, 573);
	insertFire(District::Astoria, "Little Walluski", 46, 8, 276, 123, 45, 360);
	insertFire(District::Astoria, "Pig Pen Crossing Fire", 46, 4, 38, 123, 50, 360);
	insertFire(District::Astoria, "Round Bale", 46, 6, 328, 123, 55, 180);
	insertFire(District::Forest_Grove, "Bishop Scott Fire", 45, 22, 36, 123, 11, 535);
	insertFire(District::Columbia_City, "Cox Rd #1", 46, 7, 382, 123, 3, 322);
	insertFire(District::Forest_Grove, "Manning Fire #1", 45, 39, 524, 123, 9, 553);
	insertFire(District::Columbia_City, "Timber Road #1", 45, 47, 294, 123, 16, 220);
	insertFire(District::Forest_Grove, "Kuykendall Field Fire", 45, 20, 575, 123, 12, 424);
	insertFire(District::Forest_Grove, "Hartwick Burn Pile", 45, 37, 387, 123, 8, 340);
	insertFire(District::Columbia_City, "Prescott Beach #2", 46, 3, 263, 122, 53, 296);
	insertFire(District::Columbia_City, "Hwy 47 MP 5", 46, 4, 11, 123, 15, 382);
	insertFire(District::Forest_Grove, "Sheltered Nook Bark Fire", 45, 38, 16, 122, 51, 473);
	insertFire(District::Columbia_City, "Neer City Road #1", 46, 2, 362, 122, 55, 75);
	insertFire(District::Columbia_City, "Wilark Rd", 45, 52, 318, 122, 59, 198);
	insertFire(District::Columbia_City, "Pisgah Homes Rd Fire #1", 45, 46, 153, 122, 58, 540);
	insertFire(District::Columbia_City, "Anliker Rd #1", 45, 57, 23, 122, 58, 246);
	insertFire(District::Forest_Grove, "Fir Crest Rd #1", 45, 16, 34, 123, 14, 215);
	insertFire(District::Forest_Grove, "Fire Break 1", 45, 37, 230, 123, 22, 140);
	insertFire(District::Forest_Grove, "Stubb Stewart Fire", 45, 44, 240, 123, 11, 392);
	insertFire(District::Dallas, "Socialist Valley", 44, 52, 240, 123, 26, 480);
	insertFire(District::Toledo, "Olalla Rd Fire", 44, 39, 590, 123, 55, 559);
	insertFire(District::Dallas, "Gold Creek", 45, 2, 432, 123, 32, 31);
	insertFire(District::Dallas, "Riley Central Fire", 44, 53, 510, 123, 36, 144);
	insertFire(District::Dallas, "Tindle Creek Fire", 45, 6, 277, 123, 30, 247);
	insertFire(District::Toledo, "Little Euchre", 44, 47, 190, 123, 53, 330);
	insertFire(District::Philomath, "Peterson Road", 44, 27, 519, 123, 23, 159);
	insertFire(District::Santiam, "Alder Creek", 44, 47, 97, 122, 41, 552);
	insertFire(District::Molalla, "Wagon Wheel Fire", 45, 11, 491, 122, 34, 348);
	insertFire(District::Molalla, "Paha Piles", 45, 22, 149, 122, 11, 50);
	insertFire(District::Santiam, "Ike Mooney Pile", 45, 0, 83, 122, 45, 178);
	insertFire(District::Molalla, "Vick Rd", 45, 9, 527, 122, 35, 563);
	insertFire(District::Santiam, "Shepards Pie Fire", 44, 43, 470, 122, 26, 560);
	insertFire(District::Molalla, "Beavercreek Brush", 45, 14, 20, 122, 28, 410);
	insertFire(District::Molalla, "Hwy 211 Slash", 45, 22, 133, 122, 17, 578);

	displayFires(cout);

	cout << endl << ">>> removing Beavercreek Brush" << endl <<  endl;
	fires->remove("Beavercreek Brush");

	displayFires(cout);

	cout << endl << ">>> inserting Wall St Pile" << endl << endl;
	insertFire(District::Molalla, "Wall St Pile", 45, 9, 458, 122, 26, 380);

	displayFires(cout);

	cout << endl << ">>> search for \"Wall St Pile\"" << endl << endl;
	fPtr = fires->find("Wall St Pile");
	if (fPtr != 0)
		cout << fPtr;
	else
		cout << "not found" << endl;

	cout << endl << ">>> search for \"No Fire\"" << endl << endl;
	fPtr = fires->find("No Fire");
	if (fPtr != 0)
		cout << fPtr;
	else
		cout << "not found" << endl;

	cout << endl;

	delete fires;

	return 0;
}
