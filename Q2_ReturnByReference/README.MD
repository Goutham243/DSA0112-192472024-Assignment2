
# Q2 - Return by Reference and Its Dangers

## Objective
To implement return by reference, return by const reference,
and return by value using a marks register.

## Concepts Used
1. Return by Reference
2. Return by Const Reference
3. Return by Value
4. Dangling References
5. Vector Reallocation

## Program Description
The program stores student marks in an array and finds
the highest mark. A reference is returned to modify the
highest mark directly by adding 2 moderation marks.

## Observations
- Return by reference modifies the original array element.
- Return by const reference prevents modification through
  the returned reference.
- Return by value provides an independent copy.
- Returning a reference to a local variable is unsafe.

## Dangling Reference
A local variable is destroyed when its function ends.
Returning its reference creates a dangling reference.
Accessing it results in undefined behaviour.

## Vector Reallocation
When a vector reallocates its memory, existing references,
pointers and iterators to its elements become invalid.

## Alternative Approaches
- Return by Reference: int&
- Return by Index: int
- Return by Pointer: int*

## Complexity Analysis

| Method | Time | Space |
|---|---|---|
| Reference | O(n) | O(1) |
| Index | O(n) | O(1) |
| Pointer | O(n) | O(1) |

All methods require O(n) time to find the maximum mark.

## Design Decision
Returning an index is preferred when using a growing
vector because the index can be used again after
reallocation, provided the element position remains valid.

## Result
Successfully implemented return by reference, const
reference and value. Demonstrated dangling references,
vector reallocation and alternative approaches.

