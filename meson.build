project(
  'integer-toolkit',
  'c',
  version: '1.0.1',
  default_options: ['c_std=c11', 'warning_level=3'],
  license: 'MIT',
  license_files: 'LICENSE'
)

unity_subproject = subproject('unity')
unity_dependency = unity_subproject.get_variable('unity_dep')
unity_gen_runner = unity_subproject.get_variable('gen_test_runner')

integer_toolkit_incdir = include_directories('include')

integer_toolkit_lib = library(
  'integer-toolkit',
  'src/integer_toolkit.c',
  include_directories: integer_toolkit_incdir,
  install: true
)

test_cases = [
  ['TestDivisibilityFunctions.c', 'Test Divisibility Functions'],
  ['TestIntegerInspection.c', 'Test Integer Inspection Functions'],
  ['TestIntegerManipulation.c', 'Test Integer Manipulation Functions'],
  ['TestIntegerProperties.c', 'Test Integer Properties and Validation Functions'],
  ['TestMinMaxFunctions.c', 'Test Min and Max Functions'],
  ['TestOccurrenceCounting.c', 'Test Occurrence Counting Functions'],
  ['TestRangeFunctions.c', 'Test Range Functions'],
  ['TestReductionFunctions.c', 'Test Reduction Functions'],
  ['TestRemoveFunctions.c', 'Test Remove Functions'],
  ['TestSearchFunctions.c', 'Test Search Functions'],
  ['TestSortingFunctions.c', 'Test Sorting Functions'],
  ['TestStringLikeFunctions.c', 'Test String-Like Functions'],
  ['TestUtilityFunctions.c', 'Test Utility Functions']
]

foreach test_case : test_cases
  filename = test_case[0]
  description = test_case[1]

  test_executable = executable(
    'test_' + filename,
    [
      files(
        'src' / 'integer_toolkit.c',
        'test' / filename
      ),
      unity_gen_runner.process('test' / filename)
    ],
    link_with: integer_toolkit_lib,
    include_directories: [integer_toolkit_incdir],
    dependencies: [unity_dependency]
  )

  test(description, test_executable)
endforeach