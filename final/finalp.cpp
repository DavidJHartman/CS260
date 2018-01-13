// BST is a class that manages a binary search tree. The BST
// constructor creates a tree with a random number of nodes,
// each one of which contains a random uppercase letter. The
// bst.getRoot() function returns a pointer to the root of
// the binary search tree.
//
// Each node contains a random uppercase letter.

#include <iostream>
#include "bst.h"

using namespace std;

// Write code for the following recursive function.
// Submit your code as finalp.tar.gz.

// return the number of leaf nodes (i.e. nodes with no children)
// in the binary search tree.
static int countLeaves(BST::Node const * const node)
{
    static int numberOfLeaves = 0;

    if ( node->left ) {
        countLeaves( node->left );
    }
    if ( node->right ) {
        countLeaves( node->right );
    }
    if ( !node->left && !node->right ) {
        numberOfLeaves++;
    }
    
	return numberOfLeaves;
}

int main(int argc, char** argv)
{
	if (argc > 1)				// turn off cout
		cout.setstate(ios_base::badbit);

	BST		bst;
	cout << countLeaves(bst.getRoot()) << " leaves" << endl;

	return 0;
}
