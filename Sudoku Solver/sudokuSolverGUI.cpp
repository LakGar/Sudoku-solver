#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    std::srand(std::time(nullptr)); // seed the random number generator

    // create main window
    QWidget window;
    window.setWindowTitle("Rock-Paper-Scissors Game");

    // create vertical layout for main window
    QVBoxLayout* layout = new QVBoxLayout(&window);

    // create labels for player and computer choices
    QLabel* playerLabel = new QLabel("Player chose: ");
    QLabel* computerLabel = new QLabel("Computer chose: ");
    layout->addWidget(playerLabel);
    layout->addWidget(computerLabel);

    // create horizontal layout for buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    layout->addLayout(buttonLayout);

    // create buttons for each choice
    QPushButton* rockButton = new QPushButton("Rock");
    QPushButton* paperButton = new QPushButton("Paper");
    QPushButton* scissorsButton = new QPushButton("Scissors");
    buttonLayout->addWidget(rockButton);
    buttonLayout->addWidget(paperButton);
    buttonLayout->addWidget(scissorsButton);

    // create label for result
    QLabel* resultLabel = new QLabel("");
    layout->addWidget(resultLabel);

    // create connections for buttons
    QObject::connect(rockButton, &QPushButton::clicked, [&]() {
        playerLabel->setText("Player chose: Rock");
        int computer = std::rand() % 3;
        if (computer == 0)
        {
            computerLabel->setText("Computer chose: Rock");
            resultLabel->setText("It's a tie!");
        }
        else if (computer == 1)
        {
            computerLabel->setText("Computer chose: Paper");
            resultLabel->setText("You lose!");
        }
        else if (computer == 2)
        {
            computerLabel->setText("Computer chose: Scissors");
            resultLabel->setText("You win!");
        }
    });
    QObject::connect(paperButton, &QPushButton::clicked, [&]() {
        playerLabel->setText("Player chose: Paper");
        int computer = std::rand() % 3;
        if (computer == 0)
        {
            computerLabel->setText("Computer chose: Rock");
            resultLabel->setText("You win!");
        }
        else if (computer == 1)
        {
            computerLabel->setText("Computer chose: Paper");
            resultLabel->setText("It's a tie!");
        }
        else if (computer == 2)
        {
            computerLabel->setText("Computer chose: Scissors");
            resultLabel->setText("You lose!");
        }