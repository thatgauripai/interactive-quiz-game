# **Arduino-Based Interactive Quiz Game**  

## **Overview**  
This project is an **Arduino-powered multiple-choice quiz game** designed to enhance learning and engagement. Players are presented with questions on an **LCD screen** and can choose answers using **push buttons**. The system provides **instant feedback** using **LED indicators and a buzzer**, reinforcing correct and incorrect responses. At the end of the game, the **final score is displayed**, making it a great tool for self-assessment and competitive learning.  

## **Why This Project? (Benefits & Applications)**  
- **Educational and Engaging** – Helps in learning new concepts interactively.  
- **Real-Time Feedback** – Reinforces correct answers with positive feedback (green LED, buzzer beep) and highlights mistakes with red LED and a longer beep.  
- **Hands-On Learning** – Great for STEM students interested in Arduino, electronics, and programming.  
- **Customizable** – Easily modify the questions to create quizzes on any topic.  
- **Interactive Group Activity** – Can be used in classrooms, game nights, and educational workshops.  

## **Features**  
- **LCD Display** – Shows quiz questions and answer options.  
- **Four Push Buttons** – Players select answers using dedicated buttons (A, B, C, D).  
- **LED and Buzzer Indicators** –  
  - Green LED and short beep for correct answers  
  - Red LED and long beep for incorrect answers  
- **Score Tracking** – The game keeps track of correct answers and displays the final score at the end.  
- **Looping Mechanism** – Automatically moves to the next question and restarts after the quiz ends.  

## **Key Functions Used in the Code**  
- `setup()` – Initializes the LCD display, button inputs, and output devices like LEDs and the buzzer.  
- `loop()` – Runs the quiz by iterating through questions, waiting for user input, and processing answers.  
- `displayQuestion(QuizQuestion *q)` – Displays the current question and its answer choices on the LCD.  
- `scrollText(const char* text)` – Scrolls long questions across the LCD screen for better readability.  
- `getAnswer()` – Detects button presses and returns the corresponding answer choice.  
- `checkAnswer(QuizQuestion *q, char answer)` – Compares the user’s answer with the correct one, updates the score, and triggers LED and buzzer feedback.  

## **Components Used**  
- Arduino Board  
- 16x2 LCD Display  
- Push Buttons (4 for A, B, C, D)  
- LEDs (Green and Red)  
- Buzzer  
- Resistors and Jumper Wires  
- Breadboard (for easy circuit assembly)  

## **How It Works**  
1. The LCD screen displays a multiple-choice question.  
2. The player selects an answer using one of the four push buttons (A, B, C, or D).  
3. The system verifies the answer and provides feedback:  
   - **Correct Answer**: Green LED lights up, and a short beep is heard.  
   - **Wrong Answer**: Red LED lights up, and a long beep plays.  
4. The game continues through the question set.  
5. After the last question, the final score is displayed on the LCD.  
6. The game resets, allowing players to try again.  

## **Getting Started**  
### **Hardware Setup**  
- Connect the LCD display to the Arduino following the wiring diagram.  
- Attach push buttons for answer selection.  
- Connect LEDs and a buzzer for feedback.  
- Use resistors where necessary.  

### **Software Setup**  
- Install the Arduino IDE on your computer.  
- Upload the provided C code to the Arduino board.  
- Power on the system and start playing.  

## **Customization**  
- **Modify Questions**: Edit the `quiz` array in the code to add new questions.  
- **Change Timing**: Adjust the scrolling speed and delays for smoother transitions.  
- **Enhance UI**: Improve the LCD display effects for a better user experience.  
- **Expand Features**: Add more difficulty levels, a timer, or a multiplayer mode.  

## **License**  
This project is open-source under the **MIT License**.  
