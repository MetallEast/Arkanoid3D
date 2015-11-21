
		/*
		/////-------------------------------------------------------------------------------------
		// Central line
			glVertex3f(Xleft + halfSize,	Yup,				Zfront - halfSize);	// Up
			glVertex3f(Xleft + halfSize,	Yup - halfSize,		Zfront - halfSize);	// Middle
			glVertex3f(Xleft + halfSize,	Ydown,				Zfront - halfSize);	// Down
		// Left edge
			glTexCoord2f(0, 0);	glVertex3f(Xleft,	Ydown,				Zback);				// 0
			glTexCoord2f(0, 0);	glVertex3f(Xleft,	Ydown,				Zback + halfSize);	// 1
			glTexCoord2f(1, 0);	glVertex3f(Xleft,	Ydown,				Zfront);			// 2
			glTexCoord2f(1, 0);	glVertex3f(Xleft,	Ydown + halfSize,	Zfront);			// 3
			glTexCoord2f(1, 1);	glVertex3f(Xleft,	Yup,				Zfront);			// 4	
			glTexCoord2f(1, 1);	glVertex3f(Xleft,	Yup,				Zfront - halfSize); // 5
			glTexCoord2f(0, 1);	glVertex3f(Xleft,	Yup,				Zback);				// 6
			glTexCoord2f(0, 1);	glVertex3f(Xleft,	Yup - halfSize,		Zback);				// 7
			glTexCoord2f(0, 1);	glVertex3f(Xleft,	Yup - halfSize,		Zback + halfSize);	// 8 (center point)
		// Front edge
			glTexCoord2f(0, 0);	glVertex3f(Xleft,				Ydown,				Zfront);	// 0
			glTexCoord2f(0, 0);	glVertex3f(Xleft + halfSize,	Ydown,				Zfront);	// 1
			glTexCoord2f(1, 0);	glVertex3f(Xright,				Ydown,				Zfront);	// 2
			glTexCoord2f(1, 0);	glVertex3f(Xright,				Ydown + halfSize,	Zfront);	// 3
			glTexCoord2f(1, 1);	glVertex3f(Xright,				Yup,				Zfront);	// 4
			glTexCoord2f(1, 1);	glVertex3f(Xright - halfSize,	Yup,				Zfront);	// 5
			glTexCoord2f(0, 1);	glVertex3f(Xleft,				Yup,				Zfront);	// 6
			glTexCoord2f(0, 1);	glVertex3f(Xleft,				Yup - halfSize,		Zfront);	// 7
			glTexCoord2f(0, 1);	glVertex3f(Xleft + halfSize,	Yup - halfSize,		Zfront);	// 8
		// Right edge
			glTexCoord2f(0, 0);	glVertex3f(Xright,	Ydown,				Zfront);			// 0
			glTexCoord2f(0, 0);	glVertex3f(Xright,	Ydown,				Zfront - halfSize);	// 1
			glTexCoord2f(1, 0);	glVertex3f(Xright,	Ydown,				Zback);				// 2
			glTexCoord2f(1, 0);	glVertex3f(Xright,	Ydown + halfSize,	Zback);				// 3
			glTexCoord2f(1, 1);	glVertex3f(Xright,	Yup,				Zback);				// 4
			glTexCoord2f(1, 1);	glVertex3f(Xright,	Yup,				Zback + halfSize);	// 5
			glTexCoord2f(0, 1);	glVertex3f(Xright,	Yup,				Zfront);			// 6
			glTexCoord2f(0, 1);	glVertex3f(Xright,	Yup - halfSize,		Zfront);			// 7
			glTexCoord2f(0, 1);	glVertex3f(Xright,	Yup - halfSize,		Zfront - halfSize);	// 8
		// Down edge
			glTexCoord2f(0, 0);	glVertex3f(Xleft,				Ydown,	Zfront);			// 0
			glTexCoord2f(0, 0);	glVertex3f(Xleft + halfSize,	Ydown,	Zfront);			// 1
			glTexCoord2f(1, 0);	glVertex3f(Xright,				Ydown,	Zfront);			// 2
			glTexCoord2f(1, 0);	glVertex3f(Xright,				Ydown,	Zfront - halfSize);	// 3
			glTexCoord2f(1, 1);	glVertex3f(Xright,				Ydown,	Zback);				// 4
			glTexCoord2f(1, 1);	glVertex3f(Xright - halfSize,	Ydown,	Zback);				// 5
			glTexCoord2f(0, 1);	glVertex3f(Xleft,				Ydown,	Zback);				// 6
			glTexCoord2f(0, 1);	glVertex3f(Xleft,				Ydown,	Zback + halfSize);	// 7
			glTexCoord2f(0, 1);	glVertex3f(Xleft + halfSize,	Ydown,	Zback + halfSize);	// 8
		// Up edge
			glTexCoord2f(0, 0);	glVertex3f(Xleft,				Yup,	Zfront);			// 0
			glTexCoord2f(0, 0);	glVertex3f(Xleft + halfSize,	Yup,	Zfront);			// 1
			glTexCoord2f(1, 0);	glVertex3f(Xright,				Yup,	Zfront);			// 2
			glTexCoord2f(1, 0);	glVertex3f(Xright,				Yup,	Zfront - halfSize);	// 3
			glTexCoord2f(1, 1);	glVertex3f(Xright,				Yup,	Zback);				// 4
			glTexCoord2f(1, 1);	glVertex3f(Xright - halfSize,	Yup,	Zback);				// 5
			glTexCoord2f(0, 1);	glVertex3f(Xleft,				Yup,	Zback);				// 6
			glTexCoord2f(0, 1);	glVertex3f(Xleft,				Yup,	Zback + halfSize);	// 7
			glTexCoord2f(0, 1);	glVertex3f(Xleft + halfSize,	Yup,	Zback + halfSize);	// 8
		////// ---------------------------------------------------------------------------------
		*/

