#pragma once
#define EPSILON ' '

class State; // Forward declaration

class Transition
{
public:
    Transition(State *from, State *to, char input);
    Transition(State *from, State *to);

    const State *get_from();
    const State *get_to();
    const char get_input();

private:
    const State *from;
    const State *to;
    const char input;
};
