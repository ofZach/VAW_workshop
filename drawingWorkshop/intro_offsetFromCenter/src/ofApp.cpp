#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0,0,0);
    
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){

    
    if (ofGetMousePressed() == true){
        
        // first, make a point
        ofPoint pt;
        pt.set(mouseX, mouseY);
        
        // then add it to the line. 
        line.addVertex(pt);
    }
    
    
    for (int i = 0; i < line.getVertices().size(); i++){
        
        if (ofGetMousePressed() == true){
            ofPoint diff = ofPoint (mouseX, mouseY) - ofPoint(ofGetWidth()/2, ofGetHeight()/2);
            line.getVertices()[i].x -= diff.x * 0.05;
            line.getVertices()[i].y -= diff.y * 0.05;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    line.draw();
    
    
    
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

    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    line.clear();
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
