#include<stdio.h>
#include<string.h>




typedef struct {
    int flightNumber;
    char destination[50];
    char departureTime[10];
    int availableSeats;
} flight ;

flight flights[100];
int flightCount = 0;

// Function Declaration
void addFlight();
void viewFlight();
void deleteFlight();
void searchFlight();

int main(){
    int choice;

    do {
        printf("\n***** Airport Management System *****\n");
        printf("1. Add Flight\n");
        printf("2. View All Flights\n");
        printf("3. Delete Flight\n");
        printf("4. Search Flight\n");   
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);


        switch(choice){
            case 1: 
                addFlight();
                break;
            case 2:
                viewFlight();
                break;
            case 3: 
                deleteFlight();
                break;
            case 4:
                searchFlight();
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");

        }
    }while(choice!=5);

return 0;
}

void addFlight(){
    if(flightCount>=100){
        printf("Flight list is full!\n");
        return;
    }

    printf("Enter Flight Number: ");
    scanf("%d", &flights[flightCount].flightNumber);

    printf("Enter Destination: ");
    scanf("%s", &flights[flightCount].destination);

    printf("Enter departure time (e.g . 14:30): ");
    scanf("%s", &flights[flightCount].departureTime);

    printf("Enter available seats: ");
    scanf("%d", &flights[flightCount].availableSeats);

    flightCount++;
    printf("Flight added successfully!\n");
}

void viewFlight() {
    if (flightCount ==  0){
        printf("No Flights available!\n");
        return;
    }

    printf("\n----- Flight List -----\n");
    for (int i = 0; i <flightCount; i++){
        printf("Flight #%d\n", i + 1);
        printf("  Flight Number: %d\n", flights[i].flightNumber);
        printf("  Destination: %s\n", flights[i].destination);
        printf("  Departure Time: %s\n", flights[i].departureTime);
        printf("  Available Seats: %d\n", flights[i].availableSeats);
    }
}

void deleteFlight(){
     if (flightCount ==  0){
        printf("No Flights to delete.\n");
        return;
    }

    int index;
    printf("Enter flight number to delete: \n");
    int flightNum;
    scanf("%d", &flightNum);

    int found = 0;
    for (int  i = 0; i<flightCount; i++){
        if(flights[i].flightNumber == flightNum) {
           // Shift LEft
            for (int j = i; j < flightCount-1; j++){
                flights[j]= flights[j + 1];
            }
            flightCount--;
            found  = 1;
            printf("Flight deleted successfully!\n");
            break;
        }
    }
    if(!found){
        printf("Flight not found!\n");
    }
}// Function Declaration


void searchFlight() {
    if (flightCount == 0) {
        printf("No Flights available to search!\n");
        return;
    }

    int flightNum;
    printf("Enter flight number to search: ");
    scanf("%d", &flightNum);

    int found = 0;
    for (int i = 0; i < flightCount; i++) {
        if (flights[i].flightNumber == flightNum) {
            printf("\n--- Flight Found ---\n");
            printf("  Flight Number: %d\n", flights[i].flightNumber);
            printf("  Destination: %s\n", flights[i].destination);
            printf("  Departure Time: %s\n", flights[i].departureTime);
            printf("  Available Seats: %d\n", flights[i].availableSeats);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Flight not found!\n");
    }
}


