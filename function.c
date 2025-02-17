#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include"function.h"
#include"datatype.h"
void mainmenu(){
	int choice;
	setColor(2);
	printf("\t%5s\n","***Student Management System Using C***");
	printf("\t%25s\n","CHOOSE YOUR ROLE");
	printf("%36s\n","======================");
	printf("%24s\n","[1] Admin.");
	printf("%25s\n","[2] Client.");
	printf("%35s\n","[0] Exit the program.");
	printf("%36s\n","======================");
	printf("%32s","Enter the choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:{
			system("cls");
			login();
			break;
		}
//		case 2:{
//			system("cls");
//			client();
//			break;
//		}
//		case 0:{
//			printf("Exit the program");
//			break;
//		}
	}
}


void login(){
	setColor(4);
	char email[50];
	char pass[20];
    char correctEmail[40];
    char correctPass[20];
    FILE *file = fopen("admin.txt", "r");
    if (file == NULL) {
    perror("Khong the mo file admin.txt");
    return;
    }
    fscanf(file, "%s %s", correctEmail, correctPass);
    fclose(file);
	while(1){
	printf("\n");
	printf("\t%5s\n","***Library Management System Using C***");
	printf("%28s\n","LOGIN");
    printf("%36s\n","======================");
    printf("%20s","Email:");
    scanf("%s",email);
    printf("%23s","Password:");
    int mk = 0;
    char ch;
    while(1){
    	ch = getch();
    	if(ch == 13){
    		break;
		}else if(ch == 8){
			if( mk > 0){
				mk--;
				printf("\b \b");
			}
		}
		else{
			if(mk <sizeof(pass)-1){
				pass[mk++] = ch;
				printf("*");
			}
		}
	}
	pass[mk] = '\0';
    printf("%36s\n","======================\n");
    if(strcmp(email,correctEmail) == 0 && strcmp(pass,correctPass) == 0){
    	system("cls");
    	admin();
    	break;
	}else{
		printf("Sai mat khau hoac email,vui long nhap lai.");
	}
}
};





void displaybook(){
	system("cls");
	setColor(6);
	int choice1;
	printf("\n=====BookManage=====\n");
	printf("\n[1]. Hien thi danh sach sach.");
	printf("\n[2]. Them sach.");
	printf("\n[3]. Chinh sua thong tin sach.");
	printf("\n[4]. Xoa sach");
	printf("\n[5]. Tim kiem sach.");
	printf("\n[6].Thoat giao dien.");
	printf("\n====================\n");
	printf("Nhap lua chon: ");
	scanf("%d",&choice1);
	switch(choice1){
		case 1:{
			system("cls");
			display();
			returntomenu();
			break;
		}
		case 2:{
			system("cls");
			add();
			returntomenu();
			break;
		}
		case 3:{
			system("cls");
			changeInfobook();
			returntomenu();
			break;
		}
		case 4:{
			system("cls");
			deletebook();
			returntomenu();
			break;
		}
		case 5:{
			system("cls");
			searchbook();
			returntomenu();
			break;
		}
		case 6:{
			system("cls");
			admin();
			break;
		}
	}
}




