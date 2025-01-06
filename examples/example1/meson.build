project('integer-toolkit example', 'c',
  license: 'MIT',
  default_options: ['c_std=c11', 'warning_level=3']
)

integer_toolkit_subproject = subproject('integer-toolkit')
integer_toolkit_dep = integer_toolkit_subproject.get_variable('integer_toolkit_dep')

executable(
  'main',
  'src/main.c',
  dependencies: integer_toolkit_dep
)