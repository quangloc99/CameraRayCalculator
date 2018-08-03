#pragma once

#include <opencv2/opencv.hpp>

/** @class CameraRayCalculator
 *  Class sử dụng để tính toán vector chỉ phương của 1 tia
 *  hứng pixel ảnh.
 */
class CameraRayCalculator {
public:
  /**
   * Matrix 3x3 có dạng
   * [ fx 0  px
   *   0  fy py
   *   0  0  1 ]
   * Trong đó fx, fy là tiêu cự của camera đã được nhân với
   * scale theo 2 trục, px, py là vị trí của tâm camera trên màn ảnh.
   *
   * Matrix có thể bị modify nhưng quá trình tính toán sẽ coi matrix như
   * đã được định nghĩa như trên (không sử dụng các ô 0).
   */
  cv::Mat camMat;

  CameraRayCalculator(cv::Mat _camMat);

  /** 
   * NOTE: Chưa thử nghiệm nên chưa an toàn để sử dụng.
   *       Một điều chắc chắn là có thể lấy camera matrix từ nội tham số camera.
   * Tạo camera matrix với các thông số được truyền vào.
   * Tâm camera cho là tâm ảnh.
   *  @param _focalLength tiêu cự camera (đơn vị milimeter)
   *  @param _sensorPhysicalWidth,_sensorPhysicalHeight kích thước ảnh mà sensor hứng trên màn ảnh (đơn vị milimeter)
   *  @param _imageWidth,_imageHeight kích thước ảnh bằng pixel
   */
  CameraRayCalculator(
    float focalLength,
    float sensorPhysicalWidth, float sensorPhysicalHeight,
    int imageWidth, int imageHeight
  );

  CameraRayCalculator(const CameraRayCalculator& other);

  CameraRayCalculator() {}

  ~CameraRayCalculator() {}

  /** Tinh toán vector chỉ phương với tọa độ cho trước
   *  @param x,y tọa độ của pixel.
   *  @return vector chỉ hướng chiếu, và có dạng (x, y, -1)
   *
   *  Lý do trả về với z = -1 vì 2 lý do:
   *  - Hệ trục tọa độ của openGl có chiều dương Ox về bên trái, Oy là lên trên và Oz VỀ ĐẰNG SAU
   *  - Điểm có cùng tọa độ với vector luôn cách mặt phẳng hứng ảnh 1 khoảng là 1, tiện lợi cho tính toán.
   */
  cv::Vec3f getRay(float x, float y);

};