void add(){
	FILE *file = fopen("book.txt","a");
	if(file == NULL){
		perror("loi khong mo duoc file");
		exit(1);
	}
	Book sach;
	int validinput = 0;
	while(!validinput){
		validinput = 1;
		printf("Nhap ID(toi da 10 ki tu): ");
		scanf("%s",sach.bookID);
		if(strlen(sach.bookID) == 0 || strlen(sach.bookID) > 10){
			printf("ID khong duoc rong hay lon hon 10 ky tu.\n");
			validinput = 0;
			continue;
		}
		FILE *checkfile = fopen("book.txt","r");
		if(checkfile != NULL){
			Book existbook;
			while(fscanf(checkfile,"%10[^,],%30[^,],%20[^,],%d,%d,%d\n",existbook.bookID,existbook.title,existbook.author,&existbook.price,&existbook.publication.year,&existbook.amountofbook) == 6){
				if(strcmp(existbook.bookID,sach.bookID) == 0){
					printf("ID da ton tai.Vui long nhap ID khac.\n");
					validinput = 0;
					break;
				}
			}
			fclose(checkfile);
		}
		if(!validinput) continue;
		
		getchar();
        printf("Nhap ten sach (max 30 ky tu): ");
        fgets(sach.title, sizeof(sach.title), stdin);
        sach.title[strcspn(sach.title, "\n")] = '\0';

        if (strlen(sach.title) == 0 || strlen(sach.title) > 30) {
            printf("Ten sach khong duoc rong va phai nho hon 30 ky tu.\n");
            validinput = 0;
            continue;
        }
         checkfile = fopen("book.txt", "r");
        if (checkfile != NULL) {
            Book existbook;
            while (fscanf(checkfile, "%10[^,],%30[^,],%20[^,],%d,%d,%d\n", existbook.bookID, existbook.title, existbook.author, &existbook.price, &existbook.publication.year, &existbook.amountofbook) == 6) {
                if (strcmp(existbook.title, sach.title) == 0) {
                    printf("Ten sach da ton tai. Vui long nhap ten sach khac.\n");
                    validinput = 0;
                    break;
                }
            }
            fclose(checkfile);
        }
        if (!validinput) continue;

        printf("Nhap ten tac gia: ");
        fgets(sach.author, sizeof(sach.author), stdin);
        sach.author[strcspn(sach.author, "\n")] = '\0';

        if (strlen(sach.author) == 0) {
            printf("Ten tac gia khong duoc rong.\n");
            validinput = 0;
            continue;
        }

        printf("Nhap gia: ");
        if (scanf("%d", &sach.price) != 1 || sach.price <= 0) {
            printf("Gia phai la mot so duong.\n");
            validinput = 0;
            continue;
        }

        printf("Nhap nam sang tac: ");
        if (scanf("%d", &sach.publication.year) != 1 || sach.publication.year <= 0) {
            printf("Nam xuat ban phai la mot so duong.\n");
            validinput = 0;
            continue;
        }
        
        printf("Nhap So luong moi: ");
        if (scanf("%d",&sach.amountofbook) != 1 ||sach.amountofbook <= 0) {
            printf("SO luong phai lon hon 1.\n");
            validinput = 0;
            continue;
}

        fprintf(file, "%s,%s,%s,%d,%d,%d\n", sach.bookID, sach.title, sach.author, sach.price, sach.publication.year,sach.amountofbook);
        printf("Them thanh cong vao thu vien\n");
    }

    fclose(file);
}

void display(){
	    FILE *file = fopen("book.txt", "r");
    if (file == NULL) {
        perror("Khong the mo file");
        return;
    }

	Book sach[10];
	int count = 0;

	while(fscanf(file,"%10[^,],%30[^,],%20[^,],%d,%d,%d\n",sach[count].bookID,sach[count].title,sach[count].author,&sach[count].price,&sach[count].publication.year,&sach[count].amountofbook) == 6){
		count++;
	}
		fclose(file);
		
	 if (count == 0) {
        printf("Khong co sach nao trong thu vien.\n");
        return;
    }
		
			
	printf("\n|----|----------------------|----------------|---------|----------|--------|");
    printf("\n|%-4s|%-22s|%-16s|%-9s|%-10s|%-6s|", "ID", "Ten Sach", "Tac Gia", "Gia Ban", "NXB","So Luong");
    printf("\n|----|----------------------|----------------|---------|----------|--------|");
    for (int i = 0; i < count; i++) {
        printf("\n|%-4s|%-22s|%-16s|%-9d|%-10d|%-8d|", sach[i].bookID, sach[i].title, sach[i].author, sach[i].price, sach[i].publication.year,sach[i].amountofbook);
    }
    printf("\n|----|----------------------|----------------|---------|----------|--------|\n");

    
    int sortchoice;
    printf("Ban co muon sap xep theo gia khong(1.Co/2.Khong): ");
    scanf("%d",&sortchoice);
    if(sortchoice == 1){
    	system("cls");
    	int orderchoice;
    	printf("Chon thu tu sap xep:\n");
    	printf("[1].Gia tang\n");
    	printf("[2].Gia giam\n");
    	printf("Nhap lua chon: ");
    	scanf("%d",&orderchoice);
    	
    	for(int i = 0;i < count-1;i++){
    		for(int j = i + 1;j < count;j++){
    			if((orderchoice == 1 && sach[i].price > sach[j].price) || (orderchoice == 2 && sach[i].price < sach[j].price)){
    				Book temp = sach[i];
    				sach[i] = sach[j];
    				sach[j] = temp;
				}
			}
		}
		printf("\n|----|----------------------|----------------|---------|----------|--------|");
        printf("\n|%-4s|%-22s|%-16s|%-9s|%-10d|%-6d|", "ID", "Ten Sach", "Tac Gia", "Gia Ban", "NXB","So luong");
        printf("\n|----|----------------------|----------------|---------|----------|------|");
        for (int i = 0; i < count; i++) {
            printf("\n|%-4s|%-22s|%-16s|%-9d|%-10d|%-6d|", sach[i].bookID, sach[i].title, sach[i].author, sach[i].price, sach[i].publication.year,sach[i].amountofbook);
        }
        printf("\n|----|----------------------|----------------|---------|----------|--------|\n");
    }
}




