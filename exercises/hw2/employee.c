/* Arinah Karim
 * C291-Spring 2021
 */ 

#include <stdio.h>
int main(){
  // create a char var to store the employee paycode
   char employeeType;
  //create double vars to store weekly, monthly, and hourly salaries for each employee type
  double adminWk, adminMon, adminHr;
  double staffWk, staffMon, staffHr;
  double regWk, regMon, regHr;
  double adjWk, adjMon, adjHr;
  double taWk, taMon, taHr;
  double hwWk, hwMon, hwHr;
  //create int vars to store the number of different employee types
  int admin = 0, staff = 0, regular = 0, adjunct = 0, ta = 0, hourly = 0;

  //create vars that store inputed user  information temporarily
  double temp1, temp2, totPay;            

  //for temporary usage to make math easier
  double tempWk, tempMon, tempHr, tempOT, tempTotPay;

  //ask user to enter the information with spaces after each piece of info
  printf("Enter info starting with paycode first followed by spaces in between each item: (paycode item item). If an item needs to be blank, enter -1 in the blank: ");
  //read in input from user
  scanf(" %c %lf %lf", &employeeType, &temp1, &temp2);

  //user keeps entering info until they want to quit
  while(employeeType != 'Q'){
    switch(employeeType){
      case 'A' : //case for Administrator
        if (temp2 >= 0 && temp1 < 0) //if format is incorrect for admin data or if user tries to enter OT
          printf("For entering Administrator data, enter correct paycode (A) followed by a space and then yearly salary. Nothing else should be listed besides these two items.\n");
        else {
          adminWk += temp1/52; //get paid over 12 months so weekly is tot/52 weeks
          adminMon += temp1/12;//tot/12 = monthly pay
          adminHr += temp1/2080;//if an employee works 40 hours/week and there are 52 weeks then hourly = yearly / (52*40)
          admin++; //increment by 1 for the total number of admin info entered
        }
        break;
      case 'S' : //case for Staff
        if ((temp2 > 10 || temp1 < 0) && temp2 != -1){ //temp2 = number of hours worked OT applied to current month
          //only receive pay for under 10 hours of OT
          printf("Staff cannot work over 10 hours of over time\n");
        }
        else {
          //OT = 75% of hourly salary calculations to determine how much OT affected different time payments
          tempWk = temp1/52;
          tempMon = temp1/12;
          tempHr = temp1/2080;
          tempOT = (0.75*tempHr)*temp2;
          //adjust the hourly, monthly, and weekly payments to not include OT
          staffHr += tempHr - tempOT;
          staffMon += staffHr*2080;
          staffWk += staffMon/52;
          staff++;
        }
        break;
      case 'R' : //case for Regular faculty
        if (((temp2 > 3 || temp2 < 3) && temp2 != -1) &&  temp2 < 0){ //can only teach one additional 3 credit hr class
          printf("Regular faculty can only teach one extra 3-credit hour course.\n");
        }
        //need case for where temp1 is empty
        else {
        //regular can teach one extra 3 credit hour class, doesn't count as OT
          temp1 += 8500; //adding the 8500 from how adjuncts are paid
          regMon += temp1/10; //paid over 10 month
          regWk += temp1/43.4524; //10 month = 43.4524 weeks
          regHr += temp1/1738.096; //10 month = 1738.096 hours (40 hrs/wk * 43.4524 weeks total)
          regular++;
        }
        break;
      case 'J' : //case for Adjuncts
        if(temp1 > 6 || temp1 <= 0 && temp2 != -1){
          printf("Ajuncts cannot work over time or more than 2 3-cr hour courses. Please enter proper paycode and total number of credit hours taught\n");
        }
        else {
          totPay = temp1 * 8500;
          adjMon += totPay/5; //get paid over 5 months
          adjWk += totPay/21.7262; //5 months = 21.7262 wks
          adjHr += totPay/851.048; //5 months = 851.048 hrs (21.276 * 40)
          adjunct++;
        }
        break;
      case 'T' : //case for TAs
        //paid 2500 to help with a course, work 10 hours/wk, paid over 5 months
        //can work OT and will be paid for OT <=2/wk, OT = hourly payrate
        if (temp1 < 0) {
          printf("TAs cannot teach a negative amount of courses.\n");
        }
        else {
          totPay = (3*temp1) * 2500; //paid per 3-cr hr, OT doesn't matter
          taMon += totPay / 5; //TA works during 5 months
          taWk += totPay / 21.7262;
          taHr += 217.262; //5 month = 217.262 (21.7262 week * 10 hours/wk)
          ta++;
        }
        break;
        case 'H' : //case for hourly workers
          //input: temp1 = payrate (paid/hr) temp2 = how many hours worked/wk of this month
          if (temp2 <= 0){
            printf("Hourly employee format needs paycode payrate and hours worked every week of curret month\n");
          }
          else{
            if (temp2 > 20){
              temp2 = 20;
            }
            tempTotPay = temp1 * temp2;
            hwHr += temp1;
            hwWk += temp1 * temp2;
            hwMon += hwWk * 4;
            hourly++;
          }
          break;                                                                                                                                                               }
    if (admin >= 1 && staff >= 1 && regular >= 1 && adjunct >= 1 && ta >= 1 &&  hourly >= 1){ 
      //do the following part when you have one type of each worker
      printf("Enter a paycode to review the hourly, weekly, and monthly salary of: ");
      scanf(" %c", &employeeType);
      switch(employeeType){
        case 'A':
          printf("Hourly: %.2lf, Weekly: %.2lf, Monthly: %.2lf\n", adminHr, adminWk, adminMon);
          break;
        case 'S':
          printf("Hourly: %.2lf, Weekly: %.2lf, Monthly: %.2lf\n", staffHr, staffWk, staffMon);
          break;
        case 'R':
          printf("Hourly: %.2lf, Weekly: %.2lf, Monthly: %.2lf\n", regHr, regWk, regMon);
          break;
        case 'J':
          printf("Hourly: %.2lf, Weekly: %.2lf, Monthly: %.2lf\n", adjHr, adjWk, adjMon);
          break;
        case 'T':
          printf("Hourly: %.2lf, Weekly: %.2lf, Monthly: %.2lf\n", taHr, taWk, taMon);
          break;
        case 'H':
          printf("Hourly: %.2lf, Weekly: %.2lf, Monthly: %.2lf\n", hwHr, hwWk, hwMon);
          break;
        default:
          printf("Invalid employee code.\n");
          break;
      }
    }
    //ask user to enter the information with spaces after each piece of info
    printf("Enter info starting with paycode first followed by spaces in between each item: ");
    scanf(" %c %lf %lf", &employeeType, &temp1, &temp2);
  }
  //print out averages
  printf("Averages\t\t\tHourly\t\t\tWeekly\t\t\tMonthly\n");
  printf("Admin:\t\t\t\t%.2lf\t\t\t%.2lf\t\t\t%.2lf\n", adminHr, adminWk, adminMon);
  printf("Staff:\t\t\t\t%.2lf\t\t\t%.2lf\t\t%.2lf\n", staffHr, staffWk, staffMon);
  printf("Regular:\t\t\t%.2lf\t\t\t%.2lf\t\t\t%.2lf\n", regHr, regWk, regMon);
  printf("Adjunct:\t\t\t%.2lf\t\t\t%.2lf\t\t\t%.2lf\n", adjHr, adjWk, adjMon);
  printf("TA:\t\t\t\t%.2lf\t\t\t%.2lf\t\t\t%.2lf\n", taHr, taWk, taMon);
  printf("Hourly:\t\t\t\t%.2lf\t\t\t%.2lf\t\t\t%.2lf\n", hwHr, hwWk, hwMon);
}  
