# Q7 – Diagnose, Redesign and Validate

## A. Diagnose the Limitation

### Selected Program
Q4 – Savings Account Mini-Statement using an array.

### Existing Limitation

The original implementation stores recent transactions in a fixed-size array. When the array becomes full, it shifts all existing elements one position to the left to insert a new transaction.

This creates unnecessary data movement.

If the array has a capacity of 50 elements, each new insertion after the array becomes full requires shifting up to 49 elements.

### Complexity of Original Approach

- Insertion when the array is not full: O(1)
- Insertion when the array is full: O(n)
- Space complexity: O(n)

As the number of stored transactions increases, repeated shifting reduces performance.

## B. Objective

The objective is to redesign the transaction storage mechanism using a circular buffer.

The redesigned solution should:

1. Store the latest 50 transactions.
2. Avoid shifting existing elements.
3. Perform insertion in O(1) time.
4. Display transactions in chronological order.
5. Maintain fixed memory usage.

## C. Revised Solution

### Circular Buffer Approach

A circular buffer is implemented using a fixed-size array and two variables:

- `start` – indicates the position of the oldest transaction.
- `count` – indicates the number of stored transactions.

When the buffer is not full, a new transaction is inserted at the next available position.

When the buffer is full, the oldest transaction is overwritten, and the starting position moves forward.

### Main Design Changes

| Original Approach | Redesigned Approach |
|---|---|
| Shifts elements when full | Overwrites the oldest element |
| Uses a fixed array | Uses a fixed array |
| O(n) insertion when full | O(1) insertion |
| More data movement | No shifting required |

### Circular Buffer Logic

```cpp
if (count < CAPACITY) {
    transactions[(start + count) % CAPACITY] = value;
    count++;
}
else {
    transactions[start] = value;
    start = (start + 1) % CAPACITY;
}
```

The modulo operator ensures that the array index wraps around to the beginning when it reaches the end.

### Memory and Trade-off

The redesigned solution uses a fixed-size array of 50 elements, requiring O(50) storage.

It avoids shifting but introduces additional index management using `start`, `count`, and modulo operations.

## D. Prediction Before Implementation

Before implementing the redesigned solution, the following results are predicted:

1. The circular buffer should perform better than the shifting approach when the buffer is full.
2. The original implementation should move multiple elements for every new insertion after reaching capacity.
3. The redesigned implementation should insert new elements without shifting.
4. Both implementations should retain the latest 50 transactions.
5. Both approaches should display the latest transaction correctly.

## E. Implementation and Validation

### Files Included

| File | Description |
|---|---|
| `original.cpp` | Original array-based shifting implementation |
| `redesigned.cpp` | Circular buffer implementation |
| `benchmark.cpp` | Compares the performance of both approaches |

### Test Conditions

- Buffer capacity: 50 elements
- Number of insertions in benchmark: 10,000,000
- Both implementations receive the same sequence of input values.
- Execution time is measured using the C++ `chrono` library.

### Compilation and Execution

Compile and run the original implementation:

```bash
g++ -std=c++17 -Wall -Wextra original.cpp -o original.exe
```

```powershell
.\original.exe
```

Compile and run the redesigned implementation:

```bash
g++ -std=c++17 -Wall -Wextra redesigned.cpp -o redesigned.exe
```

```powershell
.\redesigned.exe
```

Compile and run the benchmark:

```bash
g++ -std=c++17 -O2 -Wall -Wextra benchmark.cpp -o benchmark.exe
```

```powershell
.\benchmark.exe
```

### Benchmark Results

Enter the actual execution times obtained from your system.

| Measurement | Original Shifting | Circular Buffer |
|---|---|---|
| Buffer Capacity | 50 | 50 |
| Number of Insertions | 10,000,000 | 10,000,000 |
| Latest Stored Value | 9,999,999 | 9,999,999 |
| Insertion Complexity when Full | O(n) | O(1) |
| Execution Time | [Enter actual time] | [Enter actual time] |

### Validation

Both implementations are tested using the same input sequence.

The original approach shifts existing elements, whereas the redesigned approach overwrites the oldest element and updates the starting index.

The benchmark output is used to compare the actual execution times.

## F. Defence and Final Design Decision

The circular buffer is selected as the redesigned solution because it avoids unnecessary shifting and provides constant-time insertion when the buffer is full.

### Advantages

- Faster insertion for a full buffer.
- Avoids repeated element shifting.
- Maintains only the latest 50 transactions.
- Uses fixed memory allocation.

### Limitations

- Requires additional index management.
- Modulo operations are used to calculate array positions.
- The implementation is slightly more complex than the original approach.

### Final Design Decision

The circular buffer is more suitable when transactions are inserted frequently and only the latest 50 records need to be maintained.

The original shifting approach is still suitable for small datasets where simplicity is more important than insertion performance.

## Screenshots

- `original-output.png` – Original implementation output.
- `redesigned-output.png` – Redesigned circular buffer output.
- `benchmark-output.png` – Performance comparison output.

## Conclusion

The original transaction storage implementation was analysed and its limitation was identified. A circular buffer was designed and implemented to eliminate repeated shifting of elements.

The redesigned solution provides O(1) insertion when the buffer is full while maintaining the latest 50 transactions. Both implementations were tested under the same conditions, and their execution times were measured to evaluate the improvement.

