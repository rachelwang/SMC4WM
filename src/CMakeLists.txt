cmake_minimum_required(VERSION 3.5)
project (SC CXX)

add_definitions(-std=c++11)
#Boost
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.45.0 COMPONENTS regex)
if(Boost_FOUND)
include_directories(${Boost_INCLUDE_DIRS})
set(EXTRA_LIBS ${Boost_LIBRARIES} ${EXTRA_LIBS})
endif()
# GSL
find_package(GSL REQUIRED)
include_directories(${GSL_INCLUDE_DIRS})
set(EXTRA_LIBS ${EXTRA_LIBS} ${GSL_LIBRARIES})
# OpenMP
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()
set(CMAKE_EXE_LINKER_FLAGS "-fopenmp")

include_directories(${SC_SOURCE_DIR})

add_executable(SMC_wm ${CMAKE_SOURCE_DIR}/SMC_wm.cpp)
target_link_libraries(SMC_wm ${EXTRA_LIBS})

add_library(BN ${CMAKE_SOURCE_DIR}/BN.cpp)
set(SC_LIBS ${SC_LIBS} BN)
add_library(DBN ${CMAKE_SOURCE_DIR}/DBN.cpp)
set(SC_LIBS ${SC_LIBS} DBN)
add_library(CPD ${CMAKE_SOURCE_DIR}/CPD.cpp)
set(SC_LIBS ${SC_LIBS} CPD)
add_library(Sampler ${CMAKE_SOURCE_DIR}/Sampler.cpp)
set(SC_LIBS ${SC_LIBS} Sampler)
add_library(Tools ${CMAKE_SOURCE_DIR}/Tools.cpp)
set(SC_LIBS ${SC_LIBS} Tools)
add_library(checker ${CMAKE_SOURCE_DIR}/checker.cpp)
set(SC_LIBS ${SC_LIBS} checker)
add_library(interface ${CMAKE_SOURCE_DIR}/interface.cpp)
set(SC_LIBS ${SC_LIBS} interface)
add_library(parser.tab ${CMAKE_SOURCE_DIR}/parser.tab.cpp)
set(SC_LIBS ${SC_LIBS} parser.tab)


add_library(SampleChecker ${CMAKE_SOURCE_DIR}/SampleChecker.cpp)
set(EXTRA_LIBS1 ${EXTRA_LIBS1} SampleChecker)
set(EXTRA_LIBS1 ${SC_LIBS} ${EXTRA_LIBS1})
add_executable (Check ${EXTRA_LIBS1})



