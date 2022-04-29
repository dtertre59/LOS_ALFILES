#pragma once
class Vector3d
{
public:
	float x;
	float y;
	float z;

	Vector3d();
	void Set_vector(float equis, float i, float ceta);
	void Set_vector(Vector3d v);
};