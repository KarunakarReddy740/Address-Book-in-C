#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) {
    // Sort contacts based on the chosen criteria
    for(int i=0;i<addressBook->contactCount;i++){
        printf("\n%s\t",addressBook->contacts[i].name);
        printf("%s\t",addressBook->contacts[i].phone);
        printf("%s\n",addressBook->contacts[i].email);
    }
  printf("\n_________________________________________________________\n");
    
}

void initialize(AddressBook *addressBook) {
    loadContactsFromFile(addressBook);
  }

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook);

}

void createContact(AddressBook *addressBook)
{
    	/* Define the logic for createContact */
    printf("Enter contact name: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);

    do{
        printf("Enter contact phone number: ");//prompt the user to enter the phone number
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone);//prompt the user to enter the phone number
        if(strlen(addressBook->contacts[addressBook->contactCount].phone) != 10){//check if the phone number is 10 digits
            printf("Invalid phone number. Please enter the 10 digit phone number.\n");
        }

    }while(strlen(addressBook->contacts[addressBook->contactCount].phone) != 10);//loop until the user enters a valid phone number

    do{
        printf("Enter contact email: ");
        scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].email);

        if(!strchr(addressBook->contacts[addressBook->contactCount].email, '@'))
        {
            printf("Invalid email address. Please enter a valid email.\n");

        }
    }while(!strchr(addressBook->contacts[addressBook->contactCount].email, '@'));

    addressBook->contactCount++;
    printf("Contact created successfully.\n");

}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int flag=0;
    int choice_2;
    char searchName[50];
    char searchPhone[11];
    char searchEmail[50];
    do{
        printf("Search contact by:\n");
        printf("1. Name\n");
        printf("2. Phone number\n");
        printf("3. Email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if(scanf("%d", &choice_2) != 1)
        {
        printf("Invalid input.\n");
        while(getchar() != '\n');
            return;
        }

        switch(choice_2){

            case 1:
                flag=0;
                printf("Enter name to search: ");//prompt the user to enter the name to search
                scanf(" %[^\n]", searchName);
                for(int i=0;i<addressBook->contactCount;i++){

                    if(strcmp(searchName,addressBook->contacts[i].name)==0){//compare the name entered by the user with the names in the address book
                        printf("Contact found:\n");
                        printf("Name: %s\n", addressBook->contacts[i].name);
                        printf("Phone number: %s\n", addressBook->contacts[i].phone);
                        printf("Email: %s\n", addressBook->contacts[i].email);
                        flag=1;
                        break;
                    }
                }
                if(flag==0){//if the contact is not found, print a message
                    printf("Contact not found.\n");
                }

                break;

                case 2:
                flag=0;

                printf("Enter phone number to search: ");//prompt the user to enter the phone number to search
                scanf(" %[^\n]", searchPhone);

                for(int i=0;i<addressBook->contactCount;i++)
                {
                    if(strcmp(searchPhone,addressBook->contacts[i].phone)==0){//compare the phone number entered by the user with the phone numbers in the address book
                        printf("Contact found:\n");
                        printf("Name: %s\n", addressBook->contacts[i].name);
                        printf("Phone number: %s\n", addressBook->contacts[i].phone);
                        printf("Email: %s\n", addressBook->contacts[i].email);
                        flag=1;
                        break;
                    }
                }

                if(flag==0){//if the contact is not found, print a message
                    printf("Contact not found. \n");
                }
                break;

                case 3:
                flag=0;
                printf("Enter email to search: ");
                scanf( "%[^\n]", searchEmail);

                for(int i=0;i<addressBook->contactCount;i++)
                {
                    if(strcmp(searchEmail,addressBook->contacts[i].email)==0){//compare the email entered by the user with the emails in the address book
                        printf("Contact found: \n");
                        printf("Name: %s\n",addressBook->contacts[i].name);
                        printf("Phone number: %s\n",addressBook->contacts[i].phone);
                        printf("Email: %s\n",addressBook->contacts[i].email);
                        flag=1;
                        break;
                    }
                }
                if(flag==0){//if the contact is not found, print a message
                    printf("Contact not found. \n");
                }
                break;

            case 4:
                printf("4.Existing search menu. \n");
                break; 

            default:
                printf("Invalid choice. \n");
                break;
            }

    }while(choice_2!=4);
    

}

