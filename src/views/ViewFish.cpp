//
//  ViewFish.cpp
//  EEtang
//
//  Created by Yiwen on 27/05/2014.
//
//

#include "ViewFish.h"


ViewFish::ViewFish() {}

ViewFish::ViewFish(string vsPath, string fsPath) : View(vsPath, fsPath) {
    _init();
}


void ViewFish::_init() {
    
}


void ViewFish::render(gl::TextureRef texture) {
    shader->bind();
    shader->uniform("texture", 0);
    texture->bind();
    gl::draw(mesh);
    texture->unbind();
    shader->unbind();
}