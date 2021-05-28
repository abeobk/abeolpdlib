cmake_minimum_required(VERSION 3.2)
project(test_lpd)

find_package(OpenCV REQUIRED)

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    /usr/include/abeolpdlib/
)

add_executable(${PROJECT_NAME} test_lpd.cpp)

target_link_libraries(${PROJECT_NAME} 
    ${OpenCV_LIBS}
    abeolpd
)
