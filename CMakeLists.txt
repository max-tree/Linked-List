cmake_minimum_required(VERSION 3.10)

project(LinkedList)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED 1)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

FIND_PACKAGE(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(${PROJECT_NAME} STATIC
	LinkedList.hpp
	LinkedList.cpp
  )

set(TEST_NAME ${PROJECT_NAME}_UnitTest)

add_executable(${TEST_NAME}
    AcceptanceTest_UnitTest.cpp
    CreateLinkedListHeadOrNode_UnitTest.cpp
    AddItemToEndOfList_UnitTest.cpp
    GetLinkedListLength_UnitTest.cpp
    AssignNodeXToPointToNodeY_UnitTest.cpp
    AddItemToBeginningOfList_UnitTest.cpp
    ConvertLinkedListToString.cpp
    )

target_link_libraries(${TEST_NAME}  ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} ${PROJECT_NAME})

