#include "ofApp.h"




//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255,255,255);
}

//--------------------------------------------------------------
void ofApp::update(){

}


void ofApp::drawPolyineThickWZ( ofPolyline & line){
    
    ofMesh meshy;
    meshy.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    float widthSmooth = 10;
    float angleSmooth;
    
    for (int i = 0;  i < line.getVertices().size(); i++){
        int me_m_one = i-1;
        int me_p_one = i+1;
        if (me_m_one < 0) me_m_one = 0;
        if (me_p_one ==  line.getVertices().size()) me_p_one =  line.getVertices().size()-1;
        ofPoint diff = line.getVertices()[me_p_one] - line.getVertices()[me_m_one];
        float angle = atan2(diff.y, diff.x);
        float dist = diff.length();
        ofPoint offset;
        offset.x = cos(angle + PI/2) * line.getVertices()[i].z;
        offset.y = sin(angle + PI/2) * line.getVertices()[i].z;
        meshy.addVertex(  line.getVertices()[i] +  offset );
        meshy.addVertex(  line.getVertices()[i] -  offset );
    }
    
    meshy.draw();
    
    
}
void ofApp::drawPolyineThick( ofPolyline & line, int thickness){
    
    
    ofMesh meshy;
    meshy.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);

    float widthSmooth = 10;
    float angleSmooth;
    
    for (int i = 0;  i < line.getVertices().size(); i++){
        int me_m_one = i-1;
        int me_p_one = i+1;
        if (me_m_one < 0) me_m_one = 0;
        if (me_p_one ==  line.getVertices().size()) me_p_one =  line.getVertices().size()-1;
        ofPoint diff = line.getVertices()[me_p_one] - line.getVertices()[me_m_one];
        float angle = atan2(diff.y, diff.x);
        float dist = diff.length();
        ofPoint offset;
        offset.x = cos(angle + PI/2) * thickness;
        offset.y = sin(angle + PI/2) * thickness;
        meshy.addVertex(  line.getVertices()[i] +  offset );
        meshy.addVertex(  line.getVertices()[i] -  offset );
    }
    
    meshy.draw();
   
    
}


//--------------------------------------------------------------
void ofApp::draw(){

    
    ofSetColor(0,0,0);
    
    drawPolyineThick(line, 10);
    
    ofSetColor(100,100,100);
    
    drawPolyineThickWZ(lineWZasWidth);
            
    
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

    line.addVertex(ofPoint(x,y));
    
    lineWZasWidth.addVertex(ofPoint(x + 300,y,20 + 10 * sin(ofGetElapsedTimef() * 5)));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    line.clear();
    
    lineWZasWidth.clear();
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
