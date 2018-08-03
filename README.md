# Camera ray calculator

Code sử dụng để tính vector chỉ phương của tia từ camera đến 1 điểm trên màn ảnh.
Document có thể xem comment trong file header CameraRayCalculator.hpp.

Có2 cách để khởi tạo:

## Với camera matrix:
Xem thêm: [Camera calibration](https://docs.opencv.org/2.4/doc/tutorials/calib3d/camera_calibration/camera_calibration.html).

Cụ thể, camera matrix là 1 matrix có dạng:
```
fx 0  px
0  fy py
0  0  1
```

Trong đó `fx, fy` là tiêu cự tương ứng trên trục Ox và Oy, `(px, py)` là
tọa độ của tâm camera trên màn ảnh.

## Với nội tham số (Chưa test hoàn toàn)
Ta có thể sử dụng nội tham số camera để suy ra camera matrix. Tham
số khởi tạo xem thêm trong file header.

Các thông số tương tự có thể lấy sử dụng Camera Api của android tại
[đây](https://developer.android.com/reference/android/hardware/camera2/CameraCharacteristics).
