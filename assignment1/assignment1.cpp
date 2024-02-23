#include <iostream>
#include <string>

int main() {
    int Marbles = 0; // Initial number of marbles
    std::string response;

    while (true) { // Start of the loop
        std::cout << "Do you want to add a marble to the bag? Type 'yes' to add, 'no' to remove, or 'exit' to stop (input sensitive): ";
        std::cin >> response;

        if (response == "exit") {
            break; // Exit the loop if response is "exit"
        } else if (response == "yes") {
            Marbles++; // Add a marble
            std::cout << "A marble has been added. Total marbles: " << Marbles << std::endl;
        } else if (response == "no") {
            if (Marbles > 0) {
                Marbles--; // Remove a marble with a minimum of 0
                std::cout << "A marble has been removed. Total marbles: " << Marbles << std::endl;
            } else {
                std::cout << "Cannot remove a marble. No marbles in the bag." << std::endl;
            }
        } else {
            std::cout << "Invalid input. Please type 'yes', 'no', or 'exit'." << std::endl;
        }
    }

    std::cout << "Final total marbles: " << Marbles << std::endl;
    return 0;
}
