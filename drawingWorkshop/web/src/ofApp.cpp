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

    ofEnableAlphaBlending();
    ofSetColor(30,30,30,30);
    
    for (int i = 0; i < lines.size(); i++){
        
        ofLine( lines[i].a.x, lines[i].a.y, lines[i].b.x, lines[i].b.y);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f') ofToggleFullscreen();
    

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

    for (int i = 0; i < drawnPoints.size(); i++){
        ofPoint mouse;
        mouse.set(x,y);
        float dist = (mouse - drawnPoints[i]).length();
        if (dist < 30){
            line lineTemp;
            lineTemp.a = mouse;
            lineTemp.b = drawnPoints[i];
            lines.push_back(lineTemp);
        }
    }
    
    drawnPoints.push_back(ofPoint(x,y));
    
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
