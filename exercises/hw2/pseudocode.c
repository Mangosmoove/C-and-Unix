
 /* criteria, Q to quit
 *  *3 categories of employees:
 *(A)DMIN & (S)TAFF
 * --paid over 12 months
 * --admin doens't receive overtime pay, but staff can as long as OT is <=10
 * ---OT hourly salary: 75% of regular salary
 *FACULTY
 *--consists of:
 *---(R)egular faculty:  tenure-track, non-tenture track
 * -----paid annual salary over 10 months
 *---NO OVERTIME, but can teach 1 extra 3 cr. course per semester (paid in same way as adjunct
 * ---non-regular faculty: (A)djuncts, (T)eaching assistants (TA)
 * -----paid per course, $8500 for 3 cr. course
 * -----TA gets $2500 to help with a course and usually works ~10 hours/wk
 * -----salary gets paid over 5 months
 * -----TA can get OVERTIME pay as long as its <=2 hours/wk and OT payrate = hourly payrate, working over 2 hours = not paid for extra hours
 *(H)OURLY WORKERS
 *--receive fixed hourly wage up to FIRST 20 HOURS worked
 * --receive 1.5x hourly wage for OT (aka >20 hours)
 * --paid for a maximum of 40 hours/wk, additional is not paid
 *                                   
 *  *format: code salary OT
 *    store info then ask which paycode they want to review **need to watch for if the code has not been entered*
 *         print out weekly and monthly salary received for paycode & hourly salary rate
 *           need to use switch statements
 *             can't use the same loop more than once
 *              */

 /*
 *  *main {
 *      have variables that can store for each type of employee: number of employees, wkly slaary, monthly salary, hourly salary (not including OT)
 *          while user doesn't enter Q:
 *                prompt user to enter info in correct format
 *                      switch statement here to do cumulative calculations
 *                            prompt user to enter paycode they want to review
 *                                    print wkly & monthly salary received and hourly salary rate(not including OT)
 *                                              another switch statement or if statements?
 *                                                  if user enters Q,print avg wkly & monthly salary & payrate for all 3 types of employee
 *         }
 */
