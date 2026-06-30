#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 3
#define TOTAL_SEATS 20


typedef struct {
    int id;
    char title[50];
    float price;
    int seats[TOTAL_SEATS]; 
} Movie;


void displayMenu();
void viewShows(Movie movies[]);
void bookTicket(Movie movies[]);
void cancelTicket(Movie movies[]);

int main() {
    
    Movie movies[MAX_MOVIES] = {
        {1, "Inception", 12.50, {0}},
        {2, "Interstellar", 15.00, {0}},
        {3, "The Dark Knight", 10.00, {0}}
    };

    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1:
                viewShows(movies);
                break;
            case 2:
                bookTicket(movies);
                break;
            case 3:
                cancelTicket(movies);
                break;
            case 4:
                printf("\nThank you for using the Ticket Booking System!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}


void displayMenu() {
    printf("\n=================================");
    printf("\n    TICKET BOOKING SYSTEM        ");
    printf("\n=================================");
    printf("\n1. View Available Shows");
    printf("\n2. Book a Ticket");
    printf("\n3. Cancel a Ticket");
    printf("\n4. Exit");
    printf("\n=================================\n");
}


void viewShows(Movie movies[]) {
    printf("\n--- Available Shows & Seat Maps ---\n");
    for (int i = 0; i < MAX_MOVIES; i++) {
        printf("\n[%d] Movie: %s | Price: $%.2f\n", movies[i].id, movies[i].title, movies[i].price);
        printf("Seats Map:\n");
        
        for (int j = 0; j < TOTAL_SEATS; j++) {
            
            if (movies[i].seats[j] == 1) {
                printf("[ X ] ");
            } else {
                printf("[%02d] ", j + 1);
            }
            
            if ((j + 1) % 5 == 0) {
                printf("\n");
            }
        }
    }
}


void bookTicket(Movie movies[]) {
    int movieChoice, seatNumber;
    
    printf("\nEnter Movie ID (1-%d): ", MAX_MOVIES);
    scanf("%d", &movieChoice);
    
    if (movieChoice < 1 || movieChoice > MAX_MOVIES) {
        printf("Invalid Movie ID!\n");
        return;
    }
    
    
    int mIdx = movieChoice - 1;
    
    printf("Enter Seat Number (1-%d) to reserve: ", TOTAL_SEATS);
    scanf("%d", &seatNumber);
    
    if (seatNumber < 1 || seatNumber > TOTAL_SEATS) {
        printf("Invalid Seat Number!\n");
        return;
    }
    
    int sIdx = seatNumber - 1;
    
    
    if (movies[mIdx].seats[sIdx] == 1) {
        printf("Sorry, Seat %d is already booked.\n", seatNumber);
    } else {
        movies[mIdx].seats[sIdx] = 1;
        printf("\n Success! Seat %d booked for '%s'.\n", seatNumber, movies[mIdx].title);
        printf("Total Amount Due: $%.2f\n", movies[mIdx].price);
    }
}


void cancelTicket(Movie movies[]) {
    int movieChoice, seatNumber;
    
    printf("\nEnter Movie ID (1-%d): ", MAX_MOVIES);
    scanf("%d", &movieChoice);
    
    if (movieChoice < 1 || movieChoice > MAX_MOVIES) {
        printf("Invalid Movie ID!\n");
        return;
    }
    
    int mIdx = movieChoice - 1;
    
    printf("Enter your Booked Seat Number (1-%d) to cancel: ", TOTAL_SEATS);
    scanf("%d", &seatNumber);
    
    if (seatNumber < 1 || seatNumber > TOTAL_SEATS) {
        printf("Invalid Seat Number!\n");
        return;
    }
    
    int sIdx = seatNumber - 1;
    
    
    if (movies[mIdx].seats[sIdx] == 0) {
        printf("This seat is not currently booked.\n");
    } else {
        movies[mIdx].seats[sIdx] = 0;
        printf("\n Success! Booking for Seat %d has been canceled.\n", seatNumber);
    }
}
