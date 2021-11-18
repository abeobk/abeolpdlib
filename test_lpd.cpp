#include <opencv2/opencv.hpp>
#include "lpd.h"

//#define SHOW_DEBUG


using namespace cv;
using namespace std; 

int main(int argc, char** argv){
    
    if(argc<4){
        std::cout<<"TOO FEW ARGUMENTS!"<<std::endl;
        std::cout<<"syntax: test_lpd config_dir video_file"<<std::endl;
    }

    std::string config_dir = argv[1];
    std::string video_file = argv[2];

    cout<<"config_dir="<<config_dir<<endl;
    cout<<"video_file="<<video_file<<endl;

    abeo::LaunchpadDetector lpd(config_dir);
    cv::VideoCapture cap(video_file);
    cv::Mat img;

    bool extreme=false;
    double last_height=1e9;
    double extreme_height=5000.0;

    //load img
    for(int i=0;;i++){
        //capture an image
        cap>>img;

        //detect
        auto res = lpd.detect(img,extreme, true);

        //should we use extreme mode?
        extreme = res.error > 1.0 || res.z > extreme_height;

        //Print position
        cout<<"Position: ("<<res.x<<","<<res.y<<","<<res.z<<")"<< endl;
        cout<<"Angle: "<<res.angle<<"degree"<<endl;
        
        //show image
        imshow("img",img);

        waitKey();
    }
}
