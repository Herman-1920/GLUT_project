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

## What the Project Does 

This is a 2D spaceshooter game built using C++ and OpenGL(GLUT).

The player controls a spaceship at the bottom of the screen and must shoot down enemy spaceships coming from the top before they collide with player.

**Gameplay Details:**

- Movement: The player can move the spaceship left and right using the A/D keys or the arrow keys.

- Shooting: Pressing Spacebar fires a bullet upward from the player's ship.

- Enemies: Enemy spaceships spawn randomly at the top of the screen and move downward toward the player.

- Combat: If a bullet hits an enemy, the enemy is destroyed and the player's score increase by 1.

- Health: If an enemy collides with the player's ship instead of being shot, the player loses health(5 points). The current health is shown as a health bar and text at top of the screen.

- Win Condition: The player will win the game if they reach a score of 20.

- Lose Condition: The game ends if the player's health drops to 0.

- Restart: Pressing R restarts the game at any time.

- Visuals: The game has a starry background, and the spaceships(mine and the enemies) are made from simple shapes like triangles and circles, colored differently so you can tell your ship apart from enemy ships.

=======
## **Output**

After successfully executing the code, in our outputs we can see that everything appears perfectly. The blue spaceship can move left and right by the left and right arrow keys. It can also move left and right with the A and D keys. Every time we press the spacebar, the blue spaceship fires a bullet. And the enemy spaceship coming from the top to the bottom. When these spaceship hit the blue spaceship. The blue spaceship loses it health point by 5. When the bullet fired from blue spaceship hit the enemy spaceship, the enemy spaceship disappears from screen.

## **Output Screenshot**

![Project Output](ss1.png)
![Project Output](ss2.png)
