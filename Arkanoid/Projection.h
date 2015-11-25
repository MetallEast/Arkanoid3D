#include <iostream>
#include "gl\glut.h"

#pragma once

typedef GLfloat GLTVector3[3];
typedef GLfloat GLTVector4[4];
typedef GLfloat GLTMatrix[16];

class Projection
{
	GLfloat ambientLight[4];
	GLfloat diffuseLight[4];
	GLfloat specular[4];

	GLfloat gltGetVectorLength(GLTVector3 vNormal);
	void gltScaleVector(GLTVector3 vVector, const GLfloat fScale);
	void gltNormalizeVector(GLTVector3 vNormal);
	void gltSubtractVectors(const GLTVector3 vFirst, const GLTVector3 vSecond, GLTVector3 vResult);
	void gltVectorCrossProduct(const GLTVector3 vU, const GLTVector3 vV, GLTVector3 vResult);
	void gltGetNormalVector(const GLTVector3 vP1, const GLTVector3 vP2, const GLTVector3 vP3, GLTVector3 vNormal);
	void gltGetPlaneEquation(GLTVector3 vPoint1, GLTVector3 vPoint2, GLTVector3 vPoint3, GLTVector3 vPlane);
	void gltMakeShadowMatrix(GLTVector3 vPoints[3], GLTVector4 vLightPos, GLTMatrix destMat);
public:
	GLTMatrix shadowMat, shadowMatParts;
	GLfloat	lightPos[4], lightPosParts[4];

	void Init(GLfloat, GLfloat, GLfloat, GLfloat);
	void InitParts(GLfloat, GLfloat, GLfloat, GLfloat);
	Projection();
	~Projection(void);
};