void changeInfobook(){
	FILE *file = fopen("book.txt","r");
	if(file == NULL){
		printf("Khong the mo file");
		return;
	}
	Book book[10];
	int count = 0;
	while(fscanf(file,"%10[^,],%30[^,],%20[^,],%d,%d,%d\n",book[count].bookID,book[count].title,book[count].author,&book[count].price,&book[count].publication.year,&book[count].amountofbook) == 6){
		count++;
	}
	fclose(file);
	
	
char id[10];
printf("Nhap ID cua sach can thay doi thong tin: ");
scanf("%s",id);
getchar();
int found = 0;
for(int i = 0;i < count;i++){
	if(strcmp(book[i].bookID, id)== 0){
		found = 1;
		printf("Nhap ten sach moi: ");
		fgets(book[i].title,sizeof(book[i].title),stdin);
		book[i].title[strcspn(book[i].title,"\n")] = '\0';
		
		while (strlen(book[i].title) == 0 || strlen(book[i].title) > 30) {
            printf("Ten sach khong duoc rong va phai nho hon 30 ky tu.Vui long nhap lai.");
            fgets(book[i].title, sizeof(book[i].title), stdin);
            book[i].title[strcspn(book[i].title, "\n")] = '\0'; 
            }
		
		printf("Nhap ten tac gia: ");
		fgets(book[i].author,sizeof(book[i].author),stdin);
		book[i].author[strcspn(book[i].author,"\n")] = '\0';
		
		while (strlen(book[i].author) == 0) {
            printf("Ten tac gia khong duoc rong.Vui long nhap lai: ");
            fgets(book[i].author, sizeof(book[i].author), stdin);
            book[i].author[strcspn(book[i].author, "\n")] = '\0'; 
            }
		
		printf("Nhap gia moi: ");
		while(scanf("%d",&book[i].price) != 1 || book[i].price <= 0){
			printf("Gia nhap khong hop le.\n");
			printf("Vui long nhap lai: ");
			while (getchar() != '\n');
			scanf("%d",&book[i].price);
		}
		
		printf("Nhap  nam xuat ban moi: ");
		while (scanf("%d", &book[i].publication.year) != 1 || book[i].publication.year <= 0) {
            printf("Nam xuat ban khong hop le.\n");
            printf("Vui long nhap lai: ");
            while (getchar() != '\n');
            scanf("%d", &book[i].publication.year);
        }
        
        printf("Nhap so luong sach moi: ");
        while(scanf("%d",&book[i].amountofbook) != 1 || book[i].amountofbook <= 0){
        	printf("So luong khong hop le.\n");
        	printf("Vui long nhap lai: ");
        	while(getchar() != 'n');
        	scanf("%d",&book[i].amountofbook);
		}
		break;
	}
}
if(!found){
	printf("Khong tim thay sach trung voi ID: %s\n",id);
	return;
}
file = fopen("book.txt","w");
if(file == NULL){
	printf("Khong the mo file\n");
	return;
}
for(int i = 0;i < count;i++){
	fprintf(file,"%s,%s,%s,%d,%d,%d\n",book[i].bookID,book[i].title,book[i].author,book[i].price,book[i].publication.year,book[i].amountofbook);
}
fclose(file);
printf("Cap nhat thong tin thanh cong\n");
}



void returntomenu(){
	int choice2;
	printf("\nNhan 1 quay ve man hinh chinh: ");
	scanf("%d",&choice2);
	if(choice2 == 1){
	system("cls");
	displaybook();
}
}



