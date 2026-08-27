#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstdio>
using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

const int MAX_HEALTH = 50;
const int WIN_SCORE = 20;

float playerX = 400;
float playerY = 70;

bool leftKey = false;
bool rightKey = false;

int health = MAX_HEALTH;
int score = 0;

bool gameOver = false;
bool playerWon = false;

// bullet
struct Bullet{
    float x,y;
};

vector<Bullet>bullets;

// enemy
struct Enemy{
    float x,y;
};
vector<Enemy>enemies;

void circle(float x,float y,float r){
    glBegin(GL_POLYGON);

    for(int i=0;i<30;i++){
        float angle=i*2.0f*3.14159f/30;

        glVertex2f(
                   x+r*cos(angle),
                   y+r*sin(angle)
        );
    }
    glEnd();
}

// player spaceship
void drawPlayer(){

}

// enemy spaceship
void drawEnemy(float x,float y){

}

// bullet
void drawBullet(float x,float y){

}

// bg
void drawStars(){
    // abracadabra i love you maisha 
}

void drawHealth(){
    glColor3f(0.25f,0.25f,0.25f);
    glBegin(GL_QUADS);
    glVertex2f(20,HEIGHT-30);
    glVertex2f(220,HEIGHT-30);
    glVertex2f(220,HEIGHT-10);
    glVertex2f(20,HEIGHT-10);
    glEnd();

    float healthWidth=200.0f*health/MAX_HEALTH;
    glColor3f(0.1f,0.9f,0.2f);
    glBegin(GL_QUADS);
    glVertex2f(20,HEIGHT-30);
    glVertex2f(20+healthWidth,HEIGHT-30);
    glVertex2f(20+healthWidth,HEIGHT-10);
    glVertex2f(20,HEIGHT-10);
    glEnd();
    glColor3f(1,1,1);
    char t[50];
    sprintf(t,"Health: %d",health);
    glRasterPos2f(20,HEIGHT-50);
    for (int i=0;t[i]!='\0';i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,t[i]);
    }
}

// display
void display(){

}

// updates
void update(int value){

}

// key operation
void keyDown(unsigned char key,int x,int y){

}
void keyUp(unsigned char key,int x,int y){

}
void specialDown(int key,int x,int y){

}
void specialUp(int key,int x,int y){

}

// initialization
void init(){
    glClearColor(0.02f,0.02f,0.08f,1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,WIDTH,0,HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    srand(time(0));
}

// main function

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow("Space Shooter");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);
    glutSpecialFunc(specialDown);
    glutSpecialFunc(specialUp);

    glutTimerFunc(16,update,0);

    glutMainLoop();

    return 0;

}
