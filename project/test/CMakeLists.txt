add_executable(MyProjectUnitTests myprojecttests.cpp)

find_package(GTest REQUIRED)

target_link_libraries(MyProjectUnitTests
  PRIVATE
  myproject::myproject
  GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(MyProjectUnitTests)
