#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fp;
    fp = fopen("contacts.txt", "w");
    if(fp==NULL)
    {
        printf("Error opening file for writing. \n");
        return;
    }
    else{
        for(int i=0;i<addressBook->contactCount;i++)
        {
            fprintf(fp,"%s\n",addressBook->contacts[i].name);// Write the name to the file
            fprintf(fp,"%s\n",addressBook->contacts[i].phone);
            fprintf(fp,"%s\n",addressBook->contacts[i].email);

        }
    }
    fclose(fp);
    printf("%d contacts saved successfully to contacts.txt\n",addressBook->contactCount);
  
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fp;
    fp = fopen("contacts.txt", "r");
    if(fp==NULL)
    {
        printf("No existing contacts found.\n");
        return;
    }
    addressBook->contactCount=0;
    for(int i=0;i<100;i++){
        if(fscanf(fp, " %[^\n]",addressBook->contacts[i].name)!=1)
        {
            break;
        }
        fscanf(fp, " %[^\n]",addressBook->contacts[i].phone);
        fscanf(fp, " %[^\n]",addressBook->contacts[i].email);
        addressBook->contactCount++;
    }
    
    fclose(fp);
     printf("%d contacts loaded successfully from contacts.txt\n",addressBook->contactCount);
    
}
