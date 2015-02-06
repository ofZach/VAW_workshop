#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255,255,255);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    float timeT = ofGetElapsedTimef();
    while (timeT > 5) timeT -= 5.0;
    ofDrawBitmapStringHighlight(ofToString(timeT), 30,30);
    
    
    
    ofSetColor(0,0,0);
    
    
    stroke.draw(timeT, 1, 5);
    for (int i = 0; i < strokes.size(); i++){
        strokes[i].draw(timeT, 1, 5);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    strokes.clear();
    stroke.clear();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    float timeT = ofGetElapsedTimef();
    while (timeT > 5) timeT -= 5.0;
    stroke.addVertex(ofPoint(x,y), timeT);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    strokes.push_back(stroke);
    stroke.clear();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
