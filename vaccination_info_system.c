/*
    @author - Bryan Jesus Mangapit
    @start - 05/23/2022

    | Project 'Vaccination Info System' w/ data structures integrated and file operations |
*/

#include <stdio.h>
#include <string.h>

struct Px_address {
    char houseNum[25];
    char street[25], barangay[25], city[25], province[25];
    char sex[5];
    char dateOfBirth[25];
    char vaxxManufacturer[25], vaxxDate[25];
};
struct Px_info {
    char category[5];
    char lastName[25], firstName[25], middleName[25];
    char contactNum[15];
    struct Px_address pxAddress;
} user;

// Function Prototypes.
void getDetails(struct Px_info);
void importFile();
void displayRecords();

int main() {
    int entered_Num;
    while (1) {
        printf(" ===============| Vaccination Maker App |=============== \n");
        printf(" [1] - Add New Record \n");
        printf(" [2] - Import Record \n");
        printf(" [3] - Display All Records \n");
        printf(" [4] - Exit \n");
        printf(" What do you want to do? -> ");
        scanf("%d", &entered_Num);
        scanf("%c"); // Here I intenionally used scanf("%c") because it would allow me to
                     // input from the next input buffer and it would allow me to use the "%[^\n]%*c" method.
                     // Otherwise, if I didn't code this part it would make my next scanf function be jumbled or messy.
        if (entered_Num == 1) {
            getDetails(user);
            system("pause");
            system("cls");
        } else if (entered_Num == 2) {
            importFile();
            system("pause");
            system("cls");
        } else if (entered_Num == 3) {
            displayRecords();
            system("pause");
            system("cls");
        } else if (entered_Num == 4) {
            printf(" Closing Program. Thank you! :D \n");
            system("pause");
            break;
        } else {
            printf(" Invalid Input! Please try again. \n");
            system("pause");
            system("cls");
        }
    }
    return 0;
}

// Function Definition.
void getDetails(struct Px_info a) {
    printf("\n ============> Enter The Following <============ \n");
    // From struct Px_info
    printf(" Category: ");
    scanf("%[^\n]%*c", &a.category);
    printf("\n ~~~~~~ Enter your Personal Information ~~~~~~ \n");
    printf(" Last Name: ");
    scanf("%[^\n]%*c", &a.lastName);
    printf(" First Name: ");
    scanf("%[^\n]%*c", &a.firstName);
    printf(" Middle Name: ");
    scanf("%[^\n]%*c", &a.middleName);
    printf(" Contact Number: ");
    scanf("%[^\n]%*c", &a.contactNum);
    // From struct Px_address
    printf("\n ~~~~~~ Address ~~~~~~ \n");
    printf(" House Number: ");
    scanf("%[^\n]%*c", &a.pxAddress.houseNum);
    printf(" Street: ");
    scanf("%[^\n]%*c", &a.pxAddress.street);
    printf(" Barangay: ");
    scanf("%[^\n]%*c", &a.pxAddress.barangay);
    printf(" City: ");
    scanf("%[^\n]%*c", &a.pxAddress.city);
    printf(" Province: ");
    scanf("%[^\n]%*c", &a.pxAddress.province);
    printf("\n Sex (M/F): ");
    scanf("%[^\n]%*c", &a.pxAddress.sex);
    printf(" Date of Birth (MM/DD/YYYY): ");
    scanf("%[^\n]%*c", &a.pxAddress.dateOfBirth);
    printf("\n Vaccine Manufacturer: ");
    scanf("%[^\n]%*c", &a.pxAddress.vaxxManufacturer);
    printf(" Vaccination Date (MM/DD/YYYY): ");
    scanf("%[^\n]%*c", &a.pxAddress.vaxxDate);

    FILE *store_file = fopen("Vaxx.txt", "a");

    if (store_file == NULL)
        printf(" Error. File could not be opened. \n");
    else
        fprintf(store_file, "\n\n");

    fprintf(store_file, "Category: %s \n", a.category);
    fprintf(store_file, "Last Name: %s \n", a.lastName);
    fprintf(store_file, "First Name: %s \n", a.firstName);
    fprintf(store_file, "Middle Name: %s \n", a.middleName);
    fprintf(store_file, "Contact Num: %s \n", a.contactNum);
    fprintf(store_file, "House Number: %s \n", a.pxAddress.houseNum);
    fprintf(store_file, "Street: %s \n", a.pxAddress.street);
    fprintf(store_file, "Barangay: %s \n", a.pxAddress.barangay);
    fprintf(store_file, "City: %s \n", a.pxAddress.city);
    fprintf(store_file, "Province: %s \n", a.pxAddress.province);
    fprintf(store_file, "Sex: %s \n", a.pxAddress.sex);
    fprintf(store_file, "Date of Birth: %s \n", a.pxAddress.dateOfBirth);
    fprintf(store_file, "Vaccine Manufacturer: %s \n", a.pxAddress.vaxxManufacturer);
    fprintf(store_file, "Vaccination Date: %s \n", a.pxAddress.vaxxDate);
    printf("\n ==========! RECORD SAVED SUCCESSFULLY !========== \n");

    fclose(store_file);
}

// Function Definition.
void importFile() {
    FILE *input_file, *output_file;
    char texts, fileName[100];
    int temp;

    printf(" Enter the File Name: ");
    scanf("%s", &fileName);

    input_file = fopen(fileName, "r");
    output_file = fopen("Vaxx.txt", "a");

    if (input_file == NULL || output_file == NULL)
        printf(" Error. File could not be opened. \n");
    else
        fprintf(output_file, "\n\n");

    // Main Formula for importing file.
    while (input_file != NULL) {
        temp = (fscanf(input_file, "%c", &texts));
        fprintf(output_file, "%c", texts);
        if (temp == EOF) {
            printf("\n ==========! ENTERED FILE APPENDED SUCCESSFULLY !========== \n");
            break;
        }
    }
    fclose(input_file);
    fclose(output_file);
}

// Function Definition.
void displayRecords() {
    FILE *display_file = fopen("Vaxx.txt", "r");
    char texts;
    int temp;

    if (display_file == NULL)
        printf(" Error. File could not be opened. \n");
    else
        printf("\n");

    // Main Formula for displaying file.
    while (display_file != NULL) {
        temp = (fscanf(display_file, "%c", &texts));
        printf("%c", texts);
        if (temp == EOF) {
            printf("\n\n");
            break;
        }
    }
    fclose(display_file);
}