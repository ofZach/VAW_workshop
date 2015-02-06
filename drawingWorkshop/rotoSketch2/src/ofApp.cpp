#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    pina.loadMovie("pina.mov");
    cout << pina.getHeight() << endl;
    pina.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    pina.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
    ofSetColor(255,255,255);
    pina.draw(0,0);
    
    
    float time = pina.getPosition() * pina.getDuration();
    
    ofDrawBitmapStringHighlight(ofToString(time), 30,30);
    
    
    //stroke.draw();
    
    ofSetColor(0,0,0);
    
    stroke.totalTime = pina.getDuration();
    stroke.draw(time, 1);
    
    for (int i = 0; i < strokes.size(); i++){
        strokes[i].draw(time, 1);
        strokes[i].totalTime = pina.getDuration();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    strokes.clear();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    if (mouseY > 600){
        
        float speed = ofMap(mouseX, 0, ofGetWidth(), -2, 2);
        pina.setSpeed(speed);
        return;
        
    }
    
    float time = pina.getPosition() * pina.getDuration();
    stroke.addVertex(ofPoint(x,y), time);
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
