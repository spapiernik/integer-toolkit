project('integer-toolkit example', 'c',
  license: 'MIT',
  default_options: ['c_std=c11', 'warning_level=3']
)

intk_subproject = subproject('integer-toolkit')
intk_dep = intk_subproject.get_variable('integer_toolkit_dep')

executable(
  'main',
  'src/main.c',
  dependencies: intk_dep
)
