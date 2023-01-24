#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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
            inputCString(patient->name, 1, NAME_LEN, ISFALSE);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            // putchar('\n');
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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

        if (selection == 1) {
            searchPatientByPatientNumber(patient, max);
            suspend();
        }
        else if (selection == 2) {
            searchPatientByPhoneNumber(patient, max);
            printf("\n");
            clearInputBuffer();
            suspend();
        }

    } while (selection);
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max) {
    int i = 0, counter = 0, freeAddress = 0;

    for (i = 0; i < max; i++)
    {
        if(patient[i].patientNumber > 0) {
            counter++;
        } else {
            freeAddress = i;
        }
    }

    if(counter == max) {
        printf("ERROR: Patient listing is FULL!\n\n");
    } else {
        patient[freeAddress].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[freeAddress]);

        printf("*** New patient record added ***\n\n");
    }
}


// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max) {
    int patientNum = 0, foundIndex = 0;
    printf("Enter the patient number: ");
    patientNum = inputIntPositive();

    foundIndex = findPatientIndexByPatientNum(patientNum, patient, max);
    putchar('\n');

    if(foundIndex != -1) {
        menuPatientEdit(&patient[foundIndex]);
    } else {
        printf("ERROR: Patient record not found!\n\n");
    }
    
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max) {
    int patientNum = 0, foundIndex = 0;
    char yesNo = ' ';
    printf("Enter the patient number: ");
    patientNum = inputIntPositive();

    foundIndex = findPatientIndexByPatientNum(patientNum, patient, max);
    
    if(foundIndex != -1) {
        printf("\n");
        displayPatientData(&patient[foundIndex], FMT_FORM);

        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        
        yesNo = inputCharOption("yn");

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

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data) {
    int i = 0, patientId = 0, maxAppoint = data->maxAppointments;

    struct Appointment appoint[maxAppoint];
    
    for (i=0; i < data->maxAppointments; i++)
    {
        appoint[i].patientNum = data->appointments[i].patientNum;
        appoint[i].date = data->appointments[i].date;
        appoint[i].time = data->appointments[i].time;
    }

    sortArray(appoint, data->maxAppointments);

    displayScheduleTableHeader(&appoint->date, ISTRUE);
    for (i=0; i < data->maxAppointments; i++)
    {
        if (appoint[i].patientNum > 0) {
            patientId = findPatientIndexByPatientNum(appoint[i].patientNum, data->patients, data->maxPatient);
            displayScheduleData(&data->patients[patientId], &appoint[i], ISTRUE);
        }
    }
    putchar('\n');
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data) {
    int year = 0, month = 0, day = 0, i = 0, foundIndex = 0, maxAppoint = data->maxAppointments;
    struct Date inputDate = { 0 };
    struct Appointment appoint[maxAppoint];

    printf("Year        : ");
    year = inputIntPositive();
    printf("Month (%d-%d): ", MIN_MONTH, MAX_MONTH);
    month = inputIntRange(MIN_MONTH, MAX_MONTH);


    if (year % 4 == 0) {
        printf("Day (%d-%d)  : ", MIN_DAY, FEB_LEAP_YEAR_DAY);
        day = inputIntRange(MIN_DAY, FEB_LEAP_YEAR_DAY);
    } else {
        printf("Day (%d-%d)  : ", MIN_DAY, FEB_REGULAR_DAY);
        day = inputIntRange(MIN_DAY, FEB_REGULAR_DAY);
    }
    putchar('\n');

    inputDate.year = year;
    inputDate.month = month;
    inputDate.day = day;

    displayScheduleTableHeader(&inputDate, ISFALSE);

    for (i = 0; i < data->maxAppointments; i++)
    {
        appoint[i].patientNum = data->appointments[i].patientNum;
        appoint[i].date = data->appointments[i].date;
        appoint[i].time = data->appointments[i].time;
    }

    sortArray(appoint, data->maxAppointments);

    for (i = 0; i < data->maxAppointments; i++)
    {
        if (appoint[i].patientNum != 0 && appoint[i].date.year == inputDate.year
            && appoint[i].date.month == inputDate.month && appoint[i].date.day == inputDate.day) {
            foundIndex = findPatientIndexByPatientNum(appoint[i].patientNum, data->patients, data->maxPatient);
            displayScheduleData(&data->patients[foundIndex], &appoint[i], ISFALSE);
        }
    }
    putchar('\n');
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appointment, int maxAppointments, struct Patient* patients, int maxPatient) {
    int patientNum = 0, year = 0, month = 0, day = 0, hour = 0, minute = 0, i = 0,
    counter = 0, isDone = 0, foundIndex = 0, freeAddress = 0, isValid = 0, checkHour = 0, hourValidity = 0;

    for (i = 0; i < maxAppointments; i++)
    {
        if(appointment[i].patientNum > 0) {
            counter++;
        } else {
            freeAddress = i;
        }
    }

    if(counter == maxAppointments) {
        printf("ERROR: Appointment listing is FULL!\n\n");
        isDone = 1;
    }

    if(!isDone) {
        printf("Patient Number: ");
        patientNum = inputIntPositive();

        foundIndex = findPatientIndexByPatientNum(patientNum, patients, maxPatient);
        if (foundIndex == -1)
        {
            printf("ERROR: Patient record not found!\n\n");
            isDone = 1;
        }
    }

    if(!isDone) {
        while(!isValid) {
            printf("Year        : ");
            year = inputIntPositive();
            printf("Month (%d-%d): ", MIN_MONTH, MAX_MONTH);
            month = inputIntRange(MIN_MONTH, MAX_MONTH);

            if ((year % LEAP_YEAR == 0) && (month == FEB)) {
                printf("Day (%d-%d)  : ", MIN_DAY, FEB_LEAP_YEAR_DAY);
                day = inputIntRange(MIN_DAY, FEB_LEAP_YEAR_DAY);
            } else if ((year % LEAP_YEAR != 0) && (month == FEB)) {
                printf("Day (%d-%d)  : ", MIN_DAY, FEB_REGULAR_DAY);
                day = inputIntRange(MIN_DAY, FEB_REGULAR_DAY);
            } else {
                printf("Day (%d-%d)  : ", MIN_DAY, MAX_DAY);
                day = inputIntRange(MIN_DAY, MAX_DAY);
            }

            printf("Hour (%d-%d)  : ", MIN_HOUR, MAX_HOUR);
            hour = inputIntRange(MIN_HOUR, MAX_HOUR);
            printf("Minute (%d-%d): ", MIN_MINUTE, MAX_MINUTE);
            minute = inputIntRange(MIN_MINUTE, MAX_MINUTE);

            checkHour = 0;
            for (i = 0; i < maxAppointments; i++)
            {
                if (appointment[i].date.year == year &&
                    appointment[i].date.month == month &&
                    appointment[i].date.day == day &&
                    appointment[i].time.hour == hour &&
                    appointment[i].time.min == minute) {
                    printf("\nERROR: Appointment timeslot is not available!\n\n");
                    checkHour = 1;
                }
            }

            if(checkHour == 0) {
                while(!hourValidity)
                {
                    int input = hour * 60 + minute;
                    if (!(input % INTERVAL != 0 || 
                        input < START_HOUR * 60 + START_MIN ||
                        input > END_HOUR * 60 + END_MIN)) {
                            hourValidity = 1;
                    } else {
                        printf("ERROR: Time must be between %02d:%02d and %02d:%02d in %d minute intervals.\n\n",
                            START_HOUR, START_MIN, END_HOUR, END_MIN, INTERVAL);
                        printf("Hour (%d-%d)  : ", MIN_HOUR, MAX_HOUR);
                        hour = inputIntRange(MIN_HOUR, MAX_HOUR);
                        printf("Minute (%d-%d): ", MIN_MINUTE, MAX_MINUTE);
                        minute = inputIntRange(MIN_MINUTE, MAX_MINUTE);
                        hourValidity = 0;
                    }
                }

                if (hourValidity == 1)
                    isValid = 1;
            }
        }

        appointment[freeAddress].patientNum = patientNum;
        appointment[freeAddress].date.year = year;
        appointment[freeAddress].date.month = month;
        appointment[freeAddress].date.day = day;
        appointment[freeAddress].time.hour = hour;
        appointment[freeAddress].time.min = minute;

        printf("\n*** Appointment scheduled! ***\n");
        putchar('\n');
    }
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointment, int maxAppointments, struct Patient* patients, int maxPatient) {
    int patientNum = 0, year = 0, month = 0, day = 0, foundIndex = 0, apptId = -1;
    char yesNo;

    printf("Patient Number: ");
    patientNum = inputIntPositive();

    foundIndex = findPatientIndexByPatientNum(patientNum, patients, maxPatient);
    if (foundIndex == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
        return;
    }

    printf("Year        : ");
    year = inputIntPositive();

    printf("Month (1-12): ");
    month = inputIntRange(1, 12);

    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        printf("Day (1-29)  : ");
        day = inputIntRange(1, 29);
    }
    else
    {
        printf("Day (1-28)  : ");
        day = inputIntRange(1, 28);
    }
    putchar('\n');
    
    displayPatientData(&patients[foundIndex], FMT_FORM);
    printf("Are you sure you want to remove this appointment (y,n): ");
    
    yesNo = inputCharOption("yn");

    if (yesNo == 'y') {
        apptId = findAppointmentIndex(appointment, patientNum, year, month, day, maxAppointments);
        appointment[apptId].patientNum = 0;
        printf("\nAppointment record has been removed!\n");
    } else {
        printf("Operation aborted.\n");
    }
    putchar('\n');
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    int i = 0, isValid = 0;
    char phoneNum[PHONE_LEN + 1] = { '\0' };
    printf("Search by phone number: ");
    //inputCString(phoneNum, PHONE_LEN, PHONE_LEN, ISTRUE);
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient) {
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN, ISFALSE);
    putchar('\n');
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
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
        inputCString(phone->number, PHONE_LEN, PHONE_LEN, ISTRUE);
        putchar('\n');
    }

}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max) {
    FILE *fp = NULL;
    int i = 0, count = 0;
    fp = fopen(datafile, "r");

    if (fp != NULL)
    {
        for(i = 0; i < max; i++) {
            if(fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]",
                &patients[i].patientNumber, patients[i].name, 
                patients[i].phone.description, patients[i].phone.number) != EOF){
                    count++;
                }
        }
    }

    fclose(fp);
    return count;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max) {
    FILE *fp = NULL;
    int i = 0, count = 0;
    fp = fopen(datafile, "r");

    if (fp != NULL)
    {
        for(i = 0; i < max; i++) {
            if(fscanf(fp, "%d,%d,%d,%d,%d,%d",
            &appoints[i].patientNum, &appoints[i].date.year,
            &appoints[i].date.month, &appoints[i].date.day,
            &appoints[i].time.hour, &appoints[i].time.min
            ) != EOF) {
                count++;
            }
        }
    }

    fclose(fp);
    return count;
}


