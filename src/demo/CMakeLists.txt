set (DEMO_SRC ${CMAKE_CURRENT_SOURCE_DIR})

set (SLEEFE_INC ${CMAKE_CURRENT_SOURCE_DIR}/../../lib)

file (GLOB CPP_FILES ${DEMO_SRC}/*.cpp)

add_executable(sleefe-demo "")

target_compile_features(sleefe-demo PRIVATE cxx_std_17)

if (MSVC)
  if (NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(sleefe-demo PRIVATE /W4 /WX- /O2 /MD)
  else ()
    target_compile_options(sleefe-demo PRIVATE /W4 /WX- /MDd)
  endif ()
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  if (NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(sleefe-demo PRIVATE -Wall -Wextra -Werror -pedantic -O3)
  else ()
    target_compile_options(sleefe-demo PRIVATE -Wall -Wextra -Werror -pedantic)
  endif ()
endif ()

target_sources(sleefe-demo PRIVATE ${CPP_FILES})

target_include_directories(
  sleefe-demo
    PRIVATE
       ${SLEEFE_INC}
)

target_link_libraries(
  sleefe-demo
    PRIVATE
      sleefe
)

install(TARGETS sleefe-demo DESTINATION bin)
