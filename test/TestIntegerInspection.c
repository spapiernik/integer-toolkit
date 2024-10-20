#include "unity.h"
#include "integer_toolkit.h"

void test_front_n() {
  int number = 1234567890;

  TEST_ASSERT_EQUAL(1, intk_front_n(number, 1));
  TEST_ASSERT_EQUAL(12, intk_front_n(number, 2));
  TEST_ASSERT_EQUAL(123, intk_front_n(number, 3));
  TEST_ASSERT_EQUAL(1234, intk_front_n(number, 4));
  TEST_ASSERT_EQUAL(12345, intk_front_n(number, 5));
  TEST_ASSERT_EQUAL(123456, intk_front_n(number, 6));
  TEST_ASSERT_EQUAL(1234567, intk_front_n(number, 7));
  TEST_ASSERT_EQUAL(12345678, intk_front_n(number, 8));
  TEST_ASSERT_EQUAL(123456789, intk_front_n(number, 9));
  TEST_ASSERT_EQUAL(1234567890, intk_front_n(number, 10));
}

void test_front() {
  TEST_ASSERT_EQUAL(1, intk_front(1234567890));
  TEST_ASSERT_EQUAL(2, intk_front(234567890));
  TEST_ASSERT_EQUAL(3, intk_front(34567890));
  TEST_ASSERT_EQUAL(4, intk_front(4567890));
  TEST_ASSERT_EQUAL(5, intk_front(567890));
  TEST_ASSERT_EQUAL(6, intk_front(67890));
  TEST_ASSERT_EQUAL(7, intk_front(7890));
  TEST_ASSERT_EQUAL(8, intk_front(890));
  TEST_ASSERT_EQUAL(9, intk_front(90));
  TEST_ASSERT_EQUAL(0, intk_front(0));
}

void test_back_n() {
  int number = 1234567890;

  TEST_ASSERT_EQUAL(0, intk_back_n(number, 1));
  TEST_ASSERT_EQUAL(90, intk_back_n(number, 2));
  TEST_ASSERT_EQUAL(890, intk_back_n(number, 3));
  TEST_ASSERT_EQUAL(7890, intk_back_n(number, 4));
  TEST_ASSERT_EQUAL(67890, intk_back_n(number, 5));
  TEST_ASSERT_EQUAL(567890, intk_back_n(number, 6));
  TEST_ASSERT_EQUAL(4567890, intk_back_n(number, 7));
  TEST_ASSERT_EQUAL(34567890, intk_back_n(number, 8));
  TEST_ASSERT_EQUAL(234567890, intk_back_n(number, 9));
  TEST_ASSERT_EQUAL(1234567890, intk_back_n(number, 10));
}

void test_back() {
  TEST_ASSERT_EQUAL(0, intk_back(1234567890));
  TEST_ASSERT_EQUAL(9, intk_back(123456789));
  TEST_ASSERT_EQUAL(8, intk_back(12345678));
  TEST_ASSERT_EQUAL(7, intk_back(1234567));
  TEST_ASSERT_EQUAL(6, intk_back(123456));
  TEST_ASSERT_EQUAL(5, intk_back(12345));
  TEST_ASSERT_EQUAL(4, intk_back(1234));
  TEST_ASSERT_EQUAL(3, intk_back(123));
  TEST_ASSERT_EQUAL(2, intk_back(12));
  TEST_ASSERT_EQUAL(1, intk_back(1));
}

void test_at() {
  int number = 1234567890;

  TEST_ASSERT_EQUAL(1, intk_at(number, 0));
  TEST_ASSERT_EQUAL(2, intk_at(number, 1));
  TEST_ASSERT_EQUAL(3, intk_at(number, 2));
  TEST_ASSERT_EQUAL(4, intk_at(number, 3));
  TEST_ASSERT_EQUAL(5, intk_at(number, 4));
  TEST_ASSERT_EQUAL(6, intk_at(number, 5));
  TEST_ASSERT_EQUAL(7, intk_at(number, 6));
  TEST_ASSERT_EQUAL(8, intk_at(number, 7));
  TEST_ASSERT_EQUAL(9, intk_at(number, 8));
  TEST_ASSERT_EQUAL(0, intk_at(number, 9));
}