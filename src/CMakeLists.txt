list (APPEND petsc_fem_SRCS
  femcontroller.cpp
  main.cpp
  settings.cpp
)

add_executable (petsc_fem ${petsc_fem_SRCS})
target_link_libraries (petsc_fem ${petsc_fem_DEPENDENT_LIBRARIES})
