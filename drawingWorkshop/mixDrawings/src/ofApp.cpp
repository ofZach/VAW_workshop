#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    bDrawingFirst = true;
    ofBackground(255, 255, 255);
    slider.setup(30, 30, 100, 20, 0, 1, 0, false, 0);
    bDrawing = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(230,230,230);
    ofFill();
    ofRect(0,0,ofGetWidth(), 100);
    
    ofSetColor(0,0,0);
    
    if (bDrawing){
        if (bDrawingFirst) lineA.draw();
        else lineB.draw();
    }
    
    if (lineA.getVertices().size() == lineB.getVertices().size()){
        
        int nPts = lineA.getVertices().size();
        ofPolyline mix;
        mix.resize(nPts);
        
        float pct = slider.getValue();
        
        for (int i = 0; i < lineA.getVertices().size(); i++){
            
            mix.getVertices()[i] = (1-pct) * lineA.getVertices()[i] + 
                                     (pct) * lineB.getVertices()[i];
        }
        
        
        mix.draw();
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

    if (mouseY < 100) return;
    
    if (bDrawingFirst == true){
        lineA.addVertex(ofPoint(x,y));
    } else {
        lineB.addVertex(ofPoint(x,y));
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    if (mouseY < 100) return;
   
    
    if (bDrawingFirst == true){
        lineA.clear();
        lineA.addVertex(ofPoint(x,y));
    } else {
        lineB.clear();
        lineB.addVertex(ofPoint(x,y));
        
    }
    
    bDrawing = true;
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    if (mouseY < 100) return;
    
    if (lineA.getVertices().size() > 0){
        lineA = lineA.getResampledByCount(250);
    }
    
    if (lineB.getVertices().size() > 0){
        lineB = lineB.getResampledByCount(250);
    }
    
   
    bDrawingFirst = !bDrawingFirst;
    
    bDrawing = false;
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
