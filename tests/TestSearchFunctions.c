#include "unity.h"
#include "integer_toolkit.h"

void test_find_first_of() {
  int number = 1234567890;

  TEST_ASSERT_EQUAL(0, intk_find_first_of(number, 1));
  TEST_ASSERT_EQUAL(1, intk_find_first_of(number, 2));
  TEST_ASSERT_EQUAL(2, intk_find_first_of(number, 3));
  TEST_ASSERT_EQUAL(3, intk_find_first_of(number, 4));
  TEST_ASSERT_EQUAL(4, intk_find_first_of(number, 5));
  TEST_ASSERT_EQUAL(5, intk_find_first_of(number, 6));
  TEST_ASSERT_EQUAL(6, intk_find_first_of(number, 7));
  TEST_ASSERT_EQUAL(7, intk_find_first_of(number, 8));
  TEST_ASSERT_EQUAL(8, intk_find_first_of(number, 9));
  TEST_ASSERT_EQUAL(9, intk_find_first_of(number, 0));

  TEST_ASSERT_EQUAL(0, intk_find_first_of(number, 12));
  TEST_ASSERT_EQUAL(2, intk_find_first_of(number, 34));
  TEST_ASSERT_EQUAL(4, intk_find_first_of(number, 567));
  TEST_ASSERT_EQUAL(7, intk_find_first_of(number, 890));
}

void test_find_last_of() {
  int number = 1876543210;

  TEST_ASSERT_EQUAL(8, intk_find_last_of(number, 1));
  TEST_ASSERT_EQUAL(7, intk_find_last_of(number, 2));
  TEST_ASSERT_EQUAL(6, intk_find_last_of(number, 3));
  TEST_ASSERT_EQUAL(5, intk_find_last_of(number, 4));
  TEST_ASSERT_EQUAL(4, intk_find_last_of(number, 5));
  TEST_ASSERT_EQUAL(3, intk_find_last_of(number, 6));
  TEST_ASSERT_EQUAL(2, intk_find_last_of(number, 7));
  TEST_ASSERT_EQUAL(1, intk_find_last_of(number, 8));
  TEST_ASSERT_EQUAL(-1, intk_find_last_of(number, 9));
  TEST_ASSERT_EQUAL(9, intk_find_last_of(number, 0));

  TEST_ASSERT_EQUAL(8, intk_find_last_of(number, 10));
  TEST_ASSERT_EQUAL(3, intk_find_last_of(number, 6543));
  TEST_ASSERT_EQUAL(1, intk_find_last_of(number, 876));
  TEST_ASSERT_EQUAL(1, intk_find_last_of(number, 876543210));
}