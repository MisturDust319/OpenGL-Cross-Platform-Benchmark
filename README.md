# OpenGL Cross Platform Benchmark 
### A tool for testing the performance of OpenGL across different operating systems
### Part of Stan Slupecki's Senior Research

##Overview

This is a simple OpenGL benchmark tool written in C++. It is meant for use in Windows 10, Mac OSX, and Fedora. However, there is no reason to believe it shouldn't be portable to other systems.
The benchmark is simply a system of rotating gears that will increase in complexity at set intervals. The framerate will be used as a metric for how each system handles the benchmark, and will also be recorded at set intervals.

## Project Dependencies
-OpenGL
-[GLFW](https://www.glfw.org/) for IO management
-[GLAD](https://glad.dav1d.de/) for loading OpenGL functions
-[GLM](https://glm.g-truc.net/0.9.9/index.html) for mathematics