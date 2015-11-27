#include <iostream>
#include "defines.h"
#include "Textures.h"


struct Camera
{
public:
	GLfloat angle;
	GLfloat dirx, dirz;
	GLfloat x, z;
	GLfloat tmp, move;
	GLint xAnchor;
	Camera()
	{
		angle = 0;
		dirx = 0;
		dirz = -1;
		x = 0;
		z = 0;
		tmp = 0;
		move = 0;
		xAnchor = -1;		
	}
}	camera;

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

		DrawOnPoint(halfSize, Xleft - shardX,				Ydown - shardY,				Zfront + shardZ * 1.25);
		DrawOnPoint(halfSize, Xleft + halfSize + shardX,	Ydown - shardY,				Zfront + shardZ * 1.25);
		DrawOnPoint(halfSize, Xleft - shardX,				Ydown + halfSize - shardY,	Zfront + shardZ);
		DrawOnPoint(halfSize, Xleft + halfSize + shardX,	Ydown + halfSize - shardY,	Zfront + shardZ);
		DrawOnPoint(halfSize, Xleft - shardX,				Ydown - shardY,				Zfront - halfSize + shardZ * 1.25);
		DrawOnPoint(halfSize, Xleft + halfSize - shardX,	Ydown - shardY,				Zfront - halfSize + shardZ * 1.25);
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
void DrawBall(GLboolean isProjection)
{
	glColor3f(1, 1, 1);
	glPushMatrix();	
		if (!isProjection)
		{
			glBindTexture(GL_TEXTURE_2D, otherTextures[BALL]);
			glEnable(GL_TEXTURE_GEN_S);		
			glEnable(GL_TEXTURE_GEN_T);		
			glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
			glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);	
		}

		run ? glTranslatef(X, Y, Z) 
			: glTranslatef(reflectorX, reflectorY, ROOM_HALF_LENGTH - BALL_DIAMETER);
		glutSolidSphere(BALL_DIAMETER / 2.0, 10.0, 10.0);

		if (!isProjection)
		{
			glDisable(GL_TEXTURE_GEN_S);		
			glDisable(GL_TEXTURE_GEN_T);
		}
	glPopMatrix();	

	if (!isProjection)
	{
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
}
void DrawCubes()
{
	for(GLint i = 0; i < cubesNumber; i++)
	{
		glColor3f(1, 1, 1);
		if (cubes[i].destroyed == GL_FALSE)
			cubes[i].Draw();
		else if (cubes[i].shards == GL_TRUE)
		{
			cubes[i].DrawParts();
			glColor3f(0, 0, 0);
			glPushMatrix();
				glMultMatrixf((GLfloat*)projection.shadowMatParts);
				cubes[i].DrawParts();
			glPopMatrix();
		}
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
	gluLookAt(camera.x,					ROOM_HALF_HEIGHT + camera.move,	ROOM_HALF_LENGTH + ROOM_HALF_WIDTH * 2.5 - abs(camera.move),
			  camera.x + camera.dirx,	ROOM_HALF_HEIGHT,				camera.z + camera.dirz,
			  0,						1,								0);
}
void Render() 
{ 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	SetCamera();
	DrawBall(GL_FALSE);		
	DrawLifes();
	DrawScores();
	DrawCubes();
	DrawRoom();

	projection.Init(ROOM_HALF_LENGTH - 0.01, X, Y, -ROOM_LENGTH*10);
	glPushMatrix();
		glMultMatrixf((GLfloat*)projection.shadowMat);
		DrawBall(GL_TRUE);
	glPopMatrix();

	DrawReflector();
	RoomCollision();
	CubesCollision();

	glClearColor(0.3, 0.3, 0.3, 0);
    glutSwapBuffers();
}

// Control keyboard
void Keys(unsigned char key, GLint x, GLint y) 
{ 
	if (key == 27)
		exit(0);
}
void PressKey(GLint key, GLint x, GLint y) 
{ 
	if (key == GLUT_KEY_UP && camera.move < ROOM_HALF_LENGTH)	
		camera.move += 0.05f;
	if (key == GLUT_KEY_DOWN && camera.move > -ROOM_HALF_LENGTH)
		camera.move -= 0.05f;
} 
// Control mouse
void PassiveMouseMove(GLint x, GLint y) 
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
void MouseMove(GLint x, GLint y) 
{ 	
    if (camera.xAnchor >= 0) 
	{
		camera.tmp  = (x - camera.xAnchor) * 0.001f;
		camera.dirx =  sin(camera.angle + camera.tmp);
		camera.dirz = -cos(camera.angle + camera.tmp);
	}
}
void MouseButton(GLint button, GLint state, GLint x, GLint y) 
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
		run = GL_TRUE;
	if (button == GLUT_RIGHT_BUTTON) 
	{
		if (state == GLUT_UP) 
		{
			camera.angle += camera.tmp;
			camera.xAnchor = -1;
		}
		else camera.xAnchor = x;
	}
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
	glutSpecialFunc(PressKey);
	glutPassiveMotionFunc(PassiveMouseMove);
	glutMotionFunc(MouseMove);
	glutMouseFunc(MouseButton);
	ShowCursor(GL_FALSE);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);	
	
	LoadTextures();
	InitializeCubes();
	projection.InitParts(0.001, 0, ROOM_HEIGHT, -ROOM_HALF_LENGTH);

	glutMainLoop();
	return 0;
}