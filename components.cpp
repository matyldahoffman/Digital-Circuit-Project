#include "components.h"

// IN functions
IN::IN(int t, std::string label) : time_step{t}, gate_name{label} {};
std::string IN::get_gate_name() {return gate_name;}
int IN::logic_operation() {return input;}
void IN::set_input(int i) {input = i;}
std::string IN::get_symbol() {return gate_name+"-------";}

// NOT functions
NOT::NOT(int in) : input{in} {};
std::string NOT::get_gate_name() {return gate_name;}
int NOT::logic_operation()
{
    if (input == 1) {return 0;}
    else {return 1;}
}
std::string NOT::get_symbol() {return "--NOT---";}
void NOT::set_input(int i) {input = i;}

// buffer functions
buffer::buffer(int in) : input{in} {};
std::string buffer::get_gate_name() {return gate_name;}
int buffer::logic_operation() {return input;}
std::string buffer::get_symbol() {return "--------";}
void buffer::set_input(int i) {input = i;}

// AND functions
AND::AND(int a, int b) : A{a}, B{b} {};
std::string AND::get_gate_name() {return gate_name;}
int AND::logic_operation() {
    if (A == 1 && B == 1) {return 1;}
    else {return 0;}
}
std::string AND::get_symbol() {return "+-AND---";}
void AND::set_input_A(int i) {A = i;}
void AND::set_input_B(int i) {B = i;}

// OR functions
OR::OR(int a, int b) : A{a}, B{b} {};
std::string OR::get_gate_name() {return gate_name;}
int OR::logic_operation() {
    if (A == 1 || B ==1) {return 1;}
    else {return 0;}
}
std::string OR::get_symbol() {return "+-OR----";}
void OR::set_input_A(int i) {A = i;}
void OR::set_input_B(int i) {B = i;}

//NAND functions
NAND::NAND(int a, int b) : A{a}, B{b} {};
std::string NAND::get_gate_name() {return gate_name;}
int NAND::logic_operation() {
    if (A == 1 && B == 1) {return 0;}
    else {return 1;}
}
std::string NAND::get_symbol() {return "+-NAND--";}
void NAND::set_input_A(int i) {A = i;}
void NAND::set_input_B(int i) {B = i;}

// NOR functions
NOR::NOR(int a, int b) : A{a}, B{b} {};
std::string NOR::get_gate_name() {return gate_name;}
int NOR::logic_operation() {
    if (A == 0 && B == 0) {return 1;}
    else {return 0;}
}
std::string NOR::get_symbol() {return "+-NOR---";}
void NOR::set_input_A(int i) {A = i;}
void NOR::set_input_B(int i) {B = i;}

// XOR functions
XOR::XOR(int a, int b) : A{a}, B{b} {};
std::string XOR::get_gate_name() {return gate_name;}
int XOR::logic_operation() {
    if (A == B) {return 0;}
    else {return 1;}
}
std::string XOR::get_symbol() {return "+-XOR---";}
void XOR::set_input_A(int i) {A = i;}
void XOR::set_input_B(int i) {B = i;}

// XNOR functions
XNOR::XNOR(int a, int b) : A{a}, B{b} {};
std::string XNOR::get_gate_name() {return gate_name;}
int XNOR::logic_operation() {
    if (A == B) {return 1;}
    else {return 0;}
}
std::string XNOR::get_symbol() {return "+-XNOR--";}
void XNOR::set_input_A(int i) {A = i;}
void XNOR::set_input_B(int i) {B = i;}