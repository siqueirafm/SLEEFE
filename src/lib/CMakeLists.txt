set (SLEEFELIB_INC ${CMAKE_CURRENT_SOURCE_DIR})
set (SLEEFELIB_SRC ${CMAKE_CURRENT_SOURCE_DIR})

file (GLOB HPP_FILES ${SLEEFELIB_INC}/*.hpp)
file (GLOB CPP_FILES ${SLEEFELIB_SRC}/*.cpp)

# Make a static library (omit STATIC if you want user setting to decide)
add_library(sleefe
  STATIC
    ${HPP_FILES}
    ${CPP_FILES}
)

# Library needs these directories, and its users will need them too
target_include_directories(sleefe
  PUBLIC 
    $<INSTALL_INTERFACE:include>
    ${SLEEFELIB_INC}
)

# All users of this library will need to have at C++ 17 or higher
target_compile_features(sleefe PUBLIC cxx_std_17)

# Set compiler options for MS Visual Studio and everything else
if (MSVC)
  if (NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(sleefe PRIVATE /W4 /WX- /O2 /MD)
  else ()
    target_compile_options(sleefe PRIVATE /W4 /WX- /MDd)
  endif ()
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  list (APPEND flags )
  if (NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(sleefe PRIVATE -Wall -Wextra -Werror -pedantic -O3)
  else ()
    target_compile_options(sleefe PRIVATE -Wall -Wextra -Werror -pedantic)
  endif ()
endif ()

source_group(
  TREE "${SLEEFELIB_INC}"
  PREFIX "Header Files"
  FILES ${HPP_FILES})

source_group(
  TREE "${SLEEFELIB_SRC}"
  PREFIX "Source Files"
  FILES ${CPP_FILES})

install(TARGETS sleefe DESTINATION lib)
install(FILES ${HPP_FILES} DESTINATION include)
