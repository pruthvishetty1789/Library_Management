#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void heading();
void admin();
void user();
void user_profile();
void create_profile_user();
void user_login();
void create_profile_Admin();
void admin_login();
void user_menu();
void deleteBook();
void admin_menu ( );
void help();
void showbook();
void showbook2();
void findbook();
void findbook2();
void admin_profile();
void addbook();
void editbook();
void see_all_user();
void comment_on_book();
void see_all_comment();

struct comment
{
	char userName[30];
	char nameBook[30];
	char coment[200];

};
struct comment c;

struct Login
{
	int id;
	char name[30];
	int age;
	char date[15];
	char password[30];
	int review;
	int comment;

};

struct Book_info {

	int id;
	char name[30];
	char author[30];
	int quantity;
	int rack;
};

struct Book_info a;
struct Login la;
FILE *loginF, *loginF2, *file, *file2, *fcomment;
int pwd_ceck = 0, t = 0;
int main()
{
	heading();
}


void heading() {

	system ( "cls" );
	int d;
	printf ( "\n\n\n\t\t\t   Library System \n" );
	printf ( "\n\t\t ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" );
	printf ( "\n\n\t\t   1. Admin" );
	printf ( "\n\t\t   2. User " );
	printf ( "\n\n\t\t   Enter you choice: " );
	scanf ( "%d", &d );
	if ( d == 1 )
	{
		admin();
	}
	else
		if ( d == 2 ) {

			user();
		}
		else {
			printf ( "\n\n\t\t \a  wrong choice!\n\t\t   try agin!" );

			fflush ( stdin );
			getchar();

			heading();
		}
}

void admin()
{
	system ( "cls" );
	int d;
	printf ( "\n\n\t\t ========> Admin <========" );
	printf ( "\n\n\t\t   1. New" );
	printf ( "\n\t\t   2. Login" );
	printf ( "\n\t\t   3. auto" );
	printf ( "\n\t\t   0. Back" );
	printf ( "\n\n\t\t   Enter you choice: " );
	scanf ( "%d", &d );

	if ( d == 0 ) { heading();}
	else
		if ( d == 1 ) {
			create_profile_Admin();
		}
		else
			if ( d == 2 ) {

				admin_login();
			}
			else
				if ( d == 3 )
				{
					char ch;
					system ( "cls" );
					printf ( "\n\n\t\t use auto then some option like -> Profile not work properly " );
					printf ( "\n\n\t\t continue (y/n): " );
					fflush ( stdin );
					scanf ( "%c", &ch );
					if ( ch == 'y' || ch == 'Y' ) {admin_menu();}
					else {
						admin();
					}
				}
				else {

					printf ( "\n\n\t\t \a  wrong choice!\n\t\t   try agin!" );

					fflush ( stdin );
					getchar();

					admin();
				}
}

void create_profile_Admin() {
	system ( "cls" );
	loginF2 = fopen ( "long2.txt", "a" );
	printf ( "\n\n\t\t ************* Create A Admin Profile ************" );
	printf ( "\n\n\t\t  Enter ID: " );
	scanf ( "%d", &la.id );
	fflush ( stdin );
	printf ( "\n\t\t  Enter Name: " );
	gets ( la.name );
	fflush ( stdin );
	printf ( "\n\t\t  Enter age: " );
	scanf ( "%d", &la.age );
	fflush ( stdin );
	printf ( "\n\t\t  Enter Date: " );
	fflush ( stdin );
	gets ( la.date );
	fflush ( stdin );
	printf ( "\n\t\t  Enter password: " );
	scanf ( "%s", la.password );
	fwrite ( &la, sizeof ( la ), 1, loginF2 );
	printf ( "\n\n\t\t Profile Create Successfully!" );
	fclose ( loginF2 );
	fflush ( stdin );
	getchar();
	admin();

}

