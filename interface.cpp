#include "interface.h"
#include "components.h"

void print_instructions()
{
    std::cout << std::endl;
    std::cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " << std::endl
              << " *                                  DIGITAL CIRCUIT SIMULATOR                                              * " << std::endl
              << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " << std::endl
              << " *                                                                                                         * " << std::endl
              << " *    BUILDING YOUR OWN CIRCUIT - METHOD                                                                   * " << std::endl
              << " *                                                                                                         * " << std::endl
              << " *    Method uses timesteps which correspond to a set of simultaneous logic operations. They are created   * " << std::endl
              << " *    one-by-one by the user. Within each timestep you can access previous circuit inputs, as well as add  * " << std::endl
              << " *    completely new inputs to the circuit.                                                                * " << std::endl
              << " *                                                                                                         * " << std::endl 
              << " *    First Timestep                                                                                       * " << std::endl
              << " *    1. Create a circuit input                                                                            * " << std::endl
              << " *    2. Choose the type of gate to append                                                                 * " << std::endl
              << " *       If binary chosen then create another input to append to it                                        * " << std::endl
              << " *    3. Exit intial timestep or connect another logic gate to the inputs                                  * " << std::endl 
              << " *                                                                                                         * " << std::endl  
              << " *    Consecutive Timesteps                                                                                * " << std::endl 
              << " *    1. Choose an input to connect to out of:                                                             * " << std::endl
              << " *       - Previous outputs                                                                                * " << std::endl;
    std::cout << " *       - An existing circuit input                                                                       * " << std::endl
              << " *       - Create a new circuit input                                                                      * " << std::endl
              << " *    2. Choose a gate to connect                                                                          * " << std::endl
              << " *       If binary chosen then create another input to append to it                                        * " << std::endl
              << " *    3. Repeat these until all previous outputs are covered and you decide to start adding                * " << std::endl
              << " *       components in series                                                                              * " << std::endl
              << " *                                                                                                         * " << std::endl
              << " *    Circuit can only end when there is one conclusive output, hence the program will run until there     * " << std::endl
              << " *    are no idle outputs left.                                                                            * " << std::endl
              << " *                                                                                                         * " << std::endl
              << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " << std::endl << std::endl;
}

void print_particular_table(int gate)
{
    std::cout << std::endl;
    switch (gate) {
        case 1:
            std::cout << "| A | B |   AND  |" << std::endl
                      << "| 0 | 0 |    0   |" << std::endl
                      << "| 1 | 0 |    0   |" << std::endl
                      << "| 0 | 1 |    0   |" << std::endl
                      << "| 1 | 1 |    1   |" << std::endl;
            break;
        case 2:
            std::cout << "| A | B |    OR  |" << std::endl
                      << "| 0 | 0 |    0   |" << std::endl
                      << "| 1 | 0 |    1   |" << std::endl
                      << "| 0 | 1 |    1   |" << std::endl
                      << "| 1 | 1 |    1   |" << std::endl;
            break;
        case 3:
            std::cout << "| A | B |   NAND  |" << std::endl
                      << "| 0 | 0 |    1   |" << std::endl
                      << "| 1 | 0 |    1   |" << std::endl
                      << "| 0 | 1 |    1   |" << std::endl
                      << "| 1 | 1 |    0   |" << std::endl;
            break;
        case 4:
            std::cout << "| A | B |   NOR  |" << std::endl
                      << "| 0 | 0 |    1   |" << std::endl
                      << "| 1 | 0 |    0   |" << std::endl
                      << "| 0 | 1 |    0   |" << std::endl
                      << "| 1 | 1 |    0   |" << std::endl;
            break;
        case 5:
            std::cout << "| A | B |   XOR  |" << std::endl
                      << "| 0 | 0 |    0   |" << std::endl
                      << "| 1 | 0 |    1   |" << std::endl
                      << "| 0 | 1 |    1   |" << std::endl
                      << "| 1 | 1 |    0   |" << std::endl;
            break;
        case 6:
            std::cout << "| A | B |    OR  |" << std::endl
                      << "| 0 | 0 |    1   |" << std::endl
                      << "| 1 | 0 |    0   |" << std::endl
                      << "| 0 | 1 |    0   |" << std::endl
                      << "| 1 | 1 |    1   |" << std::endl;
            break;
        case 7:
            std::cout << "| A |   NOT  |" << std::endl
                      << "| 0 |    1   |" << std::endl
                      << "| 1 |    0   |" << std::endl;
            break;
        case 8:
            std::cout << "| A | BUFFER |" << std::endl
                      << "| 0 |    0   |" << std::endl
                      << "| 1 |    1   |" << std::endl;
            break;
        case 9:
            for (int i{}; i <= 8; i++) {
                print_particular_table(i);
            }
    }
}

