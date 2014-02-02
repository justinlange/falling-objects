#pragma once

#include "ofMain.h"
#include "ofxSpacebrew.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"
//#include "ofx3DModelLoader.h"

GLfloat lightOnePosition[] = {40.0, 40, 100.0, 0.0};
GLfloat lightOneColor[] = {0.99, 0.99, 0.99, 1.0};

GLfloat lightTwoPosition[] = {-40.0, 40, 100.0, 0.0};
GLfloat lightTwoColor[] = {0.99, 0.99, 0.99, 1.0};

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    // create your spacebrew object
    Spacebrew::Connection spacebrew;
    
    // listen to spacebrew Messages
    void onMessage( Spacebrew::Message & m );
    
    // button stuff
    int  radius;
    bool bButtonPressed;
    bool bBackgroundOn;
    
    // useful quick test
    bool checkInsideCircle( ofPoint point, ofPoint position, int radius );
    
//-----------------MODEL-----------------//
    //void setupModel();
    
    
//-----------------KINECT----------------//
    
    void drawPointCloud();
    void keyPressed (int key);
    void exit();

    
    ofxKinect kinect;
	
#ifdef USE_TWO_KINECTS
	ofxKinect kinect2;
#endif
	
	ofxCvColorImage colorImg;
	
	ofxCvGrayscaleImage grayImage; // grayscale depth image
	ofxCvGrayscaleImage grayThreshNear; // the near thresholded image
	ofxCvGrayscaleImage grayThreshFar; // the far thresholded image
	
	ofxCvContourFinder contourFinder;
	
	bool bThreshWithOpenCV;
	bool bDrawPointCloud;
	
	int nearThreshold;
	int farThreshold;
	
	int angle;
    int rotateY;
	
	// used for viewing the point cloud
	ofEasyCam easyCam;
   // ofx3DModelLoader squirrelModel;

};
