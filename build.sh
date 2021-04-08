if [ "$1" = "--apple" ]; then
  echo "Building on Mac"
  APPLE="true"
elif [ "$1" = "" ]; then
  APPLE="false"
else 
  echo "Invalid flag. Usage: --apple for building on Mac"
  exit 1
fi

echo "Configuring and building Thirdparty/OpenCV ..."

cd ThirdParty/OpenCV
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release \
-DBUILD_opencv_apps=OFF \
-DBUILD_opencv_dnn=OFF \
-DBUILD_opencv_flann=OFF \
-DBUILD_opencv_java_bindings_gen=OFF \
-DBUILD_opencv_js_bindings_gener=OFF \
-DBUILD_opencv_ml=OFF \
-DBUILD_opencv_objdetect=OFF \
-DBUILD_opencv_photo=OFF \
-DBUILD_opencv_python3=OFF \
-DBUILD_opencv_python_bindings_g=OFF \
-DBUILD_opencv_python_tests=OFF \
-DBUILD_opencv_shape=OFF \
-DBUILD_opencv_superres=OFF \
-DBUILD_opencv_ts=OFF \
-DBUILD_opencv_video=OFF \
-DBUILD_opencv_videoio=OFF \
-DBUILD_opencv_videostab=OFF
make -j4

cd ../../
echo "Configuring and building Thirdparty/DBoW2 ..."

cd DBoW2
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j4


cd ../../
echo "Configuring and building Thirdparty/g2o ..."

EIGEN3_INCLUDE_DIR=$(pwd)/Eigen
export EIGEN3_INCLUDE_DIR

cd g2o
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j4


echo "Configuring and building Thirdparty/opengv ..."

cd ../../OpenGV

mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j4


echo "Configuring and building MultiCol-SLAM ..."
cd ../../../
echo $(pwd)
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release \
-DAPPLE=${APPLE}
make -j4
