#include<stdio.h>
#define CHAR_LIMIT 255
#define MAX_TIERS 3

struct Tier
{
	int id;
	char title[CHAR_LIMIT];
	double price;
};

struct Customer
{
	int id;
	char fName[CHAR_LIMIT];
	char lName[CHAR_LIMIT];
	int tierSubscription;
	int numberOfWashUsed;
};

int main() {
	int isEOD = 0, isValid = 0, isClientVip = 0, 
	isClientUseFreeWash = 0, vipID = -1, tierUsed = -1, i = 0;
	char container = ' ';

	struct Tier currentTier = { 0 };
	struct Customer currentCustomer = { 0 };
	
	

	struct Tier tiers[MAX_TIERS] = {
		{ 1, "Basic", 4.00},
		{ 2, "Clean", 10.00},
		{ 3, "Super Clean", 17.00}
	};

	struct Customer custVIP[MAX_TIERS] = {
		{ 1, "Stan", "Smith", 2, 0},
		{ 2, "John", "Doe", 1, 0},
		{ 3, "Test", "User", 3, 1},
	};

	while (!isEOD)
	{
		isValid = 0;
		while (!isValid)
		{
			printf("Is it End of Day?(y/n): ");
			scanf(" %c", &container);

			if(container == 'Y' || container == 'y') {
				isValid = 1;
				isEOD = 1;
			} else if(container == 'N' || container == 'n') {
				isValid = 1;
				isEOD = 0;
			} else {
				printf("Please enter the correct values\n");
			}
		};

		if(!isEOD) {

			isValid = 0;
			while (!isValid)
			{
				printf("Are you a VIP?(y/n): ");
				scanf(" %c", &container);

				if(container == 'Y' || container == 'y') {
					isValid = 1;
					isClientVip = 1;
				} else if(container == 'N' || container == 'n') {
					isValid = 1;
					isClientVip = 0;
				} else {
					printf("Please enter the correct values\n");
				}
			};


			if(isClientVip) {
				isValid = 0;
				while (!isValid)
				{
					printf("Please enter id number (enter -1 to quit): ");
					scanf("%d", &vipID);

					if(vipID == -1) {
						isValid = 1;
					}

					for(i = 0; i < MAX_TIERS; i++) {
						if(vipID == custVIP[i].id) {
							currentCustomer = custVIP[i];
							isValid = 1;
							printf("Good Morning sir %s %s\n", currentCustomer.fName, currentCustomer.lName);
						}
					}

					if(!isValid) {
						printf("Please enter the correct values\n");
						vipID = -1;
					}
				}

				if(vipID > -1) {
					isValid = 0;
					while (!isValid)
					{
						printf("Do you want to use your free wash?(y/n): ");
						scanf(" %c", &container);

						if(container == 'Y' || container == 'y') {
							isValid = 1;
							isClientUseFreeWash = 1;
						} else if(container == 'N' || container == 'n') {
							isValid = 1;
							isClientUseFreeWash = 0;
						} else {
							printf("Please enter the correct values\n");
						}
					}; 
				}
			}

			isValid = 0;
			while (!isValid)
			{
				printf("\nSELECT TIERS\n");
				for(i = 0; i < MAX_TIERS; i++) {
					printf("TIER-%d, %s $%.2lf\n", tiers[i].id, tiers[i].title, tiers[i].price);
				}

				printf("\n\n");

				printf("Please TIER NUMBER YOU WANT(enter -1 to quit): ");
				scanf("%d", &tierUsed);

				if(tierUsed == -1) {
					isValid = 1;
				}

				for(i = 0; i < MAX_TIERS; i++) {
					if(tierUsed == tiers[i].id) {
						currentTier = tiers[i];
						isValid = 1;
					}
				}

				if(!isValid) {
					printf("Please enter the correct values\n");
					tierUsed = -1;
				}
			}


			if(tierUsed > -1) {
				if(vipID > -1) {
					if (currentCustomer.tierSubscription == currentTier.id) {
						if (isClientUseFreeWash) {
							printf("YOU USED YOUR FREE WASH THANK YOU\n");
							
							for(i = 0; i < MAX_TIERS; i++) {
								if(vipID == custVIP[i].id) {
									custVIP[i].numberOfWashUsed++;
								}
							}
						} else {
							printf("YOU DIDN'T USE FREE WASH THANK YOU\n");
							printf("YOU HAVE BEEN CHARGED %.2lf\n", currentTier.price);
						}
					} else {
						if (isClientUseFreeWash) {
							printf("YOU ARE NOT SUBSCRIBED TO THIS PLEASE DO AGAIN\n");
						} else {
							printf("YOU HAVE BEEN CHARGED %.2lf\n", currentTier.price);
						}
					}
				} else {
					printf("YOU HAVE BEEN CHARGED %.2lf\n", currentTier.price);
				}
			} else {
				printf("See you next time\n");
			}

		}

	};
	
	
	
	return 0;
}