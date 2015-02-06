#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    ofSetFrameRate(60);
    
    particleA.bFixed = true;
    
    particleA.pos.set(100,100);
    particleB.pos.set(100,100);
    particleC.pos.set(100,100);
    
    
    connector.springiness = 0.15;
    connector.distance = 0;
    connector.particleA = &particleA;
    connector.particleB = &particleB;
    
    connector2.springiness = 0.05;
    connector2.distance = 0;
    connector2.particleA = &particleB;
    connector2.particleB = &particleC;
    
    //ofBackground(0, 0, 0);
    
    
}

ofPolyline temp;

//--------------------------------------------------------------
void ofApp::update(){

    
    particleA.pos.set(mouseX, mouseY);
    
    
    particleB.resetForce();
    connector.update();
    particleB.addDampingForce();
    particleB.update();
    
    particleC.resetForce();
    connector2.update();
    particleC.addDampingForce();
    particleC.update();
    
    
    
    if (ofGetMousePressed())
    temp.addVertex(particleC.pos);
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofBackgroundGradient(ofColor(10,10,10), ofColor(0,0,0) );
    
    particleA.draw();
    particleB.draw();
    particleC.draw();
    connector.draw();
    connector2.draw();
    
    if (temp.getVertices().size() > 500){
        temp.getVertices().erase(temp.getVertices().begin());
    }
    
    ofEnableAlphaBlending();
    //temp.draw();
    
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < temp.getVertices().size(); i++){
        float pct = ofMap(i, 0, temp.getVertices().size()-1, 0,1);
        ofSetColor(255,255,255,255*pct);
        glVertex2f(temp.getVertices()[i].x, temp.getVertices()[i].y);
    }
    glEnd();
    ofEndShape();
    
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

    temp.clear();
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
