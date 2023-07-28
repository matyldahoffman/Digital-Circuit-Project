#include<string>

#ifndef COMPONENTS_H
#define COMPONENTS_H

class components
{
    protected:
        int input_number{};
    public:
        components() {};
        virtual std::string get_gate_name() = 0;
        virtual int logic_operation() = 0;
        virtual std::string get_symbol() = 0;
        virtual void set_input(int i) = 0;
        virtual void set_input_A(int i) = 0;
        virtual void set_input_B(int i) = 0;
        virtual ~components() {};

};

// Unary components have one input e.g. NOT gate
class unaryComponents : public components
{
    public:
    unaryComponents() {input_number = 1;}
    void set_input_A(int i) {};
    void set_input_B(int i) {};
    ~unaryComponents() {};
};

// Binary components have two inputs e.g. AND gate
class binaryComponents : public components
{
    public:
        binaryComponents() {input_number = 2;}
        void set_input(int i) {};
        ~binaryComponents() {};
};

// Single input gates

class IN : public unaryComponents
{
    private:
        std::string gate_name{};
        int time_step{};
        int input{};
    public:
        IN() {};
        IN(int t, std::string label);
        std::string get_gate_name();
        int logic_operation();
        void set_input(int i);
        std::string get_symbol();
        ~IN() {};
};


class NOT : public unaryComponents
{
    private:
        std::string gate_name{"NOT"};
        int input{};
    public:
        NOT() {};
        NOT(int in);
        std::string get_gate_name();
        int logic_operation();
        std::string get_symbol();
        void set_input(int i);
        ~NOT() {}
};

class buffer : public unaryComponents
{
    private:
        std::string gate_name{"BUFFER"};
        int input{};
    public:
        buffer() {};
        buffer(int in);
        std::string get_gate_name();
        int logic_operation();
        std::string get_symbol();
        void set_input(int i);
        ~buffer() {};
};

// Double input components

class AND : public binaryComponents
{
    private:
        std::string gate_name{"AND"};
        int A{};
        int B{};
    public:
        AND() {};
        AND(int a, int b);
        std::string get_gate_name();
        int logic_operation();
        std::string get_symbol();
        void set_input_A(int i);
        void set_input_B(int i);
        ~AND() {};
};

class OR : public binaryComponents
{
    private:
        std::string gate_name{"OR"};
        int A{};
        int B{};
    public:
        OR() {};
        OR(int a, int b);
        std::string get_gate_name();
        int logic_operation();
        std::string get_symbol();
        void set_input_A(int i);
        void set_input_B(int i);
        ~OR() {};
};

class NAND : public binaryComponents
{
    private:
        std::string gate_name{"NAND"};
        int A{};
        int B{};
    public:
        NAND() {};
        NAND(int a, int b);
        std::string get_gate_name();
        int logic_operation();
        std::string get_symbol();
        void set_input_A(int i);
        void set_input_B(int i);
        ~NAND() {};
};

class NOR : public binaryComponents
{
    private:
        std::string gate_name{"NOR"};
        int A{};
        int B{};
    public:
        NOR() {};
        NOR(int a, int b);
        std::string get_gate_name();
        int logic_operation();
        std::string get_symbol();
        void set_input_A(int i);
        void set_input_B(int i);
        ~NOR() {};
};

class XOR : public binaryComponents
{
    private:
        std::string gate_name{"XOR"};
        int A{};
        int B{};
    public:
        XOR() {};
        XOR(int a, int b);
        std::string get_gate_name();
        int logic_operation();
        std::string get_symbol();
        void set_input_A(int i);
        void set_input_B(int i);
        ~XOR() {};
};

class XNOR : public binaryComponents
{
    private:
        std::string gate_name{"XNOR"};
        int A{};
        int B{};
    public:
        XNOR() {};
        XNOR(int a, int b);
        std::string get_gate_name();
        int logic_operation();
        std::string get_symbol();
        void set_input_A(int i);
        void set_input_B(int i);
        ~XNOR() {};
};

#endif