// add code to these functions to make Quack do something useful

#include "quack.h"

using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	Quack::YOUR_NAME[]{"David Hartman"};

// change the value of this variable to true if you're doing the Premium version
const bool	Quack::PREMIUM_VERSION{false};

Quack::Quack(int capacity, int growBy) :
	// replace these initializations with the ones you actually need
	items{new char[capacity]},
	capacity{capacity}
{
	initArray();	// you are required to call this function here, and
					// it must be the first thing in the constructor body
}

Quack::~Quack(void)
{
	delete[] items;
}

// items are pushed to successively LOWER slots in the circular array
// (except for when the beginning of the array "wraps around" to the end)
bool Quack::pushFront(const char ch)
{
    if ( currentAmount != capacity ) {
        
        currentAmount++;
        front--;
        if (front < 0)
            front=capacity-1; 
        items[front] = ch;
        return true;

    }
	return false;
}

// items are pushed to successively HIGHER slots in the circular array
// (except for when the end of the array "wraps around" to the beginning)
bool Quack::pushBack(const char ch)
{
    if ( currentAmount != capacity ) {
        currentAmount++;
        back++;
        if (back == capacity)
            back = 0;
        items[back] = ch;
        return true;
    }
	return false;
}

bool Quack::popFront(char& ch)
{
    if ( currentAmount != 0) {
        ch = items[front];
        front++;
        if (front==capacity)
            front=0;
        currentAmount--;
        return true;
    }
	return false;
}

bool Quack::popBack(char& ch)
{
    if ( currentAmount != 0) {
        ch = items[back];
        back--;
        if (back<0)
            back = capacity-1;
        currentAmount--;
        return true;
    }
	return false;
}

void Quack::rotate(int r)
{
    
    if (currentAmount < capacity) {
        if (r < 0) {
            int r2 = r*-1;
            for (int i = 0; i < r2; i++) {
                items[(back + 1 - i) % capacity] = items[(back-i<0)?
                capacity+back-i : back - i];
            }
        }
        else {
            for (int i = 0; i < r; i++){
                items[(back+1+i)%capacity] = items[(front+i)%capacity];
            }
        }
    }
    front = ((front + r > 0) ? (front + r)% capacity: front + r + capacity);
    back = (back + r) % capacity;
}

void Quack::reverse(void)
{
    int deltaFront = front;
    int deltaBack = back;
    if (currentAmount < capacity) {
        for (int i = 0; i < currentAmount/2; i++) {
            char temp = items[deltaFront];
            items[deltaFront] = items[deltaBack];
            items[deltaBack] = temp;
            deltaFront++;
            deltaBack--;
        }
    }
}

int	Quack::itemCount(void)
{
	return currentAmount;
}

ostream& operator<<(ostream& out, Quack *q)
{

    
    if (q->currentAmount == 0)
	    out << "quack: empty" << endl << endl;
    else {
        out << "quack: " << q->items[q->front];
        
        int itor = q->front;
        if (q->currentAmount!=1){
            do {
                itor++;
                if (itor >= q->capacity) itor = 0;
                out << ", " <<  q->items[itor];
            }while (itor != q->back);
        }
        out << std::endl << std::endl;
    }
	// returning out is ALWAYS required for an operator<< overload
	return out;
}
