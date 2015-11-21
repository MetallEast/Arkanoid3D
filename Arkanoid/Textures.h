#include "gl\GLAux.h"
#pragma comment(lib, "GLAux.lib")

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