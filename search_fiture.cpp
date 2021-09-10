#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Item{
	char itemName[100];
	int itemPrice;
	int itemQty;
};

typedef struct Item list;

void addMenu(struct Item *list, int *i);

void removeMenu(struct Item *list, int i);

void viewMenu(struct Item *list, int *i);

int searchItem(struct Item *list, int left, int right, char name[]);

void mergeSort(struct Item *list, int left, int right);

void merge(struct Item *list, int left, int mid, int right);

int linearSearch(struct Item *list, char *name);

int binarySearch(struct Item *list, char name[], int left, int right);

int main(){
	int choice = -1, i = 0;
	list shop[100];
	FILE *fptr;
	for(int k=0; k<100; k++){
		strcpy(shop[k].itemName, "Empty");
		shop[k].itemPrice = shop[k].itemQty = 0;
	}
	do{
		puts("Shopping Cart Program");
		puts("1. Add Item");
		puts("2. Remove Item");
		puts("3. View List");
		puts("4. Store Item");
		puts("5. Search Item");
		puts("6. Sort Item");
		puts("7. Exit");
		printf("Pick a menu >> ");
		scanf("%d", &choice);
		getchar();
		switch(choice){
			case 1:{
				addMenu(shop, &i);
//				char name[100];
//				int price;
//				int qty;
//				int len;
//				do{
//					printf("Input Item Name [6-35 character]: ");
//					scanf("%[^\n]", name);
//					len = strlen(name);
//					getchar();
//				}while(len < 6 || len > 35);
//	
//	do{
//		printf("Input Item price [1000 - 100000]: ");
//		scanf("%d", &price);
//		getchar();
//	}while(price < 1000 || price > 100000);
//	
//	do{
//		printf("Input Item price [1 - 10]: ");
//		scanf("%d", &qty);
//		getchar();
//	}while(qty < 1 || qty > 10);
//	
//	strcpy(shop[i].itemName, name);
//	shop[i].itemPrice = price;
//	shop[i].itemQty = qty;
	
//	i += 1;
				printf("%d\n", i);
				break;
}
			case 2:{
//				removeMenu(itemList, i);
char name[100];
	int loc = -1;
	
	do{
		printf("Input Item Name [6-35 character]: ");
		scanf("%[^\n]", name);
		getchar();
	}while(strlen(name) < 6 && strlen(name) > 35);
	
	loc = linearSearch(shop, name);//searchItem(shop, 0, 99, name);//
	
	if(loc == -1){
		puts("Item not available in list!");
	}
	else{
		strcpy(shop[loc].itemName, "Empty");
		shop[loc].itemPrice = shop[loc].itemQty = 0;
	}
	i--;
				break;
			}
			case 3:{
//				viewMenu(itemList, &i);/
				for(int j=0; j<100; j++){
						printf("element %d: %s %d %d\n", j+1, shop[j].itemName, shop[j].itemPrice, shop[j].itemQty);
			}
				
				
				
				
				puts("shopping list has been stored");
				break;
			}
			case 4:{
				fptr = fopen("shoppinglist.txt", "w");
				if(fptr == NULL){
					puts("Error in opening file !");
					exit(1);
				}
				for(int k=0; k<100; k++){
					fprintf(fptr, "Element#%d:%s,%d,%d\n", k+1, shop[k].itemName, shop[k].itemPrice, shop[k].itemQty);
				}
				fclose(fptr);
				break;
			}
			case 5:{
				char name[100];
				scanf("%s", &name);
//				printf("%s", name);
				int loc = searchItem(shop, 0, i+1, name);
				if(loc == -1) puts("Name not available");
				else printf("%s is at index %d", name, loc);
				break;
			}
			case 6:{
				mergeSort(shop, 0, i-1);
				break;
			}
			case 7:
				puts("Terimakasih telah menggunakan aplikasi ini");
//				free(itemList);
//				itemList = NULL; 
				break;
		}
	}while(choice != 7);
	
	return 0;
}