void deletebook(){
	FILE *file = fopen("book.txt","r");
	if(file == NULL){
		printf("Khong the mo file");
		return;
	}
	Book book[10];
	int count = 0;
	while(fscanf(file,"%10[^,],%30[^,],%20[^,],%d,%d,%d\n",book[count].bookID,book[count].title,book[count].author,&book[count].price,&book[count].publication.year,&book[count].amountofbook) == 6){
		count++;
	}
	fclose(file);
	char id[10];
	printf("Nhap ID sach can xoa:");
	scanf("%s",id);
	getchar();
	int found = 0;
	for(int i = 0;i < count;i++){
		if(strcmp(book[i].bookID,id)==0){
			found = 1;
			char confirm;
			printf("Ban co chac muon xoa ID %s ko(y/n): ",id);
			scanf("%c",&confirm);
			if(confirm == 'y' || confirm == 'Y'){
				file = fopen("book.txt","w");
				if(file == NULL){
					printf("Khong the mo file\n");
					return;
				}
				for(int j = 0;j<count;j++){
					if(j != i){
						fprintf(file,"%s,%s,%s,%d,%d,%d\n",book[j].bookID,book[j].title,book[j].author,book[j].price,book[j].publication.year,book[j].amountofbook);
					}
				}
				fclose(file);
				printf("Xoa thanh cong.\n");
			}else{
				printf("Huy thao tac xoa.\n");
			}
			break;
		}
	}
	if(!found){
		printf("Khong tim thay sach.\n");
	}
}



void searchbook() {
    FILE *file = fopen("book.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file\n");
        return;
    }

    Book book[10];
    int count = 0;

    while (fscanf(file, "%10[^,],%30[^,],%20[^,],%d,%d,%d\n", book[count].bookID, book[count].title, book[count].author, &book[count].price, &book[count].publication.year,&book[count].amountofbook) == 6) {
        count++;
    }
    fclose(file);

    char searchTitle[30];
    printf("Nhap ten sach muon tim: ");
    getchar(); 
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; 

    int found = 0;
    printf("\n|----|----------------------|----------------|---------|----------|--------|");
    printf("\n|%-4s|%-22s|%-16s|%-9s|%-10s|%-8s|", "ID", "Ten Sach", "Tac Gia", "Gia Ban", "NXB","So luong");
    printf("\n|----|----------------------|----------------|---------|----------|--------|");

    for (int i = 0; i < count; i++) {
        if (strstr(book[i].title, searchTitle) != NULL) { 
            found = 1;
            printf("\n|%-4s|%-22s|%-16s|%-9d|%-10d|%-8d|",book[i].bookID,book[i].title,book[i].author,book[i].price,book[i].publication.year,book[i].amountofbook);
        }
    }

    if (!found) {
        printf("\nKhong tim thay sach nao voi ten: %s\n", searchTitle);
    }
    printf("\n|----|----------------------|----------------|---------|----------|--------|\n");
}


void admin(){
	int manager;
	setColor(5);
	printf("\n");
	printf("\t%5s\n","***Library Management System Using C***");
    printf("%45s\n","===========ADMINISTRATOR==========");
    printf("%32s\n","[1].Books");
    printf("%34s\n","[2].Members");
    printf("%40s","Chon he thong quan li: ");
    scanf("%d",&manager);
    switch(manager){
    	case 1:{
    		system("cls");
    		displaybook();
			break;
		}
		case 2:{
			system("cls");
			memberlogin();
			break;
		}
	}
}

void memberlogin(){
	int clientchoice;
	setColor(9);
	printf("\n========MEMBER========\n");
	printf("\n[1].Hien thi danh sach khach hang.");
	printf("\n[2].Nhap thong tin khach hang.");
	printf("\n[3].Sua thong tin khach hang.");
	printf("\n[4].Khoa/Mo khoa thong tin khach hang.");
	printf("\n[5].Tim kiem khach hang.");
	printf("\n[6].Muon sach.");
	printf("\n[7].Tra sach.");
	printf("\n[8].Thoat giao dien.");
	printf("\n======================\n");
	printf("Nhap lua chon cua ban: ");
	scanf("%d",&clientchoice);
	switch(clientchoice){
		case 1:{
			system("cls");
			displaymember();
			returntomenu2();
			break;
		}
		case 2:{
			system("cls");
			addmember();
			returntomenu2();
			break;
		}
		case 3:{
			system("cls");
			updateMemberInfo();
			returntomenu2();
			break;
		}
		case 4:{
			system("cls");
			memberstatus();
			returntomenu2();
			break;
		}
		case 5:{
			system("cls");
			searchMember();
			returntomenu2();
			break;
		}
		case 6:{
			system("cls");
			borrow();
			returntomenu2();
			break;
		}
		case 7:{
			system("cls");
			returnbook();
			returntomenu2();
			break;
		}
		case 8:{
			system("cls");
			admin();
			break;
		}
	}
}

