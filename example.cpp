#include <opencv2/opencv.hpp>
#include <bits/stdc++.h>
#include "CameraRayCalculator.hpp"

using namespace cv;
using namespace std;

Mat getCamMatrix(const FileNode& camParams) {
    return (Mat_<float>(3, 3) <<
        (float)camParams["FocalLength"][0], 0, (float)camParams["PrincipalPoint"][0],
        0, (float)camParams["FocalLength"][1], (float)camParams["PrincipalPoint"][1],
        0, 0, 1
    );
}

int main() {
  FileStorage fs("config.json", FileStorage::READ);
  Mat camMat = getCamMatrix(fs["camera-params"]);
  CameraRayCalculator rayCaltor(camMat);
  cout << rayCaltor.getRay(0.f, 0.f);
  return 0;
}
