#pragma once

#include <opencv2/opencv.hpp>

/** @class CameraRayCalculator
 *  Class sử dụng để tính toán vector chỉ phương của 1 tia
 *  hứng pixel ảnh.
 */
class CameraRayCalculator {
protected:
  /** Tiêu cự camera
   */
  float focalLength;

  /** Kích thước ảnh mà sensor hứng trên màn ảnh
   *  Đơn vị: milimeter.
   */
  float sensorPhysicalWidth;
  float sensorPhysicalHeight;

  /** Kích thước ảnh bằng pixel.
   */
  int imageWidth;
  int imageHeight;

public:
  /** 
   *  @param _focalLength tiêu cự camera (đơn vị milimeter)
   *  @param _sensorPhysicalWidth,_sensorPhysicalHeight kích thước ảnh mà sensor hứng trên màn ảnh (đơn vị milimeter)
   *  @param _imageWidth,_imageHeight kích thước ảnh bằng pixel
   */
  CameraRayCalculator(
    float _focalLength,
    float _sensorPhysicalWidth, float _sensorPhysicalHeight,
    int _imageWidth, int _imageHeight
  );

  ~CameraRayCalculator() {}

  /** Tinh toán vector chỉ phương với tọa độ cho trước
   *  @param x,y tọa độ pixel *tương đối* với principal point
   *  @return matrix 4x1 CV_32FC1 có dạng (x, y, z, 0)^T là tọa độ vector chỉ phương của tia hứng pixel
   */
  cv::Mat operator()(float x, float y);

  // một đống setter/getter :v
  // TODO: cải tiến bằng cách thêm biến phụ và sửa getter, setter

  float setFocalLength(float val) {
    return focalLength = val;
  }

  float getFocalLength() {
    return this->focalLength;
  }

  float setSensorPysicalWidth(float val) {
    return this->sensorPhysicalWidth = val;
  }

  float getSensorPysicalWidth() {
    return this->sensorPhysicalWidth;
  }

  float setSensorPysicalHeight(float val) {
    return this->sensorPhysicalHeight = val;
  }

  float getSensorPysicalHeight() {
    return this->sensorPhysicalHeight;
  }
  
  int setImageWidth(int val) {
    return this->imageWidth = val;
  }

  int getImageWidth() {
    return this->imageWidth;
  }

  int setImageHeight(int val) {
    return this->imageHeight = val;
  }

  int getImageHeight() {
    return this->imageHeight;
  }
};
