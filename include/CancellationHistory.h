#ifndef CANCELLATION_HISTORY_H
#define CANCELLATION_HISTORY_H

#include "Reservation.h"
#include <stack>
#include <vector>


class CancellationHistory {
public:
    void push(const Reservation& r);

  .
    bool pop(Reservation& out);

    bool isEmpty() const;
    size_t size() const;

 
    std::vector<Reservation> toVector() const;

private:
    std::stack<Reservation> stack_;
};

#endif // CANCELLATION_HISTORY_H
