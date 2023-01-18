/* Filename:  itemtype.h

   Programmer:  Br. David Carlson

   Date:  October 7, 1997

   Modified:  August 8, 1998

   Modified:  July 21, 2000 to use modern headers.

   This header file is used to define ItemType.  Modify this file to
   define the kind of data you wish to place in your linked list.  If the
   data type does not have == and > operators, you will need to provide
   overloaded ones, perhaps by using a class for this data type.
*/

// The following keeps itemtype.h from being included more than once:
#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
using namespace std;


typedef int ItemType;

#endif
