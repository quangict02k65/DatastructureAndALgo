#include<stdio.h>

#define MAX_ELENMENT 100

typedef struct phoneaddress{
	char name[20];
	char tell[11];
	char email[25];
}phoneaddress;

int main(){
	FILE *fp;
	phoneaddress contact[MAX_ELENMENT];
	int i, n, irc;

	printf("How many contacts do you want to enter ( < 100) ? \n");
	scanf("%d", &n);
	getchar();

	for(i = 0; i < n; i++){
		printf("Input data for the contact %d: \n", i+1);
		printf("Name: ");scanf("%[^\n]%*c", contact[i].name);
		printf("Tel: "); scanf("%[^\n]%*c", contact[i].tell);
		printf("Email: "); scanf("%[^\n]%*c", contact[i].email);
	}

	//write the entire array into the file phonebook.dat
	//open the file

	if((fp = fopen("phonebook.dat", "w+b")) == NULL){
		printf("Can not open %s. \n", "phoneaddress.dat");
		return -1;
	}
	//Write the entire array into the file 
	irc = fwrite(contact, sizeof(phoneaddress), n, fp); //ghi file
	printf("fwrite return code = %d\n", irc);
	fclose(fp);

	//read data from the file and write to the array contactR
	//open the file
	if((fp = fopen("phonebook.dat", "r+b")) == NULL){
		printf("Can not open %s . \n", "phonebook.dat");
		return -1;
	}

	//read data from the file and write to array contactR
	phoneaddress contactR[MAX_ELENMENT];
	irc = fread(contactR, sizeof(phoneaddress), n, fp); //doc file roi ghi vao contactR.
	printf("Fread return code = %d \n", irc);

	//write content of array contactR to screen 
	printf("Data of %d contacts in the file \n", n);
	
	for(i = 0; i < n; i++){
		printf("Name : %s; Tel: %s; Email: %s \n", contactR[i].name, contactR[i].tell, contactR[i].email);
	
	}
	fclose(fp);



	printf("size of one contact is: %d", sizeof(contact));




	return 0;
}