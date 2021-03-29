# This file is part of MultiCol-SLAM
#
# Copyright (C) 2015-2016 Steffen Urban <rurbste at googlemail.com>
# For more information see <https://github.com/urbste/MultiCol-SLAM>
#
# MultiCol-SLAM is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# MultiCol-SLAM is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with MultiCol-SLAM . If not, see <http://www.gnu.org/licenses/>.

project (MultiCol-SLAM)

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
ENDIF()


SET (MCSSLAM_LIB_TYPE SHARED)

MESSAGE("Build type: " ${CMAKE_BUILD_TYPE})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp -O3 -march=native -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -O3 -march=native -std=c++11")

# LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)
# message(STATUS "HI!!!!")
# LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV)
# message(STATUS ${CMAKE_MODULE_PATH})
# find_package(OpenCV 3.4 EXACT REQUIRED PATHS "${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV")
find_package(Pangolin REQUIRED)


# ==============================================================================
# Search OpenCV
# ============================================================================== 
# SET(OpenCV_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/include)
# SET(OpenCV_LIBRARIES opengv)
# MESSAGE("OpenCV include DIR ${OpenCV_INCLUDE_DIR}")
# INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIR})

# SET(OpenCV_INCLUDE_TEST ${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/build)

# INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_TEST})


# ==============================================================================
# Search OpenGV
# ============================================================================== 
#FIND_PACKAGE(OpenGV QUIET HINTS ${OpenGV_DIR_HINTS})
#IF(NOT OpenGV_FOUND)
SET(OpenGV_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/ThirdParty/OpenGV/include)
SET(OpenGV_LIBRARIES opengv)
MESSAGE("OpenGV include DIR ${OpenGV_INCLUDE_DIR}")
INCLUDE_DIRECTORIES(${OpenGV_INCLUDE_DIR})
#ENDIF()

# ==============================================================================
# Search g2o includes
# ============================================================================== 
#FIND_PACKAGE(g2o QUIET HINTS ${g2o_DIR_HINTS})
#IF(NOT g2o_FOUND)
SET(g2o_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/ThirdParty/g2o)
SET(g2o_LIBRARIES g2o)
MESSAGE("g2o include DIR ${g2o_INCLUDE_DIR}")
INCLUDE_DIRECTORIES(${g2o_INCLUDE_DIR})
#ENDIF()

# ==============================================================================
# Search Eigen, borrowed from openMVG
# this makes it a lot smoother for Windows
# ==============================================================================
# - internal by default, (Eigen version 3.2.9)
# - external if EIGEN_INCLUDE_DIR_HINTS is defined
# ============================================================================== 
IF(NOT DEFINED EIGEN_INCLUDE_DIR_HINTS)
  SET(EIGEN_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/ThirdParty/Eigen)
  MESSAGE("Eigen include DIR ${EIGEN_INCLUDE_DIR}")
  #SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/ThirdParty/Eigen/cmake)
  #FIND_PACKAGE(Eigen3 REQUIRED)
  #MESSAGE("-- Eigen version ${EIGEN3_VERSION}: ${EIGEN3_INCLUDE_DIR}")
  #INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIR})
  SET(MultiCol-SLAM_USE_INTERNAL_EIGEN ON)
  INCLUDE_DIRECTORIES(${EIGEN_INCLUDE_DIR})
ENDIF()


SET(MultiColHeaders
include/cam_model_omni.h
include/cam_system_omni.h
include/cConverter.h
include/cMultiFrame.h
include/cMultiFramePublisher.h
include/cMultiKeyFrame.h
include/cConverter.h
include/cMapPoint.h
include/cMap.h
include/cMapPublisher.h
include/cLocalMapping.h
include/cLoopClosing.h
include/cOptimizer.h
include/cORBVocabulary.h
include/cORBmatcher.h
include/cMultiFrame.h
include/cMultiKeyFrameDatabase.h
include/cSim3Solver.h
include/cSystem.h
include/cTracking.h
include/cMultiInitializer.h
include/cViewer.h
include/mdBRIEFextractorOct.h
include/misc.h
#include/MultiCol_cayley_jacobians.h
include/g2o_MultiCol_vertices_edges.h
include/g2o_MultiCol_sim3_expmap.h
)

include_directories(
${PROJECT_SOURCE_DIR}
${PROJECT_SOURCE_DIR}/include
${PROJECT_SOURCE_DIR}/ThirdParty
${PROJECT_SOURCE_DIR}/ThirdParty/g2o
${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/include
${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/build
${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/modules/core/include
${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/modules/calib3d/include
${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/modules/imgproc/include
${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/modules/imgcodecs/include
${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/modules/highgui/include
${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/modules/features2d/include
${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/modules/flann/include
${Pangolin_INCLUDE_DIRS}
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_library(${PROJECT_NAME} ${MCSSLAM_LIB_TYPE}
src/cam_model_omni.cpp
src/cam_system_omni.cpp
src/cConverter.cpp
src/cMultiFrame.cpp
src/cMultiFramePublisher.cpp
src/cMultiKeyFrame.cpp
src/cConverter.cpp
src/cMapPoint.cpp
src/cMap.cpp
src/cMapPublisher.cpp
src/cOptimizer.cpp
src/cOptimizerLoopStuff.cpp
src/cMultiFrame.cpp
src/cMultiKeyFrameDatabase.cpp
src/cSim3Solver.cpp
src/cSystem.cpp
src/cMultiInitializer.cpp
src/mdBRIEFextractorOct.cpp
src/cTracking.cpp
src/cLocalMapping.cpp
src/cLoopClosing.cpp
src/cViewer.cpp
src/cORBmatcher.cpp
src/g2o_MultiCol_sim3_expmap.cpp
src/g2o_MultiCol_vertices_edges.cpp
src/misc.cpp
${MultiColHeaders}
)


SET (G2OLIBS ${PROJECT_SOURCE_DIR}/ThirdParty/g2o/lib/libg2o.so)
SET (DBOW2LIBS ${PROJECT_SOURCE_DIR}/ThirdParty/DBoW2/lib/libDBoW2.so)
SET (OPENGVLIBS ${PROJECT_SOURCE_DIR}/ThirdParty/OpenGV/build/lib/librandom_generators.a
                ${PROJECT_SOURCE_DIR}/ThirdParty/OpenGV/build/lib/libopengv.a)
SET (OPENCVLIBS ${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/build/lib/libopencv_core.so
                ${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/build/lib/libopencv_calib3d.so
                ${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/build/lib/libopencv_imgproc.so
                ${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/build/lib/libopencv_imgcodecs.so
                ${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/build/lib/libopencv_highgui.so
                ${PROJECT_SOURCE_DIR}/ThirdParty/OpenCV/build/lib/libopencv_features2d.so)


target_link_libraries(${PROJECT_NAME}
${OPENCVLIBS}
${Pangolin_LIBRARIES}
${G2OLIBS}
${DBOW2LIBS}
${OPENGVLIBS}
${RANDOMGENLIBS})


# Build examples
MESSAGE("${PROJECT_NAME}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Examples/Lafida)
add_executable(multi_col_slam_lafida Examples/Lafida/mult_col_slam_lafida.cpp)
target_link_libraries(multi_col_slam_lafida ${PROJECT_NAME})