# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

set(CMAKE_MESSAGE_LOG_LEVEL DEBUG)

# Project name and version
project(MyCPlusPlusProject VERSION 1.0)

# Add your source code files
add_executable(MyCPlusPlusProject videoAnalyzer.cpp)

#find_package(PkgConfig REQUIRED)
# pkg_check_modules (OPENCV REQUIRED opencv)

include("C:/Users/joshl/source/repos/cpp/vcpkg/installed/x64-windows/share/opencv2/OpenCVConfig.cmake")

set(VCPKG_INSTALLED_DIR "C:/vcpkg/installed/x64-windows")

# Find the OpenCV package
set(OpenCV_DIR "C:/vcpkg/installed/x64-windows/share/opencv2/")
find_package(OpenCV REQUIRED)
target_link_libraries(MyCPlusPlusProject PRIVATE ${OpenCV_LIBS})

# Find the Leptonica package
set(Leptonica_DIR "C:/vcpkg/installed/x64-windows/share/Leptonica/")
find_package(Leptonica REQUIRED)

# Find the Tesseract package
set(Tesseract_DIR "C:/vcpkg/installed/x64-windows/share/tesseract/")
set(CURL_DIR "C:/vcpkg/installed/x64-windows/share/curl/")
set(ZLIB_INCLUDE_DIR "C:/vcpkg/installed/x64-windows/share/zlib/")
set(ZLIB_LIBRARY "C:/vcpkg/downloads/tools/msys2/d7266db249278763/usr/lib/perl5/core_perl/auto/Compress/Raw/Zlib")
set(LibArchive_LIBRARY "C:/vcpkg/downloads/tools/perl/5.38.0.1/c/bin")
set(LibArchive_INCLUDE_DIR "C:/vcpkg/installed/x64-windows/share/libarchive")


find_package(ZLIB REQUIRED)
find_package(Tesseract REQUIRED)
target_link_libraries(MyCPlusPlusProject PRIVATE ${Tesseract_LIBRARIES})
find_package(CURL REQUIRED)
#pkg_check_modules (find_package(LibArchive REQUIRED))
find_package(LibArchive REQUIRED)

# target_link_libraries(MyCPlusPlusProject PRIVATE ${LibArchive_LIBRARY})