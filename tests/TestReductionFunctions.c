#include "unity.h"
#include "integer_toolkit.h"

int add(int x, int y) {
  return x + y;
}

int multiply(int x, int y) {
  return x * y;
}

void test_reduce() {
  TEST_ASSERT_EQUAL(6, intk_reduce(123, add, 0));
  TEST_ASSERT_EQUAL(7, intk_reduce(123, add, 1));
  TEST_ASSERT_EQUAL(8, intk_reduce(123, add, 2));

  TEST_ASSERT_EQUAL(24, intk_reduce(234, multiply, 1));
  TEST_ASSERT_EQUAL(0, intk_reduce(234, multiply, 0));
}

void test_sum_digits() {
  TEST_ASSERT_EQUAL(10, intk_sum_digits(1234));
  TEST_ASSERT_EQUAL(4, intk_sum_digits(22));
  TEST_ASSERT_EQUAL(2, intk_sum_digits(101));
  TEST_ASSERT_EQUAL(2, intk_sum_digits(200));
}