#include <iostream>
#include <conio.h>
#include <graphics.h>

const int WIDTH = 800;
const int HEIGHT = 600;
const int GRAVITY = 1;
const int JUMP_FORCE = 15;

struct Bird {
    int x, y;
    int velocity;

    Bird() {
        x = WIDTH / 4;
        y = HEIGHT / 2;
        velocity = 0;
    }

    void show() {
        setcolor(YELLOW);
        circle(x, y, 20);
        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(x, y, YELLOW);
    }

    void update() {
        velocity += GRAVITY;
        y += velocity;
        if (y > HEIGHT) {
            y = HEIGHT;
            velocity = 0;
        }
    }

    void jump() {
        velocity = -JUMP_FORCE;
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Bird bird;

    while (!kbhit()) {
        cleardevice();
        bird.show();
        bird.update();
        delay(10);
    }

    while (1) {
        if (kbhit()) {
            char key = getch();
            if (key == ' ') {
                bird.jump();
            }
            else if (key == 'q') {
                closegraph();
                return 0;
            }
        }

        cleardevice();
        bird.show();
        bird.update();
        delay(10);
    }

    closegraph();
    return 0;
}