#include <iostream>
#include "gl\glut.h"
#include "gl\GLAux.h"
#include "Projection.h"
#pragma comment(lib, "GLAux.lib")

//-------------------------------------------------
// Room declarations
//-------------------------------------------------
#define ROOM_WIDTH			5.0		// = ROOM_HEIGHT
#define ROOM_HEIGHT			5.0		// = ROOM_WIDTH
#define ROOM_LENGTH			8.0

GLfloat ROOM_HALF_HEIGHT = ROOM_HEIGHT / 2.0;
GLfloat ROOM_HALF_LENGTH = ROOM_LENGTH / 2.0;
GLfloat ROOM_HALF_WIDTH  = ROOM_WIDTH  / 2.0;

//-------------------------------------------------
//	Ball declarations
//-------------------------------------------------
#define SPEED			0.01
#define BALL_DIAMETER	0.2

GLfloat X = 0, Y = 0, Z = 0;
GLfloat Xdir = SPEED, Ydir = SPEED, Zdir = SPEED;
// Collision points (CP)
GLfloat leftCP  = -BALL_DIAMETER / 2.0,
		rightCP =  BALL_DIAMETER / 2.0,
		downCP	= -BALL_DIAMETER / 2.0,
		upCP    =  BALL_DIAMETER / 2.0,
		backCP  = -BALL_DIAMETER / 2.0,
		frontCP =  BALL_DIAMETER / 2.0;

//-------------------------------------------------
// Textures
//-------------------------------------------------
// Cube textures
enum {WHITE, GREEN, YELLOW, RED, CUBE_TEX_NUMBER};
GLuint cubeTextures[CUBE_TEX_NUMBER];
// Score textures
enum {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, SCORE, SCORE_TEX_NUMBER};
GLuint scoreTextures[SCORE_TEX_NUMBER];
// Other textures
enum {BALL, WALL, REFLECTOR, LIFE, OTHER_TEX_NUMBER};
GLuint otherTextures[OTHER_TEX_NUMBER];

