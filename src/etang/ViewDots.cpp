//
//  ViewDots.cpp
//  Etang
//
//  Created by Yiwen on 05/07/2014.
//
//

#include "ViewDots.h"
#include "MathUtils.h"

using namespace etang;
using namespace bongiovi::utils;

ViewDots::ViewDots() : View("shaders/dot.vert", "shaders/dot.frag") {
    _init();
}

ViewDots::ViewDots(string vsPath, string fsPath) : View(vsPath, fsPath) {
    _init();
}


void ViewDots::_init() {
    int numParticles    = 1000;
    int range           = 1000;
    int i               = 0;
    float               tx, ty, tz;
    
    vector<uint> indices;
    vector<Vec3f> positions;
    
    while(i++ < numParticles) {
        tx = MathUtils::random(-range, range);
        ty = MathUtils::random(-range, range);
        tz = MathUtils::random(-range, range);
        
        positions.push_back(Vec3f(tx,   ty,   tz));
        indices.push_back(i);
    }
    
    
    gl::VboMesh::Layout layout;
    layout.setStaticIndices();
    layout.setStaticPositions();
    
    mesh = gl::VboMesh(positions.size(), positions.size(), layout, GL_POINTS);
    mesh.bufferPositions(positions);
    mesh.bufferIndices(indices);

}


void ViewDots::render() {
    shader->bind();
    gl::draw(mesh);
    shader->unbind();
}