void addMenu(list *shop, int *i){
	char name[100];
	int price;
	int qty;
	int len;
	do{
		printf("Input Item Name [6-35 character]: ");
		scanf("%[^\n]", name);
		len = strlen(name);
		getchar();
	}while(len < 6 || len > 35);
	
	do{
		printf("Input Item price [1000 - 100000]: ");
		scanf("%d", &price);
		getchar();
	}while(price < 1000 || price > 100000);
	
	do{
		printf("Input Item price [1 - 10]: ");
		scanf("%d", &qty);
		getchar();
	}while(qty < 1 || qty > 10);
	
	strcpy(shop[*(i)].itemName, name);
	shop[*(i)].itemPrice = price;
	shop[*(i)].itemQty = qty;
	
	*(i) += 1;
}

//void removeMenu(struct Item *list, int i){
//	char name[100];
//	int loc = -1;
//	
//	do{
//		printf("Input Item Name [6-35 character]: ");
//		scanf("%[^\n]", name);
//		getchar();
//	}while(strlen(name) < 6 && strlen(name) > 35);
//	
//	loc = /*searchItem(list, 0, i-1, name)*/linearSearch(list, i);
//	
//	if(loc == -1){
//		puts("Item not available in list!");
//	}
//	else{
//		list[loc].itemPrice = list[loc].itemQty = 0;
//		strcpy(list[loc].itemName, "Empty");
//	}
//}

int searchItem(struct Item *list, int left, int right, char *name){
	
	if(left < right){
		int mid = (left+(right-1))/2;
		printf("%d\n", mid);
		if(strcmp(list[mid].itemName, name) == 0) return mid;
		else if(strcmp(list[mid].itemName, name) < 0) searchItem(list, left, mid-1, name);
		else if(strcmp(list[mid].itemName, name) > 0) searchItem(list, mid+1, right, name);
	}
	return -1;
}

void mergeSort(list *shop, int left, int right){
	
	if(left < right){
		int mid = (left + (right-1)) / 2;
		printf("mid skrng = %d\n", mid);
		mergeSort(shop, left, mid);
		mergeSort(shop, mid+1, right);
		merge(shop, left, mid, right);
	}
}

