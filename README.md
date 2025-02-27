# Time++ - A Lightweight C++ Timing Utility

## Overview
Timepp is a simple yet powerful C++20 utility for measuring execution times of functions, statements, and code blocks. It provides an easy-to-use API to benchmark performance and gather statistical insights, including mean, median, min, and max execution times. A summary is printed automatically at the end of the program run (when static instances go out of scope). 

## Features
- Measure execution time of statements, functions, and code blocks
- Automatically logs and summarizes execution statistics
- Provides mean, median, min, and max times
- Supports both inline and scoped timing measurements
- Uses high-resolution clock for accurate timing

## Installation
Simply include `timepp.hpp` in your project:
```cpp
#include "timepp.hpp"
```
No additional dependencies are required.

## Usage
Examples can be found in [tpp-test.cpp](tpp-test.cpp)

### Measure a Statement
```cpp
timest(std::cout << "Hello, World!" << std::endl);
```

### Measure a Function Call
```cpp
int result = timefn(my_function());
```

### Measure a Function in Global Scope
```cpp
timegb(some_expensive_operation());
```

### Measure a Code Block
```cpp
timepush("Computation Block");
// Your code here
timepop();
```

## Example
```cpp
#include "timepp.hpp"

void example_function() {
    timepush("Example");
    for (volatile int i = 0; i < 1000000; ++i); // Simulated workload
    timepop();
}

int main() {
    timest(std::cout << "Starting..." << std::endl);
    timefn(example_function());
    return 0;
}
```

