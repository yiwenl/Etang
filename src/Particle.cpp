//
//  Particle.cpp
//  Etang
//
//  Created by Yiwen on 05/07/2014.
//
//

#include "Particle.h"

using namespace etang;


Particle::Particle() {
    location.set(0, 0, 0);
    velocity.set(0, 0, 0);
    acceleration.set(0, 0, 0);
}


Particle::Particle(float x, float y, float z) {
    location.set(x, y, z);
    velocity.set(0, 0, 0);
    acceleration.set(0, 0, 0);
}


void Particle::update(vector<Particle*> particles) {
    _pullToCenter();
    velocity += acceleration;
    location += velocity;
    acceleration.set(0, 0, 0);
}


void Particle::_pullToCenter() {
    Vec3f dirToCenter = Vec3f(location);
    float distToCenter = dirToCenter.length();
    float maxDistance = 500.0f;
    
    if(distToCenter > maxDistance) {
        dirToCenter.normalize();
        float pullStrength = .0001f;
        acceleration -= dirToCenter * ( ( distToCenter - maxDistance ) * pullStrength );
    }
}