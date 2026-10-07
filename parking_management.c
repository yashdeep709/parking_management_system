#include<stdio.h>
#include<string.h>

int main() {

    char twoWheeler[25][20];
    char fourWheeler[25][20];

    int twoCount = 0;
    int fourCount = 0;

    int choice, type;
    char number[20];
    int found;

    while (1) {

        printf("\n===== PARKING MANAGEMENT SYSTEM =====\n");
        printf("1. Park Vehicle\n");
        printf("2. Remove Parked Vehicle\n");
        printf("3. Search Parked Vehicle\n");
        printf("4. Display Parked Vehicles\n");
        printf("5. Available Slots for Parking\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        /* Park Vehicle */
        if (choice == 1) {

            printf("\nEnter Vehicle Type:\n");
            printf("1. Two Wheeler\n");
            printf("2. Four Wheeler\n");
            printf("Enter type: ");
            scanf("%d", &type);

            if (type != 1 && type != 2) {
                printf("Invalid vehicle type!\n");
                continue;
            }

            printf("\nEnter Vehicle Number: ");
            scanf("%19s", number);

            found = 0;

            /* Check duplicate in Two Wheeler */
            for (int i = 0; i < twoCount; i++) {

                if (strcmp(twoWheeler[i], number) == 0) {
                    found = 1;
                    break;
                }
            }

            /* Check duplicate in Four Wheeler */
            if (found == 0) {

                for (int i = 0; i < fourCount; i++) {

                    if (strcmp(fourWheeler[i], number) == 0) {
                        found = 1;
                        break;
                    }
                }
            }

            if (found == 1) {
                printf("Vehicle already parked!\n");
            }

            /* Park Two Wheeler */
            else if (type == 1) {

                if (twoCount == 25) {
                    printf("Two Wheeler Parking Full!\n");
                }
                else {
                    strcpy(twoWheeler[twoCount], number);
                    twoCount++;

                    printf("Vehicle parked at Slot %d\n", twoCount);
                }
            }

            /* Park Four Wheeler */
            else {

                if (fourCount == 25) {
                    printf("Four Wheeler Parking Full!\n");
                }
                else {
                    strcpy(fourWheeler[fourCount], number);
                    fourCount++;

                    printf("Vehicle parked at Slot %d\n", fourCount);
                }
            }
        }

        /* Remove Vehicle */
        else if (choice == 2) {

            printf("\nEnter Vehicle Type:\n");
            printf("1. Two Wheeler\n");
            printf("2. Four Wheeler\n");
            printf("Enter type: ");
            scanf("%d", &type);

            if (type != 1 && type != 2) {
                printf("Invalid vehicle type!\n");
                continue;
            }

            printf("\nEnter Vehicle Number: ");
            scanf("%19s", number);

            found = 0;

            /* Remove Two Wheeler */
            if (type == 1) {

                for (int i = 0; i < twoCount; i++) {

                    if (strcmp(twoWheeler[i], number) == 0) {

                        printf("Vehicle removed from Slot %d\n", i + 1);

                        twoWheeler[i][0] = '\0';

                        found = 1;
                        break;
                    }
                }
            }

            /* Remove Four Wheeler */
            else {

                for (int i = 0; i < fourCount; i++) {

                    if (strcmp(fourWheeler[i], number) == 0) {

                        printf("Vehicle removed from Slot %d\n", i + 1);

                        fourWheeler[i][0] = '\0';

                        found = 1;
                        break;
                    }
                }
            }

            if (found == 0) {
                printf("Vehicle not found!\n");
            }
        }

        /* Search Vehicle */
        else if (choice == 3) {

            printf("\nEnter Vehicle Number: ");
            scanf("%19s", number);

            found = 0;

            /* Search Two Wheeler */
            for (int i = 0; i < twoCount; i++) {

                if (strcmp(twoWheeler[i], number) == 0) {

                    printf("Vehicle found in Two Wheeler Parking at Slot %d\n",
                           i + 1);

                    found = 1;
                    break;
                }
            }

            /* Search Four Wheeler */
            if (found == 0) {

                for (int i = 0; i < fourCount; i++) {

                    if (strcmp(fourWheeler[i], number) == 0) {

                        printf("Vehicle found in Four Wheeler Parking at Slot %d\n",
                               i + 1);

                        found = 1;
                        break;
                    }
                }
            }

            if (found == 0) {
                printf("Vehicle not found!\n");
            }
        }

        /* Display Vehicles */
        else if (choice == 4) {

            printf("\n================ PARKED VEHICLES ================\n");

            printf("%-10s %-20s %-15s\n",
                   "Slot", "Vehicle Type", "Vehicle Number");

            printf("--------------------------------------------------\n");

            found = 0;

            /* Display Two Wheelers */
            for (int i = 0; i < twoCount; i++) {

                if (twoWheeler[i][0] != '\0') {

                    printf("%-10d %-20s %-15s\n",
                           i + 1,
                           "Two Wheeler",
                           twoWheeler[i]);

                    found = 1;
                }
            }

            /* Display Four Wheelers */
            for (int i = 0; i < fourCount; i++) {

                if (fourWheeler[i][0] != '\0') {

                    printf("%-10d %-20s %-15s\n",
                           i + 1,
                           "Four Wheeler",
                           fourWheeler[i]);

                    found = 1;
                }
            }

            if (found == 0) {
                printf("No vehicles parked.\n");
            }

            printf("--------------------------------------------------\n");
        }

        /* Available Slots */
        else if (choice == 5) {

            int twoAvailable = 25 - twoCount;
            int fourAvailable = 25 - fourCount;

            printf("\nTwo Wheeler Total Slots     : 25\n");
            printf("Two Wheeler Occupied Slots  : %d\n", twoCount);
            printf("Two Wheeler Available Slots : %d\n",
                   twoAvailable);

            printf("\nFour Wheeler Total Slots     : 25\n");
            printf("Four Wheeler Occupied Slots  : %d\n", fourCount);
            printf("Four Wheeler Available Slots : %d\n",
                   fourAvailable);

            printf("\nTotal Slots     : 50\n");
            printf("Occupied Slots  : %d\n",
                   twoCount + fourCount);
            printf("Available Slots : %d\n",
                   twoAvailable + fourAvailable);
        }

        /* Exit */
        else if (choice == 6) {

            printf("\nThank you!\n");
            break;
        }

        else {
            printf("\nInvalid choice!\n");
        }
    }

    return 0;
}