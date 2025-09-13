#include <iostream>
#include <opencv2/opencv.hpp>
#include <filesystem>

int main(int argc, char** argv) {

    //If the ints app, input_image and output_image return error
    if (argc<3){
        std::cout << "Usage: app <input_image> <output_image>" << std::endl;
        return 1;
    }

    std::filesystem::path im_in_path = argv[1]; //this is a path variable now
    std::filesystem::path im_out_path = argv[2];

    //---------Load a CV image---------
    cv::Mat img = cv::imread(im_in_path.string(),cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cout << "Image not loaded correctly" << std::endl;
        return 2;
    }

    //---------Preprocess the image---------
    cv::Mat resized; //new empty matrix
    //We take img we resize it to 224,224 and put it in 'resized' variable
    cv::resize(img, resized, cv::Size(224,224), 0, 0, cv::INTER_LINEAR);

    cv::Mat rgb;
    cv::cvtColor(resized, rgb, cv::COLOR_BGR2RGB);

    //---------Display an image---------
    cv::imshow("Resized RGB image",rgb);
    cv::waitKey(0); //Wait for a button to be pressed


    return 0;
}