void returntomenu2(){
	int choice22;
	printf("\nNhan 1 quay ve man hinh chinh: ");
	scanf("%d",&choice22);
	if(choice22 == 1){
	system("cls");
	memberlogin();
}
}

void displaymember(){
 FILE *file = fopen("member.txt", "r");
    if (file == NULL) {
        perror("Khong the mo file");
        return;
    }

    Member members[100];
    int count = 0;

    while (fscanf(file,"%9[^,],%29[^,],%14[^,\n],%d\n",members[count].memberID,members[count].name,members[count].phone,&members[count].status) == 4) {
    	count++;
    }
    fclose(file);

    if (count == 0) {
        printf("Khong co thanh vien nao trong danh sach.\n");
        return;
    }

    printf("\n|----|----------------------------------------|-----------|----------|");
    printf("\n|%-4s|%-40s|%-11s|%-8s|","ID","Ten Thanh Vien","Dien Thoai","Trang Thai");
    printf("\n|----|----------------------------------------|-----------|----------|");

    for (int i = 0; i < count; i++) {
        printf("\n|%-4s|%-40s|%-11s|%-10s|",members[i].memberID,members[i].name,members[i].phone,members[i].status ? "unlock" : "lock");
    }
    printf("\n|----|----------------------------------------|-----------|----------|\n");
}


void addmember(){
    FILE *file = fopen("member.txt", "a");
    if (file == NULL) {
        perror("Khong the mo file");
        exit(1);
    }

    Member newMember;
    int validInput = 0;

    while (!validInput) {
        validInput = 1;

        printf("Nhap ID: ");
        scanf("%s", newMember.memberID);
        if (strlen(newMember.memberID) == 0) {
            printf("ID khong duoc rong. Vui long nhap lai.\n");
            validInput = 0;
            continue;
        }

        FILE *checkFile = fopen("member.txt", "r");
        if (checkFile != NULL) {
            Member existMember;
            while (fscanf(checkFile, "%9[^,],%29[^,],%14[^,\n],%d\n", existMember.memberID, existMember.name, existMember.phone, &existMember.status) == 4) {
                if (strcmp(existMember.memberID, newMember.memberID) == 0) {
                    printf("ID da ton tai. Vui long nhap ID khac.\n");
                    validInput = 0;
                    break;
                }
            }
            fclose(checkFile);
        }
        if (!validInput) continue;

        printf("Nhap ten: ");
        getchar(); 
        fgets(newMember.name, sizeof(newMember.name), stdin);
        newMember.name[strcspn(newMember.name, "\n")] = '\0'; 
        if (strlen(newMember.name) == 0) {
            printf("Ten khach hang khong duoc rong. Vui long nhap lai.\n");
            validInput = 0;
            continue;
        }

        printf("Nhap so dien thoai: ");
        scanf("%s", newMember.phone);
        if (strlen(newMember.phone) == 0) {
            printf("So dien thoai khong duoc rong. Vui long nhap lai.\n");
            validInput = 0;
            continue;
        }

        checkFile = fopen("member.txt", "r");
        if (checkFile != NULL) {
            Member existMember;
            while (fscanf(checkFile, "%9[^,],%29[^,],%14[^,\n],%d\n", existMember.memberID, existMember.name, existMember.phone, &existMember.status) == 4) {
                if (strcmp(existMember.phone, newMember.phone) == 0) {
                    printf("So dien thoai da ton tai. Vui long nhap so dien thoai khac.\n");
                    validInput = 0;
                    break;
                }
            }
            fclose(checkFile);
        }
    }

    int statusInput;
    printf("Nhap trang thai (1: unlock, 0: lock): ");
    scanf("%d", &statusInput);
    newMember.status = (statusInput == 1);

    fprintf(file, "%s,%s,%s,%d\n", newMember.memberID, newMember.name, newMember.phone, newMember.status);
    fclose(file);

    printf("Them khach hang thanh cong!\n");
    printf("ID: %s\n", newMember.memberID);
    printf("Ten: %s\n", newMember.name);
    printf("So dien thoai: %s\n", newMember.phone);
    printf("Trang thai: %s\n", newMember.status ? "unlock" : "lock");
}




