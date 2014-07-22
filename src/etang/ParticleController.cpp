//
//  ParticleController.cpp
//  Etang
//
//  Created by Yiwen on 09/07/2014.
//
//

#include "ParticleController.h"
#include "MathUtils.h"

using namespace etang;
using namespace bongiovi::utils;


ParticleController::ParticleController(int numParticles, GlobalSettings* settings) {
    _numParticles   = numParticles;
    _settings       = settings;
    
    _init();
}


void ParticleController::_init() {
    _particles.empty();
    _particles.clear();
    
    int i               = 0;
    float range         = _settings->maxDistance;
    float velocityRange = 1.0f;
    
    while(i < _numParticles) {
        Particle* p = new Particle(MathUtils::random(-range, range), MathUtils::random(-range, range), MathUtils::random(-range, range));
        
        p->velocity.set(MathUtils::random(-velocityRange, velocityRange), MathUtils::random(-velocityRange, velocityRange), MathUtils::random(-velocityRange, velocityRange));
        _particles.push_back(p);
        i++;
    }
}


void ParticleController::update() {
    vector<Particle*>::iterator it = _particles.begin();
    
    while (it!= _particles.end() ) {
        Particle* p = (*it);
        p->update(_particles);
        it++;
    }
    
}


vector<Particle*> ParticleController::getParticles() {  return _particles;  }