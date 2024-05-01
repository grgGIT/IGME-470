#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define WIDTH 16
#define HEIGHT 2
#define MENU_ITEMS 2

int selectedMenuItem = 0;

void setup() {
  lcd.begin(WIDTH, HEIGHT);
  randomSeed(analogRead(0));

  lcd.clear();
  drawMenu();
}

void loop() {
  delay(50); // Adjust menu speed

  // Update menu selection
  if (digitalRead(A0) == HIGH && selectedMenuItem > 0) {
    selectedMenuItem--;
    drawMenu();
  } else if (digitalRead(A1) == HIGH && selectedMenuItem < MENU_ITEMS - 1) {
    selectedMenuItem++;
    drawMenu();
  }

  // Check for menu item selection
  if (digitalRead(A2) == HIGH) {
    lcd.clear();
    if (selectedMenuItem == 0) {
      startPong();
    } else if (selectedMenuItem == 1) {
      startSnake();
    }
    lcd.clear();
    drawMenu();
  }
}

void drawMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select Game:");
  lcd.setCursor(0, 1);
  for (int i = 0; i < MENU_ITEMS; i++) {
    if (i == selectedMenuItem) {
      lcd.write('>');
    } else {
      lcd.write(' ');
    }
    lcd.print(i == 0 ? "Pong" : "Snake");
    lcd.write(' ');
  }
}

void startPong() {
  #include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define WIDTH 16
#define HEIGHT 2
#define PADDLE_HEIGHT 2
#define PADDLE_WIDTH 1
#define BALL_SIZE 1
#define BALL_SPEED 1

int paddle1Y = HEIGHT / 2 - PADDLE_HEIGHT / 2;
int paddle2Y = HEIGHT / 2 - PADDLE_HEIGHT / 2;
int ballX = WIDTH / 2;
int ballY = HEIGHT / 2;
int ballDirX = -1;
int ballDirY = -1;

void setup() {
  lcd.begin(WIDTH, HEIGHT);
  randomSeed(analogRead(0));

  lcd.clear();
  drawPaddles();
  drawBall();
}

void loop() {
  delay(50); // Adjust game speed

  // Update ball position
  ballX += BALL_SPEED * ballDirX;
  ballY += BALL_SPEED * ballDirY;

  // Check for collisions with walls
  if (ballY <= 0 || ballY >= HEIGHT - BALL_SIZE) {
    ballDirY = -ballDirY;
  }

  // Check for collisions with paddles
  if ((ballX == 0 && ballDirX == -1 && ballY >= paddle1Y && ballY < paddle1Y + PADDLE_HEIGHT) ||
      (ballX == WIDTH - 1 && ballDirX == 1 && ballY >= paddle2Y && ballY < paddle2Y + PADDLE_HEIGHT)) {
    ballDirX = -ballDirX;
  }

  // Check for scoring
  if (ballX < 0 || ballX >= WIDTH) {
    resetBall();
  }

  // Update paddle positions
  updatePaddles();

  // Draw game state
  lcd.clear();
  drawPaddles();
  drawBall();
}

void drawPaddles() {
  for (int y = 0; y < PADDLE_HEIGHT; y++) {
    lcd.setCursor(0, paddle1Y + y);
    lcd.write('#');
    lcd.setCursor(WIDTH - 1, paddle2Y + y);
    lcd.write('#');
  }
}

void drawBall() {
  lcd.setCursor(ballX, ballY);
  lcd.write('*');
}

void updatePaddles() {
  // Update paddle 1
  if (digitalRead(A0) == HIGH && paddle1Y > 0) {
    paddle1Y--;
  } else if (digitalRead(A1) == HIGH && paddle1Y < HEIGHT - PADDLE_HEIGHT) {
    paddle1Y++;
  }

  // Update paddle 2 (AI or second player controls)
  // Example: paddle2Y = ballY - PADDLE_HEIGHT / 2;
}

void resetBall() {
  ballX = WIDTH / 2;
  ballY = HEIGHT / 2;
  ballDirX = random(0, 2) == 0 ? -1 : 1;
  ballDirY = random(0, 2) == 0 ? -1 : 1;
}

}

void startSnake() {
  #include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define WIDTH 16
#define HEIGHT 2
#define SNAKE_MAX_LENGTH 10

int snakeX[SNAKE_MAX_LENGTH], snakeY[SNAKE_MAX_LENGTH];
int snakeLength = 1;
int foodX, foodY;
int directionX = 1, directionY = 0; // Initial direction (right)

void setup() {
  lcd.begin(WIDTH, HEIGHT);
  randomSeed(analogRead(0));

  snakeX[0] = WIDTH / 2;
  snakeY[0] = HEIGHT / 2;
  foodX = random(0, WIDTH);
  foodY = random(0, HEIGHT);

  lcd.clear();
  lcd.setCursor(snakeX[0], snakeY[0]);
  lcd.write('*'); // Snake head
  lcd.setCursor(foodX, foodY);
  lcd.write('#'); // Food
}

void loop() {
  delay(200); // Adjust game speed
  int newHeadX = snakeX[0] + directionX;
  int newHeadY = snakeY[0] + directionY;

  if (newHeadX < 0 || newHeadX >= WIDTH || newHeadY < 0 || newHeadY >= HEIGHT) {
    // Game over: hit the wall
    lcd.clear();
    lcd.print("Game Over");
    while (true); // End the game loop
  }

  for (int i = snakeLength - 1; i > 0; i--) {
    snakeX[i] = snakeX[i - 1];
    snakeY[i] = snakeY[i - 1];
  }

  snakeX[0] = newHeadX;
  snakeY[0] = newHeadY;

  for (int i = 1; i < snakeLength; i++) {
    if (snakeX[i] == snakeX[0] && snakeY[i] == snakeY[0]) {
      // Game over: collided with the snake's own body
      lcd.clear();
      lcd.print("Game Over");
      while (true); // End the game loop
    }
  }

  if (snakeX[0] == foodX && snakeY[0] == foodY) {
    // Snake ate the food
    snakeLength++;
    foodX = random(0, WIDTH);
    foodY = random(0, HEIGHT);
    lcd.setCursor(foodX, foodY);
    lcd.write('#'); // New food
  }

  lcd.clear();
  for (int i = 0; i < snakeLength; i++) {
    lcd.setCursor(snakeX[i], snakeY[i]);
    if (i == 0) {
      lcd.write('*'); // Snake head
    } else {
      lcd.write('+'); // Snake body
    }
  }
}

}
