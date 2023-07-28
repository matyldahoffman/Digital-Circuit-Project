#include "components.h"
#include "interface.h"
#include "timesteps.h"

// Function to create the first step - different to the rest as it has no previous outputs to connect
std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>> timestep::create_first_step(int& time_step, std::vector<std::shared_ptr<IN>>& circuit_ins)
{
    // Create new time step map
    std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>> new_time_step;

    bool add_component{true};
    while (add_component == true) {
        // vector storing inputs to the next appended gate
        std::vector<std::shared_ptr<components>> inputs_to_next_gate;
        std::vector<std::string> possibilities;
        for (std::shared_ptr<IN> in : circuit_ins) {
            possibilities.push_back(in->get_gate_name());
        }

        // Add first input
        if (circuit_ins.size() == 0) {
            std::cout << "\nAdding a starting input to the circuit..." << std::endl;
            std::shared_ptr<IN> new_input{add_circuit_input(time_step, circuit_ins, inputs_to_next_gate)};
            possibilities.push_back(new_input->get_gate_name());
            std::cout << "\nNow choose a gate to connect to this input..." << std::endl;
        }

        else {
            int no_of_outputs{static_cast<int>(circuit_ins.size())};
            std::string connect_to{choose_output(possibilities, no_of_outputs)};
            //iterate through map to find the component of choice by comparing names
            for (std::shared_ptr<IN> in : circuit_ins) {
                if (connect_to == in->get_gate_name()) {
                    inputs_to_next_gate.emplace_back(in);
                }
            }
        }
    
        // Choose what gate type to connect
        int gate_type{choose_gate_type()};
        std::shared_ptr<components> next_component;

        // ----------- ADD UNARY GATE -----------

        if (gate_type == 1) {
            int choice{choose_unary_component()};
            if (choice == 1) {
                next_component = add_unary_component<NOT>(inputs_to_next_gate);
            } else if (choice == 2) {
                next_component = add_unary_component<buffer>(inputs_to_next_gate);
            }
        }

        // ----------- ADD BINARY GATE -----------

        else if (gate_type == 2) {
            // If binary chosen and not enough outputs then make user connect to circuit input
            if (circuit_ins.size() == 1) {
                std::cout << "\nThere is only one input to this circuit so far. Adding another input to connect a binary gate..." << std::endl;
                std::shared_ptr<IN> new_input{add_circuit_input(time_step, circuit_ins, inputs_to_next_gate)};
            }
            else {
                int input_decision{choose_old_new_input()};
                if (input_decision == 1) {
                    // add old input to vector
                    std::shared_ptr<IN> old_input{choose_circuit_input(circuit_ins)};
                    inputs_to_next_gate.emplace_back(old_input);
                }
                else if (input_decision == 2) {
                    // Add new input to the circuit
                    std::shared_ptr<IN> new_input{add_circuit_input(time_step, circuit_ins, inputs_to_next_gate)};
                }
            }

            int choice{choose_binary_component()};

            if (choice == 1) {
                next_component = add_binary_component<AND>(inputs_to_next_gate);
            } else if (choice == 2) {
                next_component = add_binary_component<OR>(inputs_to_next_gate);
            } else if (choice == 3) {
                next_component = add_binary_component<NAND>(inputs_to_next_gate);
            } else if (choice == 4) {
                next_component = add_binary_component<XOR>(inputs_to_next_gate);
            } else if (choice == 5) {
                next_component = add_binary_component<XNOR>(inputs_to_next_gate);
            } else if (choice == 6) {
                next_component = add_binary_component<NOR>(inputs_to_next_gate);
            }
        }
        std::cout << "Added " << next_component->get_gate_name() << " gate" << std::endl;
        new_time_step.insert(std::pair<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>>(inputs_to_next_gate,next_component));

        // Check whether the user wants to append any more inputs
        add_component = terminate_timestep();
    }

    // Visually display timestep
    print_timestep(new_time_step, time_step);
    this_step = new_time_step;
    return this_step;
}


