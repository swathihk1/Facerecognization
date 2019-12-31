#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include "string.h"

using namespace std;
using namespace cv;



__global__ bool detectAndDraw( Mat& img, CascadeClassifier& cascade, double scale);
{
vector<Rect> faces;
Mat gray;
cvtColor( img, gray, COLOR_BGR2GRAY );

cascade.detectMultiScale( gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );

for ( size_t i = 0; i < faces.size(); i++ )
{
Rect r = faces[i];
Scalar color = Scalar(255, 0, 0);
rectangle( img, cvPoint(cvRound(r.x*scale), cvRound(r.y*scale)), cvPoint(cvRound((r.x +
r.width-1)*scale), cvRound((r.y + r.height-1)*scale)), color, 3, 8, 0);
}

imwrite(DetectedImg+ ".jpg", img);
imshow( "Face Detection", img );
return true;
}


int main()
{
// Load the cascade classifier
cascade.load( "../../haarcascade_frontalcatface.xml" ) ;
double scale=1;

string str;

cin>>str;

if(str== 'q')
     break;


frame = imread(str, CV_LOAD_IMAGE_COLOR);


//bool status= detectAndDraw( frame, cascade, scale );

bool status = detectAndDraw<<<1,1>>>(frame, cascade, scale);
if(!status)
    cout<<"Please wait";

return 0;
}

