cmake_minimum_required (VERSION 2.6)
project (petsc_fem)

list (APPEND CMAKE_MODULE_PATH "${petsc_fem_SOURCE_DIR}/cmake-modules")

find_package (PETSc REQUIRED)


option (DEBUG_OUT              "Compile with extra debugging messages"                      ON)
option (WARN_ALL               "Enable all GCC's warning messages"                          ON)
option (WARN_AS_ERROR          "Make all warnings into errors"                              ON)

if (WARN_ALL)
  add_definitions (-Werror)
endif ()

if (WARN_ALL)
  add_definitions (-Wall)
endif ()


set (Boost_USE_STATIC_LIBS   ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_ADDITIONAL_VERSIONS "1.44" "1.44.0")
find_package(Boost COMPONENTS program_options system REQUIRED)
include_directories(${Boost_INCLUDE_DIRS}) 


set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${petsc_fem_BINARY_DIR}/bin CACHE PATH "Output directory for Dohp executables")

configure_file (${petsc_fem_SOURCE_DIR}/config.h.in
  ${petsc_fem_BINARY_DIR}/include/config.h @ONLY)

set (petsc_fem_DEPENDENT_LIBRARIES "${PETSC_LIBRARIES}" "${Boost_PROGRAM_OPTIONS_LIBRARY}")

include_directories ("${petsc_fem_SOURCE_DIR}/include" "${petsc_fem_BINARY_DIR}/include" ${PETSC_INCLUDES})
add_definitions (${PETSC_DEFINITIONS})


add_subdirectory (include)
add_subdirectory (src)