// Create new timestep
std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>> timestep::create_step(const std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>>& prev_time_step, int& time_step, std::vector<std::shared_ptr<IN>>& circuit_ins)
{
     // Create new time step map
    std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>> new_time_step;

    // Make a list of all outputs from previous operation
    int number_of_prev_outputs{0};
    std::vector<std::string> possibilities;
    for (std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>>::const_iterator it = prev_time_step.begin(); it != prev_time_step.end(); it++) {
        possibilities.push_back(it->second->get_gate_name());
        number_of_prev_outputs++;
    }
    
    bool add_component{true};
    while (add_component == true) {
        // vector storing inputs to the next appended gate
        std::vector<std::shared_ptr<components>> inputs_to_next_gate;
        if (possibilities.size() == 0) {
            int input_decision{choose_old_new_input()};
            if (input_decision == 1) {
                std::shared_ptr<IN> old_input{choose_circuit_input(circuit_ins)};
                inputs_to_next_gate.emplace_back(old_input);
            }
            else if (input_decision == 2) {
                std::shared_ptr<IN> new_input{add_circuit_input(time_step, circuit_ins, inputs_to_next_gate)};
            }
        }
        else {
            std::string connect_to{choose_output(possibilities, number_of_prev_outputs)};
            //iterate through map to find the component of choice by comparing names
            for (std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>>::const_iterator it = prev_time_step.begin(); it != prev_time_step.end(); ++it) {
                if (connect_to == it->second->get_gate_name()) {
                    inputs_to_next_gate.emplace_back(it->second);
                }
            }
        }
    
        // Choose what gate type to connect
        int gate_type{choose_gate_type()};
        std::shared_ptr<components> next_component;

        // ----------- ADD UNARY GATE -----------

        if (gate_type == 1) {
            int choice{choose_unary_component()};
            if (choice == 1) {
                next_component = add_unary_component<NOT>(inputs_to_next_gate);
            } else if (choice == 2) {
                next_component = add_unary_component<buffer>(inputs_to_next_gate);
            }
        }

        // ----------- ADD BINARY GATE -----------

        else if (gate_type == 2) {
            // If binary chosen and not enough outputs then make user connect to circuit input
            if (possibilities.size() == 0) {
                int input_decision{choose_old_new_input()};
                if (input_decision == 1) {
                    // add old input to vector - circuit_ins is a vector containing pointers to input pointers
                    std::shared_ptr<IN> old_input{choose_circuit_input(circuit_ins)};
                    inputs_to_next_gate.emplace_back(old_input);
                }
                else if (input_decision == 2) {
                    // Add new input to the circuit and a pointer to it to the inputs vector
                    std::shared_ptr<IN> new_input{add_circuit_input(time_step, circuit_ins, inputs_to_next_gate)};
                }
            }
            else {
                int input_or_gate{choose_input_gate()};
                if (input_or_gate == 1) {
                    // Choose another input
                    std::cout << "Please choose another input which you would like to connect this gate to." << std::endl;
                    std::string connect_to_2{choose_output(possibilities, number_of_prev_outputs)};
                    for (std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>>::const_iterator it = prev_time_step.begin(); it != prev_time_step.end(); ++it) {
                        if (connect_to_2 == it->second->get_gate_name()) {
                            inputs_to_next_gate.emplace_back(it->second);
                        }                
                    }
                }
                else if (input_or_gate == 2) {
                    std::shared_ptr<IN> old_input{choose_circuit_input(circuit_ins)};
                    inputs_to_next_gate.emplace_back(old_input);
                }
                else if (input_or_gate == 3) {
                    std::shared_ptr<IN> new_input{add_circuit_input(time_step, circuit_ins, inputs_to_next_gate)};
                }
            }

            int choice{choose_binary_component()};

            if (choice == 1) {
                next_component = add_binary_component<AND>(inputs_to_next_gate);
            } else if (choice == 2) {
                next_component = add_binary_component<OR>(inputs_to_next_gate);
            } else if (choice == 3) {
                next_component = add_binary_component<NAND>(inputs_to_next_gate);
            } else if (choice == 4) {
                next_component = add_binary_component<XOR>(inputs_to_next_gate);
            } else if (choice == 5) {
                next_component = add_binary_component<XNOR>(inputs_to_next_gate);
            } else if (choice == 6) {
                next_component = add_binary_component<NOR>(inputs_to_next_gate);
            }
        }
        std::cout << "\nAdded " << next_component->get_gate_name() << " gate" << std::endl;
        new_time_step.insert(std::pair<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>>(inputs_to_next_gate,next_component));

        // Check whether the user wants to append any more inputs
        if (number_of_prev_outputs != 0) {
            std::cout << "\nYou have " << number_of_prev_outputs << " idle outputs left from the previous timestep. Decide what happens to them:" << std::endl << std::endl;
        }
        else {
            add_component = terminate_timestep();
        }
    }
    // Visually display timestep
    print_timestep(new_time_step, time_step);
    time_step++;
    this_step = new_time_step;
    return new_time_step;
}