void updateMemberInfo() { 
FILE *file = fopen("member.txt", "r");
    if (file == NULL) {
        perror("Khong the mo file");
        return;
    }

    Member members[100]; 
    int count = 0;

    while (fscanf(file,"%10[^,],%30[^,],%10[^,],%d\n",members[count].memberID,members[count].name,members[count].phone,&members[count].status) == 4) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("Khong co thanh vien nao trong file.\n");
        return;
    }

    char id[10];
    printf("Nhap ID cua thanh vien can sua: ");
    scanf("%s", id);
    getchar(); 

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(members[i].memberID, id) == 0) {
            found = 1;
            printf("Thong tin hien tai:\n");
            printf("ID: %s\nTen: %s\nSo dien thoai: %s\nTrang thai: %s\n", 
                   members[i].memberID, members[i].name, members[i].phone, 
                   members[i].status ? "unlock" : "lock");

            printf("Nhap ten moi: ");
            fgets(members[i].name, sizeof(members[i].name), stdin);
            members[i].name[strcspn(members[i].name, "\n")] = '\0';

            printf("Nhap so dien thoai moi: ");
            fgets(members[i].phone, sizeof(members[i].phone), stdin);
            members[i].phone[strcspn(members[i].phone, "\n")] = '\0';

            printf("Nhap trang thai moi (1:unlock, 0:lock): ");
            scanf("%d", &members[i].status);

            file = fopen("member.txt", "w");
            if (file == NULL) {
                perror("Khong the mo file");
                return;
            }

            for (int j = 0; j < count; j++) {
                fprintf(file, "%s,%s,%s,%d\n",members[j].memberID,members[j].name,members[j].phone,members[j].status);
            }
            fclose(file);
            printf("Cap nhat thong tin thanh vien thanh cong.\n");
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay thanh vien voi ID: %s\n", id);
    }
}



void searchMember() {
    FILE *file = fopen("member.txt", "r");
    if (file == NULL) {
        perror("Khong the mo file");
        return;
    }

    Member members[100];
    int count = 0;

    while (fscanf(file,"%9[^,],%29[^,],%14[^,\n],%d\n",members[count].memberID,members[count].name,members[count].phone,&members[count].status) == 4) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("Khong co thanh vien nao trong danh sach.\n");
        return;
    }

    char searchName[30];
    printf("Nhap ten khach hang muon tim: ");
    getchar();
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; 

    bool found = false;

    printf("\n|----|----------------------------------------|-----------|----------|");
    printf("\n|%-4s|%-40s|%-11s|%-8s|","ID","Ten Thanh Vien","Dien Thoai","Trang Thai");
    printf("\n|----|----------------------------------------|-----------|----------|");
    for (int i = 0; i < count; i++) {

        if (strstr(members[i].name, searchName) != NULL) {
            found = true;
            printf("\n|%-4s|%-40s|%-11s|%-10s|",members[i].memberID,members[i].name,members[i].phone,members[i].status ? "unlock" : "lock");
        }
    }

    if (!found) {
        printf("\nKhong tim thay khach hang nao voi ten: %s\n",searchName);
    }

    printf("\n|----|----------------------------------------|-----------|----------|\n");
}

void displaybookwithoutsort(){
	 FILE *file = fopen("book.txt", "r");
    if (file == NULL) {
        perror("Khong the mo file");
        return;
    }

	Book sach[10];
	int count = 0;

	while(fscanf(file,"%10[^,],%30[^,],%20[^,],%d,%d,%d\n",sach[count].bookID,sach[count].title,sach[count].author,&sach[count].price,&sach[count].publication.year,&sach[count].amountofbook) == 6){
		count++;
	}
		fclose(file);
		
	 if (count == 0) {
        printf("Khong co sach nao trong thu vien.\n");
        return;
    }
		
			
	printf("\n|----|----------------------|----------------|---------|----------|--------|");
    printf("\n|%-4s|%-22s|%-16s|%-9s|%-10s|%-6s|", "ID", "Ten Sach", "Tac Gia", "Gia Ban", "NXB","So Luong");
    printf("\n|----|----------------------|----------------|---------|----------|--------|");
    for (int i = 0; i < count; i++) {
        printf("\n|%-4s|%-22s|%-16s|%-9d|%-10d|%-8d|",sach[i].bookID,sach[i].title,sach[i].author,sach[i].price,sach[i].publication.year,sach[i].amountofbook);
    }
    printf("\n|----|----------------------|----------------|---------|----------|--------|\n");
}

