//
//  Fish.cpp
//  EEtang
//
//  Created by Yiwen on 03/06/2014.
//
//

#include "Fish.h"

Fish::Fish() {
    
}


Fish::Fish(Vec3f loc) {
    location.set(loc);
}


void Fish::update() {
    acceleration.limit(maxForce);
    acceleration *= (1/mass);
    velocity += acceleration;
    location += velocity;
    
    acceleration.set(0, 0, 0);
    
    _bounce();
}


void Fish::seek(Vec3f target) {
    Vec3f desiredVelocity = target - location;
    desiredVelocity.normalize();
    desiredVelocity *= maxSpeed;
    Vec3f force = desiredVelocity - velocity;
    acceleration += force;
}


void Fish::arrive(Vec3f target) {
    Vec3f desiredVelocity = target - location;
    desiredVelocity.normalize();
    
    float dist = (location-target).length();
    if(dist > arriveThreshold) desiredVelocity *= maxSpeed;
    else desiredVelocity *= (maxSpeed * dist / arriveThreshold);
    
    Vec3f force = desiredVelocity - velocity;
    acceleration += force;
}


void Fish::_bounce() {
    int w = getWindowWidth();
    int h = getWindowHeight();
    
    if(location.x > w) {
        location.x = w;
        velocity.x *= -1;
    } else if(location.x < 0) {
        location.x = 0;
        velocity.x *= -1;
    }

    if(location.y > h) {
        location.y = h;
        velocity.y *= -1;
    } else if(location.y < 0) {
        location.y = 0;
        velocity.y *= -1;
    }

}