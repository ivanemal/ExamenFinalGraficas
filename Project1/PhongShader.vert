#version 330 
in vec3 VertexPosition;
in vec3 VertexColor;
in vec3 VertexNormals; 


out vec3 InterpolatedColor;
out vec3 _PixelPosition; 
out vec3 _InterpolatedNormal; 
uniform mat4 mvpMatrix;
uniform mat4 _transform;
uniform mat3 _NormalMatrix;  


void main()
{
	InterpolatedColor = VertexColor;
	gl_Position = mvpMatrix * vec4(VertexPosition, 1.0f);
	_PixelPosition = vec3(_transform*vec4(VertexPosition,1.0)); 
	_InterpolatedNormal = _NormalMatrix * VertexNormals; 

}
