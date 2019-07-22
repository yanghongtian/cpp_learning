cmake_minimum_required(VERSION 3.5)



project(gtest)


add_executable(${PROJECT_NAME} 
    gtest.cpp
)

target_link_libraries(${PROJECT_NAME}
    ${GTEST_LIBRARIES}
    pthread
)


