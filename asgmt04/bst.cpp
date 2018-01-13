#include <iostream>
#include <iomanip>
#include "bst.h"
#include <string.h>

using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	BST::YOUR_NAME[]{"David Hartman"};

// change the value of this variable to true if you're doing the Premium version
const bool	BST::PREMIUM_VERSION{false};

BST::BST(int capacity)
{
    size = capacity;
   items = new Item[size];
   for (int i = 0; i < capacity; i++)
    items[i].gcs.setName( "" );
}

BST::~BST()
{
    
}

// insert a new item into the BST
void BST::insert(const GCS& gcs)
{
    int index = 0;
    int result = 0;
    while ( true ) {
        if (index > getSize())break;
        if (strlen(items[index].gcs.getName())==0 )
            break;

        result = strcmp( gcs.getName(), items[index].gcs.getName() );

        if ( result >= 0 ) {
            index = 2 * index + 2;
        }
        else if ( result < 0 ) {
            index = 2 * index + 1;
        }

        
    }

    if ( index > getSize() ) {
        Item* newArray = new Item[getSize() * 2];
        for ( int i = 0; i < getSize() * 2; i++) {
            if (i < size)
                newArray[i].gcs.setName( items[i].gcs.getName() );
            else
                newArray[i].gcs.setName( "" );
        }
        size *= 2;
        items = newArray;

    }
    items[index].gcs.setName(gcs.getName());

}

// retrieve item associated with key
// returns true if it finds key, false if it can't
bool BST::retrieve(const char* key, GCS const *& gcs) const
{
    int index = 0;
    int result = 0;
    while ( true ) {
        if ( index > getSize() ) {
            break;
        }
        result  = strcmp( key, items[index].gcs.getName() );

        if ( result > 0 )
            index = 2 * index + 2;
        else if ( result < 0 )
            index = 2 * index + 1;
        else {
            gcs = const_cast<GCS*>(&items[index].gcs);
            return true;
        }


    }

	return false;
}

// remove item associated with key from BST
bool BST::remove(const char* key)
{
	return false;
}

// return number of items contained in the BST
int BST::getSize(void) const
{
	return size;
}

// display items in the tree by traversing the array from beginning to end
void BST::displayArrayOrder(ostream& out) const
{
    bool leaf = false;
    for (int i = 0; i < getSize(); i++) {
        if (strlen(items[i].gcs.getName()) == 0)
            continue;
        out << setw(24) << std::left << items[i].gcs.getName() << setw(7);
        int i1,i2;
        i1 = 2 * i + 1;
        i2 = 2 * i + 2;
        if (i1 > getSize() || strlen(items[i1].gcs.getName()) == 0) {
            if (i2 > getSize() || strlen(items[i2].gcs.getName()) == 0) {
                out  << "leaf";
                leaf = true;
            }
        }
        if (!leaf) {
            ;
        }
        out << "" << setw(5) << std::right << i << std::endl;
        leaf = false;
    }
}

// display items in the tree in preorder
void BST::displayPreOrder(ostream& out) const
{

}

// display items in the tree in inorder
void BST::displayInOrder(ostream& out) const
{
}

// display items in the tree in postorder
void BST::displayPostOrder(ostream& out) const
{
}
