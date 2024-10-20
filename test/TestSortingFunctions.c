#include "unity.h"
#include "integer_toolkit.h"

void test_bubble_sort() {
  int number;

  number = 15479;
  intk_bubble_sort(&number);
  TEST_ASSERT_EQUAL(14579, number);
  number = 1001;
  intk_bubble_sort(&number);
  TEST_ASSERT_EQUAL(11, number);
}