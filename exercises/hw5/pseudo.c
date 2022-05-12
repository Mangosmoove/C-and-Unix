/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/24/2021
 *
 *
 *
 *
 * SEATING ARRANGEMENT:
 *              
 * A   B  C  [aisle] D  E  F  [aisle]  G  H  I
 * 1   2  3          4  5  6           7  8  9
 * 10  11 12         13 14 15          16 17 18
 *
 *
 *
 * seating [20][7] = {{}} //populate the array with the available seats
 *
 * name[140]//that num may change since all seats cannot be used
 * seatForName[140] //index will line up with name given
 * level[140] //for level someone is traveling in
 * --row 1-3 = first class
 * --row 4-7 = business
 * --anything else = economy
 *  ---row 8 = priority economy
 * seatingDisplay[20][7] //assign 0 for empty seat, 1 for taken seat
 *
 * prompt user for seating, scan it in
 * do while the the user has not typed in quit
 *   available options: choose seat, print boarding pass, display seating map, print manifest of passengers and seat numbers, or quit
 *
 *   if they want to choose a seat:
 *     prompt for level using given menu
 *       use rand num generator to assign a seat based on level (inital seat selection)
 *        if level is booked entirely, ask if it's acceptable to downgrade or upgrade
 *          if business section is full, row 8 is an option
 *          if they don't want to upgrade/downgrade tell them to get on the next flight in 3 hours
 *
 *       if this doesn't work, ask if they want a window or aisle seat
 *         if not, then for at most three times:
 *           randomly generate a seta assignment.
 *         if they try to generate more than 3 times, tell them to get on next flight in 3 hours
 *   
 *   if they want to print boarding pass:
 *     prompt for a seat, scan in
 *       provide name, seat, and level based on user input
 *
 *   if they want to display:
 *     show the array where 0 means empty, 1 means taken
 *
 *   if they want to see a manifest in the tablular format
 *     ask if they want to see default or alphabetical format:
 *       if default:
 *         print out based on seat number
 *       if alpha:
 *         print out based on last name
 */
