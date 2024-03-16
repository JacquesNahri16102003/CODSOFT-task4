#include "ToDoList.h"

ToDoList::ToDoList() {
    myCapacity = 5;
    mySize = 0;
    myList = new (nothrow) ElementType[myCapacity];
    assert(myList != NULL);
}

bool ToDoList::isFull() const {
    return mySize == myCapacity;
}

bool ToDoList::isEmpty() const {
    return mySize == 0;
}

bool ToDoList::addAtPosition(const ElementType & element, int position) {
    if (position < 0 || position > mySize) {
        cerr << "Failed to insert task: Invalid position." << endl;
        return false;
    }

    if (isFull()) {
        myCapacity *= 2;
        ElementType * temp = new (nothrow) ElementType [myCapacity];
        assert(myList != NULL);
        for (int i = 0; i < mySize; ++i) {
            temp[i] = myList[i];
        }
        delete [] myList;
        myList = temp;
    }

    for (int i = mySize; i > position; --i) {
        myList[i] = myList[i - 1];
    }

    myList[position] = element;
    ++mySize;
    return true;
}

bool ToDoList::addAtBeginning(const ElementType & element) {
    return addAtPosition(element, 0);
}

bool ToDoList::addAtEnd(const ElementType & element) {
    return addAtPosition(element, mySize);
}

bool ToDoList::removeAtPosition(int position) {
    if (isEmpty()) {
        cerr << "List is empty." << endl;
        return false;
    }

    if (position < 0 || position >= mySize) {
        cerr << "Invalid position." << endl;
        return false;
    }

    for (int i = position; i < mySize - 1; ++i) {
        myList[i] = myList[i + 1];
    }

    --mySize;
    return true;
}

bool ToDoList::markCompleted(int position) {
    if (isEmpty()) {
        cerr << "List is empty." << endl;
        return false;
    }

    if (position < 0 || position >= mySize) {
        cerr << "Invalid position." << endl;
        return false;
    }

    myList[position].completed = true;

    return true;
}

void ToDoList::display(ostream & out) const {
    if (isEmpty()) {
        out << "The list is empty" << endl;
    } else {
        for (int i = 0; i < mySize; i++) {
            out << (i + 1) << ": " << myList[i].task;
            out << (myList[i].completed ? " - Completed" : " - Not completed") << endl;
        }
        out << endl;
    }
}

ostream & operator<<(ostream & out, const ToDoList & list) {
    list.display(out);
    return out;
}