int timestep::choose_unary_component()
{
    int user_choice;
    bool valid_data{false};
    std::cout << "\nWhich unary gate would you like to add?" << std::endl
    << "\t1. NOT" << std::endl
    << "\t2. Buffer" << std::endl;
    while (valid_data == false) {
        try {
            std::cout << "Enter option: ";
            std::cin >> user_choice;
            if (std::cin.fail()) {throw type_error;}
            else if (user_choice < 1 || user_choice > 2) {throw value_error;}
            else {valid_data = true;}
        }
        catch (int error) {
            if (error == type_error) {std::cerr << "You have not entered an integer. Please enter a number corresponding to one of the options." << std::endl;}
            else if (error == value_error) {std::cerr << "Your choice if out of the range. Please enter a number corresponding to one of the options." << std::endl;}
            std::cin.clear();
            std::cin.ignore();
            valid_data = false;
        }
    }
    return user_choice;
}

int timestep::choose_binary_component()
{
    int user_choice{};
    bool valid_data{false};
    std::cout << "\nWhich binary gate would you like to add?" << std::endl
    << "\t1. AND" << std::endl
    << "\t2. OR" << std::endl
    << "\t3. NAND" << std::endl
    << "\t4. XOR" << std::endl
    << "\t5. XNOR" << std::endl
    << "\t6. NOR" << std::endl;
    while (valid_data == false) {
        try {
            std::cout << "Enter option: ";
            std::cin >> user_choice;
            if (std::cin.fail()) {throw type_error;}
            else if (user_choice < 1 || user_choice > 6) {throw value_error;}
            else {valid_data = true;}
        }
        catch (int error) {
            if (error == type_error) {std::cerr << "You have not entered an integer. Please enter a number corresponding to one of the options." << std::endl;}
            else if (error == value_error) {std::cerr << "Your choice if out of the range. Please enter a number corresponding to one of the options." << std::endl;}
            std::cin.clear();
            std::cin.ignore();
            valid_data = false;
        }
    }
    return user_choice;
}

std::shared_ptr<IN> timestep::add_circuit_input(int t, std::vector<std::shared_ptr<IN>>& circuit_ins_vector, std::vector<std::shared_ptr<components>>& gate_ins)
{
    std::shared_ptr<IN> new_input{std::make_shared<IN>(t, choose_input_name(circuit_ins_vector))};
    circuit_ins_vector.emplace_back(new_input);
    gate_ins.emplace_back(new_input);
    return new_input;
}

void timestep::print_timestep(std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>>& step, int& t)
{
    std::string empty{"           "};
    std::cout << "\n|    TIMESTEP   (" << t << ")   |" << std::endl
    << "|---------------------|" << std::endl;
    for (std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>>::const_iterator it = step.begin(); it != step.end(); ++it) {
        if (it->first.size() == 1) {
            std::cout << "|  " << it->first[0]->get_symbol() << ' ' << it->second->get_symbol() << "  |" << std::endl;
        }
        else if (it->first.size() == 2) {
            std::cout << "|  " << it->first[0]->get_symbol() << empty << "|" << std::endl
            << '|' << empty << it->second->get_symbol() << "  |" << std::endl
            << "|  " << it->first[1]->get_symbol() << empty << "|" << std::endl;
        }
    }
    std::cout << std::endl;
}