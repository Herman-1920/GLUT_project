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
    glPushMatrix();
    glTranslatef(playerX,playerY,0);

    glColor3f(0.2f, 0.7f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 40);
    glVertex2f(-30, -20);
    glVertex2f(30, -20);
    glEnd();

    glColor3f(0.1f, 0.4f, 0.9f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-18, 0);
    glVertex2f(-45, -20);
    glVertex2f(-15, -15);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(18, 0);
    glVertex2f(45, -20);
    glVertex2f(15, -15);
    glEnd();

    glColor3f(0.8f, 0.95f, 1.0f);
    circle(0, 10, 9);

    glColor3f(1.0f, 0.5f, 0.1f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-10, -18);
    glVertex2f(0, -35);
    glVertex2f(10, -18);
    glEnd();

    glPopMatrix();
}

// enemy spaceship
void drawEnemy(float x,float y){
    glPushMatrix();
    glTranslatef(x, y, 0);

    glScalef(0.65f, 0.65f, 1.0f);
    glRotatef(180.0f, 0, 0, 1);

    glColor3f(1.0f, 0.15f, 0.15f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 40);
    glVertex2f(-30, -20);
    glVertex2f(30, -20);
    glEnd();

    glColor3f(0.75f, 0.05f, 0.05f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-18, 0);
    glVertex2f(-45, -20);
    glVertex2f(-15, -15);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(18, 0);
    glVertex2f(45, -20);
    glVertex2f(15, -15);
    glEnd();

    glColor3f(1.0f, 0.8f, 0.2f);
    circle(0, 10, 9);

    glColor3f(0.8f, 0.05f, 0.05f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-10, -18);
    glVertex2f(0, -35);
    glVertex2f(10, -18);
    glEnd();

    glPopMatrix();
}

// bullet
void drawBullet(float x,float y){
    glColor3f(1.0f, 1.0f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(x - 3, y);
    glVertex2f(x + 3, y);
    glVertex2f(x + 3, y + 15);
    glVertex2f(x - 3, y + 15);

    glEnd();
}
    
void drawStars(){
    glColor3f(1.0f, 1.0f, 1.0f);
    for(int i=0;i<100;i++){
        float x = (i*97)% WIDTH;
        float y = (i*53)% HEIGHT;
        
        glBegin(GL_POINTS);

        glVertex2f(x, y);

        glEnd();
    }
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
    for(int i=0;t[i]!='\0';i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,t[i]);
    }
}

// display
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawStars();

    if(!gameOver && !playerWon){
        drawPlayer();

        for (int i = 0; i < bullets.size(); i++)
        {
            drawBullet(
                bullets[i].x,
                bullets[i].y
            );
    }
    for (int i = 0; i < enemies.size(); i++)
        {
            drawEnemy(
                enemies[i].x,
                enemies[i].y
            );
        }
    }
    drawHealth();
    glColor3f(1, 1, 1);

    char text[50];

    sprintf(text, "Score: %d / %d", score, WIN_SCORE);
    glRasterPos2f(WIDTH - 180, HEIGHT - 30);

    for (int i = 0; text[i] != '\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,
            text[i]);
    }
    if(gameOver){
        const char* message =
          "GAME OVER - Press R to Restart";
        glRasterPos2f(270, 300);

        for (int i = 0; message[i] != '\0'; i++)
        {
            glutBitmapCharacter(
                GLUT_BITMAP_HELVETICA_18,
                message[i]
            );
        }
    }
    if(playerWon){
        const char* message =
            "YOU WIN! - Press R to Play Again";

        glRasterPos2f(260, 300);
        for(int i = 0;message[i]!='\0';i++){
             glutBitmapCharacter(
                GLUT_BITMAP_HELVETICA_18,
                message[i]
            );
        }
    }
    glutSwapBuffers();
}

// updates
void update(int value){
    if(!gameOver && !playerWon){
        if (leftKey) playerX-=7;
        if (rightKey) playerX+=7;

        if (playerX<45) playerX=45;
        if (playerX>WIDTH-45) playerX=WIDTH-45;

        for (int i=0;i<bullets.size();i++) bullets[i].y+=10;

        for (int i=0;i<enemies.size();i++) enemies[i].y-=2;

        for (int i=bullets.size()-1;i>=0;i--){
            bool bulletDestroyed=false;
            for (int j=enemies.size()-1;j>=0;j--){
                float dx=bullets[i].x-enemies[j].x;
                float dy=bullets[i].y-enemies[j].y;
                float distance=sqrt(dx*dx+dy*dy);

                if (distance<30){
                    bullets.erase(bullets.begin()+i);
                    enemies.erase(enemies.begin()+j);

                    score++;
                    bulletDestroyed=true;
                    break;
                }
            }
            if (bulletDestroyed) continue;
        }

        for (int i=enemies.size()-1;i>=0;i--){
            float dx=enemies[i].x-playerX;
            float dy=enemies[i].y-playerY;
            float distance=sqrt(dx*dx+dy*dy);

            if (distance<45){
                enemies.erase(enemies.begin()+i);
                health-=5;
                if(health<=0){
                    health=0;
                    gameOver=true;
                }
            }
        }

        for (int i=bullets.size()-1;i>=0;i--){
            if (bullets[i].y>HEIGHT) bullets.erase(bullets.begin()+i);
        }
        for (int i=enemies.size()-1;i>=0;i--){
            if(enemies[i].y<-50) enemies.erase(enemies.begin()+i);
        }


        if(rand()%35==0){
            Enemy enemy;
            enemy.x=50+rand()%(WIDTH-100);
            enemy.y=HEIGHT+40;
            enemies.push_back(enemy);
        }

        if(score>=WIN_SCORE) playerWon=true;
    }
     glutPostRedisplay();
     glutTimerFunc(16,update,0);
}
void keyDown(unsigned char key,int x,int y){
    if(key=='a'|| key=='A'){
        leftKey=true;
    }
    if(key=='d' || key=='D'){
        rightKey=true;
    }
    if(key==' '){
        if(!gameOver && !playerWon){
            Bullet bullet;
            bullet.x=playerX;
            bullet.y=playerY+35;
            bullets.push_back(bullet);
        }
    }
    if(key=='r' || key=='R'){
        playerX=WIDTH/2;
        health=MAX_HEALTH;
        score=0;
        bullets.clear();
        enemies.clear();
        gameOver=false;
        playerWon=false;
    }
}
void keyUp(unsigned char key,int x,int y){
    if(key=='a' || key=='A'){
        leftKey=false;
    }
    if(key=='d' || key=='D'){
        rightKey=false;
    }
}
void specialDown(int key,int x,int y){
    if(key==GLUT_KEY_LEFT){
        leftKey=true;
    }
    if(key==GLUT_KEY_RIGHT){
        rightKey=true;
    }
}
void specialUp(int key,int x,int y){
    if(key==GLUT_KEY_LEFT){
        leftKey=false;
    }
    if(key==GLUT_KEY_RIGHT){
        rightKey=false;
    }
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
    glutSpecialUpFunc(specialUp);

    glutTimerFunc(16,update,0);

    glutMainLoop();

    return 0;

}