void LoadTextures()
{
#pragma region CubeTextures Loading
	AUX_RGBImageRec *White	= auxDIBImageLoadA("Textures/Cube/white.bmp");
	AUX_RGBImageRec *Green	= auxDIBImageLoadA("Textures/Cube/green.bmp");
	AUX_RGBImageRec *Yellow	= auxDIBImageLoadA("Textures/Cube/yellow.bmp");
	AUX_RGBImageRec *Red	= auxDIBImageLoadA("Textures/Cube/red.bmp");
	
	glGenTextures(CUBE_TEX_NUMBER, &cubeTextures[0]);

	glBindTexture(GL_TEXTURE_2D, cubeTextures[WHITE]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, White->sizeX, White->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, White->data);

	glBindTexture(GL_TEXTURE_2D, cubeTextures[GREEN]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Green->sizeX, Green->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Green->data);

	glBindTexture(GL_TEXTURE_2D, cubeTextures[YELLOW]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Yellow->sizeX, Yellow->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Yellow->data);

	glBindTexture(GL_TEXTURE_2D, cubeTextures[RED]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Red->sizeX, Red->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Red->data);
#pragma endregion
#pragma region ScoreTextures Loading
	AUX_RGBImageRec *Zero	= auxDIBImageLoadA("Textures/Score/zero.bmp");
	AUX_RGBImageRec *One	= auxDIBImageLoadA("Textures/Score/one.bmp");
	AUX_RGBImageRec *Two	= auxDIBImageLoadA("Textures/Score/two.bmp");
	AUX_RGBImageRec *Three	= auxDIBImageLoadA("Textures/Score/three.bmp");
	AUX_RGBImageRec *Four	= auxDIBImageLoadA("Textures/Score/four.bmp");
	AUX_RGBImageRec *Five	= auxDIBImageLoadA("Textures/Score/five.bmp");
	AUX_RGBImageRec *Six	= auxDIBImageLoadA("Textures/Score/six.bmp");
	AUX_RGBImageRec *Seven	= auxDIBImageLoadA("Textures/Score/seven.bmp");
	AUX_RGBImageRec *Eight	= auxDIBImageLoadA("Textures/Score/eight.bmp");
	AUX_RGBImageRec *Nine	= auxDIBImageLoadA("Textures/Score/nine.bmp");
	AUX_RGBImageRec *Score	= auxDIBImageLoadA("Textures/Score/score.bmp");
	
	glGenTextures(SCORE_TEX_NUMBER, &scoreTextures[0]);

	glBindTexture(GL_TEXTURE_2D, scoreTextures[ZERO]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Zero->sizeX, Zero->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Zero->data);

	glBindTexture(GL_TEXTURE_2D, scoreTextures[ONE]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, One->sizeX, One->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, One->data);

	glBindTexture(GL_TEXTURE_2D, scoreTextures[TWO]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Two->sizeX, Two->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Two->data);

	glBindTexture(GL_TEXTURE_2D, scoreTextures[THREE]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Three->sizeX, Three->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Three->data);

	glBindTexture(GL_TEXTURE_2D, scoreTextures[FOUR]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Four->sizeX, Four->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Four->data);

	glBindTexture(GL_TEXTURE_2D, scoreTextures[FIVE]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Five->sizeX, Five->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Five->data);

	glBindTexture(GL_TEXTURE_2D, scoreTextures[SIX]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Six->sizeX, Six->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Six->data);

	glBindTexture(GL_TEXTURE_2D, scoreTextures[SEVEN]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Seven->sizeX, Seven->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Seven->data);

	glBindTexture(GL_TEXTURE_2D, scoreTextures[EIGHT]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Eight->sizeX, Eight->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Eight->data);

	glBindTexture(GL_TEXTURE_2D, scoreTextures[NINE]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Nine->sizeX, Nine->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Nine->data);

	glBindTexture(GL_TEXTURE_2D, scoreTextures[SCORE]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Score->sizeX, Score->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Score->data);
#pragma endregion
#pragma region OtherTextures Loading
	AUX_RGBImageRec *Ball		= auxDIBImageLoadA("Textures/Other/ball.bmp");
	AUX_RGBImageRec *Wall		= auxDIBImageLoadA("Textures/Other/wall.bmp");
	AUX_RGBImageRec *Reflector	= auxDIBImageLoadA("Textures/Other/reflector.bmp");
	AUX_RGBImageRec *Life		= auxDIBImageLoadA("Textures/Other/life.bmp");
	
	glGenTextures(OTHER_TEX_NUMBER, &otherTextures[0]);

	glBindTexture(GL_TEXTURE_2D, otherTextures[BALL]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Ball->sizeX, Ball->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Ball->data);

	glBindTexture(GL_TEXTURE_2D, otherTextures[WALL]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Wall->sizeX, Wall->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Wall->data);

	glBindTexture(GL_TEXTURE_2D, otherTextures[REFLECTOR]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Reflector->sizeX, Reflector->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Reflector->data);

	glBindTexture(GL_TEXTURE_2D, otherTextures[LIFE]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Life->sizeX, Life->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Life->data);
#pragma endregion
}

//-------------------------------------------------
// Cubes declarations
//-------------------------------------------------
#define CUBE_STATES		3
#define SHARD_SPEED		0.01
GLfloat CubeWallZCoord1  = -ROOM_HALF_LENGTH * 3 / 5.0,
		CubeWallZCoord2  = -ROOM_HALF_LENGTH * 4 / 5.0;
const GLint cubesNumber = 50;
GLfloat cubeSize = ROOM_WIDTH / 5.0;
GLfloat halfSize = cubeSize / 2.0;
GLint first, last;

struct Cube
{
	GLfloat Xleft, Xright, Yup, Ydown, Zfront, Zback;
	GLfloat hits;
	GLfloat shardX, shardY, shardZ;
	GLboolean destroyed;
	GLboolean shards;

