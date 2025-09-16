# Integer Toolkit

Suppose you have the number `12345` and you want to know how many digits it has,
check if it ends with `45`, or extract the first digit.

Instead of writing that logic yourself,
this library gives you ready-to-use functions like
`intk_length`, `intk_endswith`, and `intk_front` to do it directly.

## Example

```c
#include "integer_toolkit.h"
#include <stdio.h>

int main() {
    int number = 12345;

    printf("Original number: %d\n", number);
    printf("Number of digits: %u\n", intk_length(number));
    printf("Is number zero? %s\n", intk_is_empty(number) ? "Yes" : "No");
    printf(
      "Is number in range (1000-20000)? %s\n",
      intk_in_range(number, 1000, 20000) ? "Yes" : "No"
    );

    printf("First digit of %d: %d\n", number, intk_front(number));
    printf("Last digit of %d: %d\n", number, intk_back(number));
    printf("Digit at index 2 of %d: %d\n", number, intk_at(number, 2));

    printf(
      "Does %d contain the digit 3? %s\n", number,
      intk_contains(number, 3)? "Yes" : "No"
    );
    printf(
      "Does %d start with 12? %s\n", number,
      intk_startswith(number, 12)? "Yes" : "No"
    );
    printf(
      "Does %d end with 45? %s\n", number,
      intk_endswith(number, 45)? "Yes" : "No"
    );
}
```