int check2 = 1;
void admin_login() {
	system ( "cls" );
	int d, c = 0;
	char pwd[30];
	printf ( "\n\n\t\t  ********** Login page for Admin **********" );
	printf ( "\n\n\t\t  Enter ID: " );
	scanf ( "%d", &d );
	printf ( "\n\t\t  Enter password: " );
	fflush ( stdin );
	gets ( pwd );
	loginF2 = fopen ( "long2.txt", "rb+" );
	while ( fread ( &la, sizeof ( la ), 1, loginF2 ) == 1 ) {

		if ( la.id == d && strcmp ( la.password,  pwd ) == 0 ) {

			pwd_ceck = la.id;
			c = 1;
		}
	}

	fclose ( loginF2 );
	if ( c == 1 ) {
		admin_menu ();
	}
	else {
		printf ( "\n\n\t\t wrong ! ID or password %d to 3", check2 );
		fflush ( stdin );
		getchar();
		if ( check2 == 3 ) { exit ( 0 ); }
		check2++;
		admin_login();

	}
}

void admin_menu ( ) {

	t = 1;
	system ( "cls" );
	char *nam;
	int d;
	loginF2 = fopen ( "long2.txt", "rb+" );
	while ( fread ( &la, sizeof ( la ), 1, loginF2 ) == 1 ) {
		if ( la.id == pwd_ceck ) {
			nam = la.name;
		}
	}

	printf ( "\n\n\t\t====>> Welcome %s in Admin Menu <<===", nam );
	printf ( "\n\n\t\t 1. Profile" );
	printf ( "\n\t\t 2. see All user" );
	printf ( "\n\t\t 3. see all comments" );
	printf ( "\n\t\t 4. add book" );
	printf ( "\n\t\t 5. show books" );
	printf ( "\n\t\t 6. Find book" );
	printf ( "\n\t\t 7. edit book" );
	printf ( "\n\t\t 8. Delete book" );
	printf ( "\n\t\t 9. logout" );
	printf ( "\n\t\t 0. Back" );
	printf ( "\n\n\t\t Enter you choice: " );
	fflush ( stdin );
	scanf ( "%d", &d );
	if ( d == 0 ) {heading();}
	else
		if ( d == 1 ) {
			admin_profile();
		}
		else
			if ( d == 2 ) {
				see_all_user();
			}
			else
				if ( d == 3 ) {
					see_all_comment();
				}
				else
					if ( d == 4 ) {
						addbook();
					}
					else
						if ( d == 5 ) {
							showbook();
						}
						else
							if ( d == 6 ) {
								findbook();
							}
							else
								if ( d == 7 ) {
									editbook();
								}
								else
									if ( d == 8 ) {
										deleteBook();
									}
									else
										if ( d == 9 ) {
											int i;
											system ( "cls" );
											printf ( "\n\n\t\t Thank you for useing !\n\n \t\t wait...... \n\t\tfor closing program" );
											for ( i = 1; i < 1e9; i++ ) {}
											exit ( 0 );
										}
}

void admin_profile() {
	system ( "cls" );
	printf ( "\n\n\t\t     Admin Profile\n" );
	printf ( "\n\t\t ******************************" );
	loginF2 = fopen ( "long2.txt", "rb+" );
	while ( fread ( &la, sizeof ( la ), 1, loginF2 ) == 1 ) {
		if ( pwd_ceck == la.id ) {
			printf ( "\n\n\t\tName: %s", la.name );
			printf ( "\n\t\tPassword: %s", la.password );
		}
	}

	printf ( "\n\n\t\t press any key.... " );
	fflush ( stdin );
	getchar();
	admin_menu();
}

void see_all_user() {
	int i = 1;
	system ( "cls" );
	printf ( "\n\n\t\t     All User Profile\n" );
	printf ( "\n\t\t ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" );
	loginF = fopen ( "long.txt", "rb+" );
	while ( fread ( &la, sizeof ( la ), 1, loginF ) == 1 ) {
		printf ( "\n\n\t\t   Serial: %d\n", i++ );
		printf ( "\n\t\tName: %s", la.name );
		printf ( "\n\t\tAge: %d", la.age );
		printf ( "\n\t\tDate: %s", la.date );
		printf ( "\n\t\tReview: %d", la.review );
		printf ( "\n\t\tComment: %d", la.comment );
		printf ( "\n\t\tPassword: %s", la.password );
	}

	printf ( "\n\n\t\t press any key.... " );
	fflush ( stdin );
	getchar();
	admin_menu();
}

