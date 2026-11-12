# Q3 - Default Arguments and Function Overloading

## Objective
To develop a courier charge calculator using function
overloading and default arguments.

## Concepts Used
1. Function Overloading
2. Default Arguments
3. Exact Match
4. Type Promotion
5. Type Conversion
6. Parcel Class

## Problem
Multiple charge functions with overlapping parameters
cause ambiguous function calls.

## Solution
Designed three overloads:
- charge(int grams)
- charge(double kg, bool express, bool insured)
- charge(const Parcel& p)

## Test Cases
Six different function calls were tested, including
charge(2) and charge(2.0f).

## Default Arguments
Express and insurance are optional parameters.
Their default values are false.

## Overload Resolution
Exact matches are preferred over promotions,
and promotions are preferred over conversions.

## Alternative Design
A Parcel structure can store weight, express delivery
and insurance information in one object.

## Complexity Analysis
Time complexity: O(1) for each charge calculation.
Overload resolution occurs at compile time.
Space complexity: O(1) for these parameters.

## Result
Successfully implemented the courier charge calculator
using function overloading and default arguments.
