#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofEnableDepthTest();
    baseNode.setPosition(0, 0, 0);
    childNode.setParent(baseNode);
    childNode.setPosition(0, 0, 200);
    grandChildNode.setParent(childNode);
    grandChildNode.setPosition(0,50,0);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    baseNode.pan(1);
    childNode.tilt(3);
    
    line.addVertex(grandChildNode.getGlobalPosition());
    if (line.size() > 200){
        
        line.getVertices().erase(
                                 line.getVertices().begin()
                                 );
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    cam.begin();
    baseNode.draw();
    childNode.draw();
    grandChildNode.draw();
    
    line.draw();
    
    cam.end();
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
