/* 1241602611 Erdi Haruni */

// WARNINGS:
// PLEASE ENTER DATES WITH ' / ' SEPARATOR. EXAMPLE: 13/12/2025
// I PREPARED THE CODE ON CLION ON A MACBOOK. THEREFORE THE sleep FUNCTION WORKS IN SECONDS.
// unistd.h IS NOT AVAILABLE ON WINDOWS
// I USED A LOT OF \t CHARACTERS — NOT SURE HOW WINDOWS CMD WILL REACT, BUT IT WORKED FINE FOR ME.
// SOME EFFECTS I ADDED MAY BE DELAYED OR BEHAVE ODDLY, BUT AS I SAID IT WORKS FINE ON MAC.
// IT LOOKS BETTER IF RUN IN POWERSHELL...

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "data_set.h"



int current = 100;


void MainMenu() // THE MAIN MENU IS DEFINED INSIDE THIS FUNCTION.
{
    system("clear"); // I used 'clear' because I'm on a MacBook. If you want to run it on Windows, you can use system("cls")
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tWELCOME...\n");
    sleep(1);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tLoading");
    for(int i=0;i<3;i++) // This loop prints '.' characters one by one every 1 second with a delay. I added it to make the program feel more realistic.
    {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    // THIS IS THE SKELETON STRUCTURE OF THE MAIN MENU
    printf("\n");
    printf("\t\t\t\t\t\t\t\t**********************************************************************************************************\n");
    printf("\t\t\t\t\t\t\t\t*                                      GSM SUBSCRIBER MANAGEMENT INFORMATION SYSTEM                       *\n");
    printf("\t\t\t\t\t\t\t\t**********************************************************************************************************\n");
    printf("\t\t\t\t\t\t\t\t*                  A-) DATA SET OPERATIONS                                                                *\n");
    printf("\t\t\t\t\t\t\t\t*                    Press 1 to add a subscriber!                                                         *\n");
    printf("\t\t\t\t\t\t\t\t*                    Press 2 to delete a subscriber from records!                                         *\n");
    printf("\t\t\t\t\t\t\t\t*                    Press 3 to update subscriber information!                                            *\n");
    printf("\t\t\t\t\t\t\t\t*                    Press 4 to search for a subscriber!                                                  *\n");
    printf("\t\t\t\t\t\t\t\t**********************************************************************************************************\n");
    printf("\t\t\t\t\t\t\t\t*                  B-) REPORTING AND ANALYSIS OPERATIONS                                                  *\n");
    printf("\t\t\t\t\t\t\t\t*                    Press 5 to update operator information!                                              *\n");
    printf("\t\t\t\t\t\t\t\t*                    Press 6 to view the Loyalty Report!                                                  *\n");
    printf("\t\t\t\t\t\t\t\t*                    Press 7 for Campaign Popularity Analysis!                                            *\n");
    printf("\t\t\t\t\t\t\t\t*                    Press 0 to exit!                                                                     *\n");
    printf("\t\t\t\t\t\t\t\t**********************************************************************************************************\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t\t-->Operation you want to perform: ");
}




// - ADD SUBSCRIBER FUNCTION -
void addSubscriber()
{
    if( current >= 1000) // We already have 100 people in the data set and the memory can hold a maximum of 1000 people. Exceeding that will trigger this error.
    {
        printf("Unfortunately the capacity limit has been exceeded...");
        return;
    }
    int invalid_id;
    // THIS IS AN EXTRA FEATURE not mentioned in the PDF. It validates that the ID number is exactly 11 digits, consists of digits only, and cannot start with '0'.
    do {
        invalid_id = 0;
        printf("Please enter the ID Number of the person you want to add: ");
        scanf("%s",people[current].id_no);
        if(strlen(people[current].id_no)!=11 || people[current].id_no[0]=='0')
        {
            invalid_id =1;
        }
        for(int i=0;i<11;i++)
        {
            if(people[current].id_no[i] < '0' || people[current].id_no[i] > '9')
            {
                invalid_id =1;
                break;
            }
        }
        if(invalid_id)
        {
            printf("Please enter a valid national ID number!\n");
        }

    }while(invalid_id);

    // Subscriber information is collected here in line with the fields required by the PDF.

    printf("Enter the first name of the person you want to add: ");
    scanf("%s",people[current].first_name);

    printf("Enter the last name of the person you want to add: ");
    scanf("%s",people[current].last_name);

    printf("Enter the age of the person you want to add: ");
    scanf("%s",people[current].age);

    printf("Enter the address of the person you want to add: ");
    getchar(); // fgets could have been used here, but due to issues encountered getchar() had to be used
    scanf("%[^\n]",people[current].address);

    printf("Enter the phone number of the person you want to add: ");
    getchar(); // fgets could have been used here, but due to issues encountered getchar() had to be used
    scanf("%[^\n]",people[current].phone_no);

    printf("Enter the date the phone number was assigned to the person you want to add: ");
    scanf("%d/%d/%d",&people[current].first_date.day,&people[current].first_date.month,&people[current].first_date.year);
    getchar(); // fgets could have been used here, but due to issues encountered getchar() had to be used

    printf("Enter the current operator name of the person you want to add: ");
    scanf("%[^\n]",people[current].op_name);

    printf("Enter the start date of the operator plan for the person you want to add: ");
    scanf("%d/%d/%d",&people[current].plan_start.day,&people[current].plan_start.month,&people[current].plan_start.year);
    getchar(); // fgets could have been used here, but due to issues encountered getchar() had to be used

    printf("Enter the end date of the operator plan for the person you want to add: ");
    scanf("%d/%d/%d",&people[current].plan_end.day,&people[current].plan_end.month,&people[current].plan_end.year);
    getchar(); // fgets could have been used here, but due to issues encountered getchar() had to be used

    printf("Enter the campaign package type for the person you want to add: ");
    scanf("%[^\n]",people[current].campaign);

    printf("Enter the first previous operator brand for the person you want to add: ");
    getchar(); // fgets could have been used here, but due to issues encountered getchar() had to be used
    scanf("%[^\n]",people[current].prev_op1);

    printf("Enter the start date of the first previous operator plan for the person you want to add: ");
    scanf("%d/%d/%d",&people[current].op1_start.day,&people[current].op1_start.month,&people[current].op1_start.year);
    getchar(); // fgets could have been used here, but due to issues encountered getchar() had to be used

    printf("Enter the end date of the first previous operator plan for the person you want to add: ");
    scanf("%d/%d/%d",&people[current].op1_end.day,&people[current].op1_end.month,&people[current].op1_end.year);
    getchar(); // fgets could have been used here, but due to issues encountered getchar() had to be used

    printf("Enter the second previous operator brand for the person you want to add: ");
    scanf("%[^\n]",people[current].prev_op2); // fgets could have been used here, but due to issues encountered getchar() had to be used

    printf("Enter the start date of the second previous operator plan for the person you want to add: ");
    scanf("%d/%d/%d",&people[current].op2_start.day,&people[current].op2_start.month,&people[current].op2_start.year);
    getchar();

    printf("Enter the end date of the second previous operator plan for the person you want to add: ");
    scanf("%d/%d/%d",&people[current].op2_end.day,&people[current].op2_end.month,&people[current].op2_end.year);
    getchar();

    current++;
    sleep(2);
    printf("Record has been successfully created.\nRedirecting you to the menu...\n");

}

// DELETE SUBSCRIBER FUNCTION
void deleteSubscriber()
{
    char id_no[12]; // ID number is defined here because if we want to delete a subscriber, the ID stored in memory must match the one we enter. See strcmp()
    int invalid_id; // Same invalid ID check as in the addSubscriber function — copy-pasted.
    do {
        invalid_id = 0;
        printf("Please enter the ID Number of the person you want to delete: ");
        scanf("%s",id_no);
        if(strlen(id_no)!=11 || id_no[0]=='0')
        {
            invalid_id =1;
        }
        for(int i=0;i<11;i++)
        {
            if(id_no[i] < '0' || id_no[i] > '9')
            {
                invalid_id =1;
                break;
            }
        }
        if(invalid_id)
        {
            printf("Please enter a valid national ID number!\n");
        }

    }while(invalid_id);

    // This is the check area — it will compare the stored ID with the entered one and decide if they match.
    int found_index = -1;
    for(int i =0;i<current;i++)
    {
        if(strcmp(people[i].id_no,id_no) == 0) // Used strcmp to compare both ID numbers.
        {
            found_index =i;
            break;
        }
    }
    if(found_index == -1) // If they don't match, this message will be printed to the console.
    {
        printf("The ID number you entered does not match any record...\n");
        return;
    }

    char answer; // Extra feature — asks for final confirmation before deleting the subscriber.

    printf("Do you want to delete this subscriber? (Y/N): ");
    scanf(" %c", &answer);

    if (answer == 'Y' || answer == 'y')
    {
        // Deletion proceeds...
    }

    else
    {
        printf("Operation cancelled. Returning to main menu...\n");
        return;
    }



    // If they match, a for loop shifts elements left (one less than current after deletion) and waits 2 seconds before printing the success message.
    for(int j=found_index;j<current-1;j++)
    {
        people[j] = people[j+1];
    }
    current--;
    sleep(2);
    printf("Record has been deleted...\n");

}

// UPDATE SUBSCRIBER FUNCTION
void updateSubscriber()
{
    char id_no[12]; // Defined again for ID comparison
    int invalid_id; // Also essential for invalid ID validation.
    do {
        invalid_id = 0;
        printf("Please enter the ID Number of the person you want to update: ");
        scanf("%s",id_no);
        if(strlen(id_no)!=11 || id_no[0]=='0')
        {
            invalid_id =1;
        }
        for(int i=0;i<11;i++)
        {
            if(id_no[i] < '0' || id_no[i] > '9') // Each character in the national ID must be a digit. The for loop checks every index of the ID.
            {
                invalid_id =1;
                break;
            }
        }
        if(invalid_id)
        {
            printf("Please enter a valid national ID number!\n");
        }

    }while(invalid_id);

    int found_index = -1;
    for(int i =0;i<current;i++)
    {
        if(strcmp(people[i].id_no,id_no) == 0) // Used strcmp to compare both ID numbers.
        {
            found_index =i;
            break;
        }

    }
    if(found_index == -1)
    {
        printf("The ID number you entered does not match any record...\n");
        return;
    }
    // If the national ID is valid and matches an existing record, the user is redirected to the update menu.

    int update_choice;
    do
    {
        printf("\t\t\t\t\t\t\t\t************************************************************************************************************\n");
        printf("\t\t\t\t\t\t\t\t*                               WELCOME TO THE SUBSCRIBER UPDATE MENU                                      *\n");
        printf("\t\t\t\t\t\t\t\t************************************************************************************************************\n");
        printf("\t\t\t\t\t\t\t\t*                   Press 1 to update the address!                                                         *\n");
        printf("\t\t\t\t\t\t\t\t*                   Press 2 to update the phone number!                                                    *\n");
        printf("\t\t\t\t\t\t\t\t*                   Press 3 to update the current operator!                                                *\n");
        printf("\t\t\t\t\t\t\t\t*                   Press 4 to update the plan start date!                                                 *\n");
        printf("\t\t\t\t\t\t\t\t*                   Press 5 to update the plan end date!                                                   *\n");
        printf("\t\t\t\t\t\t\t\t*                   Press 6 to update the campaign package!                                               *\n");
        printf("\t\t\t\t\t\t\t\t*                   Press 0 to exit!                                                                       *\n");
        printf("\t\t\t\t\t\t\t\t************************************************************************************************************\n");
        printf("-->Operation you want to perform: ");
        scanf("%d", &update_choice);


        switch (update_choice) // Presents the selected option to the user's console via a switch-case structure.
        {
            case 1:
                printf("Please enter the new address: ");
                getchar();
                scanf("%[^\n]s",people[found_index].address);
                sleep(1);
                printf("Your address has been successfully updated...");
                sleep(1);

                break;
            case 2:
                printf("Please enter the new phone number: ");
                getchar();
                scanf("%[^\n]s",people[found_index].phone_no);
                sleep(1);
                printf("Your phone number has been successfully updated...");
                sleep(1);

                break;
            case 3:
                printf("Please enter the new operator: ");
                getchar();
                scanf("%[^\n]",people[found_index].op_name);
                sleep(1);
                printf("Your operator has been successfully updated...");
                sleep(1);

                break;
            case 4:
                printf("Please enter the new plan start date: ");
                scanf("%d/%d/%d",&people[found_index].plan_start.day,&people[found_index].plan_start.month,&people[found_index].plan_start.year);
                getchar();
                sleep(1);
                printf("Date has been successfully updated...");
                sleep(1);

                break;

            case 5:
                printf("Please enter the new plan end date: ");
                scanf("%d/%d/%d",&people[found_index].plan_end.day,&people[found_index].plan_end.month,&people[found_index].plan_end.year);
                getchar();
                sleep(1);
                printf("Date has been successfully updated...");
                sleep(1);

                break;
            case 6:
                printf("Please enter the new campaign package: ");
                getchar();
                scanf("%[^\n]s",people[found_index].campaign);
                sleep(1);
                printf("Campaign Package has been successfully updated...");
                sleep(1);

                break;
            case 0:
                sleep(1);
                printf("Exiting...\nThank you.\n ");
                break;
            default:
                printf("Invalid selection! Redirecting you to the main menu...\n");
                sleep(2);
                return;


        }

    }while(update_choice != 0);

}

// SUBSCRIBER SEARCH FUNCTION
void searchSubscriber()
{
    int search_choice;
    do {
        printf("\t\t\t\t\t\t\t\t**********************************************************************************************************\n");
        printf("\t\t\t\t\t\t\t\t                            WELCOME TO THE SUBSCRIBER SEARCH MENU\n");
        printf("\t\t\t\t\t\t\t\t**********************************************************************************************************\n");
        printf("\t\t\t\t\t\t\t\t       ***Press 1 if you want to search by National ID Number!****\n");
        printf("\t\t\t\t\t\t\t\t       ***Press 2 if you want to search by First and Last Name!****\n");
        printf("\t\t\t\t\t\t\t\t       ***Press 0 if you want to exit the menu!****\n");
        printf("\t\t\t\t\t\t\t\t**********************************************************************************************************\n");
        printf("Your selection -> ");
        scanf("%d",&search_choice);

        // If searching by National ID, the if condition activates and starts checking the required conditions
        if(search_choice ==1)
        {
            char id_no[12];
            int found; // Indicates whether the entered national ID was found among the stored 'current' records.
            found = -1;
            while (found==-1) // 'found' is initialized to -1, meaning we have nothing yet
            {
                int invalid_id; // First we check whether the ID number is valid
                do {
                    invalid_id = 0;
                    printf("Please enter the ID Number of the person you want to search for: ");
                    scanf("%s",id_no);
                    if(strlen(id_no)!=11 || id_no[0]=='0')
                    {
                        invalid_id =1;
                    }
                    for(int i=0;i<11;i++)
                    {
                        if(id_no[i] < '0' || id_no[i] > '9')
                        {
                            invalid_id =1;
                            break;
                        }
                    }
                    if(invalid_id)
                    {
                        printf("Please enter a valid national ID number!\n");
                    }

                }while(invalid_id);

                for(int i =0;i<current;i++) // A for loop checks everyone in our current people list
                {
                    if(strcmp(people[i].id_no,id_no) == 0) // If the comparison function finds the ID in our people list, 'found' is set to that element's index
                    {
                        found = i;
                        break;
                    }
                }
                if(found==-1) // If not found, this message is printed to the console
                {
                    printf("The ID Number you entered does not match our records. Please try again!\n");
                }
                else // Once found, the subscriber's information is printed to the console as follows...
                {
                    sleep(3);

                    printf("\n--- SUBSCRIBER INFORMATION ---\n");
                    printf("National ID: %s\n", people[found].id_no);
                    printf("Full Name: %s %s\n", people[found].first_name, people[found].last_name);
                    printf("Age: %s\n", people[found].age);
                    printf("Phone: %s\n", people[found].phone_no);
                    printf("Phone assignment date: %d/%d/%d\n",people[found].first_date.day,people[found].first_date.month,people[found].first_date.year);
                    printf("Address: %s\n", people[found].address);
                    printf("Current Operator: %s\n", people[found].op_name);
                    printf("Previous Operators: %s - %s\n ", people[found].prev_op1, people[found].prev_op2);
                }
            }
        }
            // We also have the option to find a subscriber by first and last name.
        else if(search_choice == 2)
        {
            char name[30], surname[30]; // name and surname defined with max 30 characters
            int found = -1; // 'found' set to -1 to indicate nothing has been found yet.

            printf("Please enter the subscriber's first name: ");
            scanf("%s", name);
            printf("Please enter the subscriber's last name: ");
            scanf("%s", surname);

            for(int i = 0; i < current; i++)
            {
                if(strcmp(people[i].first_name, name) == 0 && strcmp(people[i].last_name, surname) == 0)
                    // If both first and last name match a record in our current people list, 'found' is set to that element's index
                {
                    found = i;
                    break;
                }
            }
            if(found == -1) // If not found, this message is printed to the console...
            {
                printf("No subscriber found with this name!\n");
            }
            else // If found, the subscriber's information is printed to the screen...
            {
                sleep(3);

                printf("\n--- SUBSCRIBER INFORMATION ---\n");
                printf("National ID Number: %s\n", people[found].id_no);
                printf("Full Name: %s %s\n", people[found].first_name, people[found].last_name);
                printf("Age: %s\n", people[found].age);
                printf("Phone: %s\n", people[found].phone_no);
                printf("Phone assignment date: %d/%d/%d\n",people[found].first_date.day,people[found].first_date.month,people[found].first_date.year);
                printf("Address: %s\n", people[found].address);
                printf("Current Operator: %s\n", people[found].op_name);
                printf("Previous Operators: %s - %s\n ", people[found].prev_op1, people[found].prev_op2);
            }
        }
        else if(search_choice == 0) // Pressing 0 exits the subscriber search menu and returns to the main menu.
        {
            printf("Exiting...\n");
            sleep(1);
            printf("Redirecting to Main Menu...\n");
            sleep(2);
        }

        else if(search_choice != 0)
        {
            printf("Invalid selection!\n");
        }

    }while(search_choice !=0);



}

// OPERATOR CHANGE FUNCTION
void operatorChange()
{
    int year; // year variable defined
    printf("Please enter the year you want to view: ");
    scanf("%d",&year);

    int displayed =0; // Same purpose as the 'found' variable used previously — tracks whether anything was displayed.
    printf("\nOperator changes in %d:\n", year);

    for(int i = 0; i < current; i++)
    {

        if(people[i].op1_end.year == year) // In our data set or memory, if op1 or op2 end years match the entered year, it means an operator change occurred.
        {
            printf("%s %s %s: %s --> %s\n", // Prints the person's name, surname, previous op1, and current operator.
                   people[i].first_name,
                   people[i].last_name,
                   people[i].phone_no,
                   people[i].prev_op1,
                   people[i].op_name);
            displayed = 1;
        }


        if(people[i].op2_end.year == year) // In our data set or memory, if op1 and op2 end years match, it means an operator change occurred.
        {
            printf("%s %s %s: %s --> %s\n", // Prints the person's name, surname, previous op2, and current operator.
                   people[i].first_name, // name
                   people[i].last_name,
                   people[i].phone_no,
                   people[i].prev_op2,
                   people[i].op_name);
            displayed = 1;
        }
    }
    if(displayed == 0) // If no data was found, this message is printed to the screen.
    {
        printf("There are no subscribers with an operator change in the year you requested!\n");
    }

}

// LOYALTY FUNCTION
void loyalty()
{
    int turkcell=0,vodafone=0,turktelekom=0,bimcell=0; // All current operators are defined and initialized to 0

    for(int i=0;i<current;i++) // Iterates through all current people with a for loop
    {
        if(strcmp(people[i].prev_op1,people[i].op_name)==0 && strcmp(people[i].prev_op2,people[i].op_name)==0)
            // If old op1 and op2 both match the current operator (op_name), loyal customers are found and their info is printed.
        {
            printf("Loyal subscribers: %s %s %s %s %s\n",
                   people[i].first_name,
                   people[i].last_name,
                   people[i].op_name,
                   people[i].phone_no,
                   people[i].age);
            if(strcmp(people[i].op_name,"Turkcell")==0) // If loyal to Turkcell, Turkcell counter increases
            {
                turkcell++;
            }
            else if(strcmp(people[i].op_name,"Vodafone")==0) // If loyal to Vodafone, Vodafone counter increases
            {
                vodafone++;
            }
            else if(strcmp(people[i].op_name,"Turk Telekom")==0) // If loyal to Turk Telekom, Turk Telekom counter increases
            {
                turktelekom++;
            }
            else if(strcmp(people[i].op_name,"Bimcell")==0) // If loyal to Bimcell, Bimcell counter increases
            {
                bimcell++;
            }


        }

    }
    // After a 2-second delay, prints how many subscribers are loyal to each operator.
    sleep(2);
    printf("Number of subscribers loyal to Turkcell: %d\n",turkcell);
    printf("Number of subscribers loyal to Vodafone: %d\n",vodafone);
    printf("Number of subscribers loyal to Turk Telekom: %d\n",turktelekom);
    printf("Number of subscribers loyal to Bimcell: %d\n",bimcell);



}

// CAMPAIGN FUNCTION
void campaign()
{
    int counter[1000],campaign_count=0; // counter and campaign count defined
    char campaign_list[1000][50];
    int found; // and the 'found' variable is defined

    for(int i=0;i<current;i++) // We examine all current people one by one
    {
        found =-1;
        for(int j=0;j<campaign_count;j++) // This time I used the j variable for our campaign count.
        {
            if(strcmp(people[i].campaign,campaign_list[j])==0) // The comparison function checks whether the campaigns of current people are equal
            {
                found=j;
                break;
            }
        }
        if(found!=-1)
        {
            counter[found]++; // We increment those found with the counter
        }

        else
        { // If this campaign hasn't been added to our list before, it recognizes it as a new campaign and increments the campaign count by 1
            strcpy(campaign_list[campaign_count], people[i].campaign);
            counter[campaign_count] = 1;
            campaign_count++;
        }
    }

    for(int i=0;i<campaign_count-1;i++) // This is the descending sort loop
    {
        int maxIndex=i;

        for(int j=i+1;j<campaign_count;j++)
        {
            if(counter[j] > counter[maxIndex])
            {
                maxIndex=j;
            }

        }
        if(maxIndex!=i) // I used the classic selection sort method we learned in class.
        {
            int temp = counter[i];
            counter[i]=counter[maxIndex];
            counter[maxIndex]=temp;
            char tempName[50];
            strcpy(tempName,campaign_list[i]);
            strcpy(campaign_list[i],campaign_list[maxIndex]);
            strcpy(campaign_list[maxIndex],tempName);

        }

    }
    printf("\n*** CAMPAIGN POPULARITY ANALYSIS ***\n"); // The analysis section we were asked for is printed to the screen here
    for(int i = 0; i < campaign_count; i++)
    {
        printf("%s : %d subscribers\n", campaign_list[i], counter[i]);
    }


}



int main()
{

// The main function calls all the functions defined above
    int choice;
    setlocale(LC_ALL,"turkish");
    do{
        MainMenu(); // The program always starts with the main menu and stays active until the user exits.
        scanf("%d",&choice);

        // Using a switch-case structure to determine which function to call based on the user's selection
        switch (choice) {

            case 1:
                addSubscriber();
                break;
            case 2:
                deleteSubscriber();
                break;
            case 3:
                updateSubscriber();
                break;
            case 4:
                searchSubscriber();
                break;
            case 5:
                operatorChange();
                break;
            case 6:
                loyalty();
                break;
            case 7:
                campaign();
                break;
            case 0: // If the user wants to exit, a message is shown and the program ends with a small effect, just like how it started.
                printf("Program is closing");
                for(int i=0;i<3;i++)
                {
                    printf(".");
                    fflush(stdout);
                    sleep(1);
                }
                printf("\nThank You.");
                break;
            default:
                printf("You made an invalid selection. Please try again.\n");
        }

    }while(choice != 0);

    return 0;
}