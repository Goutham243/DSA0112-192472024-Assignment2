
# Q5 - Static Members and Arrays of Objects

## Objective
To implement a college bus ticket system using static members and arrays of objects.

## Concepts Used
- Static data members
- Static member functions
- Constructors
- Arrays of objects
- Object initialization
- Scope resolution operator

## Static Members
The variable issued is static because the number of seats issued must be shared by all BusTicket objects.

The count() function is static because it accesses shared class-level information.

## Static Member Function
A static member function cannot access this or non-static members directly because it does not belong to a particular object.

## Array of Objects
An array of four BusTicket objects is created. The first three receive seats, and the fourth is placed on the waiting list.

## Function Called Twice
The static count continues across function calls. It does not reset when a function finishes.

## Alternative Design
A global counter can be used, but it is less encapsulated. A separate TicketOffice object supports multiple buses with independent counters.

## Complexity Analysis
- Time complexity for issuing a ticket: O(1).
- Space for the shared counter: O(1).
- Space for an array of n ticket objects: O(n).

## Result
Successfully implemented a bus ticket system using static members and an array of objects. The system assigns seats within capacity and places additional passengers on the waiting list.

