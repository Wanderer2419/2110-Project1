# Milestone 1 (Due 9/20)
## Objectives:
Develop core functionality of the campus resource reservation system and establish the team's collaboration workflow.  
By the end of this milestone, the system should support resource management, reservations, waiting lists, cancellation tracking, and team collaboration through GitHub.  
Although this is a group project, each student will be evaluated individually based on their own contribution to the milestone.  

## Requirements:
### Resource management
The system should:
- Load resource information from a file
- Store resource information
- Display all resources
- Display resource availability

### Reservation management
The system should:
- Create reservations.
- Cancel reservations.
- Display active reservations.
- Validate reservation requests.

### Linked list implementation
A linked list must be used to store active reservations.  
The implementation must support:
- Insert reservation
- Remove reservation
- Traverse reservation records
- Display reservation information

### Waiting list management
A queue must be used for waiting lists.  
The implementation must support:
- Add student to waiting list
- Remove student from waiting list
- Display waiting list

### Cancellation history
A stack must be used for cancellation tracking.  
The implementation must support:
- Store cancelled reservations
- Restore the most recently cancelled reservation
- Display cancellation history

### Complexity analysis
Provide a short report discussing:
- Reservation insertion complexity
- Reservation removal complexity
- Waiting-list processing complexity
- Undo cancellation complexity

Include Big-O notation and brief explanations.
