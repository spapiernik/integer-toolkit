#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

#include "integer_toolkit.h"

// Integer Properties and Validation Functions

unsigned int intk_length(int number) {
    if (number == 0) return 1;
    return (unsigned int) floor(log10(abs(number))) + 1;
}

int intk_is_empty(int number) {
    if (number == 0) {
        return 1;
    }
    return 0;
}

int intk_in_range(int number, int start, int stop) {
    return number >= start && number < stop;
}

int intk_index_ok(int number, int index) {
    return intk_in_range(index, 0, intk_length(number));
}

// Integer Manipulation Functions

void intk_push_front(int *number, int digit_or_number) {
    if (!intk_is_empty(*number)) {
        *number += intk_with_zeros(digit_or_number, intk_length(*number));
    }
    else {
        *number = digit_or_number;
    }
}

void intk_push_back(int *number, int digit_or_number) {
    *number = intk_with_zeros(*number, intk_length(digit_or_number)) + digit_or_number;
}

int intk_pop_front_n(int *number, int n) {
    int popped_value = intk_front_n(*number, n);
    *number = intk_back_n(*number, (int) fdim(intk_length(*number), n));
    return popped_value;
}

int intk_pop_back_n(int *number, int n) {
    int popped_value = intk_back_n(*number, n);
    *number = intk_front_n(*number, (int) fdim(intk_length(*number), n));
    return popped_value;
}

int intk_pop_front(int *number) {
    return intk_pop_front_n(number, 1);
}

int intk_pop_back(int *number) {
    return intk_pop_back_n(number, 1);
}

void intk_insert(int *number, int index, int digit_or_number) {
    index = intk_clamp(index, 0, intk_length(*number));

    unsigned int number_length = intk_length(*number);
    int popped_value = intk_pop_back_n(number, number_length - index);

    intk_push_back(number, digit_or_number);
    if (!intk_is_empty(popped_value)) {
        intk_push_back(number, popped_value);
    }
}

// Integer Inspection Functions

int intk_front_n(int number, int n) {
    return (int) floor(number / pow(10, fdim(intk_length(number), n)));
}

int intk_back_n(int number, int n) {
    return number % (int) pow(10, n);
}

int intk_front(int number) {
    return intk_front_n(number, 1);
}

int intk_back(int number) {
    return intk_back_n(number, 1);
}

int intk_at(int number, int index) {
    assert(intk_index_ok(number, index));
    return intk_back(intk_front_n(number, index + 1));
}

// Utility Functions

int intk_concat(int argc, ...){
    va_list argv;
    va_start(argv, argc);

    int result = 0;

    for (int i = 0; i < argc; ++i) {
        int number = va_arg(argv, int);
        if (number < 0) continue;

        intk_push_back(&result, number);
    }

    va_end(argv);
    return result;
}

int intk_with_zeros(int number, int quantity) {
    assert(quantity >= 0);
    return number * (int) floor(pow(10, quantity));
}

void intk_set_digit(int *number, int index, int digit_or_number) {
    assert(intk_index_ok(*number, index));
    int number_length = intk_length(*number);
    int bn = intk_back_n(*number, fdim(intk_length(*number), index + 1));
    int fn = intk_front_n(*number, index);

    int bn_expected_length = fdim(intk_length(*number), index + 1);
    int bn_length = intk_length(bn);

    if (index == 0) {
        fn = -1;
    }
    if (index == number_length - 1) {
        bn = -1;
    }
    *number = intk_concat(3, fn, intk_with_zeros(digit_or_number, (int) fdim(bn_expected_length, bn_length)), bn);
}

void intk_swap(int *number, int i, int j) {
    assert(intk_index_ok(*number, i));
    assert(intk_index_ok(*number, j));

    if (i == j) {
        return;
    }

    if (i == 0) {
        int z = i;
        i = j;
        j = z;
    }
    
    int tmp_i = intk_at(*number, i);
    intk_set_digit(number, i, intk_at(*number, j));
    intk_set_digit(number, j, tmp_i);
}

int intk_clamp(int number, int min, int max) {
    if (number < min) {
        return min;
    }
    else if (number > max) {
        return max;
    }
    return number;
}

// String-Like Functions

int intk_contains(int number, int digit_or_number) {
    return intk_find_first_of(number, digit_or_number) != -1;
}

int intk_startswith(int number, int digit_or_number) {
    return intk_front_n(number, intk_length(digit_or_number)) == digit_or_number;
}

int intk_endswith(int number, int digit_or_number) {
    return intk_back_n(number, intk_length(digit_or_number)) == digit_or_number;
}

int intk_reversed(int number) {
    int result = 0;
    while (!intk_is_empty(number)) {
        intk_push_back(&result, intk_pop_back(&number));
    }
    return result;
}

// Search Functions

int intk_find_first_of(int number, int digit_or_number) {
    int number_length = intk_length(number);
    int digit_or_number_length = intk_length(digit_or_number);
    for (int from = 0; from + digit_or_number_length <= number_length; from += 1) {
        if (intk_number_from_to(number, from, from + digit_or_number_length) == digit_or_number) {
            return from;
        }
    }
    return -1;
}