void editContact(AddressBook *addressBook)
{
    	/* Define the logic for Editcontact */
    int choice_12;
    int index=-1;
    char searchName[50];
    char searchPhone[11];
    char searchEmail[50];

    printf("Search contact to search and edit by:\n");
    printf("1. Name\n");
    printf("2. Phone number\n");
    printf("3. Email\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    if(scanf("%d", &choice_12) != 1)
    {
    printf("Invalid input.\n");
    while(getchar() != '\n');
        return;
    }

    switch(choice_12){

        case 1:
            printf("Enter name to search: ");
            scanf(" %[^\n]",searchName);
            for(int i=0;i<addressBook->contactCount;i++)//loop through the contacts in the address book
            {
                if(strcmp(searchName,addressBook->contacts[i].name)==0){//compare the name entered by the user with the names in the address book
                    index=i;
                    break;
                }

            }
            break;

        case 2:
            printf("Enter phone number to search: ");//prompt the user to enter the phone number to search
            scanf(" %[^\n]",searchPhone);
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(strcmp(searchPhone,addressBook->contacts[i].phone)==0){//compare the phone number entered by the user with the phone numbers in the address book
                    index=i;
                    break;
                }

            }
            break;

            case 3:
            printf("Enter email to search: ");
            scanf(" %[^\n]",searchEmail);
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(strcmp(searchEmail,addressBook->contacts[i].email)==0){//compare the email entered by the user with the emails in the address book
                    index=i;
                    break;
                }

            }
            break;

            case 4:
                printf("4.Existing edit menu. \n");
                break;

            default:
                printf("Invalid choice. \n");
                break;
        }


        if(index!=-1){//if the contact is found, prompt the user to enter the new details
            printf("Enter the name to update name:");
            scanf(" %[^\n]",addressBook->contacts[index].name);

            do
            {
            printf("Enter the phone number to update Phone number:");
            scanf(" %[^\n]",addressBook->contacts[index].phone);

            if(strlen(addressBook->contacts[index].phone)!=10)//check if the phone number is 10 digits
            {
                printf("Invalid phone number. Please enter the 10 digit phone number.\n");
            }

            }while(strlen(addressBook->contacts[index].phone)!=10);//check if the phone number is 10 digits


            do
            {
            printf("Enter the email to update email: ");
            scanf(" %[^\n]",addressBook->contacts[index].email);

            if(!strchr(addressBook->contacts[index].email,'@'))//check if the email contains '@'
            {
                printf("Invalid email address. Please enter a valid email.\n");
            }

            }while(!strchr(addressBook->contacts[index].email,'@'));
            printf("Contact updated successfully. \n");

        }
        else{
            printf("Contact not found. \n");
        }


    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int Search_choice_123;
    int index=-1;
    char searchName[50];
    char searchPhone[11];
    char searchEmail[50];
    printf("Search contact to search and delete by:\n");
    printf("1. Name\n");
    printf("2. Phone number\n");
    printf("3. Email\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    if(scanf("%d", &Search_choice_123) != 1)
    {
    printf("Invalid input.\n");
    while(getchar() != '\n');
    return;
    }

    switch(Search_choice_123){//switch case to search contact by name, phone number or email

        case 1:
        printf("Enter name to search: ");
        scanf(" %[^\n]",searchName);
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(strcmp(searchName,addressBook->contacts[i].name)==0)
                {
                    index=i;
                    break;

                }
                
            }
            break;

        case 2:
        printf("Enter phone number to search: ");
        scanf(" %[^\n]",searchPhone);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(searchPhone,addressBook->contacts[i].phone)==0)
            {
                index=i;
                break;

            }
        }
        break;

    case 3:
    printf("Enter email to search: ");
    scanf(" %[^\n]",searchEmail);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(searchEmail,addressBook->contacts[i].email)==0)//compare the email entered by the user with the emails in the address book
        {
            index=i;
            break;
        }

    }
    break;

    case 4:
        printf("4.Existing delete menu. \n");
        break;

    default:
        printf("Invalid choice. \n");
        break;

    }
    if(index!=-1)//if the contact is found, delete the contact by shifting the contacts in the array
    {
        for(int i=index;i<addressBook->contactCount-1;i++)
        {
            addressBook->contacts[i]=addressBook->contacts[i+1];
        }
        addressBook->contactCount--;
        printf("Contact deleted successfully. \n");

    }
    else
    {
        printf("Contact not found. \n");
    }
   
}
