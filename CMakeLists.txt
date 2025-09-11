cmake_minimum_required(VERSION 3.20)
project(opencv_to_onnxruntime_cpp_cli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Let CLion see real compiler flags/paths
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# OpenCV via pkg-config (installed by Homebrew)
find_package(PkgConfig REQUIRED)
pkg_check_modules(OPENCV REQUIRED IMPORTED_TARGET opencv4)

add_executable(app src/main.cpp)

# Link the imported target so include/lib flags propagate to 'app'
target_link_libraries(app PRIVATE PkgConfig::OPENCV)