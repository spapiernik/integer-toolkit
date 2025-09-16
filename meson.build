project(
  'integer-toolkit',
  'c',
  version: '1.3.4',
  default_options: ['default_library=static', 'c_std=c11', 'warning_level=3'],
  license: 'MIT',
  license_files: ['LICENSE'],
  meson_version: '>=1.3.0'
)

intk_incdir = include_directories('include')

intk_lib = library(
  'integer-toolkit',
  'src/integer_toolkit.c',
  include_directories: intk_incdir
)

intk_dep = declare_dependency(
  link_with: intk_lib,
  include_directories: intk_incdir
)

unity_subproject = subproject('unity')
unity_dependency = unity_subproject.get_variable('unity_dep')
unity_gen_runner = unity_subproject.get_variable('gen_test_runner')

test_cases = [
  ['TestDivisibilityFunctions', 'Test Divisibility Functions'],
  ['TestIntegerInspection', 'Test Integer Inspection Functions'],
  ['TestIntegerManipulation', 'Test Integer Manipulation Functions'],
  ['TestIntegerProperties', 'Test Integer Properties and Validation Functions'],
  ['TestMinMaxFunctions', 'Test Min and Max Functions'],
  ['TestOccurrenceCounting', 'Test Occurrence Counting Functions'],
  ['TestRangeFunctions', 'Test Range Functions'],
  ['TestReductionFunctions', 'Test Reduction Functions'],
  ['TestRemoveFunctions', 'Test Remove Functions'],
  ['TestSearchFunctions', 'Test Search Functions'],
  ['TestSortingFunctions', 'Test Sorting Functions'],
  ['TestStringLikeFunctions', 'Test String-Like Functions'],
  ['TestUtilityFunctions', 'Test Utility Functions']
]

foreach test_case : test_cases
  testname = test_case[0]
  filename = testname + '.c'
  description = test_case[1]

  exe = executable(
    testname,
    [
      'tests' / filename,
      unity_gen_runner.process('tests' / filename)
    ],
    link_with: intk_lib,
    include_directories: [intk_incdir],
    dependencies: [unity_dependency]
  )

  test(testname, exe)
endforeach
