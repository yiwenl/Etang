//
//  Fish.cpp
//  EEtang
//
//  Created by Yiwen on 03/06/2014.
//
//

#include "Fish.h"
#include "MathUtils.h"


using namespace bongiovi::utils;

Fish::Fish() {
    _perlin.setSeed(int(MathUtils::random(9999)));
}


Fish::Fish(Vec3f loc) {
    location.set(loc);
    _perlin.setSeed(int(MathUtils::random(9999)));
}


void Fish::update() {
    acceleration.limit(maxForce);
    acceleration *= (1/mass);
    velocity += acceleration;
    location += velocity;
    
    acceleration.set(0, 0, 0);
    velocity.limit(maxSpeed);
    _bounce();
    
    rotation = atan2(location.y-preLocation.y, location.x - preLocation.x);
//    cout << "Rotation : " << rotation*180/M_PI << endl;
    preLocation.set(location);
}


void Fish::seek(Vec3f target) {
    Vec3f desiredVelocity = target - location;
    desiredVelocity.normalize();
    desiredVelocity *= maxSpeed;
    Vec3f force = desiredVelocity - velocity;
    acceleration += force;
}

void Fish::flee(Vec3f target) {
    Vec3f desiredVelocity = target - location;
    desiredVelocity.normalize();
    desiredVelocity *= maxSpeed;
    Vec3f force = desiredVelocity - velocity;
    acceleration -= force;
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


void Fish::flock(vector<Fish *> fishes) {
    Vec3f averageVelocity;
    averageVelocity.set(velocity);
    Vec3f averageLocation;
    averageLocation.set(0, 0, 0);
    int inSightCount = 0;
    
    vector<Fish *>::iterator it;
    for(it = fishes.begin() ; it!=fishes.end(); it++) {
        if( (*it) != this && inSight( *it) ) {
            averageVelocity += (*it)->velocity;
            averageLocation += (*it)->location;
            if(tooClose(*it)) flee((*it)->location);
            inSightCount++;
        }
    }
    
    if(inSightCount>0) {
        averageVelocity *= (1.0/(float)inSightCount);
        averageLocation *= (1.0/(float)inSightCount);
        seek(averageLocation);
        acceleration += averageVelocity;
    }
    
    
}

bool Fish::tooClose(Fish* fish) {
    return ((location - fish->location).length()) < tooCloseDist;
}


bool Fish::inSight(Fish* fish) {
    if( (location-fish->location).length() > inSightDist ) return false;
    
    Vec3f heading;
    heading.set(velocity);
    heading.normalize();
    Vec3f difference = fish->location - location;
    float dotProd = difference.dot(heading);
    if(dotProd < 0 ) return false;
    else return true;
}


void Fish::wonder() {
    Vec3f forceWonder;
    forceWonder.set(velocity);
    forceWonder.normalize();
    float offset = .002;
    forceWonder.rotateZ(_perlin.noise(location.x*offset, location.y*offset) * 3);
    float wonderForce = 1;
    forceWonder *= wonderForce;
    acceleration += forceWonder;
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