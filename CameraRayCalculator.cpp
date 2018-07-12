#include <opencv2/opencv.hpp>
#include "CameraRayCalculator.hpp"

using namespace cv;
  
CameraRayCalculator::CameraRayCalculator(
  float _focalLength,
  float _sensorPhysicalWidth, float _sensorPhysicalHeight,
  int _imageWidth, int _imageHeight
)
    : focalLength(_focalLength)
    , sensorPhysicalWidth(_sensorPhysicalWidth)
    , sensorPhysicalHeight(_sensorPhysicalHeight)
    , imageWidth(_imageWidth)
    , imageHeight(_imageHeight)
{ }

Mat CameraRayCalculator::operator()(float x, float y) {
  // because sensor physical size has diffirent scale ratio from
  // image size, so new y is computed to have the same scale
  // ratio with x
  y *= this->sensorPhysicalHeight * this->imageWidth;
  y /= this->sensorPhysicalWidth * this->imageHeight;

  // also new focalLength is compute for the same reason
  float newFocalLength = this->focalLength * this->imageWidth;
  newFocalLength /= this->sensorPhysicalWidth;

  return Mat_<float>(4, 1) << x, y, newFocalLength, 0;
}
