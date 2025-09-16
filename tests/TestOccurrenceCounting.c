#include "unity.h"
#include "integer_toolkit.h"

void test_count_occurrences_of() {
  TEST_ASSERT_EQUAL(2, intk_count_occurrences_of(133, 3));
  TEST_ASSERT_EQUAL(1, intk_count_occurrences_of(133, 33));
  TEST_ASSERT_EQUAL(3, intk_count_occurrences_of(71191, 1));
  TEST_ASSERT_EQUAL(0, intk_count_occurrences_of(71191, 8));
}