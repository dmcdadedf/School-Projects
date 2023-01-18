/* Filename:  queue.h

   Programmer:  Br. David Carlson

   Date:  April 13, 1998

   This is the header file to provide the abstract base class called
   QueBaseClass.
*/

#include "itemtype.h"


class QueBaseClass
{
public:
    virtual void Insert(const ItemType& Item) = 0;
    virtual void Remove(ItemType& Item) = 0;
    virtual bool Empty(void) const = 0;
};

// The = 0; means there is no code; these are "pure virtual" functions.
