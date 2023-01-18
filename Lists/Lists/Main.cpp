
#include "S.h"


void headInsert(SPtr &h, SPtr &newItem);
void printList(SPtr& h);
SPtr searchList(SPtr& h, float target);
SPtr searchListAndInsert(SPtr& h, SPtr& newItem, float target);
void tailInsert(SPtr& head, SPtr& tail, SPtr& newItem); // Need both , never only use one
void deleteList(SPtr& head);

int main()
{
    SPtr head = NULL;
    SPtr tail = NULL;
    deleteList(head);
    //SPtr t = new S(9);
    //searchList(head, -1);
    for (int i = 0; i < 3; i++){
        SPtr t = new S(i);
        headInsert(head, t);
    }
    headInsert(head, t);
    float t = 0;
    std::cout << "Target ";
    std::cin >> t;
    SPtr item = searchList(head, t);
    printList(head);
    deleteList(head);
    printList(head);
    return 0;
}

void headInsert(SPtr& h, SPtr& newItem) {
    newItem->next = h;
    h = newItem;
    newItem = NULL;
}

void printList(SPtr& h) {
    for (SPtr itr = h; itr != NULL; itr = itr->next) {
        itr->print();
        std::cout << std::endl;
    }
}
SPtr searchList(SPtr& h, float target) {
    SPtr itr = h;
    for (; itr -> f != target && itr != NULL; itr->next) {

    }
    return itr;
}
SPtr searchListAndInsert(SPtr& h, SPtr& newItem, float target) {
    if (h == NULL) {
        headInsert(h, newItem);
        return NULL;
    }

    SPtr itr = h;
    for (; itr->f != target && itr != NULL; itr->next) {

    }
    if (itr == NULL) {
        headInsert(h, newItem);
        return NULL;
    }
    if (itr != NULL) {
        newItem->next = itr;
        itr->next = newItem;
    }
    return itr;
}

void tailInsert(SPtr& head, SPtr& tail, SPtr& newItem) {

    if (head == NULL) {
        headInsert(head, newItem);
        tail = head;
        newItem = NULL;
        return;
    }

    tail->next = newItem;
    tail = newItem;
    newItem = NULL;

}

void deleteList(SPtr& head) {
    if (head == NULL) {
        return;
    }
    for (; head != NULL; ) {
        SPtr t = head;              // Temp pointer to head of list
        head = head->next;          // removes the item from the list
        t->next = NULL;
        delete t;

    }
}