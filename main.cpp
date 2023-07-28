// Digital Circuit Simulation Project
// Matylda Hoffman
// May 2022

#include<iostream>

#include "interface.h"
#include "circuit.h"
#include "components.h"

int main()
{
    bool program_running{true};
    while (program_running == true) {
        int user_choice{option_menu()};
        // Building a circuit
        if (user_choice == 1) {
            print_instructions();
            circuit your_circuit{};
            your_circuit.build_circuit();
            your_circuit.truth_table();
        }
        // Displaying truth tables for components
        else if (user_choice == 2) {
            print_truth_tables();
        }
        // Terminate the program
        else if (user_choice == 3) {
            std::cout << "Exiting program..." << std::endl;
            program_running = false;
        }

    }
    return 0;
}