/* Filename:  arrqueue.h

   Programmer:  Br. David Carlson

   Date:  May 14, 1999

   This is the header file to accompany arrqueue.cpp.  They provide the
   ArrQueClass shown below which is a subclass of QueBaseClass.
*/

#include "queue.h"


const int QueueMax = 100;

typedef ItemType QueueArrayType[QueueMax];

class ArrQueClass : public QueBaseClass
{
public:
    ArrQueClass(void);
    bool Empty(void) const;
    void Insert(const ItemType& Item);
    void Remove(ItemType& Item);
private:
    void Advance(int& Index);
    QueueArrayType Info;
    int Front, Rear, Count;
};