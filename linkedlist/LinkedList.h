/* A linked-based implementation of List;
Unlike the Arraylist (array-based implementation List), a link-based
implementation does not shift items during insertion and removal, does not
impose a fixed length on the list (however, does limit by system storage)
*/
#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"
#include "PreCondViolatedExcept.h"