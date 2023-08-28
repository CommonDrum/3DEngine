# introduction

This program is a custom-built renderer designed to provide efficient and high-quality rendering for both 2D and 3D graphics. Developed with flexibility and extensibility in mind, it integrates seamlessly with various projects, making it an ideal choice for game engines, simulations, and other graphics-intensive applications.
Features

    Efficient Batching: Reduces the number of draw calls by batching multiple objects together.
    Versatile Rendering: Supports both 2D and 3D graphics with a unified API.
    Custom Shader Support: Easily integrate custom shaders to achieve unique visual effects.
    Platform Compatibility: Designed to work on multiple platforms, including Windows, macOS, and Linux.

# Setup

Setting up the renderer is a straightforward process. Follow the instructions below based on your operating system.
## Linux
Prerequisites:

Ensure you have the following dependencies installed:

    CMake (version >= 3.10)
    OpenGL
    GLFW
    GLEW
    [Any other dependencies]

If you're unsure about any missing dependencies, don't worry. CMake will notify you if something is amiss.
Building and Running:

    Using the run.sh Script:

    The provided run.sh script simplifies the build and run process.

        Generate Build Files:

        bash

./run.sh cmake

This command prepares the build environment by generating necessary files.

Build, Compile, and Run:

bash

    ./run.sh

    This command compiles the source files and runs the renderer. It uses the files from the "build" directory.

### Manual Setup:

If you prefer not to use the run.sh script, you can manually set up the build process:

bash

    mkdir build
    cd build
    cmake ..
    make
    ./YourRendererExecutable

# Troubleshooting:

    CMake Errors: If CMake throws an error about missing dependencies, ensure you've installed all required libraries and tools. Use your package manager (like apt, yum, or pacman) to install missing packages.

    Runtime Errors: Ensure your graphics drivers are up-to-date. Some features might require modern GPU support.

