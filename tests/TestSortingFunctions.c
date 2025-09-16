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

void test_selection_sort() {
  int number;

  number = 15479;
  intk_selection_sort(&number);
  TEST_ASSERT_EQUAL(14579, number);
  number = 1001;
  intk_selection_sort(&number);
  TEST_ASSERT_EQUAL(11, number);
}

void test_insertion_sort() {
  int number;

  number = 15479;
  intk_insertion_sort(&number);
  TEST_ASSERT_EQUAL(14579, number);
  number = 1001;
  intk_insertion_sort(&number);
  TEST_ASSERT_EQUAL(11, number);
}

void test_merge_sort() {
  int number;

  number = 15479;
  intk_merge_sort(&number, 0, intk_length(number) - 1);
  TEST_ASSERT_EQUAL(14579, number);
  number = 1001;
  intk_merge_sort(&number, 0, intk_length(number) - 1);
  TEST_ASSERT_EQUAL(11, number);
  number = 9090100;
  intk_merge_sort(&number, 0, intk_length(number) - 1);
  TEST_ASSERT_EQUAL(199, number);
}