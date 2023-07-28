#include<iostream>
#include<vector>
#include<map>
#include<memory>

#include "components.h"


#ifndef INTERFACE_H
#define INTERFACE_H

// error types
const int type_error(-1); 
const int value_error(-2);
const int repeat_error(-3);


void print_instructions();
void print_particular_table(int gate);
void print_truth_tables();
int option_menu();
bool terminate_circuit();
int add_another_primary_input();
std::string choose_output(std::vector<std::string>& options, int& output_no);
int choose_gate_type();
int choose_old_new_input();
std::shared_ptr<IN> choose_circuit_input(std::vector<std::shared_ptr<IN>>& input_choices);
int choose_input_gate();
std::string choose_input_name(std::vector<std::shared_ptr<IN>>& ins_names);
bool terminate_timestep();

#endif