int intk_find_last_of(int number, int digit_or_number) {
    int number_length = intk_length(number);
    int digit_or_number_length = intk_length(digit_or_number);
    
    for (int to = number_length; to - digit_or_number_length >= 0; to -= 1) {
        if (intk_number_from_to(number, to - digit_or_number_length, to) == digit_or_number) {
            return to - digit_or_number_length;
        }
    }
    return -1;
}

// Remove Functions

void intk_remove_first_of(int *number, int digit_or_number) {
    int index = intk_find_first_of(*number, digit_or_number);
    assert(index != -1);

    int fn = intk_number_from_to(*number, 0, index);
    int bn = intk_number_from_to(*number, index + intk_length(digit_or_number), intk_length(*number));
    if (intk_is_empty(bn)) {
        bn = -1;
    }
    *number = intk_concat(2, fn, bn);
}

void intk_remove_last_of(int *number, int digit_or_number) {
    int index = intk_find_last_of(*number, digit_or_number);
    assert(index != -1);

    int fn = intk_number_from_to(*number, 0, index);
    int bn = intk_number_from_to(*number, index + intk_length(digit_or_number), intk_length(*number));
    if (intk_is_empty(bn)) {
        bn = -1;
    }
    *number = intk_concat(2, fn, bn);
}

void intk_remove_all(int *number, int digit_or_number) {
    while (intk_contains(*number, digit_or_number)) {
        intk_remove_first_of(number, digit_or_number);
    }
}

void intk_remove_digit_if(int *number, int(*predicate)(int)) {
    int result = 0;
    while (!intk_is_empty(*number)) {
        int popped_value = intk_pop_back(number);
        if (predicate(popped_value)) continue;
        else {
            intk_push_front(&result, popped_value);
        }
    }
    *number = result;
}

// Count Functions

int intk_count_occurrences_of(int number, int digit_or_number) {
    int number_length = intk_length(number);
    int digit_or_number_length = intk_length(digit_or_number);
    int counter = 0;
    for (int from = 0; from + digit_or_number_length <= number_length; ++from) {
        if (intk_number_from_to(number, from, from + digit_or_number_length) == digit_or_number) {
            counter += 1;
        }
    }
    return counter;
}

// Min Max Functions

int intk_max_digit(int number) {
    int number_length = intk_length(number);
    int max_digit = 0;
    for (int index = 0; index < number_length; ++index) {
        int current_digit = intk_at(number, index);
        if (current_digit > max_digit) {
            max_digit = current_digit;
        }
    }
    return max_digit;
}

int intk_min_digit(int number) {
    int number_length = intk_length(number);
    int min_digit = 9;
    for (int index = 0; index < number_length; ++index) {
        int current_digit = intk_at(number, index);
        if (current_digit < min_digit) {
            min_digit = current_digit;
        }
    }
    return min_digit;
}

// Reduction Functions

int intk_reduce(int number, int(*func)(int, int), int initial) {
    while (!intk_is_empty(number)) {
        unsigned int number_length = intk_length(number);
        int popped_value = intk_pop_front(&number);
        initial = func(initial, popped_value);
        if (intk_length(number) < number_length - 1) {
            initial = func(initial, 0);
        }
    }
    return initial;
}

int intk_sum_digits(int number) {
    int result = 0;
    while (!intk_is_empty(number)) {
        result += intk_pop_back(&number);
    }
    return result;
}

// Range Functions

int intk_range(int start, int stop, int step) {
    assert(start >= 0);
    assert(step > 0);
    assert(start <= stop);

    int result = 0;
    while (start < stop) {
        intk_push_back(&result, start);
        start += step;
    }

    return result;
}

int intk_number_from_to(int number, int from, int to) {
    int number_length = intk_length(number);
    assert(intk_in_range(from, 0, number_length + 1));
    assert(intk_in_range(to, 0, number_length + 1));
    assert(from <= to);

    (void) intk_pop_back_n(&number, intk_length(number) - to);
    return intk_back_n(number, (int) abs(to - from));
}

// Sorting Functions

void intk_bubble_sort(int *number) {
    intk_remove_all(number, 0);

    int iterations = intk_length(*number);
    for (int i = 0; i < iterations - 1; ++i) {
        for (int j = 0; j < iterations - 1; ++j) {
            if (intk_at(*number, j) > intk_at(*number, j + 1)) {
                intk_swap(number, j, j + 1);
            }
        }
    }
}

// Divisibility Functions

int intk_divisible_by_2(int number) {
    if (intk_back(number) % 2 == 0) {
        return 1;
    }
    return 0;
}

int intk_divisible_by_3(int number) {
    if (intk_sum_digits(number) % 3 == 0) {
        return 1;
    }
    return 0;
}

int intk_divisible_by_4(int number) {
    if (intk_back_n(number, 2) % 4 == 0) {
        return 1;
    }
    return 0;
}

int intk_divisible_by_5(int number) {
    if (intk_back(number) % 5 == 0) {
        return 1;
    }
    return 0;
}
