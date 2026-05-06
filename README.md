# DAG Optimization - Redundant Expression Detection using Expression Frequency Analysis

## Problem Understanding

Directed Acyclic Graphs (DAGs) are used in compiler optimization to represent arithmetic expressions and their dependencies. If the same arithmetic expression appears more than once, the compiler can compute it once and reuse the result instead of recalculating it.

This project detects such repeated arithmetic expressions by counting how many times each expression occurs. If an expression appears more than once, it is marked as a common subexpression.

## Objectives

- Store arithmetic expressions representing DAG nodes.
- Count the frequency of each unique expression.
- Detect repeated expressions.
- Generate the flag `Is_Common_Subexpression`.
- Display the result in a clean tabular format.
- Avoid printing duplicate expressions.

## Logic Used

The program uses a predefined array of arithmetic expressions:

```text
a+b
c*d
a+b
x-y
c*d
m/n
```

The program scans each expression one by one. For every expression:

1. It searches whether the expression already exists in the unique expression table.
2. If the expression already exists, its frequency is increased.
3. If the expression does not exist, it is added as a new unique expression with frequency `1`.
4. After all expressions are processed, the program checks the frequency of each unique expression.
5. If frequency is greater than `1`, the expression is marked as a common subexpression.

## Justification of Feature/Threshold

The feature `Is_Common_Subexpression` is based on the condition:

```c
Expression_Frequency > 1
```

This condition correctly identifies redundancy because an expression that appears only once does not cause repeated computation. However, if the same expression appears two or more times, it means the same computation is being performed repeatedly. Therefore, `Frequency > 1` is a suitable threshold for identifying common subexpressions in DAG-based compiler optimization.

## Structure Used

```c
struct DAGExpression {
    char Expression[MAX_EXPRESSION_LENGTH];
    int Expression_Frequency;
    int Is_Common_Subexpression;
};
```

The structure contains:

- `Expression`: stores the arithmetic expression.
- `Expression_Frequency`: stores how many times the expression appears.
- `Is_Common_Subexpression`: stores `1` if repeated, otherwise `0`.

## Algorithm

1. Start.
2. Define a list of input expressions.
3. Create an empty table for unique expressions.
4. For each expression in the input list:
   - Search the unique expression table.
   - If found, increase its frequency.
   - If not found, add it to the table with frequency `1`.
5. For each unique expression:
   - If frequency is greater than `1`, set `Is_Common_Subexpression = 1`.
   - Otherwise, set `Is_Common_Subexpression = 0`.
6. Print the expression, frequency, and common subexpression flag in table format.
7. Stop.

## Complete C Source Code

The complete source code is available in:

```text
dag_common_subexpression.c
```

## Sample Input

The program uses the following predefined input array:

```text
a+b
c*d
a+b
x-y
c*d
m/n
```

## Sample Output

```text
Expression    Frequency    Is_Common_Subexpression
---------------------------------------------------
a+b           2            1
c*d           2            1
x-y           1            0
m/n           1            0
```

## Time Complexity Analysis

Let `n` be the total number of expressions.

For each expression, the program searches the unique expression table. In the worst case, this search may take `O(n)` time. Since this search is performed for all `n` expressions, the total time complexity is:

```text
O(n^2)
```

The space complexity is:

```text
O(n)
```

because the program stores at most `n` unique expressions.

## Real-World Relevance in Compiler Optimization

In compiler design, common subexpression elimination is an important optimization technique. Consider the following repeated expression:

```text
t1 = a + b
t2 = a + b
```

Instead of computing `a + b` twice, an optimizing compiler can compute it once and reuse the result:

```text
t1 = a + b
t2 = t1
```

This reduces redundant computation, improves execution speed, and can produce more efficient intermediate code. DAGs help compilers identify such repeated expressions by representing equivalent computations as shared nodes.

## How to Compile and Run

Using GCC:

```bash
gcc dag_common_subexpression.c -o dag_common_subexpression
./dag_common_subexpression
```

On Windows PowerShell, the executable may be run as:

```powershell
gcc dag_common_subexpression.c -o dag_common_subexpression.exe
.\dag_common_subexpression.exe
```
# CD-H0T-Skill
