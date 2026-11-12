
# Q6 - Friend Functions and Inline Functions

## Objective
To calculate the difference between two journey times and compare their order using friend functions.

## Concepts Used
- Classes and Objects
- Private Data Members
- Friend Functions
- Inline Functions
- Function Calls
- Encapsulation

## Friend Functions
The functions minutesBetween() and earlier() are declared as friends because they need access to the private hour and minute values of two Time objects.

## Inline Functions
Inline functions allow the compiler to consider replacing function calls with the function body. This can reduce function-call overhead, especially for small functions. The compiler makes the final decision.

## Correctness Testing
Tested:
- 09:45 and 13:10
- 11:50 and 12:10
- Two identical times: 10:30 and 10:30

## Expected Main Output
205 false

## Alternative Design
Member functions such as minutesTo() and isEarlier() can perform the same operations without using friend functions.

## Complexity Analysis
- Time complexity per comparison: O(1).
- Extra space per comparison: O(1).
- Inline and normal function versions perform the same calculation.

## Performance Measurement
Recorded execution times for 10,000,000 calls using -O0 and -O2 compiler optimization levels. Actual measurements are included in the timing results.

## Design Decision
Friend functions are suitable when a comparison treats two objects equally and needs access to private members. Member functions are preferable when operations naturally belong to one object and can preserve encapsulation without friendship.

## Result
Successfully implemented and tested the Time class using friend functions and compared inline and normal function performance.

