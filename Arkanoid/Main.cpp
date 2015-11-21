#include <iostream>
#include "defines.h"
#include "Textures.h"


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
		if (Z >= CubeWallZCoord2)	
		{
			first = 0;
			last  = cubesNumber / 2;
		}
		else	
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
				score++;
				if (cubes[i].hits > CUBE_STATES)
				{
					cubes[i].destroyed = GL_TRUE;
					cubes[i].shards = GL_TRUE;
					score += 5;
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
	if (key == 27)
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
	ShowCursor(GL_FALSE);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);	
	
	LoadTextures();
	InitializeCubes();

	glutMainLoop();
	return 0;
}