	// (x, y, z) - front left down cube vertex 
	void DrawOnPoint(GLfloat finlen, GLfloat x, GLfloat y, GLfloat z)		
	{
			glBegin(GL_QUADS);
				// Left edge
				glTexCoord2f(0, 0);	glVertex3f(x,			y,				z - finlen);	
				glTexCoord2f(1, 0);	glVertex3f(x,			y,				z);			
				glTexCoord2f(1, 1);	glVertex3f(x,			y + finlen,		z);			
				glTexCoord2f(0, 1);	glVertex3f(x,			y + finlen,		z - finlen);	
				// Front edge
				glTexCoord2f(0, 0);	glVertex3f(x,			y,				z);	
				glTexCoord2f(1, 0);	glVertex3f(x + finlen,	y,				z);	
				glTexCoord2f(1, 1);	glVertex3f(x + finlen,	y + finlen,		z);	
				glTexCoord2f(0, 1);	glVertex3f(x,			y + finlen,		z);	
				// Right edge
				glTexCoord2f(0, 0);	glVertex3f(x + finlen,	y,				z);
				glTexCoord2f(1, 0); glVertex3f(x + finlen,	y,				z - finlen);	
				glTexCoord2f(1, 1); glVertex3f(x + finlen,	y + finlen,		z - finlen);	
				glTexCoord2f(0, 1);	glVertex3f(x + finlen,	y + finlen,		z);
				// Back edge
				glTexCoord2f(0, 0);	glVertex3f(x,			y,				z - finlen);	
				glTexCoord2f(1, 1); glVertex3f(x + finlen,	y,				z - finlen);	
				glTexCoord2f(1, 0); glVertex3f(x + finlen,	y + finlen,		z - finlen);	
				glTexCoord2f(0, 1);	glVertex3f(x,			y + finlen,		z - finlen);	
				// Down edge
				glTexCoord2f(0, 0);	glVertex3f(x,			y,				z);			
				glTexCoord2f(1, 0);	glVertex3f(x + finlen,	y,				z);		
				glTexCoord2f(1, 1); glVertex3f(x + finlen,	y,				z - finlen);	
				glTexCoord2f(0, 1);	glVertex3f(x,			y,				z - finlen);	
				// Up edge
				glTexCoord2f(0, 0);	glVertex3f(x,			y + finlen,		z);	
				glTexCoord2f(1, 0);	glVertex3f(x + finlen,	y + finlen,		z);	
				glTexCoord2f(1, 1); glVertex3f(x + finlen,	y + finlen,		z - finlen);	
				glTexCoord2f(0, 1);	glVertex3f(x,			y + finlen,		z - finlen);	
			glEnd();		
	}
public:
	void Init(GLfloat Xl, GLfloat Yd, GLfloat Zf)
	{
		Xleft = Xl;
		Xright = Xl + cubeSize;
		Ydown = Yd;
		Yup = Yd + cubeSize;
		Zfront = Zf;
		Zback = Zf - cubeSize;
		hits = 0;
		destroyed = GL_FALSE;
		shards = GL_FALSE;
		shardX = shardY = shardZ = 0;
	}
	void Draw()
	{
		if (hits == 0) glBindTexture(GL_TEXTURE_2D, cubeTextures[WHITE]);
		if (hits == 1) glBindTexture(GL_TEXTURE_2D, cubeTextures[GREEN]);
		if (hits == 2) glBindTexture(GL_TEXTURE_2D, cubeTextures[YELLOW]);
		if (hits == 3) glBindTexture(GL_TEXTURE_2D, cubeTextures[RED]);

		DrawOnPoint(cubeSize, Xleft, Ydown, Zfront);
		//glBegin(GL_QUADS);
		//	// Left edge
		//	glTexCoord2f(0, 0);	glVertex3f(Xleft,	Ydown,	Zback);
		//	glTexCoord2f(1, 0);	glVertex3f(Xleft,	Ydown,	Zfront);
		//	glTexCoord2f(1, 1);	glVertex3f(Xleft,	Yup,	Zfront);
		//	glTexCoord2f(0, 1);	glVertex3f(Xleft,	Yup,	Zback);
		//	// Front edge
		//	glTexCoord2f(0, 0);	glVertex3f(Xleft,	Ydown,	Zfront);
		//	glTexCoord2f(1, 0);	glVertex3f(Xright,	Ydown,	Zfront);
		//	glTexCoord2f(1, 1);	glVertex3f(Xright,	Yup,	Zfront);
		//	glTexCoord2f(0, 1);	glVertex3f(Xleft,	Yup,	Zfront);
		//	// Right edge
		//	glTexCoord2f(0, 0);	glVertex3f(Xright,	Ydown,	Zfront);
		//	glTexCoord2f(1, 0);	glVertex3f(Xright,	Ydown,	Zback);
		//	glTexCoord2f(1, 1);	glVertex3f(Xright,	Yup,	Zback);
		//	glTexCoord2f(0, 1);	glVertex3f(Xright,	Yup,	Zfront);
		//	// Down edge
		//	glTexCoord2f(0, 0);	glVertex3f(Xleft,	Ydown,	Zfront);
		//	glTexCoord2f(1, 0);	glVertex3f(Xright,	Ydown,	Zfront);
		//	glTexCoord2f(1, 1);	glVertex3f(Xright,	Ydown,	Zback);
		//	glTexCoord2f(0, 1);	glVertex3f(Xleft,	Ydown,	Zback);
		//	// Up edge
		//	glTexCoord2f(0, 0);	glVertex3f(Xleft,	Yup,	Zfront);
		//	glTexCoord2f(1, 0);	glVertex3f(Xright,	Yup,	Zfront);
		//	glTexCoord2f(1, 1);	glVertex3f(Xright,	Yup,	Zback);
		//	glTexCoord2f(0, 1);	glVertex3f(Xleft,	Yup,	Zback);
		//glEnd();
	}
	void DrawParts()
	{
		glBindTexture(GL_TEXTURE_2D, cubeTextures[RED]);	

		shardZ += SHARD_SPEED;
		shardY += SHARD_SPEED;
		shardX += SHARD_SPEED / 2.5;

		DrawOnPoint(halfSize, Xleft - shardX,				Ydown - shardY,				Zfront + shardZ);
		DrawOnPoint(halfSize, Xleft + halfSize + shardX,	Ydown - shardY,				Zfront + shardZ);
		DrawOnPoint(halfSize, Xleft - shardX,				Ydown + halfSize - shardY,	Zfront + shardZ);
		DrawOnPoint(halfSize, Xleft + halfSize + shardX,	Ydown + halfSize - shardY,	Zfront + shardZ);
		DrawOnPoint(halfSize, Xleft - shardX,				Ydown - shardY,				Zfront - halfSize + shardZ);
		DrawOnPoint(halfSize, Xleft + halfSize - shardX,	Ydown - shardY,				Zfront - halfSize + shardZ);
		DrawOnPoint(halfSize, Xleft + shardX,				Ydown + halfSize - shardY,	Zfront - halfSize + shardZ);
		DrawOnPoint(halfSize, Xleft + halfSize - shardX,	Ydown + halfSize - shardY,	Zfront - halfSize + shardZ);

		if (Ydown + halfSize - shardY < 0)
			shards = GL_FALSE;
	}
} cubes[cubesNumber];

