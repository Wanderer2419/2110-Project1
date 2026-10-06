#include "WaitingList.h"
#include <iostream>
using namespace std;

void WaitingList::enqueue(const string& resourceID, const WaitRequest& req) {
    queues_[resourceID].push(req);
}

bool WaitingList::dequeue(const string& resourceID, WaitRequest& out) {
    auto it = queues_.find(resourceID);
    if (it == queues_.end() || it->second.empty()) {
        return false;                    
    }
    out = it->second.front();
    it->second.pop();
    return true;
}

bool WaitingList::isEmpty(const string& resourceID) const {
    return size(resourceID) == 0;
}

size_t WaitingList::size(const string& resourceID) const {
    auto it = queues_.find(resourceID);     
    return (it == queues_.end()) ? 0 : it->second.size();
}

void WaitingList::displayAll() const {
    bool any = false;
    for (const auto& entry : queues_) {
        if (entry.second.empty()) continue;
        any = true;
        cout << "  Resource " << entry.first << ": "
             << entry.second.size() << " student(s) waiting\n";
    }
    if (!any) cout << "  No students are currently waiting.\n";
}