void print_truth_tables()
{
    int user_choice;
    bool valid_data{false};
    std::cout << "\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " << std::endl << std::endl; 
    std::cout << "Which component's truth table would you like to look at?" << std::endl
    << "\t1. AND" << std::endl
    << "\t2. OR" << std::endl
    << "\t3. NAND" << std::endl
    << "\t4. XOR" << std::endl
    << "\t5. XNOR" << std::endl
    << "\t6. NOR" << std::endl
    << "\t7. NOT" << std::endl
    << "\t8. BUFFER" << std::endl
    << "\t9. All the above" << std::endl;
    while (valid_data == false) {
        try {
            std::cout << "\nEnter option: ";
            std::cin >> user_choice;
            if (std::cin.fail()) {throw type_error;}
            else if (user_choice < 1 || user_choice > 9) {throw value_error;}
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
    print_particular_table(user_choice);
}

int option_menu()
{
    int user_choice;
    bool valid_data{false};
    std::cout << "\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " << std::endl << std::endl; 
    std::cout << "What would you like to do?" << std::endl
    << "\t1. Build a circuit" << std::endl
    << "\t2. Display the truth table for a particular logic gate" << std::endl
    << "\t3. Exit program" << std::endl;
    while (valid_data == false) {
        try {
            std::cout << "\nEnter option: ";
            std::cin >> user_choice;
            if (std::cin.fail()) {throw type_error;}
            else if (user_choice < 1 || user_choice > 3) {throw value_error;}
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

// Choose whether to add another timestep
bool terminate_circuit()
{
    int user_choice;
    bool valid_data{false};
    std::cout << "\nYou have a single output coming out of the circuit, therefore you may compute a definite logic operation."
    << "\nWould you like to terminate or add another component in series? (please type 1 or 2)" << std::endl
    << "\t1. Terminate circuit" << std::endl
    << "\t2. Add a step in series" << std::endl;
    while (valid_data == false) {
        try {
            std::cout << "Enter option: ";
            std::cin >> user_choice;
            if (std::cin.fail()) {throw type_error;}
            else if (user_choice < 1 || user_choice > 2) {throw value_error;}
            else {valid_data = true;}
        }
        catch (int error) {
            if (error == type_error) {std::cerr << "You have not entered an integer.\nPlease enter a number corresponding to one of the options." << std::endl;}
            else if (error == value_error) {std::cerr << "Your choice if out of the range.\nPlease enter a number corresponding to one of the options." << std::endl;}
            std::cin.clear();
            std::cin.ignore();
            valid_data = false;
        }
    }
    bool decision{};
    if (user_choice == 1) {decision = false;}
    else if (user_choice == 2) {decision = true;}
    return decision;   
}

// Check whether the user wants to add another input to their first timestep
int add_another_primary_input()
{
    int user_choice;
    bool valid_data{false};
    std::cout << "\nWwould you like to add another input to the circuit? (please type 1 or 2)" << std::endl
    << "\t1. Yes" << std::endl
    << "\t2. No" << std::endl;
    while (valid_data == false) {
        try {
            std::cout << "Enter option: ";
            std::cin >> user_choice;
            if (std::cin.fail()) {throw type_error;}
            else if (user_choice < 1 || user_choice > 2) {throw value_error;}
            else {valid_data = true;}
        }
        catch (int error) {
            if (error == type_error) {std::cerr << "You have not entered an integer.\nPlease enter a number corresponding to one of the options." << std::endl;}
            else if (error == value_error) {std::cerr << "Your choice if out of the range.\nPlease enter a number corresponding to one of the options." << std::endl;}
            std::cin.clear();
            std::cin.ignore();
            valid_data = false;
        }
    }
    return user_choice;   
}

// Choose which component output to connect to
std::string choose_output(std::vector<std::string>& options, int& output_no)
{
    std::vector<std::string>::iterator first_option(options.begin());
    std::vector<std::string>::iterator last_option(options.end());
    std::vector<std::string>::iterator opt;
    int i{1};
    std::cout << "\nWhich of these outputs would you like to connect?" << std::endl;
    for (opt = first_option; opt < last_option; ++opt) {
        std::cout << "\t" << i << ". " << *opt << std::endl;
        i++;
    }
    int user_choice;
    std::string choice_name;
    bool valid_data{false};
    while (valid_data == false) {
        try {
            std::cout << "Enter option: ";
            std::cin >> user_choice;
            if (std::cin.fail()) {throw type_error;}
            else if (user_choice < 1 || user_choice > options.size()) {throw value_error;}
            else {valid_data = true;}
        }
        catch (int error) {
            if (error == type_error) {std::cerr << "You have not entered an integer.\nPlease enter a number corresponding to one of the options." << std::endl;}
            else if (error == value_error) {std::cerr << "Your choice if out of the range.\nPlease enter a number corresponding to one of the options." << std::endl;}
            std::cin.clear();
            std::cin.ignore();
            valid_data = false;
        }
    }
    choice_name = options[user_choice-1];
    options.erase(options.begin()+(user_choice-1));
    output_no--;
    return choice_name;
}

// Choose whther to connect a unary or binary gate
int choose_gate_type()
{
    int user_choice;
    bool valid_data{false};
    std::cout << "\nWhat kind of gate would you like to connect to this output?" << std::endl
    << "\t1. Unary (1 input)" << std::endl
    << "\t2. Binary (2 inputs)" << std::endl;
    while (valid_data == false) {
        try {
            std::cout << "Enter option: ";
            std::cin >> user_choice;
            if (std::cin.fail()) {throw type_error;}
            else if (user_choice < 1 || user_choice > 2) {throw value_error;}
            else {valid_data = true;}
        }
        catch (int error) {
            if (error == type_error) {std::cerr << "You have not entered an integer.\nPlease enter a number corresponding to one of the options." << std::endl;}
            else if (error == value_error) {std::cerr << "Your choice if out of the range.\nPlease enter a number corresponding to one of the options." << std::endl;}
            std::cin.clear();
            std::cin.ignore();
            valid_data = false;
        }
    }
    return user_choice;
}

// If adding to input - choose whether to create a new circuit input or append to an old one
int choose_old_new_input() 
{
    int user_choice;
    bool valid_data{false};
    std::cout << "\nThere is not enough outputs left from the previous timestep :(. Please choose a circuit input to connect to:" << std::endl
    << "\t1. Existing circuit input" << std::endl
    << "\t2. Create new circuit input" << std::endl;
    while (valid_data == false) {
        try {
            std::cout << "Enter option: ";
            std::cin >> user_choice;
            if (std::cin.fail()) {throw type_error;}
            else if (user_choice < 1 || user_choice > 2) {throw value_error;}
            else {valid_data = true;}
        }
        catch (int error) {
            if (error == type_error) {std::cerr << "You have not entered an integer.\nPlease enter a number corresponding to one of the options." << std::endl;}
            else if (error == value_error) {std::cerr << "Your choice if out of the range.\nPlease enter a number corresponding to one of the options." << std::endl;}
            std::cin.clear();
            std::cin.ignore();
            valid_data = false;
        }
    }
    return user_choice;
}

// Lists all circuit inputs
std::shared_ptr<IN> choose_circuit_input(std::vector<std::shared_ptr<IN>>& input_choices)
{
    int user_choice;
    bool valid_data{false};
    std::cout << "\nWhich circuit input?" << std::endl;
    int i{1};
    for (std::vector<std::shared_ptr<IN>>::iterator it = input_choices.begin(); it != input_choices.end(); ++it) {
        std::cout << "\t" << i << ". Input " << (*it)->get_gate_name() << std::endl;
        i++;
    }
    while (valid_data == false) {
        try {
            std::cout << "Enter option: ";
            std::cin >> user_choice;
            if (std::cin.fail()) {throw type_error;}
            else if (user_choice < 1 || user_choice > input_choices.size()) {throw value_error;}
            else {valid_data = true;}
        }
        catch (int error) {
            if (error == type_error) {std::cerr << "You have not entered an integer.\nPlease enter a number corresponding to one of the options." << std::endl;}
            else if (error == value_error) {std::cerr << "Your choice if out of the range.\nPlease enter a number corresponding to one of the options." << std::endl;}
            std::cin.clear();
            std::cin.ignore();
            valid_data = false;
        }
    }
    std::shared_ptr new_input{input_choices[user_choice-1]};
    return new_input;
}

// Choose whether to connect to a previous output, new input or old input
int choose_input_gate() 
{
    int user_choice;
    bool valid_data{false};
    std::cout << "\nWould you like to connect to: " << std::endl
    << "\t1. Previous output" << std::endl
    << "\t2. Existing circuit input" << std::endl
    << "\t3. Create new circuit input" << std::endl;
    while (valid_data == false) {
        try {
            std::cout << "Enter option: ";
            std::cin >> user_choice;
            if (std::cin.fail()) {throw type_error;}
            else if (user_choice < 1 || user_choice > 3) {throw value_error;}
            else {valid_data = true;}
        }
        catch (int error) {
            if (error == type_error) {std::cerr << "You have not entered an integer.\nPlease enter a number corresponding to one of the options." << std::endl;}
            else if (error == value_error) {std::cerr << "Your choice if out of the range.\nPlease enter a number corresponding to one of the options." << std::endl;}
            std::cin.clear();
            std::cin.ignore();
            valid_data = false;
        }
    }
    return user_choice;
}

// Choose name for a new input
std::string choose_input_name(std::vector<std::shared_ptr<IN>>& ins_names)
{
    char label;
    std::string out;
    bool valid_data{false};
    while (valid_data == false) {
        std::cout << "\nLabel your new input with a letter (e.g. A, B, C ...): " << std::endl;
        try {
            std::cout << "Enter option: ";
            std::cin >> label;
            if (std::cin.fail()) {throw type_error;}

            // lambda function to format the input letter to string and uppercase
            auto lambda = [&label] () {
                std::string tmp_string(1, std::toupper(label));
                return tmp_string;
            };
            for (std::shared_ptr<IN> n : ins_names) {
                if (n->get_gate_name() == lambda()) {throw repeat_error;}
            }
            out = lambda();
            valid_data = true;
        }
        catch (int error) {
            if (error == type_error) {std::cerr << "You have entered an invalid label:(. Please enter a single LETTER." << std::endl;}
            else if (error == repeat_error) {std::cerr << "An input with that name already exists. Please choose again..." << std::endl;}
            std::cin.clear();
            std::cin.ignore();
            valid_data = false;
        }
    }
    return out;
}

// Function to terminate timestep if all previous outputs covered
bool terminate_timestep() 
{
    int user_choice;
    bool valid_data{false};
    std::cout << "\nYou have no more idle outputs left from the previous time step." << std::endl
    << "\t1. Terminate this timestep" << std::endl
    << "\t2. Connect another gate to input" << std::endl << std::endl;
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
    if (user_choice == 1) {return false;}
    else {return true;}
}