void InitializeCubes()
{
	GLint i = 0;
	for(GLfloat Zcoord = CubeWallZCoord1; Zcoord > -ROOM_HALF_LENGTH; Zcoord -= cubeSize)
		for(GLfloat Ycoord = 0; Ycoord < ROOM_HEIGHT; Ycoord += cubeSize)
			for(GLfloat Xcoord = -ROOM_HALF_WIDTH; Xcoord < ROOM_HALF_WIDTH; Xcoord += cubeSize, i++)
				cubes[i].Init(Xcoord, Ycoord, Zcoord);
}

//-------------------------------------------------
// Player parameters
//-------------------------------------------------
#define ICON_SIZE	0.35
GLint lifes = 3;
GLint score = 0;
GLboolean run = GL_FALSE;

//-------------------------------------------------
// Reflector declarations 
//-------------------------------------------------
#define REFLECTOR_SIZE		0.5
GLfloat reflectorX = 0, reflectorY = ROOM_HALF_HEIGHT;

//-------------------------------------------------
// Light and shadow declarations 
//-------------------------------------------------
#define PROJECTION_SEGMENTS	50.0
Projection projection;
GLfloat angle, dx, dy;
GLfloat SPXCoord, SPYCoord, SPZCoord;	// SP - shadow point
GLboolean SPdone = GL_FALSE;


