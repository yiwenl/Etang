uniform vec3            position;
uniform float           ratio;


void main() {
    gl_TexCoord[0]      = gl_MultiTexCoord0;
    vec4 pos            = gl_Vertex;
    pos.y               *= ratio;
    pos.xyz             += position;
    

    gl_Position         = gl_ModelViewProjectionMatrix * pos;
}