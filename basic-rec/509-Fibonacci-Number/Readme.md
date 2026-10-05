# 509. Fibonacci Number

## Problem

Given `n`, return the `n`th Fibonacci number.

The Fibonacci sequence starts with:

```text
F(0) = 0
F(1) = 1
```

Every next number is the sum of the previous two:

```text
F(n) = F(n-1) + F(n-2)
```

## Example

```text
n = 4
```

Calculate step by step:

```text
F(0) = 0
F(1) = 1

F(2) = F(1) + F(0)
     = 1 + 0
     = 1

F(3) = F(2) + F(1)
     = 1 + 1
     = 2

F(4) = F(3) + F(2)
     = 2 + 1
     = 3
```

Therefore:

```text
Answer = 3
```

## Another Example

```text
n = 5
```

```text
0, 1, 1, 2, 3, 5
            ↑
          F(5)
```

So:

```text
F(5) = 5
```

## Key Idea

Keep the previous two Fibonacci numbers:

```text
prev2 = F(n-2)
prev1 = F(n-1)

current = prev1 + prev2
```

Then move forward:

```text
prev2 = prev1
prev1 = current
```

## Complexity

* Time: `O(n)`
* Space: `O(1)`
