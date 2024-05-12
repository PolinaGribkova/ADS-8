// Copyright 2021 NNTU-CS
#include "train.h"
struct Cage {
    bool light; 
    Cage* next;
    Cage* prev;
};

class Train {
private:
    Cage* first;
    Cage* last;
    int countOp; 

public:
    Train() : first(nullptr), last(nullptr), countOp(0) {}

    void addCage(bool light) {
        Cage* newCage = new Cage{ light, nullptr, nullptr };
        if (!first) {
            first = newCage;
            last = newCage;
        }
        else {
            last->next = newCage;
            newCage->prev = last;
            last = newCage;
        }
    }

    int getLength() {
        int length = 0;
        Cage* cage = first;
        while (cage != nullptr) {
            ++length;
            cage = cage->next;
        }
        return length;
    }

    int getOpCount() {
        return countOp;
    }

    ~Train() {
        Cage* current = first;
        while (current != nullptr) {
            Cage* next = current->next;
            delete current;
            current = next;
        }
    }
};
