#include <opencv2/opencv.hpp>
#include "lpd.h"

//#define SHOW_DEBUG


using namespace cv;
using namespace std; 

cv::Mat get_sample(std::string const& dir, int idx){
    std::stringstream ss;
    ss<<dir<<"/"<<idx<<".png";
    return cv::imread(ss.str());
}


int main(int argc, char** argv){
    if(argc<4){
        std::cout<<"TOO FEW ARGUMENTS!"<<std::endl;
        std::cout<<"syntax: test_lpd config_dir sample_dir rotation_angle"<<std::endl;
    }

    std::string config_dir = argv[1];

    std::string test_dir= argv[2];

    double angle = std::stod(argv[3]);

    cout<<"config_dir="<<config_dir<<endl;
    cout<<"test_dir="<<test_dir<<endl;

    abeo::LaunchpadDetector lpd(config_dir);

    //load img
    for(int i=0;i<20;i++){
        //load img
        auto img = get_sample(test_dir, i);

        //Test rotate image
        auto M = cv::getRotationMatrix2D(cv::Point2f(img.cols/2,img.rows/2),angle,1.0);
        cv::warpAffine(img,img,M, cv::Size(img.cols,img.rows));

        //detect
        auto res = lpd.detect(img,true);

        //Print position
        cout<<"Position: ("<<res.x<<","<<res.y<<","<<res.z<<")"<< endl;
        cout<<"Angle: "<<res.angle<<"degree"<<endl;
        
        //show image
        imshow("img",img);

        waitKey();
    }
}
