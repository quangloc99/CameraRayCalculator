#include <opencv2/opencv.hpp>
#include <bits/stdc++.h>
#include "CameraRayCalculator.hpp"

using namespace cv;
using namespace std;

int main() {
  CameraRayCalculator getRay(3.5f, 4.69f, 3.52f, 4160, 3120);
  cout << getRay(getRay.getImageWidth() / 2, 0);
  return 0;
}
