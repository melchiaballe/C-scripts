#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("\nPatient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    int i = 0, hasEligibleData = 0;

    if(fmt == FMT_FORM) {
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber > 0) {
                hasEligibleData = 1;
                displayPatientData(&patient[i], FMT_FORM);
            }
        }
    } else {
        displayPatientTableHeader();
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber > 0) {
                hasEligibleData = 1;
                displayPatientData(&patient[i], FMT_TABLE);
            }
        }
    }

    printf("\n");

    if(!hasEligibleData) {
        printf("*** No records found ***\n\n");
    }
    
}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max) {
    int selection = -1;

    do {
        printf("Search Options\n"
               "==========================\n"
               "1) By patient number\n"
               "2) By phone number");
        printf("\n"
               "..........................\n"
               "0) Previous menu\n"
               "..........................\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            searchPatientByPatientNumber(patient, max);
            suspend();
        }
        else if (selection == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            printf("\n");
            clearInputBuffer();
            suspend();
        }

    } while (selection);
}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max) {
    int i = 0, counter = 0;

    for (i = 0; i < max; i++)
    {
        if(patient[i].patientNumber > 0) {
            counter++;
        }
    }

    if(counter == max) {
        printf("ERROR: Patient listing is FULL!\n\n");
    } else {
        patient[counter].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[counter]);

        printf("\n*** New patient record added ***\n\n");
    }
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max) {
    int patientNum = 0, foundIndex = 0;
    printf("Enter the patient number: ");
    patientNum = inputIntPositive();
    // scanf("%d", &patientNum);

    foundIndex = findPatientIndexByPatientNum(patientNum, patient, max);
    putchar('\n');

    if(foundIndex != -1) {
        menuPatientEdit(&patient[foundIndex]);
    } else {
        printf("ERROR: Patient record not found!\n\n");
    }
    
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max) {
    int patientNum = 0, foundIndex = 0;
    char yesNo = ' ';
    printf("Enter the patient number: ");
    patientNum = inputIntPositive();
    // scanf("%d", &patientNum);

    foundIndex = findPatientIndexByPatientNum(patientNum, patient, max);
    
    if(foundIndex != -1) {
        printf("\n");
        displayPatientData(&patient[foundIndex], FMT_FORM);

        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        
        yesNo = inputCharOption("yn");
        // scanf(" %c", &yesNo);
        clearInputBuffer();

        if(yesNo == 'y') {
            patient[foundIndex].patientNumber = 0;
            printf("Patient record has been removed!\n");
        } else {
            printf("Operation aborted.\n");
        }
        putchar('\n');
    } else {
        printf("\nERROR: Patient record not found!\n");
        putchar('\n');
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    int patientNum = 0, foundIndex = 0;
    printf("Search by patient number: ");
    patientNum = inputIntPositive();

    foundIndex = findPatientIndexByPatientNum(patientNum, patient, max);

    if(foundIndex != -1) {
        printf("\n");
        displayPatientData(&patient[foundIndex], FMT_FORM);
        printf("\n");
    } else {
        printf("\n*** No records found ***\n\n");
    }

}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    int i = 0, isValid = 0;
    char phoneNum[PHONE_LEN + 1] = { '\0' };
    printf("Search by phone number: ");
    //inputCString(phoneNum, PHONE_LEN, PHONE_LEN);
    scanf("%[^\n]", phoneNum);

    printf("\n");
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if(strcmp(patient[i].phone.number, phoneNum) == 0) {
            displayPatientData(&patient[i], FMT_TABLE);
            isValid = 1;
        }
    }

    if (!isValid) {
        printf("\n*** No records found ***\n");
    }
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max) {
    int i = 0, count = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > 0) {
            count = patient[i].patientNumber + 1;
        }
    }
    return count;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i = 0, foundIndex = -1;
    for (i = 0; i < max; i++)
    {
        if(patient[i].patientNumber == patientNumber) {
            foundIndex = i;
        }
    }
    return foundIndex;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient) {
    // clearInputBuffer();
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone) {
    int selection = 0;

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");

    selection = inputIntRange(1, 4);
    
    if(selection == 1) {
        strcpy(phone->description, "CELL");
    } else if (selection == 2) {
        strcpy(phone->description, "HOME");
    } else if (selection == 3) {
        strcpy(phone->description, "WORK");
    } else {
        strcpy(phone->description, "TBD");
    }

    if(selection < 4) {
        printf("\nContact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, PHONE_LEN, PHONE_LEN);
        clearInputBuffer();
    }

}