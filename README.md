# Integer Toolkit

Integer Toolkit is a C library providing a comprehensive set of functions for manipulating and performing operations on integers. Whether you need to inspect, manipulate, search, or sort integers, this toolkit has you covered.

## Usage

To use the Integer Toolkit library in your C project, simply include the `integer_toolkit.h` header file and link against the corresponding `integer_toolkit.c` source file. Then, you can call any of the provided functions as needed to perform integer manipulation and operations.

```c
#include "integer_toolkit.h"
#include <stdio.h>

int main() {
    int number = 12345;

    printf("Original number: %d\n", number);
    printf("Number of digits: %u\n", intk_length(number));
    printf("Is number zero? %s\n", intk_is_empty(number) ? "Yes" : "No");
    printf("Is number in range (1000-20000)? %s\n", intk_in_range(number, 1000, 20000) ? "Yes" : "No");

    printf("First digit of %d: %d\n", number, intk_front(number));
    printf("Last digit of %d: %d\n", number, intk_back(number));
    printf("Digit at index 2 of %d: %d\n", number, intk_at(number, 2));

    printf("Does %d contain the digit 3? %s\n", number, intk_contains(number, 3) ? "Yes" : "No");
    printf("Does %d start with 12? %s\n", number, intk_startswith(number, 12) ? "Yes" : "No");
    printf("Does %d end with 45? %s\n", number, intk_endswith(number, 45) ? "Yes" : "No");
}
```

## Overview

The library is organized into several categories of functions:

1. **Integer Properties and Validation Functions**: Functions to determine properties of integers and validate their correctness.
2. **Integer Manipulation Functions**: Functions to manipulate the digits of integers, such as pushing, popping, inserting, and swapping.
3. **Integer Inspection Functions**: Functions to inspect the digits of integers, including peeking at digits and accessing digits at specific indices.
4. **Utility Functions**: General-purpose utility functions for integer manipulation, concatenation, and appending zeros.
5. **String-Like Functions**: Functions to treat integers as strings, such as checking for containment, checking prefixes/suffixes, and reversing.
6. **Search Functions**: Functions to search for specific digits or numbers within integers.
7. **Remove Functions**: Functions to remove digits or numbers from integers, including removing specific occurrences or based on custom conditions.
8. **Reduction Functions**: Functions to reduce integers to single values, such as summing digits or applying custom reduction operations.
9. **Range Functions**: Functions to generate ranges of integers or extract sub-integers from existing integers.
10. **Sorting Functions**: Functions to sort the digits of integers.
11. **Divisibility Functions**: Functions to check the divisibility of integers by specific numbers.

## Function Categories

### Integer Properties and Validation Functions

These functions allow you to determine properties of integers and validate their correctness:
- `intk_length`: Calculate the number of digits in an integer.
- `intk_is_empty`: Check if an integer is empty (zero).
- `intk_in_range`: Check if an integer is within a specified range.
- `intk_index_ok`: Check if an index is valid for a given integer.

### Integer Manipulation Functions

These functions allow you to manipulate the digits of integers:
- `intk_push_front`: Insert a digit or number at the front of an integer.
- `intk_push_back`: Insert a digit or number at the back of an integer.
- `intk_pop_front_n`: Remove a specified number of digits from the front of an integer.
- `intk_pop_back_n`: Remove a specified number of digits from the back of an integer.
- `intk_pop_front`: Remove a digit from the front of an integer.
- `intk_pop_back`: Remove a digit from the back of an integer.
- `intk_insert`: Insert a digit or number at a specified index of an integer.

### Integer Inspection Functions

These functions allow you to inspect the digits of integers:
- `intk_front_n`: Get the first n digits of an integer.
- `intk_back_n`: Get the last n digits of an integer.
- `intk_front`: Get the first digit of an integer.
- `intk_back`: Get the last digit of an integer.
- `intk_at`: Get the digit at a specified index of an integer.

### Utility Functions

These functions provide general-purpose utility for integer manipulation:
- `intk_concat`: Concatenate multiple integers into a single integer.
- `intk_with_zeros`: Append zeros to an integer.
- `intk_set_digit`: Set the digit at a specified index of an integer.
- `intk_swap`: Swap the digits at specified indices of an integer.

### String-Like Functions

These functions treat integers as strings:
- `intk_contains`: Check if an integer contains a specific digit or number.
- `intk_startswith`: Check if an integer starts with a specific digit or number.
- `intk_endswith`: Check if an integer ends with a specific digit or number.
- `intk_reversed`: Reverse the digits of an integer.

### Search Functions

These functions allow you to search for specific digits or numbers within integers:
- `intk_find_first_of`: Find the index of the first occurrence of a specific digit or number.
- `intk_find_last_of`: Find the index of the last occurrence of a specific digit or number.

### Remove Functions

These functions allow you to remove digits or numbers from integers:
- `intk_remove_first_of`: Remove the first occurrence of a specific digit or number.
- `intk_remove_last_of`: Remove the last occurrence of a specific digit or number.
- `intk_remove_all`: Remove all occurrences of a specific digit or number.
- `intk_remove_digit_if`: Remove digits based on custom conditions.
- `intk_count_occurrences_of`: Count the number of occurrences of a specific digit or number.

### **Min and Max Functions**

These functions allow you to find the minimum and maximum digits in integers:
- `intk_min_digit`: Find the minimum digit in an integer.
- `intk_max_digit`: Find the maximum digit in an integer.

### Reduction Functions

These functions allow you to reduce integers to single values:
- `intk_reduce`: Reduce an integer using a binary operation and initial value.
- `intk_sum_digits`: Calculate the sum of digits in an integer.

### Range Functions

These functions allow you to generate ranges of integers or extract sub-integers:
- `intk_range`: Generate a range of integers with a specified start, stop, and step size.
- `intk_number_from_to`: Extract a sub-integer from an existing integer.

### Sorting Functions

These functions allow you to sort the digits of integers:
- `intk_bubble_sort`: Sort the digits of an integer using the bubble sort algorithm.
- `intk_selection_sort`: Sort the digits of an integer using the selection sort algorithm.
- `intk_insertion_sort`: Sort the digits of an integer using the insertion sort algorithm.
- `intk_merge_sort`: Sort the digits of an integer using the merge sort algorithm.

### Divisibility Functions

These functions allow you to check the divisibility of integers by specific numbers:
- `intk_divisible_by_2`: Check if an integer is divisible by 2.
- `intk_divisible_by_3`: Check if an integer is divisible by 3.
- `intk_divisible_by_4`: Check if an integer is divisible by 4.
- `intk_divisible_by_5`: Check if an integer is divisible by 5.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
