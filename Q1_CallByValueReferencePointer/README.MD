# Q1 – Call by Value, Reference and Pointer

## Aim

To understand and demonstrate the differences between call by value, call by reference, and call by pointer in C++.

## Description

This program demonstrates three methods of passing arguments to functions.

### 1. Call by Value
- A copy of the original variable is passed to the function.
- Changes made inside the function do not affect the original variable.
- It is useful when the original data should remain unchanged.

### 2. Call by Reference
- The function receives a reference to the original variable.
- Changes made inside the function directly affect the original variable.
- It avoids copying the variable.

### 3. Call by Pointer
- The address of the variable is passed to the function.
- The function accesses and modifies the original variable using the pointer.
- Pointers provide direct access to memory locations.

## Programs Included

| File | Description |
|---|---|
| `q1.cpp` | Demonstrates call by value, reference and pointer |
| `predict_output.cpp` | Predicts the output of reference, pointer and default argument examples |
| `complete_code.cpp` | Completes the given TODO-based program |
| `prediction.txt` | Contains predicted output and explanation |

## Compilation and Execution

Compile and run the main program:

```bash
g++ -std=c++17 -Wall -Wextra q1.cpp -o q1.exe
```

```powershell
.\q1.exe
```

Compile and run the prediction program:

```bash
g++ -std=c++17 -Wall -Wextra predict_output.cpp -o predict.exe
```

```powershell
.\predict.exe
```

Compile and run the completed program:

```bash
g++ -std=c++17 -Wall -Wextra complete_code.cpp -o complete.exe
```

```powershell
.\complete.exe
```

## Expected Output – q1.cpp

```text
Original Hostel Fee: 45000
Inside Value Function: 40500
Stored Fee after Value: 45000
Inside Reference Function: 40500
Stored Fee after Reference: 40500
Inside Pointer Function: 40500
Stored Fee after Pointer: 40500
```

## Output Explanation

- In call by value, the hostel fee is passed as a copy. Therefore, the original fee remains ₹45,000.
- In call by reference, the original variable is modified directly to ₹40,500.
- In call by pointer, the original variable is modified through its memory address to ₹40,500.

## Alternative Approach

A function can also return a modified value instead of modifying the original variable directly.

For large objects, passing by constant reference (`const &`) is useful when the function only needs to read the data.

## Complexity Analysis

| Method | Time Complexity | Extra Parameter Space |
|---|---|---|
| Call by Value | O(1) for the `long long` used here | O(1) |
| Call by Reference | O(1) | O(1) |
| Call by Pointer | O(1) | O(1) |

For large objects, passing by value may require O(n) copying time, whereas reference and pointer passing avoid copying the entire object.

## Screenshots

- `q1-output.png` – Main program output.
- `prediction-output.png` – Predicted output program execution.
- `complete-output.png` – Completed TODO program output.

## Result

Successfully implemented and executed C++ programs demonstrating call by value, call by reference, and call by pointer. The results confirm that value passing does not modify the original variable, whereas reference and pointer passing can modify it directly.