void  see_all_comment() {
	int i = 1;
	system ( "cls" );
	printf ( "\n\n\t\t  See All comment \n" );
	printf ( "\n\t\t*****************************************" );
	fcomment = fopen ( "comment.txt", "rb+" );
	while ( fread ( &c, sizeof ( c ), 1, fcomment ) == 1 ) {
		printf ( "\n\n\t\t     Comment no: %d", i++ );
		printf ( "\n\t\t User Name: %s", c.userName );
		printf ( "\n\t\t Book Name: %s", c.nameBook );
		printf ( "\n\t\t comment:\n\t\t %s\n", c.coment );

	}

	fflush ( stdin );
	getchar();
	admin_menu();
}


void addbook()
{
	system ( "cls" );
	int d, count = 0;
	printf ( "\n\n \t\t ****************** Add Book ***************\n\n" );
	file = fopen ( "books.dat", "ab+" );
	printf ( "\t\t Enter ID: " );
	fflush ( stdin );
	scanf ( "%d", &d );
	rewind ( file );
	while ( fread ( &a, sizeof ( a ), 1, file ) == 1 ) {
		if ( d == a.id ) {
			printf ( "\n\n\t\t This book is Already in Lbirary...." );
			count = 1;
		}
	}

	if ( count == 1 ) {

		fflush ( stdin );
		getchar();
		admin_menu();
	}

	a.id = d;

	printf ( "\n\t\t Enter Name: " );
	fflush ( stdin );
	scanf ( "%s", a.name );

	printf ( "\t\t Enter Author: " );
	fflush ( stdin );
	scanf ( "%s", a.author );

	printf ( "\t\t Enter quantity: " );
	fflush ( stdin );
	scanf ( "%d", &a.quantity );

	printf ( "\t\t Enter Rack: " );
	fflush ( stdin );
	scanf ( "%d", &a.rack );

	fseek ( file, 0, SEEK_END );
	fwrite ( &a, sizeof ( a ), 1, file );

	fclose ( file );

	printf ( "\n\n\t\t Add book sucessfully!" );

	fflush ( stdin );
	getchar();

	admin_menu();


}

void deleteBook() {
	system ( "cls" );
	int d, count = 0;
	printf ( "\n\n\t\t *************** delete Book **************" );
	printf ( "\n\n\t\t Enter ID for delete Book" );
	scanf ( "%d", &d );
	file = fopen ( "books.dat", "rb+" );
	rewind ( file );
	while ( fread ( &a, sizeof ( a ), 1, file ) == 1 ) {
		if ( d == a.id ) {
			printf ( "\n\t\t Book is Availble!\n" );
			printf ( "\n\t\t Book Name is: %s", a.name );
			printf ( "\n\t\t Rack no %d", a.rack );
			count = 1;

		}
	}

	if ( count == 0 ) {
		printf ( "\n\t\t Book is not Availble" );
	}
	else {

		file2 = fopen ( "text.dat", "wb+" );

		rewind ( file );
		while ( fread ( &a, sizeof ( a ), 1, file ) == 1 ) {

			if ( d != a.id ) {

				fseek ( file2, 0, SEEK_CUR );
				fwrite ( &a, sizeof ( a ), 1, file2 );
			}
		}

		fclose ( file );
		fclose ( file2 );
		remove ( "books.dat" );
		rename ( "text.dat", "books.dat" );
		file = fopen ( "books.dat", "rb" );
		fclose ( file );
		printf ( "\n\n\t\t Delete book is sucessfully!\n" );

	}
	printf ( "\n\n\t\t press any key" );
	fflush ( stdin );
	getchar();
	admin_menu();
}

