#!/bin/bash

# Create a build directory if it doesn't exist
mkdir -p build
cd build

# Check if to build with CMake
if [ "$1" == "cmake" ]; then
    # Run CMake
    cmake ..

    # Check if CMake was successful
    if [ $? -ne 0 ]; then
        echo "CMake failed."
        exit 1
    fi
fi

# Run make
make

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Run the binary
./3D-Engine

# Check if binary execution was successful
if [ $? -ne 0 ]; then
    echo "Binary execution failed."
    exit 2
fi

echo "Execution finished successfully."
