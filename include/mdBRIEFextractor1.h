/**
* This file is part of ORB-SLAM.
*
* Copyright (C) 2014 Raúl Mur-Artal <raulmur at unizar dot es> (University of Zaragoza)
* For more information see <http://webdiis.unizar.es/~raulmur/orbslam/>
*
* ORB-SLAM is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* ORB-SLAM is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with ORB-SLAM. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MDBRIEFEXTRACTOR1_H
#define MDBRIEFEXTRACTOR1_H

#include <vector>
#include <list>
#include <opencv2/opencv.hpp>
#include "BaseComponents/slam_multi_cam_fisheye/multi_cam_model_omni.h"


//static int learned_pattern_64_[4 * 512] = 
//{
//	-11, 0, 11, -1, -8, -6, -4, -2, 10, 12, 12, 15, -2, 2, -1, -1, -2, 14, 2, -13, -3, -14, 0, 6, -13, 12, -3, -6, 12, -10, 15, -12, 1, 10, 3, -7, -13, -7, -6, -12, -6, -10, -3, 13, 8, 7, 8, 13, 1, -7, 2, -2, -11, 6, -7, 9, 3, 15, 9, -13, 7, -13, 9, -10, -3, 7, -2, 4, -12, 14, -11, 10, -7, -1, -5, 4, -6, 12, -4, 15, 15, 6, 15, 10, 11, 4, 15, -14, -8, -14, -4, -13, 4, 2, 6, -2, 6, 12, 13, 11, 0, 3, 2, 6, 13, 3, 15, 6, 6, 3, 6, 7, -13, -9, -13, -5, -14, 8, -13, 5, -7, -14, -7, -10, 8, -9, 13, -6, -13, 15, -10, 13, 4, -3, 7, -6, -14, -4, -13, -1, 7, 1, 11, 1, 12, -2, 15, -1, 2, -11, 5, 14, -14, -14, -10, -11, -13, 1, -9, 3, -13, 4, -12, 1, 10, 5, 11, 0, -6, 14, -4, 10, -4, 15, 1, -4, -6, 7, -1, -12, -1, 5, 5, -11, -7, 8, -3, 9, 2, -12, 5, -11, 1, 10, 3, 7, -4, -3, -2, -6, -3, -14, 0, -13, 2, 8, 13, -10, -1, -3, 1, 2, 14, -10, 15, -13, 3, 2, 8, 4, 6, 12, 9, -5, 3, 15, 8, 13, -2, -8, 2, 14, 5, -11, 7, 0, 12, 13, 15, 15, 1, -6, 6, 10, 15, 11, 15, 15, -12, -1, -8, 15, -9, 4, -6, 2, 3, 4, 4, 1, -8, -2, -6, -6, -4, -4, -3, 0, 6, -4, 9, -1, 8, -7, 9, -12, -13, -13, -11, -8, -13, 5, -9, -14, -10, 12, -7, 14, 7, -1, 13, 15, 3, -4, 4, 15, 2, -14, 3, 9, -7, -12, -4, -7, -11, -1, -8, -3, -8, 15, -5, 14, -3, 2, -2, 5, 1, 15, 2, 12, -13, -10, -6, 8, 14, -1, 15, 2, -6, 4, -5, 10, 1, -11, 3, -14, -2, 10, -1, -8, 6, 6, 9, 8, -14, -8, -11, -6, -1, -11, -1, -4, 6, -13, 9, -14, -9, -3, -9, 1, 11, -7, 13, -2, 12, 11, 15, -7, 9, 7, 14, 5, 4, 11, 7, 15, 10, -1, 13, -4, 3, 6, 4, 10, -14, 7, -13, 10, 9, -3, 9, 1, -10, 10, -8, 7, -7, 7, -1, -1, -9, -10, 0, 9, -13, -4, -2, 4, -9, 15, 2, -10, -6, -4, -2, -4, -2, -6, 1, -4, 0, 15, 6, -8, -1, 6, 2, 2, -2, -13, 4, 12, -5, -6, 1, -11, -14, 2, -2, -10, -1, -3, 4, -6, -4, 10, 1, 7, -2, 10, 14, 15, 2, -12, 8, 8, 2, -5, 5, -4, 3, 10, 8, 4, 4, 15, 15, 1, -7, -2, -2, 15, -8, 2, -4, 7, 2, -4, 14, -4, -3, -11, 0, -7, -3, 14, 2, 15, -1, 8, 2, 10, 4, 6, 10, 0, 1, -1, 5, 3, -6, 1, -4, -2, 2, -10, 4, -6, 13, 9, 15, 12, -1, 0, 1, -3, -9, -7, -5, -7, -8, 10, -3, 4, 5, -8, 8, -7, -3, -5, 0, 9, 10, -11, 11, -14, -3, 6, -1, 9, 13, -7, 14, -10, 6, -14, 15, 6, -7, -3, -4, -14, 1, 11, 5, -13, -1, 12, 0, 0, -5, -11, -3, -14, 10, 5, 10, 9, 0, -1, 11, -14, 4, -14, 5, -10, 4, 7, 7, -7, 2, 8, 6, 12, 1, -10, 2, 5, 7, 15, 9, 11, 12, -4, 14, -7, 6, -9, 6, 15, 3, -2, 13, 8, 4, -7, 6, 4, 1, -7, 3, -10, -5, -8, -3, 7, -8, 13, -4, -14, 4, 9, 4, 13, -14, -7, -6, -3, 6, 4, 12, -5, 0, -14, 1, -11, -8, 8, -7, 13, -1, 10, 1, 15, 10, 11, 12, 8, 6, 6, 8, -14, -13, 15, -11, -7, -14, 11, -11, 8, 0, 14, 1, -8, -7, -5, -6, 11, 8, -4, 9, -8, 10, 7, 13, 10, -1, 13, 0, 7, -12, 3, -9, 7, 7, 0, 7, 4, 9, 3, 10, 6, -14, 10, -10, 13, 11, -14, 13, -11, -8, 8, -6, -9, -2, -13, -1, 12, 7, -7, 11, 6, -6, -12, -4, 2, 14, 0, 15, -5, -14, -14, -9, 0, -10, -11, -7, -10, 7, -7, 10, -8, 12, 4, 15, 3, -14, -1, -13, 2, -10, 9, -9, 2, -4, 8, -3, -4, 2, -2, 3, 9, 2, -1, 3, -4, -7, 15, -4, -2, -14, -5, -9, -7, -14, 6, -11, 4, 9, -11, 13, -14, -10, 15, -8, 12, 9, -11, 12, 15, 11, -7, 15, -7, 13, 3, 15, -1, -14, 1, -13, -2, -10, -2, -9, 6, 12, 7, 13, 4, -14, -2, -11, -1, -11, -2, -10, -6, -2, 3, -1, -9, 5, -5, 8, 11, 5, -10, 6, 10, 5, -11, 7, -14, 9, -1, 13, 4, -13, -8, 1, -2, -12, 7, 1, -7, -4, -13, 4, 4, -5, 9, 4, -11, -6, -11, 7, -11, -14, 15, 2, 0, -14, -4, 3, -14, -6, -5, 0, 2, -5, 5, 2, -5, -9, 4, -1, 4, -3, 7, 11, -12, 0, 9, 8, -7, -2, -13, 15, 8, -1, 6, 8, 6, -11, 1, -2, -3, -2, 14, 15, -9, -1, 12, 5, -3, -6, 2, 1, 8, -2, 0, 3, 1, -3, -9, 3, 9, -11, -8, 0, 15, -8, 10, 2, 12, 1, -14, 11, -5, -5, -1, 5, 15, -3, 14, 7, 10, 0, 2, 10, -4, -3, -9, 8, 15, -11, 3, -2, 12, 1, -7, 11, 5, -8, -8, -1, -9, -3, 11, 2, -7, -14, 7, -2, 1, -1, -3, 10, 10, 0, 5, 5, -4, -5, -9, -1, -1, -14, 11, 0, -14, -7, 0, -4, 1, -10, -5, -3, 10, -11, -14, -1, 3, 1, 5, 15, 2, 13, 12, 15, 15, 3, 15, 7, -3, -1, -8, 2, -9, -6, -14, 1, 13, -7, -12, 0, -14, -6, 9, -1, -7, -5, -1, -2, 4, 1, -7, 9, -9, -6, 5, 0, 15, 0, -14, 3, -1, -1, -14, 3, -12, 3, 15, 8, 7, -8, 4, -3, -8, -13, 14, -1, 15, -4, 0, -2, -3, -14, -11, -2, -14, 4, -9, 12, -1, -6, 15, 0, 4, 3, -2, 8, -1, -14, -14, -12, -11, -3, -8, 0, 5, -14, 3, -4, 6, 3, 9, 8, 9, -8, -6, -4, -10, -11, 13, -2, 8, 7, 15, 10, 1, -1, 9, 1, -3, 3, 11, 7, -9, 8, -14, 11, -3, -2, -11, 1, -13, 1, 15, 3, 2, -13, 0, -5, 0, -1, 8, 2, -9, 2, -4, 4, 0, 12, 5, 12, 15, -4, 1, 1, -14, -1, 2, 6, 11, 4, 12, 15, -7, 5, 9, 12, 5, -4, 15, 0, 12, -14, 10, -4, 11, 0, 13, 5, 15, -3, 5, -2, 1, 2, 8, 3, 5, -10, 5, -5, -4, -9, -3, -6, -4, -5, 13, -1, -11, 4, -12, 14, -10, 13, -2, 14, 15, 4, 9, 6, -2, 7, 10, 13, -1, -8, -4, -5, 2, 2, 4, 9, -9, -6, 13, -3, 12, 2, -12, 10, 15, -3, -1, 1, 11, 3, 6, 4, 3, -11, -14, -11, -10, -13, 15, -12, 5, -12, -1, -7, -10, -2, -10, 0, 9, 5, 1, 9, -1, 3, -4, 8, 6, 4, -6, 5, -3, -10, -14, -10, -4, 3, -1, 6, -4, 0, -4, 3, 7, 8, 10, 9, 15, -12, -12, -5, 15, 3, -8, 15, 11, -10, 1, -7, 3, -2, 9, 1, -14, 6, 4, 6, 11, 3, 14, 4, -8, 5, -14, 5, -4, 3, 5, 7, 8, 3, -13, 7, -14, 1, -12, 2, -8, -14, -12, -14, -8, -10, 8, -6, 7, -8, -14, -3, 9, 2, 8, 5, -10, 0, -5, 6, 15, 8, 15, 12, -9, 9, 15, 13, 10, 5, -6, 15, 3, -2, -4, 0, -8, 8, -9, 10, 1, 5, 3, 11, 5, 3, 1, 14, -8, 6, -2, 10, -3, 2, 15, 4, -12, 13, -14, 15, -3, 9, -3, 10, 10, 1, 1, 12, 13, -6, 8, -4, 1, 3, 3, 4, -14, 0, -9, 2, 11, -10, -11, -8, -14, 4, 15, 5, 11, -5, 8, -4, 11, -3, 4, -2, 7, -4, -7, -3, -10, 0, 3, 0, 7, 12, 1, 15, 3, 12, -13, 12, -8, 12, 11, 15, 12, -9, 15, -8, 3, 5, 12, 9, 13, 2, 5, 4, -7, 5, 10, 10, -11, 0, -12, 2, 14, 14, 1, 14, 5, -14, -10, -13, 1, -6, -4, -5, -7, -11, -8, -6, 1, 2, -1, 7, 9, -7, -11, -7, -7, -14, 11, -13, -1, -2, -7, 0, -13, 4, 0, 7, 15, 9, -6, 15, -12, 6, -1, 9, 2, 9, -14, 11, 9, 4, -14, 6, 12, -4, 13, -2, -6, -11, 4, -8, 3, 1, 0, 1, 4, 7, 15, 10, 14, -14, 12, -5, 2, 12, -5, 15, 9, 1, 0, 5, -9, 6, 0, 11, -14, 8, 6, 9, 2, -14, -4, -9, 10, -9, 5, -8, 9, -14, 4, -8, -6, -5, -8, -4, -5, -11, -14, -9, -11, -1, -5, -1, -1, 4, -6, 4, 9, -6, 3, -5, 0, -2, 8, -1, 11, 4, 7, 15, 13, 3, -9, 3, -4, 0, 5, 0, 9, 8, -4, 11, -3, -13, 7, -8, 7, 0, 1, 1, -12, 11, -9, 11, -5, 8, -7, 8, 9, -14, -13, -11, 8, -3, -13, -2, -9, 4, -8, 7, -11, -8, 1, -7, 7, -9, 11, -9, 15, 0, 11, 1, -11, 8, 2, 15, 9, 13, -3, 14, 0, -2, -10, -1, 15, -13, -7, -11, -3, 14, 12, 15, 8, 0, 4, 3, 14, 9, -14, 13, -14, -14, 12, -11, 11, -2, -4, 0, 15, -4, 11, -3, 8, 4, -3, 4, 5, 6, -1, 7, -7, -4, -2, -3, 11, -10, -9, -7, -6, 3, -10, 3, 11, -13, 1, -9, -1, -14, 14, -7, 10, 5, 5, 10, 15, 8, 2, 9, -1, -11, 6, -8, 0, -4, 13, -3, 2, -14, -10, -12, -13, -14, -13, -9, -8, -14, -10, -11, -9, 9, 7, 15, -4, 9, 4, 13, 1, -6, -4, -6, 0, 12, -11, 15, -9, -7, -14, -5, -11, 11, -9, 14, 5, -12, -3, -9, 1, -4, -2, -4, 3, -14, -14, -9, -13, 9, -4, 12, 0, 10, 14, 13, 15, -9, 15, -5, -8, 2, 3, 4, 8, -8, -10, -7, -3, -14, -6, -14, 5, 0, -5, 0, 6, 1, -5, 2, 12, 8, 6, 12, 7, 8, 5, 10, -9, 7, -1, 15, -2, 3, 1, 4, 4, 15, -8, 15, -4, -14, 15, -10, 15, -3, -8, -3, -2, -14, -2, -13, -5, 8, 11, 11, 13, 6, 0, 7, -3, -14, 2, -13, 5, 4, -5, 6, -9, 6, 0, 9, 7, 2, -2, 2, 2, 8, -1, 10, -4, -14, 5, -11, 6, -10, 2, -9, -1, 11, 4, 12, -5, 12, 9, 15, 8, 2, 12, 3, 15, -11, -14, -8, -12, -6, -5, -6, 6, 9, -5, 13, -6, -14, -4, -12, -7, -8, -11, 5, 8, -11, 10, 6, -10, -14, -6, 3, 5, -10, -6, 4, -8, -5, 12, 6, -7, -11, -9, 15, -12, -7, 2, 6, -12, -8, 3, 1, -1, -5, 7, 5, 4, -4, -7, 5, 0, -14, 1, 3, 10, -7, 7, 15, 11, -7, -8, 5, 13, -6, -14, 7, -5, -14, 0, 0, 1, -4, -4, 9, -8, -13, 5, 8, 15, -2, -10, 8, 7, -3, 4, 7, -6, -4, -12, 15, -4, -10, 0, 1, -9, -7, -5, 2, 9, -4, 13, 15, 3, -8, 10, 2, -4, -5, -2, 3, -4, -5, -13, 8, 12, -1, 15, 9, -4, -9, -3, 2, 14, -1, -7, 10, -3, -4, -1, 6, 8, -9, 6, 2, -13, -9, 14, 5, 7, -4, 15, 6, 2, 0, 9, 10, 0, -2, 13, 8, -10, -7, -10, 2, -5, -2, 1, 12, 4, 0, -12, 8, 1, -13, -5, 0, 10, -14, 7, 1, 6, -1, -3, 8, 1, -14, -3, 0, -6, -4, 3, 0, 3
//};

static int learned_pattern_64_[4 * 512] =
{
	-12, -1, 11, 0, 11, 1, 11, 15, -9, -14, -9, 3, -1, -1, -1, 10, 9, -9, 15, -14, 2, -12, 2, 14, -5, -8, -2, -1, -11, -10, -3, 10, -7, 4, -4, -2, -2, -14, 1, 9, 0, 4, 2, -3, -14, 12, -3, 5, 9, 4, 10, -14, -1, 12, 2, -13, -5, 14, -1, -7, -11, 8, -7, 14, 6, 15, 7, 7, 7, -14, 8, -8, -13, 15, -12, 7, 3, 10, 7, -11, -10, -8, -8, -14, 1, -5, 2, 2, 4, 2, 8, -4, -14, -5, -7, -8, 4, -4, 4, 12, 8, 12, 12, -6, -13, 0, -13, 14, 5, -10, 15, 12, 13, -11, 13, -3, -14, 2, -13, -13, -4, 3, -3, -10, 5, 0, 9, 5, 13, -2, 15, 4, -14, -14, -10, -9, -14, 6, -13, 0, 8, 5, 14, 3, -7, 9, -6, 1, -4, -4, -4, 3, -9, 10, -1, -1, -8, -7, -1, -5, -8, 8, 0, -14, -6, -12, 4, -13, -4, -8, 1, 5, -14, -4, -2, 2, -1, -11, 4, -3, -9, 5, -2, 7, -3, 7, 2, -8, -14, 4, -2, -5, -2, 15, 4, -9, -1, 4, 9, -11, -6, -5, 0, 14, -7, 14, 3, 15, 2, -14, 7, 7, 1, 15, 11, -10, -1, -7, 4, 10, -9, -3, -3, -9, -1, 12, 9, 14, -3, 2, 1, 7, 3, 10, 7, 3, 1, 1, 7, 3, 2, 6, 12, 7, -11, 11, -2, 15, 3, -6, 9, -5, -1, 7, 1, 0, -7, -2, -3, 5, 5, 14, 14, 0, -12, 1, -5, 10, 1, -14, 7, -13, -8, -10, -3, -14, -3, -12, 2, 15, 4, 7, 9, -2, -1, -4, 3, -9, 4, -13, 14, -8, -6, 5, -3, 11, 1, 11, 3, -6, -3, 9, -1, 3, 11, -8, 12, -14, 8, -14, 12, 4, 8, 8, 8, 15, -4, -14, 0, -8, 2, 0, 15, -3, 4, 14, 6, -7, -11, 14, -3, -11, 5, -5, 10, 1, 13, -3, 15, -12, -9, -6, -6, 15, 5, -9, 7, -2, -12, -13, -12, -6, -11, -7, -5, -5, 11, 10, 15, 15, 7, -6, 7, 15, -9, 0, -6, -6, 6, 3, 6, 12, -7, -13, -2, 5, -5, -3, -3, -13, 2, 0, 2, 15, -3, -7, -1, 10, -4, 9, -2, 15, 6, -5, 7, -14, 3, -8, 7, 10, -14, -13, -5, -12, -9, -14, -3, -10, 3, -3, 5, 3, 10, 13, 11, 4, 2, 3, 7, 9, 1, -7, 7, -14, -6, 15, -2, 10, 11, 5, 15, 10, -8, 4, -7, -14, -14, -11, -14, 0, 2, -10, 3, 6, 5, 14, 11, 15, -6, -12, -3, 14, -1, 14, 0, -3, -7, -14, -7, -7, -12, 15, -11, -4, 0, 8, 4, 15, -13, 2, -7, 3, 1, -14, 1, 1, -3, 13, -1, 7, -14, 10, -13, 4, 13, 0, 15, -6, 8, -1, 8, 9, 3, 0, 3, 7, 2, 7, 4, -8, 9, 15, 14, 11, 2, -3, 15, 15, 4, 4, 5, -13, -2, -8, 0, -14, 0, 0, 3, -6, 11, -6, 15, 14, -9, -4, -6, 3, 15, 1, 15, 9, 2, 13, 3, -10, 4, 6, 13, -10, 12, -14, 13, -8, -8, 15, -7, 8, -13, -5, -8, 9, 8, -8, 13, -4, 4, -11, 10, -14, -6, 9, -4, -8, 6, -2, 7, -9, -13, 15, -7, 13, -3, 6, -2, -4, 4, -14, 7, 14, -5, -2, -4, 10, -4, 14, -2, -14, -2, -2, -1, 4, -14, 8, -7, -8, 7, -9, 7, 4, -5, -10, -5, -3, -2, 10, -1, -10, 6, 15, 9, -13, 1, -6, 1, 12, 6, -4, 12, -6, -1, 5, 1, -14, -14, -10, -10, -5, -8, 4, -8, 11, 9, 8, 10, 1, 3, -8, 4, 15, 14, 10, 15, -14, 14, 12, 15, -1, -14, 0, -9, -4, -14, -5, -12, 1, 6, 9, 7, -7, 10, 1, 15, -3, 3, -6, 3, 8, 9, -11, 9, 13, 6, -4, 6, 6, -6, -10, -6, 9, 14, 4, 15, -2, 8, -5, 12, 5, 9, 2, 14, 6, 5, 7, 11, 12, -14, -14, -11, 11, 8, 4, 11, -3, -1, 5, -1, 12, 13, -7, 13, 1, -2, -8, -2, 15, 4, -11, 4, 11, 0, -10, 0, 11, -10, 5, -8, -1, 9, -2, 15, 0, -14, -1, -14, 6, 0, -7, 0, 7, -8, -12, 6, 7, -8, 8, 5, -11, -9, -8, 8, -10, -11, 8, 3, -5, -11, -7, 2, 0, -10, 15, 7, -8, -8, 4, 1, 2, -4, 3, 7, -7, -13, -6, 3, 9, -9, -10, 15, 15, -6, -4, 3, -4, -5, 10, 11, -11, -12, 2, 0, -2, -3, -9, 6, 3, -5, -3, 4, 6, -13, 3, 2, -10, -6, 12, 9, 9, -3, -13, 11, 7, -3, 11, 6, -5, -5, -11, 14, -6, -10, -2, 5, -14, -5, -6, 8, 13, -9, 2, 2, 10, -4, 6, 3, -1, -11, 0, 0, 5, -2, 5, 9, 5, -14, 12, 3, 4, -8, -2, -1, 1, -2, -5, 9, -5, -13, 11, 11, 15, -4, -1, 15, 10, -14, -14, 4, -5, -5, -9, 3, 10, -8, 14, 3, -1, -12, -9, 5, 15, -7, 1, 1, -6, -12, -2, 2, 15, -9, -9, 1, 6, -1, -8, 14, 3, -1, 15, 10, -4, -5, 7, 3, 8, -4, -12, 6, 12, -3, -4, 2, 0, -12, -3, 0, -7, -2, 9, 6, -10, -4, -11, 5, -7, -8, 12, 2, -9, 0, 8, 10, -2, -13, 9, 3, -14, -5, 14, 6, -12, -6, -14, 3, 0, 0, -13, 9, 0, -9, -4, 0, 10, -6, 4, 6, 15, -1, -10, 6, 9, -8, 6, 0, -9, -3, 9, 3, 4, -1, 2, 13, -1, -5, -1, 3, -10, -10, -7, 1, -11, -14, 7, 1, 9, 0, 11, 9, -8, -10, -10, 1, 11, -12, 7, -1, 2, -4, -7, 3, -9, -6, 3, -1, -2, 0, -4, 9, 3, -4, 10, 3, -12, -2, 5, 15, -9, -4, -3, 9, -13, -3, -14, 4, 6, -3, 15, 6, 5, -7, 8, 0, 6, -14, -2, 0, -14, -4, 5, 6, -14, -1, -2, 5, -1, -5, 9, 1, -5, -2, 14, 15, 7, -14, 0, -1, 10, -5, 15, 3, -6, -8, 1, 0, -12, -5, -7, 0, -3, -1, -14, 10, -8, -1, -9, 11, 12, -9, 7, 1, 15, -1, 4, 5, -3, -11, 15, 1, -5, -10, -10, -1, 1, -7, 14, 3, 8, -5, -8, 3, 15, -8, -14, 3, 13, -14, -7, -1, -3, -3, -1, 6, 11, -14, 10, 0, -8, -5, 6, -1, 1, -4, -13, 10, -14, -1, 11, 4, 0, -14, 15, 2, 12, -1, 8, 5, 9, 1, -8, 7, -3, 1, 12, 9, 6, -9, 2, -3, 1, -6, -10, 1, -8, -2, -9, 6, -11, -2, 7, 14, 14, -13, -6, -1, 13, -5, -3, -1, 3, -2, 11, 3, -8, -12, -4, -2, 7, 0, 7, 6, -7, -10, -2, -3, -2, -12, 4, -2, -14, 1, 11, 15, -2, 0, -7, 5, 6, -1, -8, 14, -11, -2, -14, 11, 15, -11, 2, -2, 14, -2, -9, 2, 2, -14, 4, -2, 5, -6, 1, 1, 14, 2, -9, 8, 3, -6, 1, -1, 7, 1, -7, 9, 8, -4, -4, 2, 11, -7, 13, 2, -14, -7, 12, 0, 3, -6, 10, 0, 11, 0, 2, 8, -4, -9, -6, -2, 4, -3, 11, 3, 12, -5, -6, 0, 8, 0, 14, 5, -6, 2, -14, 14, 4, 2, -10, 12, -4, -1, 0, 11, -8, -1, 12, 9, -13, -5, -12, 1, 7, 2, 4, 8, 2, -8, -10, 0, 15, -6, -5, 1, -14, -1, 8, 3, -4, -2, -1, 3, -5, 2, 12, 7, -3, -9, 7, -2, -5, -9, 0, -3, -5, -9, -13, 0, -4, 3, 15, 9, 2, -14, 1, -3, 0, 0, 13, 6, 10, -2, -9, 6, 15, -4, 11, 0, -1, -14, 0, -3, -9, 0, -14, 6, 11, -2, -14, 4, -11, -2, -10, 3, 12, 3, 13, 11, -6, -1, 3, 9, 11, -11, -10, -1, -8, 0, -1, 11, 7, -3, 6, 2, 11, -10, 11, -1, 8, -4, 4, 1, -11, -4, -6, -1, 1, -11, -14, 1, -14, -8, -5, -3, -1, 1, -6, 4, 0, 1, 12, 6, -10, -5, -10, 0, 12, -14, -7, -2, -11, -3, 3, 1, -5, -7, -10, -1, 9, 2, 7, 11, -6, -1, 4, 4, 8, -8, -7, -2, 12, 2, 7, 6, -1, 3, 9, 12, 3, -6, 10, -1, -10, -11, 6, -3, -9, 1, -5, 15, -5, -1, -4, 11, 14, 2, -12, 11, 10, -12, 6, -3, 11, 3, -12, 8, -6, 1, 8, 8, 10, -3, -11, 1, -6, -4, 9, 2, 15, 1, -6, 8, -9, 0, 8, 14, -14, -9, -3, -3, 15, -11, -4, -4, -14, 1, -12, 4, 3, -2, -5, 2, 7, -4, 13, 1, -10, -1, 0, 4, 5, -6, 3, -2, -6, -14, -2, -4, 15, -2, 15, 5, 14, -10, 1, -4, 4, 2, -2, 9, -2, 1, -13, 5, -7, -1, 4, 4, -8, -8, -1, -3, 9, -1, 15, 2, 0, 1, -5, 15, 8, 5, -13, 11, 0, -3, -9, 2, -13, 2, 5, 15, 1, 1, 15, 12, 13, -1, -9, 2, 7, 2, 1, 11, 2, 2, 15, 6, 7, -1, 10, 5, -14, -1, 15, 6, -14, 1, 11, 4, 5, 3, -14, 6, -1, -7, -6, -3, -11, 4, 15, 12, 8, 4, -10, 11, 6, 2, -3, 14, 1, 5, 15, 9, -3, -6, 15, -1, -1, -6, -14, 0, -12, -11, 5, -4, -2, -1, 8, 3, -11, -3, -11, 0, -2, 2, 10, 15, -9, -8, 8, -3, 4, -4, -13, 0, 3, 3, 10, 7, -6, -13, 15, -2, 1, 0, -2, 5, -6, -14, -3, -4, -5, -1, 15, 3, 9, -2, -4, 5, 15, 3, 3, 11, -2, -2, 12, 1, -5, 2, 5, 6, -4, -14, 0, -6, -14, -7, 5, -3, -12, 2, 10, 15, 10, -8, 15, -1, 13, 1, -10, 6, 12, 3, -11, 9, -10, -5, -1, -2, -7, -14, -12, -2, 5, 5, 11, 9, 0, -10, 7, -4, 6, -11, 9, -4, -14, 4, -9, 14, 1, -10, 1, -5, -11, 3, 15, 5, -1, -8, 4, -4, 9, -9, -14, -1, 12, -2, 12, 1, 5, -9, 12, -2, -7, -2, 0, 5, -13, -6, -8, -2, 6, 2, 4, 10, -8, -8, 8, -4, 13, 2, 15, 5, -9, -4, 5, -2, -1, -3, -10, 0, 9, 1, 2, 15, 8, -4, 8, -1, -7, -10, 1, -6, 15, 5, 10, 13, -3, 7, 15, 11, 5, -11, -5, -5, 11, -4, -3, -1, -9, 1, -4, 6, 8, -11, -2, -5, 1, -11, -5, -6, -9, -13, -11, -3, 15, -4, 8, -1, -13, -6, 10, -2, -4, 5, 15, 15, -7, -14, 13, -3, 11, -7, 15, -1, -11, 3, -3, 9, 5, -8, -9, -3, -3, -11, 4, -5, 2, 1, 7, 6, -11, 4, 11, 10, -9, -14, 11, -3, -3, 1, -7, 8, 13, -8, 6, -4, 1, -11, -7, -4, 1, 5, -13, 7, 4, 8, -14, 11, -5, -14, 4, -6, 13, -8, -5, -4, 8, 11, 7, 11, 15, -14, -1, -5, 6, 1, -14, 3, 7, -2, 2, 4, 14, 0, -13, 5, 15, 8, -1, 8, 15, 4, -8, 12, -8, -13, 3, -6, -9, -2, -8, 1, 13, -4, 0, -1, 10, 10, -3, 11, -14, -5, -8, -2, 15, 3, -7, 5, 3, 9, 15, 11, -1, 3, -3, 9, -6, -1, -7, 0, -1, 5, -1, 5, 15, 0, -14, 2, -4, -12, 0, -6, -5, -2, 15, 1, -7, 6, -8, 10, -3, 6, 11, 12, 6, -7, -14, -2, -1, 1, 11, 2, -2, 2, -8, 15, 15, 6, 15, 9, -8, 4, -7, 8, 6, 8, 5, 8, 13, 3, 7, 7, -7, 2, -8, 3, -2, -4, -14, 0, 12, 6, 14, 7, 2, 5, 5, 11, 2, 1, -3, 13, -12, -14, -8, -6, -13, 6, -14, 10, 9
};

//namespace ORB_SLAM
//{

class mdBRIEFextractor1
{
public:
    
    enum { HARRIS_SCORE=0, FAST_SCORE=1 };

	mdBRIEFextractor1(int _nfeatures = 1000,
		float _scaleFactor = 1.2,
		int _nlevels = 8,
		int _edgeThreshold = 25,
		int _firstLevel = 0,
		int _scoreType = HARRIS_SCORE,
		int _patchSize = 32,
		int _fastThreshold = 20,
		bool _useAgast = false,
		int _fastAgastType = 2,
		bool _learnMasks = false,
		int _descSize = 32) :
		nfeatures(_nfeatures), scaleFactor(_scaleFactor), numlevels(_nlevels),
		edgeThreshold(_edgeThreshold), firstLevel(_firstLevel),
		scoreType(_scoreType), patchSize(_patchSize), fastThreshold(_fastThreshold),
		useAgast(_useAgast), fastAgastType(_fastAgastType), learnMasks(_learnMasks),
		descSize(_descSize)
	{}


	~mdBRIEFextractor1(){}

	// Compute the ORB_Impl features and descriptors on an image
	void detectAndCompute(cv::InputArray image,
		cv::InputArray mask,
		std::vector<cv::KeyPoint>& keypoints,
		cv::OutputArray descriptors,
		cv::OutputArray descriptorMasks,
		cCamModelGeneral_& camModel,
		bool useProvidedKeypoints = false);
	void compute(cv::InputArray _image,
		cv::InputArray _mask,
		const std::vector<cv::KeyPoint>& keypoints,
		const std::vector<cv::Vec2f>& undist_keypoints,
		cv::OutputArray _descriptors,
		cv::OutputArray _descriptorMasks,
		cCamModelGeneral_& camModel);
	void detect(cv::InputArray _image,
		cv::InputArray _mask,
		cCamModelGeneral_& camModel,
		std::vector<cv::KeyPoint>& keypoints,
		std::vector<cv::Vec2f>& undist_keypoints);

    int inline GetLevels(){ return numlevels; }

    double inline GetScaleFactor() { return scaleFactor; }

	bool GetMasksLearned() { return learnMasks; }
	int GetDescriptorSize() { return descSize; }

protected:


    std::vector<cv::Point> pattern;

	// returns the descriptor size in bytes
	int descriptorSize() const;
	// returns the descriptor type
	int descriptorType() const;
	// returns the default norm type
	int defaultNorm() const;

	int nfeatures;
	double scaleFactor;
	int numlevels;
	int edgeThreshold;
	int firstLevel;
	int descSize;
	int scoreType;
	int patchSize;
	int fastThreshold;
	bool useAgast;
	int fastAgastType;
	bool learnMasks;

    std::vector<int> mnFeaturesPerLevel;

    std::vector<int> umax;

	std::vector<double> mvScaleFactor;
	std::vector<double> mvInvScaleFactor;

    std::vector<cv::Mat> mvImagePyramid;
    std::vector<cv::Mat> mvMaskPyramid;

};

//} //namespace ORB_SLAM

#endif