// Draw calls
void DrawBall()
{
	glColor3f(1, 1, 1);
	glPushMatrix();	
		glBindTexture(GL_TEXTURE_2D, otherTextures[BALL]);
		glEnable(GL_TEXTURE_GEN_S);		
		glEnable(GL_TEXTURE_GEN_T);		
		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
		glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);	

		run ? glTranslatef(X, Y, Z) 
			: glTranslatef(reflectorX, reflectorY, ROOM_HALF_LENGTH - BALL_DIAMETER);
		glutSolidSphere(BALL_DIAMETER / 2.0, 10.0, 10.0);

		glDisable(GL_TEXTURE_GEN_S);		
		glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();	

	if (run)
	{
		X += Xdir;
		Y += Ydir;
		Z += Zdir;

		leftCP  += Xdir;
		rightCP += Xdir;
		upCP    += Ydir;
		downCP  += Ydir;
		backCP  += Zdir;
		frontCP += Zdir;
	}
	else
	{
		X = reflectorX;
		Y = reflectorY;
		Z = ROOM_HALF_LENGTH - BALL_DIAMETER;

		leftCP  = X - BALL_DIAMETER / 2.0;
		rightCP = X + BALL_DIAMETER / 2.0;
		downCP	= Y - BALL_DIAMETER / 2.0;
		upCP    = Y + BALL_DIAMETER / 2.0;
		backCP  = Z - BALL_DIAMETER / 2.0;
		frontCP = Z + BALL_DIAMETER / 2.0;
	}
}
void DrawBallProjection()
{
	glBegin(GL_POLYGON);
		for(GLfloat i = 0; i <= PROJECTION_SEGMENTS; i++)
		{
			angle = 2.0 * 3.1415926 * i / PROJECTION_SEGMENTS;
			dx = BALL_DIAMETER / 2.0 * cosf(angle);
			dy = BALL_DIAMETER / 2.0 * sinf(angle);
			glVertex3f(SPXCoord + dx, SPYCoord + dy, ROOM_HALF_LENGTH - 0.001);
		}
	glEnd();

//void DrawBallProjection()
//{
//	glColor3f(1, 1, 0);
//	glBegin(GL_TRIANGLE_FAN);
//		glVertex3f(X, Y, ROOM_HALF_LENGTH);
//		for(GLfloat i = 0; i <= PROJECTION_SEGMENTS; i++)
//		{
//			angle = 2.0 * 3.1415926 * i / PROJECTION_SEGMENTS;
//			dx = BALL_DIAMETER / 2.0 * cosf(angle);
//			dy = BALL_DIAMETER / 2.0 * sinf(angle);
//			glVertex3f(X + dx, Y + dy, ROOM_HALF_LENGTH);
//		}
//	glEnd();
//}
}
void DrawCubes()
{
	glColor3f(1, 1, 1);
	for(GLint i = 0; i < cubesNumber; i++)
	{
		if (cubes[i].destroyed == GL_FALSE)
			cubes[i].Draw();
		else if (cubes[i].shards == GL_TRUE)
			cubes[i].DrawParts();
	}
}
void DrawLifes()
{
	glBindTexture(GL_TEXTURE_2D, otherTextures[LIFE]);
	for(GLint i = 0; i < lifes; i++)
	{
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(ROOM_HALF_WIDTH + 0.3 + i * ICON_SIZE,				ROOM_HEIGHT * 0.8,				ROOM_HALF_LENGTH);
			glTexCoord2f(1, 0); glVertex3f(ROOM_HALF_WIDTH + 0.3 + i * ICON_SIZE + ICON_SIZE,	ROOM_HEIGHT * 0.8,				ROOM_HALF_LENGTH);
			glTexCoord2f(1, 1); glVertex3f(ROOM_HALF_WIDTH + 0.3 + i * ICON_SIZE + ICON_SIZE,	ROOM_HEIGHT * 0.8 + ICON_SIZE,	ROOM_HALF_LENGTH);
			glTexCoord2f(0, 1); glVertex3f(ROOM_HALF_WIDTH + 0.3 + i * ICON_SIZE,				ROOM_HEIGHT * 0.8 + ICON_SIZE,	ROOM_HALF_LENGTH);
		glEnd();
	}
}
void DrawScores()
{
	glBindTexture(GL_TEXTURE_2D, scoreTextures[SCORE]);
	glBegin(GL_QUADS);
		// Score word
		glTexCoord2f(0, 0);	glVertex3f(-ROOM_HALF_WIDTH * 1.75,					ROOM_HEIGHT * 0.8,				ROOM_HALF_LENGTH);
		glTexCoord2f(1, 0);	glVertex3f(-ROOM_HALF_WIDTH * 1.75 + ICON_SIZE*2,	ROOM_HEIGHT * 0.8,				ROOM_HALF_LENGTH);
		glTexCoord2f(1, 1);	glVertex3f(-ROOM_HALF_WIDTH * 1.75 + ICON_SIZE*2,	ROOM_HEIGHT * 0.8 + ICON_SIZE,	ROOM_HALF_LENGTH);
		glTexCoord2f(0, 1);	glVertex3f(-ROOM_HALF_WIDTH * 1.75,					ROOM_HEIGHT * 0.8 + ICON_SIZE,	ROOM_HALF_LENGTH);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, scoreTextures[score / 100]);
	glBegin(GL_QUADS);
		// First number
		glTexCoord2f(0, 0);	glVertex3f(-ROOM_HALF_WIDTH * 1.75 + ICON_SIZE*2,	ROOM_HEIGHT * 0.8,				ROOM_HALF_LENGTH);
		glTexCoord2f(1, 0);	glVertex3f(-ROOM_HALF_WIDTH * 1.75 + ICON_SIZE*3,	ROOM_HEIGHT * 0.8,				ROOM_HALF_LENGTH);
		glTexCoord2f(1, 1);	glVertex3f(-ROOM_HALF_WIDTH * 1.75 + ICON_SIZE*3,	ROOM_HEIGHT * 0.8 + ICON_SIZE,	ROOM_HALF_LENGTH);
		glTexCoord2f(0, 1);	glVertex3f(-ROOM_HALF_WIDTH * 1.75 + ICON_SIZE*2,	ROOM_HEIGHT * 0.8 + ICON_SIZE,	ROOM_HALF_LENGTH);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, scoreTextures[score % 100 / 10]);
	glBegin(GL_QUADS);
		// Second number
		glTexCoord2f(0, 0);	glVertex3f(-ROOM_HALF_WIDTH * 1.75 + ICON_SIZE*3,	ROOM_HEIGHT * 0.8,				ROOM_HALF_LENGTH);
		glTexCoord2f(1, 0);	glVertex3f(-ROOM_HALF_WIDTH * 1.75 + ICON_SIZE*4,	ROOM_HEIGHT * 0.8,				ROOM_HALF_LENGTH);
		glTexCoord2f(1, 1);	glVertex3f(-ROOM_HALF_WIDTH * 1.75 + ICON_SIZE*4,	ROOM_HEIGHT * 0.8 + ICON_SIZE,	ROOM_HALF_LENGTH);
		glTexCoord2f(0, 1);	glVertex3f(-ROOM_HALF_WIDTH * 1.75 + ICON_SIZE*3,	ROOM_HEIGHT * 0.8 + ICON_SIZE,	ROOM_HALF_LENGTH);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, scoreTextures[score % 10]);
	glBegin(GL_QUADS);
		// Third number
		glTexCoord2f(0, 0);	glVertex3f(-ROOM_HALF_WIDTH * 1.75 + ICON_SIZE*4,	ROOM_HEIGHT * 0.8,				ROOM_HALF_LENGTH);
		glTexCoord2f(1, 0);	glVertex3f(-ROOM_HALF_WIDTH * 1.75 + ICON_SIZE*5,	ROOM_HEIGHT * 0.8,				ROOM_HALF_LENGTH);
		glTexCoord2f(1, 1);	glVertex3f(-ROOM_HALF_WIDTH * 1.75 + ICON_SIZE*5,	ROOM_HEIGHT * 0.8 + ICON_SIZE,	ROOM_HALF_LENGTH);
		glTexCoord2f(0, 1);	glVertex3f(-ROOM_HALF_WIDTH * 1.75 + ICON_SIZE*4,	ROOM_HEIGHT * 0.8 + ICON_SIZE,	ROOM_HALF_LENGTH);
	glEnd();
}
void DrawReflector()
{
	glColor4f(1, 1, 1, 0.5);
	glBindTexture(GL_TEXTURE_2D, otherTextures[REFLECTOR]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);	glVertex3f(reflectorX - REFLECTOR_SIZE, reflectorY - REFLECTOR_SIZE, ROOM_HALF_LENGTH + 0.1);
		glTexCoord2f(1, 0);	glVertex3f(reflectorX + REFLECTOR_SIZE, reflectorY - REFLECTOR_SIZE, ROOM_HALF_LENGTH + 0.1);
		glTexCoord2f(1, 1);	glVertex3f(reflectorX + REFLECTOR_SIZE,	reflectorY + REFLECTOR_SIZE, ROOM_HALF_LENGTH + 0.1);
		glTexCoord2f(0, 1);	glVertex3f(reflectorX - REFLECTOR_SIZE, reflectorY + REFLECTOR_SIZE, ROOM_HALF_LENGTH + 0.1);
	glEnd();
}
void DrawRoom()
{
	glBindTexture(GL_TEXTURE_2D, otherTextures[WALL]);
	glBegin(GL_QUADS);
		// Bottom
		glTexCoord2f(0, 0);	glVertex3f(-ROOM_HALF_WIDTH,	0,	-ROOM_HALF_LENGTH);
		glTexCoord2f(1, 0);	glVertex3f(ROOM_HALF_WIDTH,		0,	-ROOM_HALF_LENGTH);
		glTexCoord2f(1, 1);	glVertex3f(ROOM_HALF_WIDTH,		0,	ROOM_HALF_LENGTH);
		glTexCoord2f(0, 1);	glVertex3f(-ROOM_HALF_WIDTH,	0,	ROOM_HALF_LENGTH);
		// Floor
		glTexCoord2f(0, 0);	glVertex3f(-ROOM_HALF_WIDTH,	ROOM_HEIGHT,	-ROOM_HALF_LENGTH);
		glTexCoord2f(1, 0);	glVertex3f(ROOM_HALF_WIDTH,		ROOM_HEIGHT,	-ROOM_HALF_LENGTH);
		glTexCoord2f(1, 1);	glVertex3f(ROOM_HALF_WIDTH,		ROOM_HEIGHT,	ROOM_HALF_LENGTH);
		glTexCoord2f(0, 1);	glVertex3f(-ROOM_HALF_WIDTH,	ROOM_HEIGHT,	ROOM_HALF_LENGTH);
		// Back wall
		glTexCoord2f(0, 0);	glVertex3f(-ROOM_HALF_WIDTH,	0,				-ROOM_HALF_LENGTH);
		glTexCoord2f(1, 0);	glVertex3f(ROOM_HALF_WIDTH,		0,				-ROOM_HALF_LENGTH);
		glTexCoord2f(1, 1);	glVertex3f(ROOM_HALF_WIDTH,		ROOM_HEIGHT,	-ROOM_HALF_LENGTH);
		glTexCoord2f(0, 1);	glVertex3f(-ROOM_HALF_WIDTH,	ROOM_HEIGHT,	-ROOM_HALF_LENGTH);
		// Right wall
		glTexCoord2f(0, 0);	glVertex3f(ROOM_HALF_WIDTH,		0,				-ROOM_HALF_LENGTH);
		glTexCoord2f(1, 0);	glVertex3f(ROOM_HALF_WIDTH,		0,				ROOM_HALF_LENGTH);
		glTexCoord2f(1, 1);	glVertex3f(ROOM_HALF_WIDTH,		ROOM_HEIGHT,	ROOM_HALF_LENGTH);
		glTexCoord2f(0, 1);	glVertex3f(ROOM_HALF_WIDTH,		ROOM_HEIGHT,	-ROOM_HALF_LENGTH);
		// Left wall
		glTexCoord2f(0, 0);	glVertex3f(-ROOM_HALF_WIDTH,	0,				ROOM_HALF_LENGTH);
		glTexCoord2f(1, 0);	glVertex3f(-ROOM_HALF_WIDTH,	0,				-ROOM_HALF_LENGTH);
		glTexCoord2f(1, 1);	glVertex3f(-ROOM_HALF_WIDTH,	ROOM_HEIGHT,	-ROOM_HALF_LENGTH);
		glTexCoord2f(0, 1);	glVertex3f(-ROOM_HALF_WIDTH,	ROOM_HEIGHT,	ROOM_HALF_LENGTH);
	glEnd();
}

