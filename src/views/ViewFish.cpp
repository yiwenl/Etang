//
//  ViewFish.cpp
//  EEtang
//
//  Created by Yiwen on 27/05/2014.
//
//

#include "ViewFish.h"
#include "MeshUtils.h"

ViewFish::ViewFish() : View("shaders/fish.vert", "shaders/fish.frag") {
    _init();
}

ViewFish::ViewFish(string vsPath, string fsPath) : View(vsPath, fsPath) {
    _init();
}


void ViewFish::_init() {
//    mesh = bongiovi::MeshUtils::createPlane(.02, 1);
    
    gl::VboMesh::Layout layout;
    layout.setStaticIndices();
    layout.setStaticTexCoords2d();
    layout.setStaticPositions();
    
    vector<uint> indices;
    vector<Vec3f> positions;
    vector<Vec2f> coords;
    
    
    
    float size = .2;
    int i, j, count = 0;
    float numSeg = 5;
    float numSegX = 2;
    float segSize = size/(float)numSeg;
    float segSizeY = segSize * 2.5 * .5;
    float uvBase = 1.0/numSeg;
    float uvBaseX = 1.0/numSegX;
    float startPos = size / 2.0f;
    
    for(j=0; j<numSeg; j++) {
        for(i=0; i<numSegX; i++) {
            positions.push_back(Vec3f(-startPos + i*segSize,       -j*segSizeY,   0));
            positions.push_back(Vec3f(-startPos + (i+1)*segSize,   -j*segSizeY,   0));
            positions.push_back(Vec3f(-startPos + (i+1)*segSize,   -(j+1)*segSizeY,   0));
            positions.push_back(Vec3f(-startPos + i*segSize,       -(j+1)*segSizeY,   0));
            
            coords.push_back(Vec2f(uvBaseX*i, uvBase*j));
            coords.push_back(Vec2f(uvBaseX*(i+1), uvBase*j));
            coords.push_back(Vec2f(uvBaseX*(i+1), uvBase*(j+1)));
            coords.push_back(Vec2f(uvBaseX*i, uvBase*(j+1)));
            
            
            indices.push_back(count*4+0);
            indices.push_back(count*4+1);
            indices.push_back(count*4+2);
            indices.push_back(count*4+0);
            indices.push_back(count*4+2);
            indices.push_back(count*4+3);
            
            count++;
        }
    }
    
    mesh = gl::VboMesh(positions.size(), indices.size(), layout, GL_TRIANGLES);
    mesh.bufferPositions(positions);
    mesh.bufferIndices(indices);
    mesh.bufferTexCoords2d(0, coords);

}


void ViewFish::render(gl::TextureRef texture, Vec3f pos, float rotation) {
    shader->bind();
    shader->uniform("texture", 0);
    shader->uniform("position", pos);
    shader->uniform("rotation", -rotation+float(M_PI*.5));
    shader->uniform("ratio", float(getWindowWidth())/(float(getWindowHeight())) );
    texture->bind();
    gl::draw(mesh);
    texture->unbind();
    shader->unbind();
}