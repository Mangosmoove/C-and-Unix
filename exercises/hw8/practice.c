/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 4/16/2021
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct patientinformation {
    char patient_name[ 20 ];
    char* abbreviated_name;
    unsigned int age;
    struct {
        char phone_number[ 11 ];
        char address[ 60 ];
        char city[ 20 ];
        char state[ 3 ];
        int zipCode;
    } physical_address;
    bool istested;
    struct {
        char* test_date;
        bool istested_positive;
    } covid_results;
} healthrecord, *healthrecord_ptr;

int main()
{
    healthrecord_ptr = &healthrecord;
    
    puts("a. Accessing and printing patient_name using healthrecord...");
    puts("\tAltering patient_name variable to 'Jonathan'...");
    strcpy(healthrecord.patient_name, "Jonathan");
    printf("\tPatient name: %s\n", healthrecord.patient_name);
    
    puts("b. Accessing and printing patient_name using healthrecord_ptr...");
    puts("\tAltering patient_name variable to 'Ling'...");
    strcpy(healthrecord_ptr->patient_name, "Ling");
    printf("\tPatient name: %s\n", healthrecord_ptr->patient_name);
    
    puts("c. Accessing and printing member abbreviated_name of structure healthrecord...");
    puts("\tAltering abbreviated name to 'JMO'...");
    healthrecord.abbreviated_name = "JMO";
    printf("\tAbbreviated name: %s\n", healthrecord.abbreviated_name);
    
    puts("d. Accessing and printing member abbreviated_name of structure healthrecord_ptr...");
    puts("\tAltering abbreviated name to 'YLX'...");
    healthrecord_ptr->abbreviated_name = "YLX";
    printf("\tAbbreviated name: %s\n", healthrecord_ptr->abbreviated_name); 

    puts("e. Creating new character array and assinged abbreviated_name pointer to it...");
    char *abPtr = malloc(sizeof(healthrecord.abbreviated_name));
    puts("\tAssigning creater pointer to abbreviated_name pointed to by healthrecord_ptr...");
    strcpy(abPtr, healthrecord_ptr->abbreviated_name);
    printf("\tAbbreviated name pointed to by healthrecord_ptr: %s\n", abPtr);
    
    puts("f. Accessing and printing member zipCode of structure member physical_address of structure healthrecord...");
    healthrecord.physical_address.zipCode = 47408;
    printf("\tZip code: %d\n", healthrecord.physical_address.zipCode);
  
    puts("g. Accessing and printing member zipCode of structure member physical_address of structure healthrecord_ptr...");
    healthrecord_ptr->physical_address.zipCode = 46311;
    printf("\tZip code: %d\n", healthrecord_ptr->physical_address.zipCode);    

    puts("h. Accessing and printing member istested of structure healthrecord...");
    puts("\tAssigning istested variable to true...");
    healthrecord.istested = true;
    printf("\tistested: %s\n", healthrecord.istested ? "true" : "false");

    puts("i. Accessing and printing member istested_positive of structure member covid_results of structure healthrecord...");
    puts("\tAssinging istested_positive to false...");
    healthrecord.covid_results.istested_positive = false;
    printf("\tistest_positive: %s\n", healthrecord.covid_results.istested_positive ? "true" : "false");  

    puts("j. Accessing and printing member test_date of structure member covid_results of structure pointed to by healthrecord_ptr...");
    puts("\tAssigning test_date to 3/27/2021...");
    healthrecord_ptr->covid_results.test_date = "3/27/2021";
    printf("\ttest_date: %s\n", healthrecord_ptr->covid_results.test_date);

    puts("k. Creating an array of 3 healthrecord and initializing....");
    struct patientinformation patients[3];
    strcpy(patients[0].patient_name, "Arinah Karim");
    patients[0].abbreviated_name = "AK";
    patients[0].age = 20;
    strcpy(patients[0].physical_address.phone_number, "7777838300");
    strcpy(patients[0].physical_address.address, "123 10th Street");
    strcpy(patients[0].physical_address.city, "Bloomington");
    strcpy(patients[0].physical_address.state, "IN");
    patients[0].physical_address.zipCode = 47408;
    patients[0].covid_results.test_date = "4/4/2021";
    patients[0].covid_results.istested_positive = false;
    
    strcpy(patients[1].patient_name, "Ash Ketchum");
    patients[1].abbreviated_name = "AK";
    patients[1].age = 10;
    strcpy(patients[1].physical_address.phone_number, "1234567890");
    strcpy(patients[1].physical_address.address, "155 Kanto Street");
    strcpy(patients[1].physical_address.city, "Las Vegas");
    strcpy(patients[1].physical_address.state, "NV");
    patients[1].physical_address.zipCode = 89109;
    patients[1].covid_results.test_date = "2/1/2021";
    patients[1].covid_results.istested_positive = true;
    
    strcpy(patients[2].patient_name, "Seto Kaiba");
    patients[2].abbreviated_name = "SK";
    patients[2].age = 17;
    strcpy(patients[2].physical_address.phone_number, "0987654321");
    strcpy(patients[2].physical_address.address, "654 Kaiba Lane");
    strcpy(patients[2].physical_address.city, "Domino City");
    strcpy(patients[2].physical_address.state, "NY");
    patients[2].physical_address.zipCode = 10001;
    patients[2].covid_results.test_date = "3/14/2021";
    patients[2].covid_results.istested_positive = false;
    
    int i;
    for(i = 0; i < 3; i++){
        printf("\tZipcode: %d\n", patients[i].physical_address.zipCode);
    }

    puts("l. Creating a new pointer to point to newly created health records and initializing istested to true...");
    struct patientinformation *arrPtr = patients;
    for (i = 0; i < 3; i++){
        arrPtr->istested = true;
        /*if (i == 2){ just for testing purposes to see how arithmetic works
 *             arrPtr->istested = false;
 *                     }*/
        printf("\tistest_positive: %s\n", arrPtr->istested ? "true" : "false");        
    }
    return 0;
}