void user() {
	system ( "cls" );
	int d;
	printf ( "\n\n\t\t ==========> User <=========" );
	printf ( "\n\n\t\t   1. Create Profile" );
	printf ( "\n\t\t   2. Login" );
	printf ( "\n\t\t   3. auto" );
	printf ( "\n\t\t   0. Back" );
	printf ( "\n\n\t\t   Enter you choice: " );
	scanf ( "%d", &d );

	if ( d == 0 ) {heading();}
	else
		if ( d == 1 ) {
			create_profile_user();
		}
		else
			if ( d == 2 ) {

				user_login();
			}
			else
				if ( d == 3 )
				{
					char ch;
					system ( "cls" );
					printf ( "\n\n\t\t use auto then some option like -> Profile not work properly " );
					printf ( "\n\n\t\t continue (y/n): " );
					fflush ( stdin );
					scanf ( "%c", &ch );
					if ( ch == 'y' || ch == 'Y' ) {user_menu();}
					else {
						user();
					}

				}
				else {

					printf ( "\n\n\t\t \a  wrong choice!\n\t\t   try agin!" );

					fflush ( stdin );
					getchar();

					user();
				}


}

void create_profile_user() {
	system ( "cls" );
	loginF = fopen ( "long.txt", "a" );
	printf ( "\n\n\t\t ************* Create A Admin Profile ************" );
	printf ( "\n\n\t\t  Enter ID: " );
	scanf ( "%d", &la.id );
	fflush ( stdin );
	printf ( "\n\t\t  Enter Name: " );
	gets ( la.name );
	fflush ( stdin );
	printf ( "\n\t\t  Enter age: " );
	scanf ( "%d", &la.age );
	fflush ( stdin );
	printf ( "\n\t\t  Enter Date: " );
	fflush ( stdin );
	gets ( la.date );
	fflush ( stdin );
	printf ( "\n\t\t  Enter password: " );
	scanf ( "%s", la.password );
	fwrite ( &la, sizeof ( la ), 1, loginF );
	printf ( "\n\n\t\t Profile Create Successfully!" );
	fclose ( loginF );
	fflush ( stdin );
	getchar();

	user();
}

int check = 1;
void user_login() {
	system ( "cls" );
	int d, c = 0;
	char pwd[30];
	printf ( "\n\n\t\t  ********** Login page for User **********" );
	printf ( "\n\n\t\t  Enter ID: " );
	scanf ( "%d", &d );
	printf ( "\n\t\t  Enter password: " );
	fflush ( stdin );
	gets ( pwd );
	loginF = fopen ( "long.txt", "rb+" );
	while ( fread ( &la, sizeof ( la ), 1, loginF ) == 1 ) {

		if ( la.id == d && strcmp ( la.password,  pwd ) == 0 ) {

			pwd_ceck = la.id;
			c = 1;
		}
	}

	fclose ( loginF );

	if ( c == 1 ) {
		user_menu ();
	}
	else {
		printf ( "\n\n\t\t wrong ! ID or password %d to 3", check );

		fflush ( stdin );
		getchar();

		if ( check == 3 ) { exit ( 0 ); }
		check++;

		user_login();

	}

}

