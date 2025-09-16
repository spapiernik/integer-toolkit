#include "unity.h"
#include "integer_toolkit.h"

void test_max_digit() {
  TEST_ASSERT_EQUAL(9, intk_max_digit(1234567890));
  TEST_ASSERT_EQUAL(3, intk_max_digit(132));
  TEST_ASSERT_EQUAL(1, intk_max_digit(101));
}

void test_min_digit() {
  TEST_ASSERT_EQUAL(0, intk_min_digit(1234567890));
  TEST_ASSERT_EQUAL(1, intk_min_digit(132));
  TEST_ASSERT_EQUAL(0, intk_min_digit(101));
}