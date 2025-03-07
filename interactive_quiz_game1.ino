#include <LiquidCrystal.h>

// Initialize the LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define pins
#define GREEN_LED 13
#define RED_LED 6
#define BUZZER 1
#define BUTTON_A 7
#define BUTTON_B 8
#define BUTTON_C 9
#define BUTTON_D 10

// Question structure
typedef struct {
    char question[50];
    char options[4][20];
    char correctAnswer;
} QuizQuestion;

// Function prototypes
void displayQuestion(QuizQuestion *q);
void scrollText(const char* text);
char getAnswer();
void checkAnswer(QuizQuestion *q, char answer);

// Quiz questions array
QuizQuestion quiz[] = {
    {"France capital?", {"A: Paris", "B: London", "C: Berlin", "D: Madrid"}, 'A'},
    {"Main gas in air?", {"A: Oxygen", "B: Nitrogen", "C: CO2", "D: Argon"}, 'B'},
    {"Largest planet?", {"A: Mars", "B: Venus", "C: Jupiter", "D: Saturn"}, 'C'},
    {"Hardest material?", {"A: Gold", "B: Iron", "C: Diamond", "D: Sapphire"}, 'C'},
    {"Cell powerhouse?", {"A: Mitochondria", "B: Nucleus", "C: Chloroplast", "D: Ribosome"}, 'A'}
};


int score = 0;
int totalQuestions = sizeof(quiz) / sizeof(quiz[0]);

void setup() {
    // Set up pins
    lcd.begin(16, 2);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(BUTTON_A, INPUT_PULLUP);
    pinMode(BUTTON_B, INPUT_PULLUP);
    pinMode(BUTTON_C, INPUT_PULLUP);
    pinMode(BUTTON_D, INPUT_PULLUP);
}

void scrollText(const char* text) {
    int len = strlen(text);
    for (int position = 0; position < len + 16; position++) {
        lcd.clear();
        if (position < len) {
            lcd.setCursor(0, 0);
            lcd.print(&text[position]);
        } else {
            lcd.setCursor(0, 0);
            lcd.print(&text[position - 16]);
        }
        delay(200); // Adjust speed of scrolling here
    }
}

void displayQuestion(QuizQuestion *q) {
    scrollText(q->question);
    delay(2000);  // Pause after scrolling before showing options
    for (int i = 0; i < 4; i++) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(q->options[i]);
        delay(1000);  // Display each option for 1 second
    }
}

char getAnswer() {
    if (digitalRead(BUTTON_A) == LOW) return 'A';
    if (digitalRead(BUTTON_B) == LOW) return 'B';
    if (digitalRead(BUTTON_C) == LOW) return 'C';
    if (digitalRead(BUTTON_D) == LOW) return 'D';
    return 'N';  // No answer selected
}

void checkAnswer(QuizQuestion *q, char answer) {
    if (answer == q->correctAnswer) {
        score++;
        digitalWrite(GREEN_LED, HIGH);
        tone(BUZZER, 1000); // Beep once for correct answer
        delay(100);
        noTone(BUZZER);
        delay(1000);
        digitalWrite(GREEN_LED, LOW);
    } else {
        digitalWrite(RED_LED, HIGH);
        tone(BUZZER, 1000); // Beep for wrong answer
        delay(2000); // Beep for 2 seconds
        digitalWrite(RED_LED, LOW);
        noTone(BUZZER);
    }
}

void loop() {
    for (int i = 0; i < totalQuestions; i++) {
        displayQuestion(&quiz[i]);
        char answer = 'N';
        while (answer == 'N') {  // Wait until a button is pressed
            answer = getAnswer();
        }
        checkAnswer(&quiz[i], answer);
        delay(1000);
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Quiz Over!");
    lcd.setCursor(0, 1);
    lcd.print("Score: ");
    lcd.print(score);
    delay(5000);
    score = 0;
}