void user_menu ( ) {
	t = 2;
	system ( "cls" );
	char *nam;
	int d;
	loginF = fopen ( "long.txt", "rb+" );
	while ( fread ( &la, sizeof ( la ), 1, loginF ) == 1 ) {
		if ( la.id == pwd_ceck ) {
			nam = la.name;
		}
	}

	printf ( "\n\n\t\t====>> Welcome %s in User Menu <<===", nam );
	printf ( "\n\n\t\t 1. Profile" );
	printf ( "\n\t\t 2. Comment on book" );
	printf ( "\n\t\t 3. Rating on book" );
	printf ( "\n\t\t 4. show books" );
	printf ( "\n\t\t 5. Find book" );
	printf ( "\n\t\t 6. Borrow book" );
	printf ( "\n\t\t 7. Return book" );
	printf ( "\n\t\t 8. help" );
	printf ( "\n\t\t 9. logout" );
	printf ( "\n\t\t 0. Back" );
	printf ( "\n\n\t\t Enter you choice: " );
	fflush ( stdin );
	scanf ( "%d", &d );
	if ( d == 0 ) {heading();}
	else
		if ( d == 1 ) {
			user_profile();
		}
		else
			if ( d == 2 ) {
				comment_on_book();
			}
			else
				if ( d == 3 ) {
					//Reting();
				}
				else
					if ( d == 4 ) {
						showbook();
					}
					else
						if ( d == 5 ) {
							findbook();
						}
						else
							if ( d == 6 ) {
								//borrowBook();
							}
							else
								if ( d == 7 ) {
									//ReturnBook();
								}
								else
									if ( d == 8 ) {
										help();
									}
									else
										if ( d == 9 ) {
											int i;
											system ( "cls" );
											printf ( "\n\n\t\t Thank you for useing !\n\n \t\t wait...... \n\t\tfor closing program" );
											for ( i = 1; i < 1e9; i++ ) {}
											exit ( 0 );
										}

}

void user_profile() {
	system ( "cls" );
	printf ( "\n\n\t\t     User Profile\n" );
	printf ( "\n\t\t ^^^^^^^^^^^^^^^^^^^^^^^^^^" );
	loginF = fopen ( "long.txt", "rb+" );
	while ( fread ( &la, sizeof ( la ), 1, loginF ) == 1 ) {
		if ( pwd_ceck == la.id ) {
			printf ( "\n\n\t\tName: %s", la.name );
			printf ( "\n\t\tAge: %d", la.age );
			printf ( "\n\t\tdate: %s", la.date );
			printf ( "\n\t\tPassword: %s", la.password );

		}
	}
	printf ( "\n\n\t\t press any key.... " );
	fflush ( stdin );
	getchar();

	user_menu();

}

void comment_on_book() {
    int d, count = 0;
	char nB[30], nA[30];
	system ( "cls" );
	printf ( "\n\n\t\t Comment on a Book " );
	printf ( "\n\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" );
	printf ( "\n\n\t\t if you read a book from the Library then Make a comment....." );
	file = fopen ( "books.dat", "rb+" );
	printf ( "\n\n\t\t Enter ID: " );
	scanf ( "%d", &d );
	while ( fread ( &a, sizeof ( a ), 1, file ) == 1 ) {
		if ( d == a.id ) {
			strcpy ( c.nameBook, a.name ); 
			printf ( "\n\n\t\t Book is Found! \n" );
			printf ( "\n\t\t Name: %s", a.name );
			printf ( "\n\t\t Author: %s", a.author );
			count = 1;

		}
	}

	if ( count == 1 ) {
		loginF = fopen ( "login.txt", "rb+" );
		while ( fread ( &la, sizeof ( la ), 1, loginF ) == 1 ) { // find user
			if ( pwd_ceck == la.id ) {

				strcpy ( c.userName, la.name );
			}
		}

		printf ( "\n\n\t\t Enter Your comment: " );
		fflush ( stdin );
		scanf ( "%[^\n]s", c.coment );
		fcomment = fopen ( "comment.txt", "ab+" );
		fwrite ( &c, sizeof ( c ), 1, fcomment );
		fclose ( fcomment );
		printf ( "\n\n\t\t comment add Successfully! " );
	}
	if ( count == 0 ) {
		printf ( "\n\n\t\t Book is Not Found ! " );
	}
	fflush ( stdin );
	getchar();
	admin_menu();

}
void showbook() {
	system ( "cls" );
	int count = 0;
	printf ( "\n\n\t\t\t\tAll BooKs are Available\n" );
	printf ( "\t\t\t********************************************\n\n" );
	printf ( "\t\t\t ID\tName\tAuthor\tQunt\tRack\n\n" );
	file = fopen ( "books.dat", "rb" );
	while ( fread ( &a, sizeof ( a ), 1, file ) == 1 ) {
		printf ( "\t\t\t %d", a.id );
		printf ( "\t%s", a.name );
		printf ( "\t%s", a.author );
		printf ( "\t%d", a.quantity );
		printf ( "\t%d\n", a.rack );
		count = count + a.quantity;

	}

	fclose ( file );
	printf ( "\n\t\t\t\t Total Books: %d ", count );
	fflush ( stdin );
	getchar();
	if ( t == 1 ) { admin_menu(); }
	else
		if ( t == 2 ) {
			user_menu();
		}
}

