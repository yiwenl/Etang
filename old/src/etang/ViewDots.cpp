//
//  ViewDots.cpp
//  Etang
//
//  Created by Yiwen on 05/07/2014.
//
//

#include "ViewDots.h"
#include "MathUtils.h"
#include "Model.h"
#include "Particle.h"

using namespace etang;
using namespace bongiovi::utils;

ViewDots::ViewDots() : View("shaders/dot.vert", "shaders/dot.frag") {
    _init();
}

ViewDots::ViewDots(string vsPath, string fsPath) : View(vsPath, fsPath) {
    _init();
}


void ViewDots::_init() {
    vector<uint> indices;
    vector<Vec3f> positions;
    vector<Particle*> particles = Model::getInstance().controller->getParticles();
    
    vector<Particle*>::iterator it;
    int count = 0;
    for(it = particles.begin(); it!=particles.end(); it++) {
        positions.push_back((*it)->location);
        indices.push_back(count);
        count ++;
    }
    
    gl::VboMesh::Layout layout;
    layout.setStaticIndices();
    layout.setStaticPositions();
    
    mesh = gl::VboMesh(positions.size(), positions.size(), layout, GL_POINTS);
    mesh.bufferPositions(positions);
    mesh.bufferIndices(indices);
}


void ViewDots::_updatePositions() {
    vector<Particle*> particles = Model::getInstance().controller->getParticles();
    vector<Vec3f> positions;
    
    vector<Particle*>::iterator it;
    for(it = particles.begin(); it!=particles.end(); it++) {
        positions.push_back((*it)->location);
    }
    
    mesh.bufferPositions(positions);
}


void ViewDots::render() {
    _updatePositions();
    
    shader->bind();
    gl::draw(mesh);
    shader->unbind();
}