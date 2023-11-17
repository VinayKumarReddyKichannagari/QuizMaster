#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <set>
#include <string>
#include <chrono>
#include <thread>
#include <map>
#include <iomanip>
#include <sstream>

using namespace std;

// Define a struct to represent a quiz question
struct Question {
    string question;        // The question text
    vector<string> options; // Answer choices
    int correctOption;      // Index of the correct answer in 'options'
    string explanation;     // Explanation of the correct answer
};

// Define the main class for the Quiz Game
class QuizGame {
public:
    void run() {
        // Seed the random number generator with the current time
        srand(static_cast<unsigned>(time(nullptr)));

        // Display a welcome message
        displayWelcomeMessage();

        while (true) {
            // Display the main menu and get the user's choice
            displayMenu();
            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    displayRules();
                    break;
                case 2:
                    if (loadQuestions("C++")) {
                        playQuiz("C++");
                    }
                    break;
                case 3:
                    cout << "Exiting the program. Goodbye!" << endl;
                    return;
                default:
                    cout << "Invalid menu choice. Please try again." << endl;
            }
        }
    }

private:
    // Define a struct to represent a user with a name and score
    struct User {
        string name;
        int score;
        User() : name(""), score(0) {}
        User(const string& n) : name(n), score(0) {}
    };

    vector<Question> allQuestions; // Store all available quiz questions
    map<string, User> users;       // Map user names to their scores

    // Display a welcome message when the game starts
    void displayWelcomeMessage() {
        system("clear");
        cout << "************************************************************" << endl;
        cout << "*            Welcome to the Quiz Game!                      *" << endl;
        cout << "************************************************************" << endl << endl;
    }

    // Display the main menu with options
    void displayMenu() {
        cout << "MENU:" << endl;
        cout << "1. RULES" << endl;
        cout << "2. GIVE C++ QUIZ" << endl;
        cout << "3. EXIT" << endl;
        cout << "Enter your choice: ";
    }

    // Display the rules of the quiz game
    void displayRules() {
        system("clear");
        cout << "=== Quiz Game Rules ===" << endl;
        cout << "1. You will be presented with a series of questions." << endl;
        cout << "2. Choose the correct answer by entering the corresponding number." << endl;
        cout << "3. Your final score will be displayed at the end of the quiz." << endl << endl;
        cout << "Press enter to return to the main menu...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    // Load quiz questions based on the chosen topic (C++ or Java)
    bool loadQuestions(const string& quizType) {
        // Clear existing questions to avoid mixing them
        allQuestions.clear();

        if (quizType == "C++") {
            allQuestions = {
					{
			"What is the primary function of main() in a C++ program?",
			{
			"To define the main class", "To execute the main class",
				"To display text on the console", "To declare variables"}
			, 2,
			"The main() function in C++ is the entry point of a program. It is where program execution begins."}
			,
			{
			"Which data type is used to store whole numbers in C++?",
			{
			"float", "char", "int", "double"}
			, 3,
			"The 'int' data type is used to store whole numbers in C++."}
			,
			{
			"What is the result of 7 + 3 * 2?",
			{
			"20", "13", "17", "26"}
			, 4,
			"In C++, the multiplication (*) operator has higher precedence than the addition (+) operator."}
			,
			{
			"What do you use to define a constant in C++?",
			{
			"const", "var", "let", "define"}
			, 1, "The 'const' keyword is used to define constants in C++."}
			,
			{
			"Which of the following is not a C++ keyword?",
			{
			"for", "if", "then", "else"}
			, 3, "In C++, 'then' is not a keyword."}
			,
			{
			"In C++, how can you create a single-line comment?",
			{
			"//", "/*", "#", "--"}
			, 1,
			"A double forward slash (//) is used for single-line comments in C++."}
			,
			{
			"What is the C++ operator for 'not equal to'?",
			{
			"==", "!=", "<>", "><"}
			, 2,
			"The '!=' operator is used in C++ to represent 'not equal to'."}
			,
			{
			"Which of the following is not a fundamental data type in C++?",
			{
			"bool", "string", "char", "int"}
			, 2, "In C++, 'string' is not a fundamental data type."}
			,
			{
			"What does the 'cin' object in C++ do?",
			{
			"It performs console input",
				"It prints text to the console", "It defines classes",
				"It handles exceptions"}
			, 1,
			"'cin' is used for console input in C++ to read values entered by the user."}
			,
			{
			"Which C++ header file is needed to work with files?",
			{
			"<iostream>", "<fstream>", "<stdio.h>", "<stdlib.h>"}
			, 2,
			"The '<fstream>' header file is used for working with files in C++."}
			,
			{
			"What is the size of 'int' data type in C++ on a 32-bit system?",
			{
			"2 bytes", "4 bytes", "8 bytes", "Depends on the compiler"}
			, 2,
			"On a 32-bit system, the 'int' data type typically occupies 4 bytes of memory."}
			,
			{
			"What is the scope resolution operator in C++?",
			{
			"->", ".", ":", "::"}
			, 4,
			"The scope resolution operator '::' is used to access members of a class or namespace in C++."}
			,
			{
			"Which C++ data structure is a collection of elements with no duplicates?",
			{
			"Vector", "Array", "Set", "List"}
			, 3,
			"A 'Set' is a data structure in C++ that stores unique elements, meaning it doesn't allow duplicates."}
			,
			{
			"In C++, what is a 'pointer'?",
			{
			"A data type", "A function",
				"A variable that stores a memory address",
				"A loop control statement"}
			, 3,
			"A 'pointer' is a variable that stores the memory address of another variable."}
			,
			{
			"What is 'polymorphism' in C++?",
			{
			"A type of loop", "A function that calls itself",
				"The ability of different objects to respond to the same function call",
				"A keyword to define classes"}
			, 3,
			"Polymorphism in C++ allows different objects to respond to the same function call in a way that is appropriate for each object."}
			,
			{
			"What is the output of the following code?\nint x = 5;\nint y = x++ + ++x;\nstd::cout << y;",
			{
			"10", "11", "12", "13"}
			, 4,
			"The code uses post-increment and pre-increment operators to modify 'x' and calculate 'y'. The output is 13."}
			,
			{
			"Which C++ operator is used to access the members of a class?",
			{
			".", "->", ":", "::"}
			, 2,
			"The '->' operator is used to access members of a class through a pointer to an object."}
			,
			{
			"What is the purpose of 'break' statement in C++?",
			{
			"To define a new loop", "To exit a loop prematurely",
				"To skip the next iteration of a loop",
				"To pause program execution"}
			, 2,
			"The 'break' statement is used to exit a loop prematurely in C++."}
			,
			{
			"What does 'std::endl' do in C++?",
			{
			"It ends the program", "It declares a variable",
				"It inserts a new line and flushes the output stream",
				"It generates a random number"}
			, 3,
			"'std::endl' in C++ inserts a new line and flushes the output stream."}
			,
			{
			"Which C++ operator is used for logical 'AND'?",
			{
			"&&", "||", "!", "&"}
			, 1, "The '&&' operator is used for logical 'AND' in C++."}
			,
			{
			"What is the C++ 'switch' statement used for?",
			{
			"Defining classes", "Logical 'AND' operation",
				"Selecting one of many code blocks to be executed",
				"String manipulation"}
			, 3,
			"The 'switch' statement in C++ is used to select one of many code blocks to be executed based on a given value."}
			,
			{
			"What is a 'constructor' in C++?",
			{
			"A type of loop", "A function that calls itself",
				"A special member function to initialize objects",
				"A data type"}
			, 3,
			"A 'constructor' in C++ is a special member function used to initialize objects of a class."}
			,
			{
			"What is 'inheritance' in C++?",
			{
			"A keyword to define classes", "A special operator",
				"The ability to create a new class from an existing class",
				"A type of comment"}
			, 3,
			"Inheritance in C++ allows you to create a new class that inherits properties and behaviors from an existing class."}
			,
			{
			"What is 'encapsulation' in C++?",
			{
			"A logical operator", "A file format",
				"The bundling of data and functions that operate on that data into a single unit",
				"A loop control statement"}
			, 3,
			"Encapsulation in C++ involves bundling data and functions that operate on that data into a single unit, known as a class."}
			,
			{
			"What is the C++ 'new' operator used for?",
			{
			"Creating a new object", "Defining a new function",
				"Reserving memory on the heap", "Ending the program"}
			, 3,
			"The 'new' operator in C++ is used to allocate memory on the heap and returns a pointer to the allocated memory."}
			,
			{
			"What is 'cout' in C++?",
			{
			"A reserved word", "A data type", "An input stream",
				"An output stream"}
			, 4,
			"'cout' in C++ is an output stream used for displaying data on the console."}
			,
			{
			"What is the result of 5 / 2 in C++?",
			{
			"2.5", "2", "2.0", "2.25"}
			, 2,
			"In C++, the division of two integers results in an integer quotient. The result of 5 / 2 is 2."}
        
            };
        }

        if (allQuestions.size() < 15) {
            cout << "Error: Insufficient questions available for the quiz." << endl;
            return false;
        }
        return true;
    }

    // Display a quiz question along with answer choices
    void displayQuestion(const Question& q, int questionNumber) {
        system("clear");
        cout << "Question " << questionNumber << ":" << endl;
        cout << q.question << endl << endl;

        for (size_t i = 0; i < q.options.size(); ++i) {
            this_thread::sleep_for(chrono::milliseconds(200));
            cout << setw(2) << i + 1 << ") " << q.options[i] << endl;
        }

        cout << "Enter your answer (1-" << q.options.size() << "): ";
    }

    // Manage the gameplay for the selected quiz type
    void playQuiz(const string& quizType) {
        set<int> randomIndices;
        while (randomIndices.size() < 15) {
            int randomIndex = rand() % allQuestions.size();
            randomIndices.insert(randomIndex);
        }

        int questionNumber = 1;

        string userName;
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, userName);

        if (users.find(userName) == users.end()) {
            users[userName] = User(userName);
        }

        User& currentUser = users[userName];
        int correctAnswers = 0;

        for (int index : randomIndices) {
            const Question& currentQuestion = allQuestions[index];
            displayQuestion(currentQuestion, questionNumber);
            int userResponse;
            cin >> userResponse;

            while (userResponse < 1 || userResponse > currentQuestion.options.size()) {
                cout << "Invalid option. Please enter a number between 1 and " << currentQuestion.options.size() << "." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter your answer (1-" << currentQuestion.options.size() << "): ";
                cin >> userResponse;
            }

            if (evaluateResponse(currentQuestion, userResponse)) {
                cout << "Correct!" << endl;
                correctAnswers++;
            } else {
                cout << "Incorrect. The correct answer is: " << currentQuestion.options[currentQuestion.correctOption - 1] << endl;
            }

            cout << "Explanation: " << currentQuestion.explanation << endl;
            pauseForNextQuestion();
            questionNumber++;
        }

        system("clear");
        displayQuizResult(userName, quizType, correctAnswers);
    }

    // Evaluate if the user's response is correct
    bool evaluateResponse(const Question& q, int response) {
        return (response == q.correctOption);
    }

    // Pause for the user to read feedback before the next question
    void pauseForNextQuestion() {
        cout << "Press Enter to continue to the next question...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    // Display the user's quiz result at the end of the quiz
    void displayQuizResult(const string& userName, const string& quizType, int correctAnswers) {
        system("clear");
        cout << "Quiz completed, " << userName << "! Your score in the " << quizType << " quiz: " << correctAnswers << " out of 15" << endl;
        cout << "Press enter to return to the main menu...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
};

int main() {
    QuizGame quiz;
    quiz.run();
    return 0;
}