// Collision detection
void RoomCollision()
{
	if (X <= -ROOM_HALF_WIDTH || X >= ROOM_HALF_WIDTH)
		Xdir = -Xdir;
	if (Y >= ROOM_HEIGHT || Y <= 0)
		Ydir = -Ydir;
	if (Z <= -ROOM_HALF_LENGTH)
		Zdir = -Zdir;
	else if (Z >= ROOM_HALF_LENGTH)
	{
		if (X > reflectorX - REFLECTOR_SIZE && X < reflectorX + REFLECTOR_SIZE &&
			Y > reflectorY - REFLECTOR_SIZE && Y < reflectorY + REFLECTOR_SIZE)
			Zdir = -Zdir;
		else
		{
			run = GL_FALSE;
			printf("\a");
			lifes--;
			if (lifes <= 0)
				exit(0);
			else reflectorX = 0, reflectorY = ROOM_HALF_HEIGHT;
		}
		SPdone = GL_FALSE;
	}
}
void CubesCollision()
{
	if (Z <= CubeWallZCoord1)		
	{
		if (Z >= CubeWallZCoord2)	// 1st Cubes Layer
		{
			first = 0;
			last  = cubesNumber / 2;
		}
		else	// 2nd Cube Layer
		{
			first = cubesNumber / 2;
			last = cubesNumber;
		}

		for(GLint i = first; i < last; i++)
		{
			if (cubes[i].destroyed == GL_FALSE && 
				X >= cubes[i].Xleft  && X <= cubes[i].Xright &&
				Y <= cubes[i].Yup    && Y >= cubes[i].Ydown)
			{
				cubes[i].hits++;
				score += 10;
				if (cubes[i].hits > CUBE_STATES)
				{
					cubes[i].destroyed = GL_TRUE;
					cubes[i].shards = GL_TRUE;
				}

				if (frontCP > cubes[i].Zfront || backCP < cubes[i].Zback)
					Zdir = -Zdir;
				else if (upCP > cubes[i].Yup || downCP < cubes[i].Ydown)
					Ydir = -Ydir;
				else if (leftCP < cubes[i].Xleft || rightCP > cubes[i].Xright)
					Xdir = -Xdir;

				break;
			}
		}
	}
}
void CalculateShadowPoint()
{
	GLfloat tmpXdir = Xdir, tmpYdir = Ydir, tmpZdir = Zdir;

	SPXCoord = X;
	SPYCoord = Y;
	SPZCoord = Z;
	
	while(true)
	{
		SPXCoord += tmpXdir;
		SPYCoord += tmpYdir;
		SPZCoord += tmpZdir;

		if (SPXCoord <= -ROOM_HALF_WIDTH || SPXCoord >= ROOM_HALF_WIDTH)
			tmpXdir = -tmpXdir;
		if (SPYCoord >= ROOM_HEIGHT || SPYCoord <= 0)
			tmpYdir = -tmpYdir;
		if (SPZCoord <= -ROOM_HALF_LENGTH)
			tmpZdir = -tmpZdir;
		else if (SPZCoord >= ROOM_HALF_LENGTH)
		{
			SPdone = GL_TRUE;
			break;
		}
	}
}

