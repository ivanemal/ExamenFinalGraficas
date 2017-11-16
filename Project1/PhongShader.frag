#version 330

in vec3 InterpolatedColor;
in vec3 _InterpolatedNormal;
in vec3 _PixelPosition;
in vec3 VertexColor;

out vec4 FragColor;
uniform vec3 _LightColor;

uniform mat4 _transform;
uniform mat4 _transform2;
uniform vec3 _LightPosition;
uniform vec3 _CameraPosition;

void main()
{
	vec3 _Ambient = _LightColor * 0.1f;
	vec3 _Light =normalize(_LightPosition - _PixelPosition);
	vec3 _Diffuse = (dot(_InterpolatedNormal,_Light))*_LightColor;
	vec3 _Reflection = reflect((-1*_Light), _InterpolatedNormal);
	vec3 _View =  normalize(_CameraPosition - _PixelPosition);
	vec3 _Specular= (0.5f*(pow(dot(_View, _Reflection), 32))*_LightColor);
	vec3 _Phong = (_Ambient + _Diffuse + _Specular)*InterpolatedColor; 
	FragColor = vec4(_Phong, 1.0f);
}
