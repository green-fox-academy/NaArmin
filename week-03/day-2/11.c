#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
	char command[256];
    char logged_in = 0;
    char registered = 0;

    //TODO: write a register-login-logout program
    //if you type in register print out "Registration..." or "You are already registered." if you are registered.
	//you are able to log in, if you are already registered, otherwise not. In that case print out "You are not registered.".
    //if you type in login print out "Logging in..." or "Already logged in." if are logged in.
    //if you type in logout print out "Logging out..." or "Already logged out." if are logged out.
	puts("Hi! You can type 'register' or 'login' or 'logout'. And 'exit'.");
	gets(&command);
	while (strcmp(strlwr(command), "exit") != 0) {
        if (strcmp(command, "register") == 0) {
            if (registered) {
                puts("You are already registered.");
            } else {
                registered = 1;
                puts("Registration...");
            }
        }
        if (strcmp(command, "login") == 0 && registered) {
            if (logged_in) {
                puts("You are already logged in.");
            } else {
                logged_in = 1;
                puts("Logging in...");
            }
        }
        if (strcmp(command, "login") == 0 && (!registered))
            puts("You are not registered.");
        if (strcmp(command, "logout") == 0 && registered) {
            if (!logged_in) {
                puts("You are already logged out.");
            } else {
                logged_in = 0;
                puts("Logging out...");
            }
        }
        if (strcmp(command, "logout") == 0 && (!registered))
            puts("You are not registered.");
    gets(&command);
	}
}

