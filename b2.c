#include <stdio.h>
#include <string.h>
#define size 10

struct contact_manager {
    char name[size];
    char mobile[size];
    char email[size];
};

void sort_contacts(struct contact_manager contact[], int n) {
    struct contact_manager temp;
	int i,j;
    for ( i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(contact[i].name, contact[j].name) > 0) {
                temp = contact[i];
                contact[i] = contact[j];
                contact[j] = temp;
            }
       }
    }
}

void binary_search(struct contact_manager contact[], char sname[], int n) {
    int low = 0, high = n - 1, mid, found = 0, cmp,k=0;

    while (low <= high) {
		++k;
		printf("number of pass:%d\n",k);
        mid = (low + high) / 2;
        cmp = strcmp(contact[mid].name, sname);
        if (cmp == 0) {
            printf("\nContact Found:\n");
            printf("Name: %s\n", contact[mid].name);
            printf("Mobile: %s\n", contact[mid].mobile);
            printf("Email: %s\n", contact[mid].email);
            found = 1;
            break;
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found)
        printf("Contact not found.\n");
}

int main() {
    struct contact_manager contact[size];
    int n,i;
    char sname[];

    printf("How many users to save: ");
    scanf("%d", &n);

    if (n > size) {
        printf("Limit exceeded. Max allowed is %d.\n", size);
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nGive information of user %d\n", i + 1);
        printf("Enter your name: ");
        scanf("%s", contact[i].name);

        printf("Enter your email ID: ");
        scanf("%s", contact[i].email);

        printf("Enter your mobile number: ");
        scanf("%s", contact[i].mobile); 
    }

    printf("Enter name to search: ");
    scanf("%s", sname);

    sort_contacts(contact, n);
    binary_search(contact, sname, n);

    return 0;
}
/*
How many users to save: 4

Give information of user 1
Enter your name: pushkar
Enter your email ID: pushar@gmail
Enter your mobile number: 344244

Give information of user 2
Enter your name: sager
Enter your email ID: sager@gmail
Enter your mobile number: 3453245577

Give information of user 3
Enter your name: krishna
Enter your email ID: sonale@gmail
Enter your mobile number: 34728335

Give information of user 4
Enter your name: aniket
Enter your email ID: andy@gmail
Enter your mobile number: 976756667
Enter name to search: sager
number of pass:1
number of pass:2

Contact Found:
Name: sager
Mobile:3453245577
Email: sager@gmai

Press Enter to return to Quincy...
*/

