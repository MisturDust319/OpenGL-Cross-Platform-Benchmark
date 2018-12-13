# OpenGL Cross Platform Benchmark 
### A tool for testing the performance of OpenGL across different operating systems
### Part of Stan Slupecki's Senior Research

## Overview

This is a simple OpenGL benchmark tool written in C++. It is meant for use in Windows 10, Mac OSX, and Fedora. However, there is no reason to believe it shouldn't be portable to other systems.
The benchmark is simply a system of rotating gears that will increase in complexity at set intervals. The framerate will be used as a metric for how each system handles the benchmark, and will also be recorded at set intervals.

## Project Dependencies
- OpenGL
- [FreeGLUT](http://freeglut.sourceforge.net/) for IO management
- [GLEW](http://glew.sourceforge.net/) for loading OpenGL functions
- [GLM](https://glm.g-truc.net/0.9.9/index.html) for mathematics

## Building and Running
This program is intended to be built on a Unix style environment with g++, even on Windows. I used [Cygwin](https://www.cygwin.com/) to build this program in Windows. Asides from setting up X Windows/X Org on Windows (which I will leave up to whoever builds this, I used Cygwin and it's xinit package), running the runExperiment.sh script should make the program, and run the benchmark 5 times, creating 5 CSV files with the benchmark results in the newly created 'results' folder in the project directory. The makefiles can also be manually run, with the Windows makefile being the default makefile, OSX makefile being makefile.osx, and the Fedora/Linux makefile being makefile.fedora.
