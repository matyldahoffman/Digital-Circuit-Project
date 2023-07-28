#include<iostream>
#include<vector>
#include<map>
#include<memory>
#include<string>
#include "components.h"
#include "interface.h"

#ifndef TIMESTEPS_H
#define TIMESTEPS_H

class timestep
{
    private:
        std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>> this_step{};
        int step_number{};
    public:
        timestep() {};
        timestep(int n) : step_number{n} {};
        std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>> create_first_step(int& time_step, std::vector<std::shared_ptr<IN>>& circuit_ins);
        std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>> create_step(const std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>>& prev_time_step, int& time_step, std::vector<std::shared_ptr<IN>>& circuit_ins);
        int choose_unary_component();
        int choose_binary_component();

        template<class T>
        std::shared_ptr<T> add_unary_component(std::vector<std::shared_ptr<components>>& in)
        {
            int out{in[0]->logic_operation()};
            std::shared_ptr<T> new_component{std::make_shared<T>(out)};
            return new_component;
        }

        template<class T>
        std::shared_ptr<T> add_binary_component(std::vector<std::shared_ptr<components>>& in)
        {
            int out{in[0]->logic_operation()};
            int out_2{in[1]->logic_operation()};
            std::shared_ptr<T> new_component{std::make_shared<T>(out,out_2)};
            return new_component;
        }

        std::shared_ptr<IN> add_circuit_input(int t, std::vector<std::shared_ptr<IN>>& ins_vector, std::vector<std::shared_ptr<components>>& gate_ins);
        void print_timestep(std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>>& step, int& t);

        std::map<std::vector<std::shared_ptr<components>>,std::shared_ptr<components>> get_step() {return this_step;}

        ~timestep() {};
};

#endif