void sortArray(struct Appointment appoints[], int max)
{
   int i = 0, j = 0, actualCount = max - 1;
   long long basis = 0.00, comparison = 0.00;


    for (i = 0; i < actualCount; i++) {
        for (j = 0; j < actualCount; j++)
        {
            basis = dateCalculator(appoints[j].date.year, "year") + 
                dateCalculator(appoints[j].date.month, "month") + 
                dateCalculator(appoints[j].date.day, "day") + 
                dateCalculator(appoints[j].time.hour, "hour" ) + 
                dateCalculator(appoints[j].time.min, "minute" );
            
            comparison = dateCalculator(appoints[j + 1].date.year, "year") + 
                dateCalculator(appoints[j + 1].date.month, "month") + 
                dateCalculator(appoints[j + 1].date.day, "day") + 
                dateCalculator(appoints[j + 1].time.hour, "hour" ) + 
                dateCalculator(appoints[j + 1].time.min, "minute" );

            if(basis > comparison) {
                struct Appointment temp = appoints[j];
                appoints[j] = appoints[j + 1];
                appoints[j + 1] = temp;
            }
        }
    }
}

long long dateCalculator(double value, char conversionMethod[NAME_LEN]) {

    long long calculated = 0.00;
    int monthsInYear = 12, daysInMonths = 30, hoursInDay = 24, minutesInHours = 60;

    if(strcmp(conversionMethod, "year") == 0) {
        calculated = value * monthsInYear * daysInMonths * hoursInDay * minutesInHours;
    } else if (strcmp(conversionMethod, "month") == 0) {
        calculated = value * daysInMonths * hoursInDay * minutesInHours;
    } else if (strcmp(conversionMethod, "day") == 0) {
        calculated = value * hoursInDay * minutesInHours;
    } else if (strcmp(conversionMethod, "hour") == 0) {
        calculated = value * minutesInHours;
    } else {
        calculated = value;
    }

    return calculated;
}
int findAppointmentIndex(const struct Appointment* appoints, int patientNum, int year, int month, int day, int max) {
    int i = 0, foundIndex = -1;
    for (i = 0; i < max; i++)
    {
        if (appoints[i].patientNum == patientNum &&
            appoints[i].date.year == year &&
            appoints[i].date.month == month &&
            appoints[i].date.day == day) {
                foundIndex = i;
        }
    }
    return foundIndex;
}