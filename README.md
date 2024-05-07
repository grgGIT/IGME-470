# IGME-470
arduino codes

Ignore this

const int rs = 11, en = 9, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int joystickPinX = A0; // Joystick X-axis connected to A0
const int joystickPinY = A1; // Joystick Y-axis connected to A1

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
   lcd.begin(16, 2);  
 lcd.print("Hello, World!");
  // Initialize LED pin as an output
  //pinMode(ledPin, OUTPUT);
}

enum GameState {
  MENU,
  SNAKE_GAME
};

GameState currentState = MENU; // Initial state: Menu
int selectedMenuItem = 0;      // Currently selected menu item

void navigateMenu() {
  int joystickValueX = analogRead(joystickPinX);
  int joystickValueY = analogRead(joystickPinY);

  if (joystickValueY < 100) { // Move up
    selectedMenuItem = (selectedMenuItem + 1) % 2; // Two menu items (0 and 1)
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(selectedMenuItem == 0 ? "> Snake Game" : "  Snake Game");
    lcd.setCursor(0, 1);
    lcd.print(selectedMenuItem == 1 ? "> Exit" : "  Exit");
    delay(200); // Debounce delay
  }

  if (joystickValueY > 900) { // Move down
    selectedMenuItem = (selectedMenuItem + 1) % 2;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(selectedMenuItem == 0 ? "> Snake Game" : "  Snake Game");
    lcd.setCursor(0, 1);
    lcd.print(selectedMenuItem == 1 ? "> Exit" : "  Exit");
    delay(200); // Debounce delay
  }
}
void startSnakeGame() {
  // Game initialization for Snake
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Snake Game");
  delay(1000); // Show message briefly

  // Game loop for Snake
  while (true) {
    // Handle Snake game logic here
    // Use joystick input to control the Snake (e.g., move up, down, left, right)
    // Update LCD display with Snake movement and game state
  }
}
void loop() {
  switch (currentState) {
    case MENU:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Select Game:");
      lcd.setCursor(0, 1);
      lcd.print("> Snake Game");
      delay(200); // Debounce delay

      navigateMenu(); // Handle menu navigation using joystick
      if (digitalRead(A2) == HIGH) { // Button press on A2 pin (select)
        currentState = selectedMenuItem == 0 ? SNAKE_GAME : MENU;
      }
      break;

    case SNAKE_GAME:
      startSnakeGame(); // Start the Snake game
      currentState = MENU; // Return to menu after game ends
      break;

    default:
      break;
  }
}



