COE428 Lab 4: State Machine Simulator
This C program, simState, simulates a configurable finite state machine. 
It handles binary transitions, dynamic reconfigurations, and reachability analysis.


Commands

0 / 1: Moves to the next state and prints its name.

c <0|1> <State>: Changes the transition logic for the current state.

p: Prints the current state machine configuration.

g: Identifies "garbage" (unreachable states) from the current position.

d or d [State]: Deletes specific or all unreachable states.

Setup: 
Use make to build the executable. 

Format: States are defined as <StateName> <NextState0> <NextState1>.
