VirtualMethodCallPerformance
==============

```
    printf("Testing the performance of virtual method calls")
```

The project tests if virutal methods can be used in a tight loop instead of long
`if` or `switch` statements.

1. Measurement method: `std::chrono::steady_clock`
   | Method              |  ns  | ms | Processed Items|
   |---------------------|:----:|:--:|:--------------:|
   | Virtual method call | 7658 | 0  | 1340           |
   | `if`                | 2553 | 0  | 1340           |
   | `switch`            | 2553 | 0  | 1340           |
   
2. Measurement method: `std::chrono::high_resolution_clock`
   | Method              |  ns  | ms | Processed Items|
   |---------------------|:----:|:--:|:--------------:|
   | Virtual method call | 7293 | 0  | 1340           |
   | `if`                | 2553 | 0  | 1340           |
   | `switch`            | 2553 | 0  | 1340           |