void findbook() {
	int d, count = 0;
	system ( "cls" );
	printf ( "\n\n\t\t ************* Find Book in Library ****************\n" );
	printf ( "\n\t\t searching.....\n\n" );
	file = fopen ( "books.dat", "rb" );
	printf ( "\n\t\t Enter ID: " );
	scanf ( "%d", &d );
	while ( fread ( &a, sizeof ( a ), 1, file ) == 1 ) {
		if ( d == a.id ) {
			printf ( "\n\n\t\t Book is Found! \n" );
			printf ( "\t\t ID: %d", a.id );
			printf ( "\n\t\t Name: %s", a.name );
			printf ( "\n\t\t Author: %s", a.author );
			printf ( "\n\t\t quantity: %d", a.quantity );
			printf ( "\n\t\t Rack: %d\n", a.rack );
			count = 1;

		}
	}

	if ( count == 0 ) {
		printf ( "\n\n\t\t Book is Not Found ! " );
	}
	printf ( "\n\n\t\t  press any key...." );
	fflush ( stdin );
	getchar();
	if ( t == 1 ) { admin_menu(); }
	else
		if ( t == 2 ) {
			user_menu();
		}

}

void editbook() {
	system ( "cls" );
	int d, count = 0;
	printf ( "\n\n\t\t ************* edit book *************\n\n" );
	file = fopen ( "books.dat", "rb+" );
	printf ( "\n\t\t Enter ID: " );
	scanf ( "%d", &d );
	while ( fread ( &a, sizeof ( a ), 1, file ) == 1 ) {
		if ( d == a.id ) {
			printf ( "\n\t\t Book is Availble!\n" );
			printf ( "\n\n \t\t ID: %d", a.id );
			printf ( "\n\t\t Enter New Name: " );
			scanf ( "%s", a.name );
			printf ( "\n\t\t Enter New Author: " );
			scanf ( "%s", a.author );
			printf ( "\n\t\t Enter New quantity: " );
			scanf ( "%d", &a.quantity );
			printf ( "\n\t\t Enter New Rack: " );
			scanf ( "%d", &a.rack );
			fseek ( file, ftell ( file ) - sizeof ( a ), 0 );
			fwrite ( &a, sizeof ( a ), 1, file );
			fclose ( file );
			count = 1;
		}
	}

	if ( count == 0 ) {
		printf ( "\n\n\t\t Book is Not Found!" );
	}

	printf ( "\n\n\t\t press any key...." );
	fflush ( stdin );
	getchar();

	admin_menu();
}
void help() {
	system ( "cls" );
	printf ( "\n\n\t\t ****************** Help section *****************\n\n" );
	printf ( "\t\t1. This is a simple Library Project\n" );
	printf ( "\n\t\t 2. you have your won password  and ID\n" );
	printf ( "\n\t\t 3. you can commnet in library books\n" );
	printf ( "\n\t\t 4. see all Feature under main menu\n" );
	printf ( "\n\t\t 5. you can use all of them\n" );
	printf ( "\n\t\t 6. press any key... to back main_menu\n" );
	printf ( "\n\t\t\t Thank you!\n\n" );
	printf ( "\n\t\t press any key....\n" );
	fflush ( stdin );
	getchar();
	user_menu();
}