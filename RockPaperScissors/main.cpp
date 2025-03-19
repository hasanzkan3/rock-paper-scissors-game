#include <iostream>
#include <ctime>
#include <cstdlib>

void seedrandom(){
    srand(time(0));
}
std::string Computer() {
    std::string selections[] = {"Rock", "Paper", "Scissors"};
    int random = rand() % 3;
    return selections[random];  // std::cout removed
}
std::string result(std::string ComputerChoice, std::string PlayerChoice) {
    if (PlayerChoice == ComputerChoice) {
        return "Draw";
    }
    else if ((PlayerChoice == "Rock" && ComputerChoice == "Scissors") ||
             (PlayerChoice == "Paper" && ComputerChoice == "Rock") ||
             (PlayerChoice == "Scissors" && ComputerChoice == "Paper")) {
        return "You Win!";
    }
    else if ((PlayerChoice == "Rock" && ComputerChoice == "Paper") ||
             (PlayerChoice == "Paper" && ComputerChoice == "Scissors") ||
             (PlayerChoice == "Scissors" && ComputerChoice == "Rock")) {
        return "You Lose!";
    }
    return "Error: Invalid game state!"; // At unexpected error
}

int main(){
    seedrandom();
    std::string selection;
    std::string PlayerChoice;
    while (true) {
        std::cout << "Choose between rock, paper and scissors (type 'exit' to exit): ";
        std::cin >> PlayerChoice;

        for (auto &c : PlayerChoice) c = tolower(c);
        if (PlayerChoice == "rock") PlayerChoice = "Rock";
        else if (PlayerChoice == "paper") PlayerChoice = "Paper";
        else if (PlayerChoice == "scissors") PlayerChoice = "Scissors";

        if(PlayerChoice == "exit"){
            std::cout << "Thank you for your participating! :)" << std::endl;
            break;
        }
         std::string ComputerChoice = Computer();
        std::cout << "Computer:" << ComputerChoice << std::endl;
        std::cout << result(ComputerChoice, PlayerChoice) << std::endl;
    }
}
