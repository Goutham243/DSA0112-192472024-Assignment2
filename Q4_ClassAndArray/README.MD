

# Q4 - Specifying a Class with an Array Inside It

## Objective
To design a SavingsAccount class that stores the last 10 transactions using an array.

## Private Data Members
- Account number
- Balance
- Array of 10 transactions
- Transaction count

## Public Member Functions
- deposit()
- withdraw()
- miniStatement()

## Concepts Used
- Classes and Objects
- Access Specifiers
- Arrays inside Classes
- Member Functions
- Scope Resolution Operator
- Encapsulation

## Handling the 11th Transaction
When the array is full, the oldest transaction is removed by shifting the remaining elements to the left. The new transaction is inserted at the last position.

## Design Decision
A circular buffer is preferred when the transaction limit increases to 50 because it inserts new transactions in O(1) time without shifting elements.

## Alternative Concept
A std::deque can be used with push_back() and pop_front() to maintain the latest 10 transactions.

## Complexity Analysis
- Shifting array: O(k) insertion when full.
- Circular buffer: O(1) insertion.
- Deque: O(1) insertion and removal at the ends.
- Space complexity: O(k) for all three designs.

## Result
Successfully implemented a SavingsAccount class that maintains the latest 10 transactions and displays a mini statement.
