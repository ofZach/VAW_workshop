#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0,0,0);
    
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){

    
    
    
    for (int i = 0; i < line.getVertices().size(); i++){
        
        if (ofGetMousePressed() == false){
        float distance = ofDist(mouseX, mouseY, line.getVertices()[i].x, line.getVertices()[i].y);
        if (distance < 100){
            
            float pct = ofMap(distance, 0,100, 1,0);
            
            ofPoint diff = ofPoint(mouseX, mouseY) - ofPoint(line.getVertices()[i].x, line.getVertices()[i].y);
            diff.normalize();
            
            line.getVertices()[i].x += diff.x * 2 *  pct;
            line.getVertices()[i].y += diff.y * 2 * pct;
            
        }
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

    // first, make a point
    ofPoint pt;
    pt.set(x,y);
    
    // then add it to the line. 
    line.addVertex(pt);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    line.clear();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    int nPts =  line.getVertices().size();
    line = line.getResampledByCount(nPts * 5);
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
