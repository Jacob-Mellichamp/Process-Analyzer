cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(Process_Analyzer VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set CMAKE to generate a .lib file along side a .dll 
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Add the Process_Query directory to the build
add_library(ProcessQuery SHARED 
    src/ProcessQuery/ProcessQuery.cpp 
)

# Include directories for ProcessQuery library
target_include_directories(ProcessQuery PRIVATE src/Process_Query)

# Create the main executable
add_executable(Process_Analyzer src/main.cpp)

# Link the ProcessQuery library with the main executable
target_link_libraries(Process_Analyzer PRIVATE ProcessQuery)