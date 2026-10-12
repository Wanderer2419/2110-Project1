// Reservation Manager implementation file
#include "Resource.h"
#include "ReservationManager.h"
#include "Reservation.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <exception>
using namespace std;
std::vector<Resource> res; 

void loadResources() {

    std::ifstream inputFile;
    inputFile.open("data/resources.txt");
    std::string line = "";
    while(std::getline(inputFile, line)) {

        std::string id, name, type, availability;
        std::stringstream ss(line);
        std::getline(ss, id, '|');
        std::getline(ss, name, '|');
        std::getline(ss, type, '|');
        std::getline(ss, availability, '|');

        Resource resources(id, name, type, availability);
        res.push_back(resources);

    } 
    inputFile.close();
}

void displayAllResources() {
    for(auto& re: res) {
        std::cout << "Resource ID: " << re.getResourceID() << std::endl;
        std::cout << "Resource Name: " << re.getResourceName() << std::endl;
        std::cout << "Resource Type: " << re.getResourceType() << std::endl;
        std::cout << "Availability: " << re.getAvailabilityStatus() << std::endl;
        std::cout << "------------------------" << std::endl; 
    }
}

void SearchResources(LinkedList& active) {
    enum Search {SEARCH_RESOURCE, SEARCH_RESERVATION, SEARCH_STUDENT};
    std::cout << "1. Search Resource by ID" << std::endl;
    std::cout << "2. Search Reservation by ID" << std::endl;
    std::cout << "3. Search Reservations by Student Name" << std::endl;
    std::cout << "Enter the number: ";
    try {
        int choose;
        if (!(cin >> choose)) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw std::runtime_error("Invalid input type. Please enter a valid number.");
        }

        if (choose < 1 || choose > 3) {
            throw std::out_of_range("Invalid search option selected.");
        }

        Search Search_option = static_cast<Search>(choose-1);
        switch(Search_option) {
            case SEARCH_RESOURCE: {
                std::string Resource_ID = "";
                std::cout << "Enter the Resource ID: ";
                std::cin >> Resource_ID;
                bool found = false;
                for(auto& re: res) {
                    if(Resource_ID == re.getResourceID()) {
                        std::cout << "Resource ID: " << re.getResourceID() << std::endl;
                        std::cout << "Resource Name: " << re.getResourceName() << std::endl;
                        std::cout << "Resource Type: " << re.getResourceType() << std::endl;
                        std::cout << "Availability: " << re.getAvailabilityStatus() << std::endl;
                        std::cout << "------------------------" << std::endl; 
                        found = true;
                    }
                }

                if(!found) {
                    throw std::runtime_error("That Resource ID does not exist.");
                }
                break;
            }
            
            case SEARCH_RESERVATION: {
                std::string ResID = "";
                std::cout << "Enter the Reservation ID: ";
                std::cin >> ResID;
                auto reservation = active.find(ResID);
                if (reservation != nullptr) {
                    reservation->DisplayReservation();
                }
            
                else {
                    throw std::runtime_error("Reservation not found.");
                }
                break;
            }

            case SEARCH_STUDENT:  {
                std::string Student_Name = "";
                std::cout << "Enter the Student Name: ";
                getline(std::cin >> ws, Student_Name);
                active.searchByName(Student_Name);
                break;
            }
        }

    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
}

static string ask(const string& prompt) {
    string s;
    cout << prompt;
    getline(cin >> ws, s);
    return s;
}

static Resource* findResource(const string& id) {
    for (auto& r : res) {
        if (r.getResourceID() == id) return &r;
    }
    return nullptr;
}

static bool slotTaken(LinkedList& active, const string& rid, const string& date) {
    for (auto& r : active.toVector()) {
        if (r.getResourceID() == rid && r.getReservationDate() == date) return true;
    }
    return false;
}


void loadReservations(LinkedList& active, int& nextID) {
    ifstream in("data/reservations.txt");

    if(!in.is_open()) {
        std::cout << "Reservation could not open" << std::endl;
        return;
    }

    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string id, sid, name, rid, date;
        getline(ss, id, '|');
        getline(ss, sid, '|');
        getline(ss, name, '|');
        getline(ss, rid, '|');
        getline(ss, date, '|');
        if (id.empty() || date.empty()) continue;   

        active.PushBack(Reservation(id, sid, name, rid, date));
        if (id.find_first_not_of("0123456789") == string::npos && stoi(id) >= nextID) {
            nextID = stoi(id) + 1;
        }
    }
}

void createReservation(LinkedList& active, WaitingList& waiting, int& nextID) {
    string sid  = ask("Student ID: ");
    string name = ask("Student name: ");
    string rid  = ask("Resource ID (for example R101): ");
    string date = ask("Date (MM/DD/YYYY): ");

    Resource* r = findResource(rid);
    if (r == nullptr || r->getAvailabilityStatus() != "Available") {
        cout << "That resource does not exist or is unavailable." << endl;
        return;
    }

    if (slotTaken(active, rid, date)) {
        cout << rid << " is already reserved on " << date << "." << endl;
        string answer = ask("Join the waiting list? (y/n): ");
        if (answer == "y" || answer == "Y") {
            WaitRequest w;
            w.studentID = sid;
            w.studentName = name;
            w.resourceID = rid;
            w.date = date;
            waiting.enqueue(rid, w);
            cout << "Added to the waiting list." << endl;
        }
        return;
    }

    int x = nextID++;
    active.PushBack(Reservation(to_string(x), sid, name, rid, date));
    cout << "Reservation created.\nYour reservation ID number is: " << x << endl;
}

