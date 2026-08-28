# SpaceShooter

A simple 2D Space Shooter game developed using **C++ and OpenGL (GLUT)**.

The player controls a spaceship, moves it horizontally and shots the incoming enemy spaceship. The goal is to destroy enough enemies while keeping the player's health avobe zero.

---
## Setup Instructions

### Dependencies

The project was developed using following components. 

1. **Code::Blocks 10.5**
2. **MinGW**
3. **OpenGL**
4. **GLUT 3.7.6**

### Download links 

1. Code::Blocks 10.5 -> https://sourceforge.net/projects/codeblocks/files/Binaries/10.05/

2. GLUT 3.7.6 -> https://drive.google.com/file/d/1dDcGy4WEz7zUBezZ0Wk8KG4XAP5cWQHM/view

### Environment Setup

Frist download Code::Blocks and extract the GLUT 3.7.6.

Then follow the steps given below.

1. Copy glut32.dll to C:\Windows\System32 (32 bit) or C:\Windows\SysWOW64 (64 bit).
2. Copy glut32.lib to C:\Program Files (x86)\CodeBlocks\MinGW\lib
3. Copy glut.h to C:\Program Files (x86)\CodeBlocks\MinGW\include\GL

After these step the Code::Blocks is ready for the project to run in the locl machine. 



## **Output**

After successfully executing the code, in our outputs we can see that everything appears perfectly. The blue spaceship can move left and right by the left and right arrow keys. It can also move left and right with the A and D keys. Every time we press the spacebar, the blue spaceship fires a bullet. And the enemy spaceship coming from the top to the bottom. When these spaceship hit the blue spaceship. The blue spaceship loses it health point by 5. When the bullet fired from blue spaceship hit the enemy spaceship, the enemy spaceship disappears from screen.

## **Output Screenshot**

![Project Output](ss1.png)
![Project Output](ss2.png)
