#include <iostream>
#include <conio.h>
#include <graphics.h>

const int WIDTH = 640;
const int HEIGHT = 480;
const int BLOCK_SIZE = 20;

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Point
{
    int x, y;
};

struct Snake
{
    Point head;
    Direction direction;
};

struct Fruit
{
    Point position;
};

void drawSnake(const Snake &snake)
{
    setfillstyle(SOLID_FILL, GREEN);
    bar(snake.head.x, snake.head.y, snake.head.x + BLOCK_SIZE, snake.head.y + BLOCK_SIZE);
}

void drawFruit(const Fruit &fruit)
{
    setfillstyle(SOLID_FILL, RED);
    bar(fruit.position.x, fruit.position.y, fruit.position.x + BLOCK_SIZE, fruit.position.y + BLOCK_SIZE);
}

void updateSnake(Snake &snake)
{
    switch (snake.direction)
    {
    case UP:
        snake.head.y -= BLOCK_SIZE;
        break;
    case DOWN:
        snake.head.y += BLOCK_SIZE;
        break;
    case LEFT:
        snake.head.x -= BLOCK_SIZE;
        break;
    case RIGHT:
        snake.head.x += BLOCK_SIZE;
        break;
    }
}

bool isCollision(const Snake &snake, const Fruit &fruit)
{
    return snake.head.x == fruit.position.x && snake.head.y == fruit.position.y;
}

int main()
{
    initwindow(WIDTH, HEIGHT);
    setcolor(WHITE);

    Snake snake;
    snake.head.x = WIDTH / 2;
    snake.head.y = HEIGHT / 2;
    snake.direction = RIGHT;

    Fruit fruit;
    fruit.position.x = (WIDTH / BLOCK_SIZE / 2) * BLOCK_SIZE;
    fruit.position.y = (HEIGHT / BLOCK_SIZE / 2) * BLOCK_SIZE;

    while (true)
    {
        cleardevice();

        drawSnake(snake);
        drawFruit(fruit);

        if (kbhit())
        {
            char key = getch();
            switch (key)
            {
            case 'w':
                snake.direction = UP;
                break;
            case 's':
                snake.direction = DOWN;
                break;
            case 'a':
                snake.direction = LEFT;
                break;
            case 'd':
                snake.direction = RIGHT;
                break;
            case 'q':
                closegraph();
                return 0;
            }
        }

        updateSnake(snake);

        if (isCollision(snake, fruit))
        {
            // Snake eats the fruit
            // Generate a new fruit at a random position
            fruit.position.x = (rand() % (WIDTH / BLOCK_SIZE)) * BLOCK_SIZE;
            fruit.position.y = (rand() % (HEIGHT / BLOCK_SIZE)) * BLOCK_SIZE;
        }

        delay(100);
    }

    closegraph();
    return 0;
}