void borrow(){
	displaymember();
	displaybookwithoutsort();
    char memberID[10], bookID[10];
    int borrowQuantity; 
    printf("Nhap ID khach hang: ");
    scanf("%s", memberID);
    printf("Nhap ID sach muon muon: ");
    scanf("%s", bookID);
    printf("Nhap so luong sach muon muon: ");
    scanf("%d", &borrowQuantity);

    FILE *file = fopen("member.txt", "r");
    if (file == NULL) {
        perror("Khong the mo file member.txt");
        return;
    }

    Member members[100];
    int count = 0;

    while (fscanf(file, "%9[^,],%19[^,],%9[^,\n],%d\n", 
                  members[count].memberID, 
                  members[count].name, 
                  members[count].phone, 
                  &members[count].status) == 4) {
        members[count].borrowedCount = 0;
        count++;
    }
    fclose(file);

    file = fopen("book.txt", "r");
    if (file == NULL) {
        perror("Khong the mo file book.txt");
        return;
    }

    Book books[100];
    int bookCount = 0;

    while (fscanf(file, "%10[^,],%30[^,],%20[^,],%d,%d,%d\n", 
                  books[bookCount].bookID, 
                  books[bookCount].title, 
                  books[bookCount].author, 
                  &books[bookCount].price, 
                  &books[bookCount].publication.year, 
                  &books[bookCount].amountofbook) == 6) {
        bookCount++;
    }
    fclose(file);

    int memberFound = 0, bookFound = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(members[i].memberID, memberID) == 0) {
            memberFound = 1;

            if (members[i].borrowedCount >= 5) {
                printf("Khach hang da muon toi da 5 quyển sach. Khong the muon them.\n");
                return;
            }

            for (int j = 0; j < members[i].borrowedCount; j++) {
                if (strcmp(members[i].borrowedBooks[j], bookID) == 0) {
                    printf("Khach hang da muon sach nay.\n");
                    return;
                }
            }
            for (int j = 0; j < bookCount; j++) {
                if (strcmp(books[j].bookID, bookID) == 0) {
                    if (books[j].amountofbook >= borrowQuantity) {
                        bookFound = 1;

                        books[j].amountofbook -= borrowQuantity;
                        strcpy(members[i].borrowedBooks[members[i].borrowedCount], bookID);
                        members[i].borrowedQuantities[members[i].borrowedCount] = borrowQuantity;
                        members[i].borrowedCount++;
                        printf("Muon sach %s voi so luong %d thanh cong.\n", books[j].title, borrowQuantity);
                        break;
                    } else {
                        printf("Khong du so luong sach de muon.\n");
                        return;
                    }
                }
            }
            break;
        }
    }

    if (!memberFound) {
        printf("Khong tim thay khach hang voi ID: %s\n", memberID);
    } else if (!bookFound) {
        printf("Khong tim thay sach voi ID: %s.\n", bookID);
    }

    file = fopen("member.txt", "w");
    if (file == NULL) {
        perror("Khong the mo file member.txt");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%s,%d\n", members[i].memberID, members[i].name, members[i].phone, members[i].status);
    }
    fclose(file);

    file = fopen("book.txt", "w");
    if (file == NULL) {
        perror("Khong the mo file book.txt");
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        fprintf(file, "%s,%s,%s,%d,%d,%d\n", books[i].bookID, books[i].title, books[i].author, books[i].price, books[i].publication.year, books[i].amountofbook);
    }
    fclose(file);
}

