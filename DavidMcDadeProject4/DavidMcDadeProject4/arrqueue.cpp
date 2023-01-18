/* Filename:  arrqueue.cpp

   Programmer:  Br. David Carlson

   Date:  May 14, 1999

   Revised:  July 21, 2000 to use modern headers.

   This file implements the functions of the ArrQueClass found in
   arrqueue.h.
*/

#include "arrqueue.h"


/* Given:  Index     An integer index with value from 0 to MaxQueue - 1.
   Task:   To advance Index by 1, with wrap-around.
   Return: Index     Updated index value.
*/
inline void ArrQueClass::Advance(int& Index)
{
    Index++;
    if (Index == QueueMax)
        Index = 0;
}


/* Given:  Nothing.
   Task:   To construct a new object of this class.
   Return: Nothing other than the implicit object that's been constructed.
*/
ArrQueClass::ArrQueClass(void)
{
    Front = 0;
    Rear = QueueMax - 1;
    Count = 0;
}


/* Given:  Nothing (other than the implicit ArrQueClass object).
   Task:   To check whether this object is empty.
   Return: true if it is empty, false otherwise.
*/
bool ArrQueClass::Empty(void) const
{
    if (Count == 0)
        return true;
    else
        return false;
}


/* Given:  Item   A data item.
   Task:   To insert item into the queue (implicit object) at the rear.
   Return: Nothing directly, but the implicit object is modified.
*/
void ArrQueClass::Insert(const ItemType& Item)
{
    if (Count == QueueMax)
    {
        cerr << "ERROR: Cannot insert -- queue is full" << endl;
        exit(1);
    }
    else
    {
        Advance(Rear);
        Info[Rear] = Item;
        Count++;
    }
}


/* Given:  Nothing.
   Task:   To remove the front item from the queue (the implicit object).
   Return: Item   The item removed from the queue.
*/
void ArrQueClass::Remove(ItemType& Item)
{
    if (Count == 0)
    {
        cerr << "ERROR: Cannot remove -- queue is empty" << endl;
        exit(1);
    }
    else
    {
        Item = Info[Front];
        Advance(Front);
        Count--;
    }
}