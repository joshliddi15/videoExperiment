#include <opencv2/opencv.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

void adjustGamma(cv::Mat& image, double gamma = 1.5) {
    double invGamma = 1.0 / gamma;
    cv::Mat table(1, 256, CV_8U);
    uchar* p = table.data;
    for (int i = 0; i < 256; ++i)
        p[i] = cv::saturate_cast<uchar>(pow(i / 255.0, invGamma) * 255.0);
    cv::LUT(image, table, image);
}

int main() {
    using namespace cv;
    const char* tesseractPath = "C:\\Users\\joshl\\AppData\\Local\\Programs\\Tesseract-OCR\\tesseract.exe";
    cv::VideoCapture cap(".\\test2.mp4");

    int interval = 10;  // in seconds
    double frameRate = 32;  //cap.get(cv::CAP_PROP_FPS);
    int intervalFrames = static_cast<int>(interval * frameRate);

    // Offset for starting frame
    int frameCount = 10;

    while (cap.isOpened()) {
        cv::Mat frame;
        bool ret = cap.read(frame);

        if (!ret)
            break;

        if (frameCount % intervalFrames == 0) {
            frame = frame(cv::Rect(800, 400, 400, 200));  // Adjust the region of interest

            cv::convertScaleAbs(frame, frame, 3, 40);
            adjustGamma(frame);
            cv::addWeighted(frame, 1.3, frame, 0, 60, frame);
            cv::Mat grayFrame;
            cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);
            cv::bilateralFilter(grayFrame, frame, 1, 17, 17);

            cv::imshow("window", frame);

            int key = cv::waitKey(10);

            if (key == 'q' || key == 'Q')
                break;

            // Perform text detection using Tesseract
            cv::imwrite(".\\temp.png", frame);
            tesseract::TessBaseAPI tess;
            if (tess.Init(NULL, "eng", tesseract::OEM_DEFAULT) == 0) {
                PIX* image = pixRead(".\\temp.png");
                tess.SetImage(image);
                char* out = tess.GetUTF8Text();
                std::string text(out);
                std::cout << "Detected text: " << text << std::endl;
                delete[] out;
                pixDestroy(&image);
            }

            // Invoking the command processor and calling the pause command
            system("pause");
        }

        ++frameCount;
    }

    return 0;
}