void returnbook() {
    char memberID[10], bookID[10];
    printf("Nhap ID khach hang: ");
    scanf("%s", memberID);

    FILE *file = fopen("member.txt", "r");
    if (file == NULL) {
        perror("Khong the mo file member.txt");
        return;
    }

    Member members[100];
    int count = 0;

    while (fscanf(file, "%9[^,],%19[^,],%9[^,\n],%d\n", 
                  members[count].memberID, 
                  members[count].name, 
                  members[count].phone, 
                  &members[count].status) == 4) {
        members[count].borrowedCount = 0;
        count++;
    }
    fclose(file);

    file = fopen("book.txt", "r");
    if (file == NULL) {
        perror("Khong the mo file book.txt");
        return;
    }

    Book books[100];
    int bookCount = 0;

    while (fscanf(file, "%10[^,],%30[^,],%20[^,],%d,%d,%d\n", 
                  books[bookCount].bookID, 
                  books[bookCount].title, 
                  books[bookCount].author, 
                  &books[bookCount].price, 
                  &books[bookCount].publication.year, 
                  &books[bookCount].amountofbook) == 6) {
        bookCount++;
    }
    fclose(file);

    int memberFound = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(members[i].memberID, memberID) == 0) {
            memberFound = 1;
            printf("Khach hang %s da muon:\n", members[i].name);
            for (int j = 0; j < members[i].borrowedCount; j++) {
                printf(" - ID sach: %s, So luong: %d\n", members[i].borrowedBooks[j], members[i].borrowedQuantities[j]);
            }
            break;
        }
    }

    if (!memberFound) {
        printf("Khong tim thay khach hang voi ID: %s\n", memberID);
        return;
    }

    printf("Nhap ID sach muon tra: ");
    scanf("%s", bookID);

    int bookFound = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(members[i].memberID, memberID) == 0) {
            for (int j = 0; j < members[i].borrowedCount; j++) {
                if (strcmp(members[i].borrowedBooks[j], bookID) == 0) {
                    bookFound = 1;

                    for (int k = 0; k < bookCount; k++) {
                        if (strcmp(books[k].bookID, bookID) == 0) {
                            books[k].amountofbook += members[i].borrowedQuantities[j];
                            printf("Tra sach thanh cong: %s\n", books[k].title);

                            for (int l = j; l < members[i].borrowedCount - 1; l++) {
                                strcpy(members[i].borrowedBooks[l], members[i].borrowedBooks[l + 1]);
                                members[i].borrowedQuantities[l] = members[i].borrowedQuantities[l + 1];
                            }
                            members[i].borrowedCount--;
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }

    if (!bookFound) {
        printf("Khach hang khong muon sach nay.\n");
    }

    file = fopen("member.txt", "w");
    if (file == NULL) {
        perror("Khong the mo file member.txt");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%s,%d\n", members[i].memberID, members[i].name, members[i].phone, members[i].status);
    }
    fclose(file);

    file = fopen("book.txt", "w");
    if (file == NULL) {
        perror("Khong the mo file book.txt");
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        fprintf(file, "%s,%s,%s,%d,%d,%d\n", books[i].bookID, books[i].title, books[i].author, books[i].price, books[i].publication.year, books[i].amountofbook);
    }
    fclose(file);
}

void memberstatus() {
    char memberID[10];
    printf("Nhap ID khach hang muon khoa/mo khoa: ");
    scanf("%s", memberID);

    FILE *file = fopen("member.txt", "r");
    if (file == NULL) {
        perror("Khong the mo file");
        return;
    }

    Member members[100];
    int count = 0;
    int found = 0;

    while (fscanf(file, "%9[^,],%29[^,],%14[^,\n],%d\n", members[count].memberID, members[count].name, members[count].phone, &members[count].status) == 4) {
        count++;
    }
    fclose(file);

    for (int i = 0; i < count; i++) {
        if (strcmp(members[i].memberID, memberID) == 0) {
            found = 1;
            printf("Khach hang %s (%s) hien tai %s.\n", members[i].name, members[i].memberID, members[i].status ? "unlock" : "lock");

            char confirm;
            if (members[i].status) {
                printf("Khach hang dang mo, ban co chac muon khoa khong? (y/n): ");
            } else {
                printf("Khach hang dang bi khoa, ban co chac muon mo khoa khong? (y/n): ");
            }
            scanf(" %c", &confirm);

            if (confirm == 'y' || confirm == 'Y') {

                members[i].status = !members[i].status;
                printf("Thay doi trang thai khach hang thanh cong.\n");
            } else {
                printf("Hanh dong bi huy.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay khach hang voi ID: %s\n", memberID);
    } else {

        file = fopen("member.txt", "w");
        if (file == NULL) {
            perror("Khong the mo file");
            return;
        }

        for (int i = 0; i < count; i++) {
            fprintf(file, "%s,%s,%s,%d\n", members[i].memberID, members[i].name, members[i].phone, members[i].status);
        }
        fclose(file);
    }
}

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
