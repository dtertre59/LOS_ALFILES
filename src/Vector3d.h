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
	void MoverVect(float xx, float yy, float zz);
	float RPosx() { return x; }
	float RPosy() { return y; }
	float GetVect();
	Vector3d operator-(Vector3d);

	//funciones amigas
	friend bool operator==(const Vector3d&, const Vector3d&);
};