void merge(list *shop, int left, int mid, int right){
	int n = (right-left+1);
	list tempList[n];
	int i,j,k;
	i = left;
	j = mid+1;
	k = 0;
	
	while(i<=mid && j<=right){
		if(strcmp(shop[i].itemName/*->itemName*/, shop[j]/*->*/.itemName) < 0/*shop[i].itemPrice < shop[j].itemPrice*//**/ /*&& ((strcmp(list[i].itemName, "Empty") != 0) || (strcmp(list[j].itemName, "Empty")))*/){
			strcpy(tempList[k]/**/.itemName, shop[i]/**/.itemName);
			tempList[k].itemPrice = shop[i]/*->*/.itemPrice;
			tempList[k].itemQty = shop[i]/*->*/.itemQty;
			printf("templist ke %d diassign data i = %d :\n", k, i);
			printf("%s\n", tempList[k]/**/.itemName);
			printf("%d\n", tempList[k].itemPrice);
			printf("%d\n", tempList[k].itemQty);
//			printf("%s\n", shop[i]/**/.itemName);
//			printf("%d\n", shop[i]/*->*/.itemPrice);
//			printf("%d\n", shop[i]/*->*/.itemQty);
			k++;
			i++;
		}
		else/*(strcmp(list[i].itemName, list[j].itemName) > 0 && ((strcmp(list[i].itemName, "Empty") != 0) && (strcmp(list[j].itemName, "Empty"))))*/{
			strcpy(tempList[k].itemName, shop[j]/*->*/.itemName);
			tempList[k].itemPrice = shop[j]/*->*/.itemPrice;
			tempList[k].itemQty = shop[j]/*->*/.itemQty;
			printf("templist ke %d diassign data j = %d : \n", k, j);
			printf("%s\n", tempList[k]/**/.itemName);
			printf("%d\n", tempList[k].itemPrice);
			printf("%d\n", tempList[k].itemQty);
//			printf("%s\n", shop[j]/**/.itemName);
//			printf("%d\n", shop[j]/*->*/.itemPrice);
//			printf("%d\n", shop[j]/*->*/.itemQty);
			k++;
			j++;
		}
	}
	
	while(i<=mid){
//		strcpy(tempList[k].itemName, list[i].itemName);
			strcpy(tempList[k].itemName, shop[i]/*->*/.itemName);
			tempList[k].itemPrice = shop[i]/*->*/.itemPrice;
			tempList[k].itemQty = shop[i]/*->*/.itemQty;
			printf("templist ke %d diappend data sisaan i dimana i = %d:\n", k, i);
			printf("%s\n", tempList[k]/**/.itemName);
			printf("%d\n", tempList[k].itemPrice);
			printf("%d\n", tempList[k].itemQty);
//			printf("%s\n", shop[i]/**/.itemName);
//			printf("%d\n", shop[i]/*->*/.itemPrice);
//			printf("%d\n", shop[i]/*->*/.itemQty);
			k++;
			i++;
	}
	while(j<=right){
			strcpy(tempList[k].itemName, shop[j]/*->*/.itemName);
			tempList[k].itemPrice = shop[j]/*->*/.itemPrice;
			tempList[k].itemQty = shop[j]/*->*/.itemQty;
			printf("templist ke %d diappend data sisaan j dimana j = %d:\n", k, j);
			printf("%s\n", tempList[k]/**/.itemName);
			printf("%d\n", tempList[k].itemPrice);
			printf("%d\n", tempList[k].itemQty);
//			printf("%s\n", shop[j]/**/.itemName);
//			printf("%d\n", shop[j]/*->*/.itemPrice);
//			printf("%d\n", shop[j]/*->*/.itemQty);
			k++;
			j++;
	}
	
	int ind = 0;
//	for(;ind < right; ind++)
//		printf("%s %d %d\n", )
	for(int i = left; i<=mid; i++){
			strcpy(shop[i].itemName/*->*/, tempList[ind].itemName);
			shop[i]/*->*/.itemPrice = tempList[ind].itemPrice;
			shop[i]/*->*/.itemQty = tempList[ind].itemQty;
			printf("shoplist ke %d diappend data ke %d:\n",i, ind);
//			printf("%s\n", tempList[ind]/**/.itemName);
//			printf("%d\n", tempList[ind].itemPrice);
//			printf("%d\n", tempList[ind].itemQty);
			printf("%s\n", shop[i]/**/.itemName);
			printf("%d\n", shop[i]/*->*/.itemPrice);
			printf("%d\n", shop[i]/*->*/.itemQty);
			ind++;
	}
	
	for(int j=mid+1; j<=right; j++){
		strcpy(shop[j]/*->*/.itemName, tempList[ind].itemName);
		shop[j]/*->*/.itemPrice = tempList[ind].itemPrice;
		shop[j]/*->*/.itemQty = tempList[ind].itemQty;
		printf("shoplist ke %d diappend data ke %d:\n", j, ind);
//		printf("%s\n", tempList[ind]/**/.itemName);
//			printf("%d\n", tempList[ind].itemPrice);
//			printf("%d\n", tempList[ind].itemQty);
			printf("%s\n", shop[j]/**/.itemName);
			printf("%d\n", shop[j]/*->*/.itemPrice);
			printf("%d\n", shop[j]/*->*/.itemQty);
		ind++;
	}
}

int linearSearch(struct Item *list, char* name){
	for(int k=0; k<100; k++){
		if(strcmp(list[k].itemName, name) == 0){
			printf("%d\n", k);
			return k;
		} 
	}
	return -1;
}

int binarySearch(struct Item *list, char name[], int left, int right){
	if(left<right){
		int mid = (left + (right-1))/2;
		if(strcmp(list[mid].itemName, name) == 0) return mid;
		else if(strcmp(list[mid].itemName, name) < 0) return binarySearch(list, name, left, mid-1);
		else if(strcmp(list[mid].itemName, name) > 0) return binarySearch(list, name, mid+1, right);
	}
	return -1;
}
