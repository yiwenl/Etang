uniform vec3            position;
uniform float           ratio;
uniform float           rotation;




void main() {
    gl_TexCoord[0]      = gl_MultiTexCoord0;
    vec4 pos            = gl_Vertex;
    
    mat3 rotationMtx = mat3(
         vec3( cos(rotation),  sin(rotation),  0.0),
         vec3(-sin(rotation),  cos(rotation),  0.0),
         vec3(        0.0,         0.0,  1.0)
    );
    
    pos.xyz             *= rotationMtx;
    pos.y               *= ratio;
    pos.xyz             += position;
    

    gl_Position         = gl_ModelViewProjectionMatrix * pos;
}