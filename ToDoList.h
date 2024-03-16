#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

struct task{
    string task;
    bool completed = false;
};typedef struct task Task;

typedef Task ElementType;

#ifndef TODOLIST_H
#define TODOLIST_H
class ToDoList{
public:
    ToDoList();
    bool isFull() const;
    bool isEmpty() const;
    bool addAtPosition(const ElementType &, int);
    bool addAtBeginning(const ElementType &);
    bool addAtEnd(const ElementType &);
    bool removeAtPosition(int);
    bool markCompleted(int);
    void display(ostream & out) const;
private:
    int mySize;
    int myCapacity;
    ElementType * myList;
};

ostream& operator<<(ostream & out, const ToDoList &);
#endif /* TODOLIST_H */
