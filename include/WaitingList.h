#ifndef WAITING_LIST_H
#define WAITING_LIST_H

#include <queue>
#include <map>
#include <string>


struct WaitRequest {
    int studentID = 0;
    std::string studentName;
    std::string resourceID;
    std::string date;
};

// Keeps a separate FIFO queue of waiting students for each resource ID,
// so a student waiting on one resource is never handed a different one.
class WaitingList {
public:
    void enqueue(const std::string& resourceID, const WaitRequest& req);


    bool dequeue(const std::string& resourceID, WaitRequest& out);

    bool isEmpty(const std::string& resourceID) const;
    size_t size(const std::string& resourceID) const;

    void displayAll() const;

private:
    std::map<std::string, std::queue<WaitRequest>> queues_;
};

#endif // WAITING_LIST_H
