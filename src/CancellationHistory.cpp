#include "CancellationHistory.h"
using namespace std;

void CancellationHistory::push(const Reservation& r) {
    stack_.push(r);
}

bool CancellationHistory::pop(Reservation& out) {
    if (stack_.empty()) return false;      
    out = stack_.top();
    stack_.pop();
    return true;
}

bool CancellationHistory::isEmpty() const { return stack_.empty(); }
size_t CancellationHistory::size() const  { return stack_.size(); }

vector<Reservation> CancellationHistory::toVector() const {
    
    stack<Reservation> copy = stack_;
    vector<Reservation> result;
    result.reserve(copy.size());
    while (!copy.empty()) {
        result.push_back(copy.top());
        copy.pop();
    }
   
    for (size_t i = 0, j = result.size(); i < j / 2; ++i) {
        std::swap(result[i], result[j - 1 - i]);
    }
    return result;
}