void cancelReservation(LinkedList& active, WaitingList& waiting,
                       CancellationHistory& history, int& nextID) {
    string id = ask("Reservation ID to cancel: ");
    Reservation* found = active.find(id);
    if (found == nullptr) {
        cout << "Reservation not found." << endl;
        return;
    }

    Reservation copy = *found;   
    history.push(copy);
    active.remove(id);
    cout << "Reservation " << id << " cancelled." << endl;

    WaitRequest w;
    if (waiting.dequeue(copy.getResourceID(), w)) {
        active.PushBack(Reservation(to_string(nextID++), w.studentID, w.studentName,
                                    copy.getResourceID(), copy.getReservationDate()));
        cout << w.studentName << " was taken off the waiting list and now holds "
             << copy.getResourceID() << " on " << copy.getReservationDate() << "." << endl;
    }
}

void undoCancellation(LinkedList& active, CancellationHistory& history) {
    if (history.isEmpty()) {
        cout << "Nothing to undo." << endl;
        return;
    }

    cout << "Cancellation history (oldest to newest):" << endl;
    for (auto& r : history.toVector()) {
        r.DisplayReservation();
    }

    Reservation last("", "", "", "", "");   
    history.pop(last);
    if (slotTaken(active, last.getResourceID(), last.getReservationDate())) {
        cout << "Cannot restore " << last.getReservationID() << ": that slot is now taken." << endl;
        history.push(last);   // keep it in the history
        return;
    }
    active.PushBack(last);
    cout << "Restored reservation " << last.getReservationID() << "." << endl;
}


static void mergeSort(vector<Resource>& v) {
    if (v.size() <= 1) return;

    size_t mid = v.size() / 2;
    vector<Resource> left(v.begin(), v.begin() + mid);
    vector<Resource> right(v.begin() + mid, v.end());
    mergeSort(left);
    mergeSort(right);

    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i].getResourceName() <= right[j].getResourceName()) v[k++] = left[i++];
        else v[k++] = right[j++];
    }
    while (i < left.size()) v[k++] = left[i++];
    while (j < right.size()) v[k++] = right[j++];
}

void sortResources() {
    mergeSort(res);
    displayAllResources();
}



void generateReport(LinkedList& active, WaitingList& waiting, CancellationHistory& history) {
    cout << "===== System Report =====" << endl;
    
    vector<Reservation> activeList = active.toVector();
    cout << "Total Active Reservations: " << activeList.size() << endl;
    cout << "Total Resources in Inventory: " << res.size() << endl;
    cout << "Cancellations on Record: " << history.size() << endl;
    cout << "----------------------------------------" << endl;

    // 1. Current Availability of Resources
    cout << "[Current Resource Availability]" << endl;
    for (auto& r : res) {
        cout << "ID: " << r.getResourceID() 
             << " | Name: " << r.getResourceName() 
             << " | Status: " << r.getAvailabilityStatus() << endl;
    }
    cout << "----------------------------------------" << endl;

    // 2. Most Frequently Reserved Resources (Using Vectors & Loops)
    cout << "[Most Frequently Reserved Resources]" << endl;
    if (activeList.empty()) {
        cout << "No active reservations to analyze frequency." << endl;
    } else {
        int maxCount = 0;

        // First pass: Find the highest reservation count for any resource
        for (auto& r : res) {
            int currentCount = 0;
            for (auto& resItem : activeList) {
                if (resItem.getResourceID() == r.getResourceID()) {
                    currentCount++;
                }
            }
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        }

        if (maxCount == 0) {
            cout << "No resources have been reserved yet." << endl;
        } else {
            cout << "Most frequently reserved resource(s) (Count: " << maxCount << "):" << endl;
            // Second pass: Print any resource that matches the maxCount (handles ties)
            for (auto& r : res) {
                int currentCount = 0;
                for (auto& resItem : activeList) {
                    if (resItem.getResourceID() == r.getResourceID()) {
                        currentCount++;
                    }
                }
                if (currentCount == maxCount) {
                    cout << " - " << r.getResourceID() << " (" << r.getResourceName() << ") with " << currentCount << " reservation(s)" << endl;
                }
            }
        }
    }
    cout << "----------------------------------------" << endl;

    // 3. Waiting List Reports
    cout << "[Waiting List Reports]" << endl;
    size_t totalWaiting = 0;
    for (auto& r : res) {
        size_t count = waiting.size(r.getResourceID());
        totalWaiting += count;
        if (count > 0) {
            cout << "Resource " << r.getResourceID() << " (" << r.getResourceName() << "): " << count << " user(s) waiting." << endl;
        }
    }
    if (totalWaiting == 0) {
        cout << "No students currently on any waiting lists." << endl;
    }
    cout << "========================================" << endl;
   
   
    // size_t waitingTotal = 0;
    // for (auto& r : res) {
    //     waitingTotal += waiting.size(r.getResourceID());
    // }
    // cout << "===== System Report =====" << endl;
    // cout << "Resources:               " << res.size() << endl;
    // cout << "Active reservations:     " << active.toVector().size() << endl;
    // cout << "Students waiting:        " << waitingTotal << endl;
    // cout << "Cancellations on record: " << history.size() << endl;
}
