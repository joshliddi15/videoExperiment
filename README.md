# Overview

In this project I have worked a lot on broadening my exposure to c++ and I worked to develop a system which would allow me to retroactively review the output of various industrial equipment by running my system on a video recording of the display of the equipment. This is valuable as it allows me to spend time away from the shop floor working on other tasks, and still have visibility of the performance of any of our equipment. 

The system takes a video file path and uses the opencv package to process it, then applies some edits which improve the ability of the system to recognize the characters in the display using the tesseract package.

[Software Demo Video](https://youtu.be/dA9XalxYdbI)

# Development Environment

I built the system in visual studio and utilized the vcpkg installation manager to download and manage the various libraries and cmake to build the system. 

I intended to create the system in c++ but was unable to get the libarchive package to import correctly, so I resorted to developing a functional version of the system in python.

# Useful Websites

- [OpenCV docs](https://docs.opencv.org/4.8.0/index.html)
- [Tesseract docs](https://tesseract-ocr.github.io/tessdoc/Installation.html)
- [vcpkg docs](https://vcpkg.io/en/)

# Future Work

- Determine how to get packages to import correctly to allow cMake to build the project files
- Determine if any alterations are needed to allow the C++ version of the system to run as intended
- Improve photo editing or expore the possibility of creating custom training data to improve character recognition
- Create a custom user interface to allow users to more easily navigate and execute the program on various files
- Create a function to store and output data in an accessible format to allow for more long term data acquisition and monitoring