// Other
void Resize(GLint w, GLint h) 
{
	if(h == 0)	h = 1;
	GLfloat ratio = 1.0 * w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
}
void SetCamera()
{
	gluLookAt(0,	ROOM_HALF_HEIGHT,	ROOM_HALF_LENGTH + ROOM_HALF_WIDTH * 2.5,		
			  0,	ROOM_HALF_HEIGHT,	0,
			  0,	1,					0);
}
void Render() 
{ 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	SetCamera();

	DrawBall();		
	DrawLifes();
	DrawScores();
	DrawCubes();
	DrawRoom();

	if (Zdir > 0)	
	{
		if (SPdone)
		{
			glDisable(GL_DEPTH_TEST);
			glDisable(GL_LIGHTING);
			projection.Init(ROOM_HALF_LENGTH - 0.001, SPXCoord, SPYCoord, -ROOM_LENGTH);
			glPushMatrix();
				glMultMatrixf((GLfloat*)projection.shadowMat);
				glEnable(GL_DEPTH_TEST);
				glEnable(GL_LIGHTING);
				DrawBallProjection();
			glPopMatrix();
		}
		else if (run && Z > CubeWallZCoord1) 
			CalculateShadowPoint();
	}

	DrawReflector();
	RoomCollision();
	CubesCollision();

	glClearColor(0, 1, 0.5, 0);
    glutSwapBuffers();
}

// Control keys
void Keys(unsigned char key, GLint x, GLint y) 
{ 
	if (key == 27)		// Esc 
		exit(0);
}
void MouseMove(GLint x, GLint y) 
{
    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY, winZ;
    GLdouble posX, posY, posZ;
 
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);
 
    winX = (GLfloat)x;
    winY = (GLfloat)viewport[3] - (GLfloat)y;
    glReadPixels(x, GLint(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
 
    gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	reflectorX = posX;
	reflectorY = posY;
}
void MouseButton(GLint button, GLint state, GLint x, GLint y) 
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
		run = GL_TRUE;
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(1024, 768);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Arkanoid");
	glutFullScreen();

	glutDisplayFunc(Render);
	glutReshapeFunc(Resize);
	glutIdleFunc(Render);
	glutKeyboardFunc(Keys);
	glutPassiveMotionFunc(MouseMove);
	glutMouseFunc(MouseButton);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);	
	
	LoadTextures();
	InitializeCubes();

	glutMainLoop();
	return 0;
}