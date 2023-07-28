#include "components.h"
#include "interface.h"
#include "timesteps.h"
#include "circuit.h"

std::vector<std::unique_ptr<timestep>>& circuit::get_circuit() {return compiled_circuit;}

std::unique_ptr<timestep> circuit::create_first_step(){
    std::unique_ptr<timestep> new_step{std::make_unique<timestep>(steps_number)};
    steps_number = 1;
    new_step->create_first_step(steps_number, circuit_inputs);
    return new_step;
}

std::unique_ptr<timestep> circuit::create_new_step() {
    steps_number++;
    std::unique_ptr<timestep> new_step{std::make_unique<timestep>(steps_number)};
    size_t circuit_size(compiled_circuit.size());
    new_step->create_step(compiled_circuit[circuit_size-1]->get_step(), steps_number, circuit_inputs);
    return new_step;
}

// Function to propagate logic through the circuit
int circuit::logic_output(std::vector<int>& input_set)
{
    // Set input values for all inputs
    for (size_t i{}; i < input_set.size(); i++) {
        circuit_inputs[i]->set_input(input_set[i]);
    }
    // iterate through the vector of timesteps - compiled_circuit
    for (auto& it : compiled_circuit) {
        std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>> t{it->get_step()};
        //From the timestep get each map and pass result of logical operation from first gates to second
        for (std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>>::const_iterator t_i = t.begin(); t_i != t.end(); ++t_i) {
            if (t_i->second->get_gate_name() == "IN" || t_i->second->get_gate_name() == "NOT" || t_i->second->get_gate_name() == "BUFFER") {
                t_i->second->set_input(t_i->first[0]->logic_operation());
            }
            else {
                t_i->second->set_input_A(t_i->first[0]->logic_operation());
                t_i->second->set_input_B(t_i->first[1]->logic_operation());
            }
            if (t.size() == 1) {output = t_i->second->logic_operation();}
        }
    }
    return output;
}

// Recursive function to generate all combinations of binary input for any number of inputs
void generate_combinations(int n, std::vector<int> combos, int i, std::vector<std::vector<int>>& all)
{
	if (i == n) {
        all.push_back(combos);
		return;
	}
	combos[i] = 0;
	generate_combinations(n, combos, i + 1, all);
	combos[i] = 1;
	generate_combinations(n, combos, i + 1, all);
}

void circuit::truth_table()
{
    // generate and store all possible inputs
    const int length{static_cast<int>(circuit_inputs.size())};
    std::vector<std::vector<int>> all_combinations{};
    std::vector<int> combinations(length);
	generate_combinations(length, combinations, 0, all_combinations);

    std::cout << "\n * TRUTH TABLE * " << std::endl << std::endl;
    for (std::shared_ptr<IN> names : circuit_inputs) {
        std::cout << "| " << names->get_gate_name();
    }
    std::cout << "| OUTPUT |" << std::endl;

    for(std::vector<int> set : all_combinations) {
        int circuit_output{logic_output(set)};
        for (int i : set) {
            std::cout << "| " << i;
        }
        std::cout << "|   " << circuit_output << "    |" << std::endl;
    }
}

void circuit::build_circuit()
{
    //create first timestep
    compiled_circuit.push_back(create_first_step());

    //Continue building the circuit
    bool build{true};
    while (build == true) {
        compiled_circuit.push_back(create_new_step());
        size_t circuit_size(compiled_circuit.size());
        if (compiled_circuit[circuit_size-1]->get_step().size() == 1) {
            build = terminate_circuit();
        }
    }
}