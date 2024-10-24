#ifndef INTEGER_TOOLKIT_H
#define INTEGER_TOOLKIT_H

// Integer Properties and Validation Functions
unsigned int intk_length(int number); // Calculate the number of digits in a given integer.
int intk_is_empty(int number); // Check if the given integer is empty (zero).
int intk_in_range(int number, int start, int stop); // Check if the given integer is within the specified range.
int intk_index_ok(int number, int index); // Check if the index is valid for the given integer.

// Integer Manipulation Functions
void intk_push_front(int *number, int digit_or_number); // Insert a digit or number at the front of the given integer.
void intk_push_back(int *number, int digit_or_number); // Insert a digit or number at the back of the given integer.
int intk_pop_front_n(int *number, int n); // Remove n digits from the front of the given integer.
int intk_pop_back_n(int *number, int n); // Remove n digits from the back of the given integer.
int intk_pop_front(int *number); // Remove a digit from the front of the given integer.
int intk_pop_back(int *number); // Remove a digit from the back of the given integer.
void intk_insert(int *number, int index, int digit_or_number); // Insert a digit or number at the specified index of the given integer.

// Integer Inspection Functions
int intk_front_n(int number, int n); // Get the first n digits of the given integer.
int intk_back_n(int number, int n); // Get the last n digits of the given integer.
int intk_front(int number); // Get the first digit of the given integer.
int intk_back(int number); // Get the last digit of the given integer.
int intk_at(int number, int index); // Get the digit at the specified index of the given integer.

// Utility Functions
int intk_concat(int n, ...); // Concatenate multiple integers into a single integer.
int intk_with_zeros(int number, int quantity); // Append zeros to the given integer.
void intk_set_digit(int *number, int index, int value); // Set the digit at the specified index of the given integer to the given value.
void intk_swap(int *number, int i, int j); // Swap the digits at the specified indices of the given integer.
int intk_clamp(int number, int min, int max); // Clamps a value within the specified minimum and maximum range.

// String-Like Functions
int intk_contains(int number, int digit_or_number); // Check if the given integer contains a specific digit or number.
int intk_startswith(int number, int digit_or_number); // Check if the given integer starts with a specific digit or number.
int intk_endswith(int number, int digit_or_number); // Check if the given integer ends with a specific digit or number.
int intk_reversed(int number); // Reverse the digits of the given integer.

// Search Functions
int intk_find_first_of(int number, int digit_or_number); // Find the index of the first occurrence of a specific digit or number in the given integer.
int intk_find_last_of(int number, int digit_or_number); // Find the index of the last occurrence of a specific digit or number in the given integer.

// Remove Functions
void intk_remove_first_of(int *number, int digit_or_number); // Remove the first occurrence of a specific digit or number from the given integer.
void intk_remove_last_of(int *number, int digit_or_number); // Remove the last occurrence of a specific digit or number from the given integer.
void intk_remove_all(int *number, int digit_or_number); // Remove all occurrences of a specific digit or number from the given integer.
void intk_remove_digit_if(int *number, int(*predicate)(int)); // Remove digits from the given integer based on a predicate function.
int intk_count_occurrences_of(int number, int digit_or_number); // Count the number of occurrences of a specific digit or number in the given integer.
int intk_max_digit(int number); // Find the maximum digit in the given integer.
int intk_min_digit(int number); // Find the minimum digit in the given integer.

// Reduction Functions
int intk_reduce(int number, int(*func)(int, int), int initial); // Reduce the given integer using the specified binary operation and initial value.
int intk_sum_digits(int number); // Calculate the sum of digits in the given integer.

// Range Functions
int intk_range(int start, int stop, int step); // Generate a range of integers from start to stop (exclusive) with a specified step size.
int intk_number_from_to(int number, int from, int to); // Extract a sub-integer from the given integer, starting from the "from" index and ending at the "to" index.

// Sorting Functions
void intk_bubble_sort(int *number); // Sort the digits of the given integer using bubble sort algorithm.
void intk_selection_sort(int *number); // Sort the digits of the given integer using selection sort algorithm.

// Divisibility Functions
int intk_divisible_by_2(int number); // Check if the given integer is divisible by 2.
int intk_divisible_by_3(int number); // Check if the given integer is divisible by 3.
int intk_divisible_by_4(int number); // Check if the given integer is divisible by 4.
int intk_divisible_by_5(int number); // Check if the given integer is divisible by 5.

#endif /* INTEGER_TOOLKIT_H */
