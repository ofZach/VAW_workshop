#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetVerticalSync(true);
    ofBackground(255,255,255);
}

//--------------------------------------------------------------
void ofApp::update(){

    
    float rotateX = 0;
    float rotateY = 0;
    float rotateZ = 0;
    
    if (ofGetKeyPressed('a')) rotateX = 1;
    if (ofGetKeyPressed('s')) rotateX = -1;
    if (ofGetKeyPressed('z')) rotateY = 1;
    if (ofGetKeyPressed('x')) rotateY = -1;
    if (ofGetKeyPressed('q')) rotateZ = 1;
    if (ofGetKeyPressed('w')) rotateZ = -1;
    
    
    
    
    for (int i = 0; i < line.getVertices().size(); i++){
        ofPoint fromCenter = line.getVertices()[i] - ofPoint(ofGetWidth()/2, ofGetHeight()/2);
        ofMatrix4x4 rotateMatrix; 
        rotateMatrix.makeRotationMatrix(1, rotateX, rotateY, rotateZ);
        ofPoint rot = fromCenter * rotateMatrix + ofPoint(ofGetWidth()/2, ofGetHeight()/2);
        line.getVertices()[i] = rot;
    }
    
    
    for (int i = 0; i < lines.size(); i++){
        for (int j = 0; j < lines[i].getVertices().size(); j++){
            ofPoint fromCenter = lines[i].getVertices()[j] - ofPoint(ofGetWidth()/2, ofGetHeight()/2);
            ofMatrix4x4 rotateMatrix; 
            rotateMatrix.makeRotationMatrix(1, rotateX, rotateY, rotateZ);
            ofPoint rot = fromCenter * rotateMatrix + ofPoint(ofGetWidth()/2, ofGetHeight()/2);
            lines[i].getVertices()[j] = rot;
        }
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofSetColor(0,0,0);
    
    
    line.draw();
    for (int i = 0; i < lines.size(); i++){
        lines[i].draw();
    }
    
    ofDrawBitmapStringHighlight("q,w,a,s,z,x to rotate", ofPoint(50,50));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' '){
        lines.clear();
        line.clear();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

    line.addVertex(ofPoint(x,y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    line.clear();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

   lines.push_back(line);
    line.clear();
    
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
