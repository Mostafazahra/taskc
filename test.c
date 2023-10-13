 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  numbusers 100
#define  user_max 20
#define  password_max 20

typedef struct {
    char username[user_max];
    char password[password_max];
} User;

User users[numbusers];
int numUsers = 0;

int login();
void registerUser();
int validateCredentials(const char* username, const char* password);

//function for login

int login() {
    char username[user_max];
    char password[password_max];
    
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    
    return validateCredentials(username, password);
}





//function for register

void registerUser() {
    if (numUsers ==  numbusers) {
        printf("Maximum number of users reached\n");
        return;
    }
    
    User newUser;
    
    printf("Enter a username: ");
    scanf("%s", newUser.username);
    
    // Check if the username already exists
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already exists\n");
            return;
        }
    }
    
    printf("Enter a password: ");
    scanf("%s", newUser.password);
    
    users[numUsers++] = newUser;
}





int validateCredentials(const char* username, const char* password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; // Valid credentials
        }
    }
    
    return 0; // Invalid credentials
}

int main() {
    int choice;
    int loggedIn = 0;
    
    while (1) {
       
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                loggedIn = login();
                if (loggedIn) {
                    printf("Login successful!\n");
                    // Perform actions after successful login
                } else {
                    printf("Invalid username or password\n");
                }
                break;
            case 2:
                registerUser();
                printf("Registration successful!\n");
                break;
            case 3:
                printf("Exiting the program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    
    return 0;
}


