#include <cstring>
#include "list.h"

using namespace std;

const char	List::YOUR_NAME[]{"David Hartman"};

List::List()
{
    District dir{(District)(-1)};
    Fire fire{dir,nullptr, -1,-1,-1,-1,-1,-1};
    headByDistrict = new Node{fire};
    headByName = headByDistrict;
}

List::~List()
{
    
}

/*
You will need to uncomment this constructor and write the code for it.
*/

List::Node::Node(const Fire& fire) :

item{fire.getDistrict(), fire.getName(), fire.getLatitude(),
fire.getLongitude()}

{ 
    nextByDistrict = nullptr;
    nextByName = nullptr;
}


void List::displayByName(ostream& out) const
{
    Fire::displayColumnHeadings(out);
    Node* dispNode = headByName->nextByName;
    while (dispNode) {
        out << &dispNode->item  << std::endl;
        dispNode = dispNode->nextByName;
    }
}

void List::displayByDistrict(ostream& out) const
{
	Fire::displayColumnHeadings(out);
    Node* dispNode = headByDistrict->nextByDistrict;
    while (dispNode) {
        out << &dispNode->item << std::endl;
        dispNode = dispNode->nextByDistrict;
    }
}

void List::insert(const Fire& fire)
{
    Node* node = headByDistrict;
    Node* insertNode = node->nextByDistrict;
    Node* newNode;
    
    while (node) {
        if ((insertNode && fire.getDistrict() <= insertNode->item.getDistrict()
        && strcmp( fire.getName(), insertNode->item.getName() ) < 0 ) ||
            !insertNode ) {
                node->nextByDistrict = new Node{fire};
                newNode = node->nextByDistrict;
                newNode->nextByDistrict = insertNode;
                break;
        }
        node = insertNode;
        insertNode = node->nextByDistrict;
    }

    node = headByName;
    insertNode = node->nextByName;

    while (node) {
        if ((insertNode && strcmp(fire.getName(), insertNode->item.getName())<0)
            ||( !insertNode)) {
                node->nextByName = new Node{fire};
                newNode = node->nextByName;
                newNode->nextByName = insertNode;
                break;
            }
        node = insertNode;
        insertNode = node->nextByName;
    }

    return;
    
}

Fire* const List::find(const char * const name) const
{
	Node* node{headByName->nextByName};
    
    while (node) {
        if (strcmp(node->item.getName(), name) == 0)
            return &node->item;
        node=node->nextByName;
    }   

	return nullptr;
}

bool List::remove(const char * const name)
{
	Node* node = headByName;
    Node* nextNode = node->nextByName;
    while (nextNode) {
        if (strcmp(name, nextNode->item.getName()) == 0) {
            node->nextByName = nextNode->nextByName;
            break;
        }
        node = nextNode;
        nextNode = node->nextByName;
    }

    node = headByDistrict;
    nextNode = node->nextByDistrict;
    while (nextNode) {
        if (strcmp(name, nextNode->item.getName()) == 0) {
            node->nextByDistrict = nextNode->nextByDistrict;
            delete nextNode;
            return true;   
        }
        node = nextNode;
        nextNode = node->nextByDistrict;
    }

	return false;
}
