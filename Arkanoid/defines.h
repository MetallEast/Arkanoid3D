#include "gl\glut.h"
#include "Projection.h"

// Room declarations
#define ROOM_WIDTH		5.0		
#define ROOM_HEIGHT		5.0		
#define ROOM_LENGTH		8.0

GLfloat ROOM_HALF_HEIGHT = ROOM_HEIGHT / 2.0;
GLfloat ROOM_HALF_LENGTH = ROOM_LENGTH / 2.0;
GLfloat ROOM_HALF_WIDTH  = ROOM_WIDTH  / 2.0;

// Ball declarations
#define SPEED			0.01
#define BALL_DIAMETER	0.2

GLfloat X = 0, Y = 0, Z = 0;
GLfloat Xdir = SPEED, Ydir = SPEED, Zdir = SPEED;
GLfloat leftCP =  -BALL_DIAMETER / 2.0,
		rightCP =  BALL_DIAMETER / 2.0,
		downCP	= -BALL_DIAMETER / 2.0,
		upCP    =  BALL_DIAMETER / 2.0,
		backCP  = -BALL_DIAMETER / 2.0,
		frontCP =  BALL_DIAMETER / 2.0;

// Cubes declarations
#define CUBE_STATES		3
#define SHARD_SPEED		0.01

GLfloat CubeWallZCoord1  = -ROOM_HALF_LENGTH * 3 / 5.0,
		CubeWallZCoord2  = -ROOM_HALF_LENGTH * 4 / 5.0;
const GLint cubesNumber = 50;
GLfloat cubeSize = ROOM_WIDTH / 5.0;
GLfloat halfSize = cubeSize / 2.0;
GLint first, last;

// Player parameters
#define ICON_SIZE		0.35
GLint lifes = 3;
GLint score = 0;
GLboolean run = GL_FALSE;

// Reflector declarations 
#define REFLECTOR_SIZE	0.5
GLfloat reflectorX = 0, reflectorY = ROOM_HALF_HEIGHT;

// Light and shadow declarations 
#define PROJECTION_SEGMENTS	50.0
Projection projection;
GLfloat angle, dx, dy;
GLfloat SPXCoord, SPYCoord, SPZCoord;	// shadow coord
GLboolean SPdone = GL_FALSE;