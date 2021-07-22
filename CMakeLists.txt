# CMakeList.txt : CMake project for AUF_sim, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("AUF_sim")

include_directories(include)

# Add source to this project's executable.
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable (AUF_sim ${SOURCES} "main.cpp" "src/model.cpp" "src/jacobian.cpp" "include/jacobian.h" "include/matplotlib.h" "include/save_data.h" "src/save_data.cpp")


# TODO: Add tests and install targets if needed.
#find_path(MATPLOTLIB_CPP_INCLUDE_DIRS "matplotlibcpp.h"
#			HINTS
#			C:/Users/claudiop/dev/vcpkg/vcpkg/installed/x86-windows/include/)
#   target_include_directories(AUF_sim PRIVATE ${MATPLOTLIB_CPP_INCLUDE_DIRS})

#find_path(PYTHON_INCLUDE_DIRS "Python.h"
#			HINTS
#			C:/Users/claudiop/AppData/Local/Continuum/anaconda3/pkgs/python-3.9.4-h7840368_0_cpython/include/**)
#target_include_directories(AUF_sim PRIVATE ${PYTHON_INCLUDE_DIRS})

#find_path(NUMPY_ARR "numpy/arrayobject.h"
#			HINTS 
#			C:/Users/claudiop/AppData/Local/Continuum/anaconda3/pkgs/numpy-1.20.3-py39h6635163_0/Lib/site-packages/numpy/core/include/**)
#	target_include_directories(AUF_sim PRIVATE ${NUMPY_ARR})

#find_path(PY_LIB "python39.lib"
#			HINTS 
#			C:/Users/claudiop/AppData/Local/Continuum/anaconda3/pkgs/python-3.9.4-h7840368_0_cpython/libs/**)
#	target_link_directories(AUF_sim PRIVATE ${PY_LIB})
#link_directories(C:/Users/claudiop/AppData/Local/Continuum/anaconda3/pkgs/python-3.7.4-h5263a28_0/libs)
#link_directories(C:/Users/claudiop/AppData/Local/Continuum/anaconda3/pkgs/python-3.9.4-h7840368_0_cpython/libs/python39.lib)

find_package(GSL REQUIRED)
    target_link_libraries(AUF_sim PRIVATE GSL::gsl GSL::gslcblas)

