#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
	
    soilSandy.loadImage("pics/sandyb.jpg");
    soilClay.loadImage("pics/clayb.jpg");
    soilLoam.loadImage("pics/loamb.jpg");
    
}

void ofApp::update() {
    
    ofBackground(0x333333);

    //sandy
    convertColor(soilSandy, gray, CV_RGB2GRAY);
    Canny(gray, edgeSandy, mouseX, mouseY, 3);
    edgeSandy.update();
    
    //clay
    convertColor(soilClay, gray, CV_RGB2GRAY);
    Canny(gray, edgeClay, mouseX, mouseY, 3);
    edgeClay.update();
    
    //loam
    convertColor(soilLoam, gray, CV_RGB2GRAY);
    Canny(gray, edgeLoam, mouseX, mouseY, 3);
    edgeLoam.update();
    
}


void ofApp::draw() {
    
    ofSetColor(255);
    
    ofDrawBitmapString("Sandy Soil", 5, 20);
    soilSandy.draw(0, 30, 400, 300);
    
    int sandywhite = 0;
    int sandyblack = 0;
    
    unsigned char * sandypixels = edgeSandy.getPixels();
    for(int i = 0; i < edgeSandy.width*edgeSandy.height; i++){
        
        
        if (sandypixels[i] == 0){
			sandyblack++;
		}else{
			sandywhite++;
		}
	}
    
    int sandypercent = 100.00 * sandywhite / (sandyblack + sandywhite);
    
    ofDrawBitmapString("Sandy Soil Edges - "+ofToString(sandypercent, 3)+"%", 5, 350);
    edgeSandy.draw(0, 365, 400, 300);
    
    
    /////////////////////////////////
    
    
    ofDrawBitmapString("Clay Soil", 410, 20);
    soilClay.draw(405, 30, 400, 300);
    
    int claywhite = 0;
    int clayblack = 0;
    
    unsigned char * claypixels = edgeClay.getPixels();
    for(int i = 0; i < edgeClay.width*edgeClay.height; i++){
        
        if (claypixels[i] == 0){
			clayblack++;
		}else{
			claywhite++;
		}
	}
    
    int claypercent = 100 * claywhite / (clayblack + claywhite);
    
    ofDrawBitmapString("Clay Soil Edges - "+ofToString(claypercent, 3)+"%", 410, 350);
    edgeClay.draw(405, 365, 400, 300);
    
    
    /////////////////////////////////
    
    
    ofDrawBitmapString("Loam Soil", 810, 20);
    soilLoam.draw(810, 30, 400, 300);
    
    int loamwhite = 0;
    int loamblack = 0;
    
    unsigned char * loampixels = edgeLoam.getPixels();
    for(int i = 0; i < edgeLoam.width*edgeLoam.height; i++){
        
        
        if (loampixels[i] == 0){
			loamblack++;
		}else{
			loamwhite++;
		}
	}
    
    int loampercent = 100 * loamwhite / (loamblack + loamwhite);
    
    ofDrawBitmapString("Loam Soil Edges - "+ofToString(loampercent, 3)+"%", 810, 350);
    edgeLoam.draw(810, 365, 400, 300);
    
    
}
