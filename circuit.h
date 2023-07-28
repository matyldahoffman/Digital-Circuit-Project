#include<iostream>
#include<vector>
#include<map>
#include<memory>
#include<string>

#include "components.h"
#include "interface.h"
#include "timesteps.h"

#ifndef CIRCUIT_H
#define CIRCUIT_H

class circuit
{
    private:
        std::vector<std::unique_ptr<timestep>> compiled_circuit{};
        std::vector<std::shared_ptr<IN>> circuit_inputs{};
        int steps_number{};
        int output{};

    public:
        circuit() {};
        std::vector<std::unique_ptr<timestep>>& get_circuit();
        std::unique_ptr<timestep> create_first_step();
        std::unique_ptr<timestep> create_new_step();
        void build_circuit();
        int logic_output(std::vector<int>& input_set);
        void truth_table();
       
        ~circuit() {};
};

void generate_combinations(int n, std::vector<int> combos, int i, std::vector<std::vector<int>>& all);

#endif