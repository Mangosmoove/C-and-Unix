#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct HealthProfile{
    char *firstName;
    char *lastName;
    char *gender;
    struct DOB *dob;
    double* height;
    double* weight;
    struct FamHist *fam;
}*hpPtr;

struct DOB{
    int month;
    int date;
    int year;
};

struct FamHist{
    int heartProb;
    int bP;
    int cancer;
};

int age(int, int);
void mtHeartRate(int, double); 
double bmi(double, double); 
void bmiChart();
int main(){
    hpPtr = (struct HealthProfile*)malloc(sizeof(struct HealthProfile)*10);
    int i;
    int count; //for family history
    int bmiVal; //to keep track of current bmi for current patient
    int avgAge = 0; 
    int totalAges = 0;
    int currentAge = 0;
    double *bmiPtr = (double*)malloc(10*sizeof(double)); //array of bmi values
    char **allFirst = (char**)malloc(sizeof(char*) * 10); //all the first names of patients
    char **allLast = (char**)malloc(sizeof(char*) * 10); //all the last names of patients
    int indices[10] = {0}; //to keep track of fam history with 2(+) issues 
    int ages[10] = {0}; //array of ages
    int cancer[10] = {0}; //for telling person if they should see their oncologist

    for (i = 0; i < 10; i++){
        printf("\nEnter first name: "); //gets first name
        (hpPtr+i)->firstName = (char*)malloc(sizeof(char)*15);
        scanf("%s", (hpPtr+i)->firstName);
        allFirst[i] = (hpPtr+i)->firstName;
        
        printf("\nEnter last name: "); //gets last name
        (hpPtr+i)->lastName = (char*)malloc(sizeof(char)*15);
        scanf("%s", (hpPtr+i)->lastName);
        allLast[i] = (hpPtr+i)->lastName;
         
        printf("\nEnter gender: "); //gets gender info
        (hpPtr+i)->gender = (char*)malloc(sizeof(char)*15);
        scanf("%s", (hpPtr+i)->gender);
        
        printf("\nEnter birthdate(mm-dd-yyyy): "); //gets birth date
        (hpPtr+i)->dob = malloc(sizeof(struct DOB));
        scanf("%d%*c%d%*c%d", &(hpPtr+i)->dob->month, &(hpPtr+i)->dob->date, &(hpPtr+i)->dob->year);
        currentAge= age((hpPtr+i)->dob->month, (hpPtr+i)->dob->year); //calculates age
        totalAges += currentAge; //increment totalages to eventually help in getting average ages
        ages[i] = currentAge; //store current age in ages array
    
        printf("\nEnter height in inches: "); //gets height
        (hpPtr+i)->height = (double*)malloc(sizeof(double));
        scanf("%lf", (hpPtr+i)->height);
      
        printf("\nEnter weight in pounds: "); //gets weight
        (hpPtr+i)->weight = (double*)malloc(sizeof(double));
        scanf("%lf", (hpPtr+i)->weight);
        
        bmiVal = bmi(*(hpPtr+i)->weight, *(hpPtr+i)->height); //calculates BMI
        *(bmiPtr+i) = bmiVal; //stores bmi in array of bmi values
        
        count = 0;
        (hpPtr+i)->fam = malloc(sizeof(struct FamHist)); //for finding family health issues
        printf("\nHas a parent had heart problems? (1/0): ");
        scanf("%d", &(hpPtr+i)->fam->heartProb);
        if ((hpPtr+i)->fam->heartProb){
            count++;
        }
        printf("\nHas a parent had blood pressure? (1/0): ");
        scanf("%d", &(hpPtr+i)->fam->bP);
        if ((hpPtr+i)->fam->bP){
            count++;
        }    
        printf("\nHas a parent had cancer? (1/0): ");
        scanf("%d", &(hpPtr+i)->fam->cancer);
        if ((hpPtr+i)->fam->cancer){
            count++;
            cancer[i] = 1;
        }    
        if(count >= 2){
            indices[i] = i;
        }
    }
     
    //prints out first and last names of people with 2(+) health issues in family
    puts("Patients who have 2(+) health issues in family:");
    for (i = 0; i < 10; i++){
        if(indices[i] != 0){
            printf("%s, %s\n", allFirst[i], allLast[i]);
        }
    }
 
    bmiChart(); //printing bmi chart
   
    avgAge = totalAges/10; //gets average age among 10 patients
    for(i = 0; i < 10; i++){
        if(((*(bmiPtr)+i) > 30) || ((*(bmiPtr)+i) < 18.5) && count >= 2 && (ages[i] >= avgAge)){
            printf("Patient name: %s %s\n", allFirst[i], allLast[i]);
            printf("Age: %d\nBmi: %lf\n", ages[i], *(bmiPtr+i));
            mtHeartRate(ages[i], *(bmiPtr+i));
            if(cancer[i]){
                puts("It is advised for you to visit the oncologist.");
            }
        }
    }
    
    int j;
    for (i = 0; i < 9; i++){ //bubble sorting to organize bmi from highest to lowest
        for(j = 0; j < 10-i-1; j++){
            if(*(bmiPtr+j) < *(bmiPtr+j+1)){
                double temp = *(bmiPtr+j+1);
                *(bmiPtr+j+1) = *(bmiPtr+j);
                *(bmiPtr+j) = temp;
                
                char* temp2 = allFirst[j+1]; //makes sure first names align with indices of bmi
                allFirst[j+1] = allFirst[j];
                allFirst[j] = temp2;
                
                char* temp3 = allLast[j+1]; //makes sure last names align with indices of bmi
                allLast[j+1] = allLast[j];
                allLast[j] = temp3;
            }
        }
    }
    
    puts("Highest BMI to lowest BMI:");
    for (i = 0; i < 10; i++){
        printf("%lf\t%s\t%s\n", *(bmiPtr+i), allFirst[i], allLast[i]); //prints out bmi val and the name of the patient bmi belongs to
    }
    
    free(bmiPtr);  //freeing potnters 
    freee(hpPtr);  //freeing pointers
    return 0;
}

int age(int month, int year){
    int presentYear = 2021;
    int age = 0;
    if(month > 4){ //4 is the current month
        presentYear--;
    }
    age = presentYear - year;
    return age;
}

void mtHeartRate(int age, double bmiVal){
    int max = 200 - age;
    int lowTarget = max*0.55;
    int highTarget = max*0.75;
 
    printf("Max heart rate: %d\n", max);
    printf("Target heart rate range: %d to %d\n", lowTarget, highTarget);
    if(max < lowTarget || max > highTarget){
        puts("Your heart rate is outside the targeted range. You should see your physician.");
    }
}

double bmi(double weight, double height){
    int result = (weight * 703)/(height*height);
    return result;
}

void bmiChart(){
    puts("BMI VALUES");
    printf("Underweight: less than 18.5\n");
    printf("Normal:\t\tbetween 18.5 and 24.9\n");
    printf("Overweight:\tbetween 25 and 29.9\n");
    printf("Obses:\t\t\t30 or greater\n");
}

