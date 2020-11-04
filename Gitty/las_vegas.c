#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#define  MAXNAME 100
#define  MAXSLOT 5
#define  MID    ,178,186
#define  TOP    ,201,187
#define  BOT    ,212,188

typedef struct user_color_information{
    int  background,
         character,
         screen,
         code;
}ColorInfor;
typedef struct account_information{
    char    username[MAXNAME];
    double  token;
    double  money;
    int     hope;
}user;
// MAIN CONTROL
//______________________________________________________________________________
// login
void draw_welcome( void );
void print_login_interface( void );
void login( ColorInfor *color, user *player, bool *key );
void new_account( ColorInfor *color, user *player, bool *check );
void content( void );
void sign_in( ColorInfor *color, user *player, bool *check);
// Las VeGas
void draw_las_vegas( void );
void print_las_vegas_interface( ColorInfor *color, user * player );
void las_vegas( ColorInfor *color, user *player );
// Quit and Ask
void ask_save( ColorInfor *color, user *player, bool *check );
// Save and Load
void save_game( ColorInfor *color, user *player);
bool load_game( ColorInfor *color, user *player );
// Money Transfer
void exchange_token( user *player );
void exchange_money( user *player );
// Color
void set_color( int code );
void print_color( ColorInfor *color );
void color_sequence( void );
void change_color( ColorInfor *color );
void change_background( ColorInfor *color );
void change_character( ColorInfor *color );
void change_screen( ColorInfor *color );
void print_change_color_interface( void );
// The end
void check_end_consonent( ColorInfor *color, user *player );
void hide_cursor( void );
void appear_cursor( void );
void the_end( ColorInfor *color, user *player );
void select_the_end( ColorInfor *color, user *player );
void print_exit_interface( void );
// Time
void wait_random( void );
void wait_login_exit( void );
void wait_half_sec( void );
// Game 1: Slot Machine
void draw_slot_machine( void );
void print_slot_machine_interface( user *player );
void slot_machine( ColorInfor *color, user *player );
void play_one( user *player );
void play_ten( user *player );
void play_machine( user *player, int turn);
int  get_random(void);
//game 2 roulette
void draw_roulette( void );
void print_roulette_interface( user *player );
void roulette( ColorInfor *color, user *player );
void play_roulette( user *player );
int  run_roulette( void );
bool scan_bet_money( double *bet_money, user *player );
//game 3 SICBO
void draw_sicbo( void );
void print_sicbo_interface( user *player );
void sicbo( ColorInfor *color, user *player );
void choose_play( ColorInfor *color, user *player );
void play_over_under( ColorInfor *color, user *player );
void play_total_points( ColorInfor *color, user *player );
int  get_random_dice(void);
void shake_dice( int *sum );
bool ask_again( double token );

int main( void ){
    user        player;
    ColorInfor  color;
    bool        key = true;

    srand( time( NULL ) );
    login( &color, &player, &key );
    if( key == true )
        las_vegas( &color, &player );
    print_exit_interface();
    return 0;
}

// Login
//____________________________________________________________________________________________________________________

void draw_welcome( void ){
    set_color( 0 );
    system( "CLS" );
    set_color( 0x00C );
    int c = 219;
    printf("\n");
    printf("                %c       %c  %c%c%c%c%c%c%c  %c        %c         %c%c%c%c%c    %c%c%c%c%c%c   %c       %c  %c%c%c%c%c%c%c          \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("                %c       %c  %c        %c        %c        %c     %c  %c      %c  %c%c     %c%c  %c                \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("                %c   %c   %c  %c        %c        %c        %c        %c      %c  %c %c   %c %c  %c                \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("                %c  %c %c  %c  %c%c%c%c%c%c   %c        %c        %c        %c      %c  %c  %c %c  %c  %c%c%c%c%c%c           \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("                %c %c   %c %c  %c        %c        %c        %c        %c      %c  %c   %c   %c  %c                \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("                %c%c     %c%c  %c        %c        %c        %c     %c  %c      %c  %c       %c  %c                \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("                %c       %c  %c%c%c%c%c%c%c  %c%c%c%c%c%c%c  %c%c%c%c%c%c%c  %c%c%c%c%c%c    %c%c%c%c%c%c   %c       %c  %c%c%c%c%c%c%c          \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    set_color( 0x003 );
    printf("________________________________________________________________________________________________________________________\n");
}

void print_login_interface( void ) {
    set_color( 0x00A );
    printf("\n");
    printf("%c=================================%c\n"TOP);
    printf("%c <1>.NEW ACCOUNT                 %c\n"MID);
    printf("%c <2>.LOGIN                       %c\n"MID);
    printf("%c <0>.QUIT                        %c\n"MID);
    printf("%c=================================%c\n"BOT);
}

void login( ColorInfor *color, user *player, bool *key ){
    int     select;
    char    enter;
    bool    check;
    set_color( 0 );
    system( "CLS" );
    draw_welcome();
    printf("Loading");
    wait_login_exit();
    print_login_interface();
    do{
        check = false;
        fflush( stdin );
        printf("[ Select ]: ");
        if( scanf("%d%c", &select, &enter) != 2 || enter != '\n' ){
            printf(" Please enter the options only.\n");
        }
        else switch( select ){
            case 1:
                new_account( color, player, &check );
                break;
            case 2:
                sign_in( color, player, &check );
                break;
            case 0:
                *key   = 0;
                check = true;
                break;
            default:
                printf(" Please enter the options only.\n");
        }
    }while( check == false );
}

void new_account( ColorInfor *color, user *player, bool *check ){
    fflush( stdin );
    char name[100];
    do{
        fflush( stdin );
        name[0] = '\0';
        printf("New username: ");
        scanf("%[^\n]", name );
    }while( name[0] == '\0' || name[0] == ' ');
    strcpy( (*player).username, name );
    strcat( (*player).username,".txt" );
    FILE *file = NULL;
    file = fopen( (*player).username,"r" );
    if( file != NULL ){
        *check = false;
        printf("This username is existed.\n");
    }else{
        *check = true;
        (*color).background = 0 ;
        (*color).character  = 10;
        (*color).screen     = 0 ;
        (*player).money     = 1000.0;
        (*player).token     = 100.0;
        (*player).hope      = 1;
        hide_cursor();
        content();
        fflush( stdin );
        printf("[ Press any key ]\n\n");
        getch();
        appear_cursor();
    }
}

void content( void ) {
    set_color( 0 << 10 | 0 << 4 |14 );
    printf("\n");
    printf("%c You went bankrupt after the business suffered a loss\n", 248); wait_half_sec();
    printf("%c You creditors are looking for you.\n", 248); wait_half_sec();
    printf("%c Your daughter needs medicine to cure the disease.\n", 248); wait_half_sec();
    printf("%c You need to earn 100.000$ as fast as you can.\n", 248); wait_half_sec();
    printf("%c With a thousand dollars left, you come to Las Vegas as the ", 248);
    set_color( 12 );
    printf("LAST HOPE\n"); wait_half_sec();
    set_color( 0 << 10 | 0 << 4 | 10 );
    printf("\n%c Balance + 1000$\n", 248);
    printf("%c Token + 100$\n", 248);

}

void sign_in( ColorInfor *color, user *player, bool *check){
    fflush( stdin );
    printf(" Username: ");
    scanf("%s", (*player).username );
    strcat( (*player).username,".txt" );
    if( load_game( color, player ) )
        *check = true;
    else
        *check = false;
}

//Las Vegas
//____________________________________________________________________________________________________________________

void draw_las_vegas( void ) {
    int c = 219;
    printf("\n");
    set_color(12);
    printf("\t\t   %c            %c       %c%c%c%c%c      %c     %c  %c%c%c%c%c%c   %c%c%c%c%c      %c       %c%c%c%c%c    \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\t\t   %c           %c %c     %c           %c     %c  %c        %c         %c %c     %c         \n",c,c,c,c,c,c,c,c,c,c,c);
    printf("\t\t   %c          %c   %c    %c%c%c%c%c%c       %c   %c   %c%c%c%c%c    %c  %c%c%c   %c   %c    %c%c%c%c%c%c    \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\t\t   %c         %c%c%c%c%c%c%c        %c        %c %c    %c        %c    %c  %c%c%c%c%c%c%c        %c    \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\t\t   %c%c%c%c%c%c%c   %c     %c   %c%c%c%c%c          %c     %c%c%c%c%c%c   %c%c%c%c%c%c  %c     %c   %c%c%c%c%c     \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    set_color( 0x003 );
    printf("________________________________________________________________________________________________________________________\n\n");
}

void print_las_vegas_interface( ColorInfor *color, user * player ){
    draw_las_vegas();
    set_color( (*color).code );
    printf("Balance: %0.2lf$\tToken: %0.2lf$\n", (*player).money, (*player).token );
    printf("%c============================================%c\n"TOP);
    printf("%c-GAME LIST:                                 %c\n"MID);
    printf("%c <1>. Slot Machine                          %c\n"MID);
    printf("%c <2>. Roulette                              %c\n"MID);
    printf("%c <3>. Sicbo                                 %c\n"MID);
    printf("%c-OTHER OPTIONS:                             %c\n"MID);
    printf("%c <4>. Money -> Token                        %c\n"MID);
    printf("%c <5>. Token -> Money                        %c\n"MID);
    printf("%c <6>. Change color                          %c\n"MID);
    printf("%c <7>. Save game                             %c\n"MID);
    printf("%c <0>. Quit                                  %c\n"MID);
    printf("%c============================================%c\n"BOT);
    printf("[ Select ]: ");
}

void las_vegas( ColorInfor *color, user *player ){
    int     select;
    bool    check;
    char    enter;
    (*color).code = ( (*color).screen << 10 ) + ( (*color).background << 4 ) + (*color).character;
    do{
        check_end_consonent( color, player );
        print_color( color );
        fflush( stdin );
        check = true;
        print_las_vegas_interface( color, player );
        while( scanf("%d%c", &select, &enter) != 2 || enter != '\n' || select < 0 || select > 8 ){
            fflush( stdin );
            printf("Please select the options only.\n");
            printf("[ Select ]: ");
        }
             if(select == 1)    slot_machine( color, player );
        else if(select == 2)    roulette( color, player );
        else if(select == 3)    sicbo( color, player );
        else if(select == 4)    exchange_token( player );
        else if(select == 5)    exchange_money( player );
        else if(select == 6)    change_color( color );
        else if(select == 7)    save_game( color, player );
        else if(select == 0)    ask_save( color, player , &check);
    }while( check == true );
}

//Quit with ask save
//______________________________________________________________________________

void ask_save( ColorInfor *color, user *player, bool *check ){
    char select = '0';
    *check = false;
    hide_cursor();
    printf("\t\t\t\t%c===========================================%c\n"TOP);
    printf("\t\t\t\t%c           Do you want to save?            %c\n"MID);
    printf("\t\t\t\t%c             [ Y ]       [ N ]             %c\n"MID);
    printf("\t\t\t\t%c===========================================%c\n"BOT);
    while( select != 'Y' && select != 'y' && select != 'N' && select != 'n' ){
        if( kbhit()){
            select = getch();
        }
    }
    if( select == 'Y' || select == 'y' ){
        save_game( color, player );
    }
    else
        printf("Not saved\n");
}
void hide_cursor( void ){
    CONSOLE_CURSOR_INFO info;
    info.bVisible = FALSE;
    info.dwSize = 10;
    SetConsoleCursorInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &info );
}
void appear_cursor( void ){
    CONSOLE_CURSOR_INFO info;
    info.bVisible = TRUE;
    info.dwSize = 10;
    SetConsoleCursorInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &info );
}

//Load and Save
//____________________________________________________________________________________________________________________

void save_game( ColorInfor *color, user *player){
    FILE *file = NULL;
    file = fopen( (*player).username,"w+" );
    if( file != NULL ){
        fprintf(file,"%0.2lf;", (*player).money );
        fprintf(file,"%0.2lf;", (*player).token );
        fprintf(file,"%d;", (*player).hope );
        fprintf(file,"%d;", (*color).background );
        fprintf(file,"%d;", (*color).character );
        fprintf(file,"%d;", (*color).screen );
        fclose(file);
        printf("Saved\n"); wait_half_sec(); wait_half_sec();
    }
    else
        printf("Something went wrong! Please try again or call 0901481153 for help.\n");
}
bool load_game( ColorInfor* color, user *player)
{
    FILE *file = NULL;
    file = fopen( (*player).username,"r" );
    if( file != NULL ){
        fscanf( file ,"%lf", &(*player).money );
        fscanf( file,"%*c%lf", &(*player).token );
        fscanf( file,"%*c%d", &(*player).hope );
        fscanf( file,"%*c%d", &(*color).background );
        fscanf( file,"%*c%d", &(*color).character );
        fscanf( file,"%*c%d", &(*color).screen );
        printf("WELCOME BACK!\n[ Press any key ]");
        fclose( file );
        getch();
        return true;
    }
    else{
        printf("Not found! Try again...\n");
        return false;
    }
}

//Exchange Token and money
//____________________________________________________________________________________________________________________

void exchange_token( user *player ){
    double  amount;
    char    enter;
    bool    check;
    do{
        check = true;
        fflush(stdin);
        printf("---------------------------------\n");
        printf("(The amount must be  >= 1$)\n");
        printf("Amount: ");
        if( scanf("%lf%c", &amount, &enter ) == 2 && enter == '\n' && ( amount >= 1 || amount == 0 ) ){
            if( amount > (*player).money ){
                printf("Not enough money.( enter 0 cancel )\n");
                check = false;
            }
            else{
                (*player).token += amount;
                (*player).money -= amount;
                printf("Token + %0.2lf$\n", amount);
                printf("Done! ");
            }
        }
        else{
            printf("Something went wrong! Try again.\n");
            check = false;
        }
    }while( check == false );
    printf("[ Press any key ]");
    getch();
}
void exchange_money( user *player ){
    double  amount;
    char    enter;
    bool    check;
    do{
        check = true;
        fflush(stdin);
        printf("---------------------------------\n");
        printf("(The amount must be  >= 1$)\n");
        printf("Amount: ");
        if( scanf("%lf%c", &amount, &enter) == 2 && enter == '\n' && ( amount >=1 || amount == 0 ) ){
            if( amount > (*player).token ){
                printf("You don't have that much.( enter 0 cancel)\n");
                check = false;
            }
            else{
                (*player).token -= amount;
                (*player).money += amount;
                printf("Money + %0.2lf$\n", amount);
                printf("Done!");
            }
        }
        else{
            printf("Something went wrong! Try again.( Enter 0 cancel)\n");
            check = false;
        }
    }while(check == false);
    fflush( stdin );
    printf("[ Press any key ]");
    getch();
}

//change color
//____________________________________________________________________________________________________________________

void print_color( ColorInfor *color ) {
    set_color( ( (*color).screen << 10 )  + ( (*color).background << 4 ) );
    system( "CLS" );
    set_color( (*color).code );
}
void set_color( int code ) {
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( color , code);
}

void print_change_color_interface( void ){
    printf("%c=============< COLOR >==============%c\n"TOP);
    printf("%c<1> Change color of background      %c\n"MID);
    printf("%c<2> Change color of character       %c\n"MID);
    printf("%c<3> Draw screen                     %c\n"MID);
    printf("%c<0> Back                            %c\n"MID);
    printf("%c====================================%c\n"BOT);
    printf("[ Select ]: ");
}

void change_color( ColorInfor *color ){
    int     select;
    char    enter;
    do{
        print_color( color );
        fflush( stdin );
        print_change_color_interface();
        if( scanf("%d%c", &select, &enter)!=2 || enter!='\n' || select < 0 || select > 3 ){
            printf("Select the options only");
            wait_random();
            fflush( stdin );
            printf("\n");
        }
        else if ( select == 1 ){
            color_sequence();
            change_background( color );
        }
        else if ( select == 2 ){
            color_sequence();
            change_character( color );
        }
        else if ( select == 3 ){
            printf(" 1 No line.\n");
            printf(" 2 Horizontal line.\n");
            printf(" 3 Vertical line.\n");
            printf(" 4 CARO.\n");
            change_screen( color );
        }
    }while( select != 0);
}

void change_background( ColorInfor *color ){
    char    enter;
    bool    check;
    do{
        fflush( stdin );
        check = false;
        printf("\nYour choice: ");
        if( scanf("%d%c", &(*color).background, &enter)!=2 || enter!='\n' || (*color).background < 0 || (*color).background >15 )
            printf("0->15 only\n");
        else if ( (*color).background == (*color).character ){
            printf("It cannot be the same with character.\n");
        }
        else{
            (*color).code = ( (*color).screen << 10 ) + ( (*color).background << 4 ) + (*color).character;
            check = true;
        }
    }while( check == false );
}

void change_character( ColorInfor *color ){
    char    enter;
    bool    check;
    do{
        fflush( stdin );
        check = false;
        printf("\nYour choice: ");
        if( scanf("%d%c", &(*color).character, &enter)!=2 || enter!='\n' || (*color).character < 0 || (*color).character >15 )
            printf("0->15 only\n");
        else if ( (*color).character == (*color).background ){
            printf("It cannot be the same with background.\n");
        }
        else{
            (*color).code =( (*color).screen<< 10 ) + ( (*color).background << 4 ) + (*color).character;
            check = true;
        }
    }while( check == false );
}

void change_screen( ColorInfor *color ){
    char    enter;
    bool    check;
    int     screen;
    do{
        fflush( stdin );
        check = false;
        printf("\nYour choice: ");
        if( scanf("%d%c", &screen, &enter)!=2 || enter!='\n' || screen < 1 || screen > 4 )
            printf(" 1 -> 4 only\n");
        else{
            (*color).screen = screen - 1;
            (*color).code = ( (*color).screen << 10 ) + ( (*color).background << 4 ) + (*color).character;
            check = true;
        }
    }while( check == false );
}

void color_sequence( void ){
    printf(" 0 Black\t\t 8 Gray\n");
    printf(" 1 Dark Blue\t\t 9 Light Blue\n");
    printf(" 2 Dark Green\t\t10 Light Green\n");
    printf(" 3 Dark Aqua\t\t11 Light Aqua\n");
    printf(" 4 Dark Red\t\t12 Light Red\n");
    printf(" 5 Dark Purple\t\t13 Light Purple\n");
    printf(" 6 Dark Yellow\t\t14 Light Yellow\n");
    printf(" 7 Dark White\t\t15 Light White\n");
}

//slot_machine
//____________________________________________________________________________________________________________________

void draw_slot_machine( void ) {
    int c = 219;
    printf("\n");
    set_color(15);
    printf("\t    %c%c%c%c%c   %c         %c%c%c%c%c   %c%c%c%c%c%c%c      %c     %c      %c       %c%c%c%c%c    %c     %c   %c%c%c%c%c%c%c   %c   %c   \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\t   %c        %c        %c     %c     %c         %c%c   %c%c     %c %c     %c     %c   %c     %c      %c      %c%c  %c   \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    set_color(7);
    printf("\t   %c%c%c%c%c%c   %c        %c     %c     %c         %c %c %c %c    %c   %c    %c         %c%c%c%c%c%c%c      %c      %c %c %c   \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    set_color(3);
    printf("\t        %c   %c        %c     %c     %c         %c  %c  %c   %c%c%c%c%c%c%c   %c     %c   %c     %c      %c      %c  %c%c   \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\t   %c%c%c%c%c    %c%c%c%c%c%c    %c%c%c%c%c      %c         %c     %c   %c     %c    %c%c%c%c%c    %c     %c   %c%c%c%c%c%c%c   %c   %c   \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    set_color( 0x003 );
    printf("________________________________________________________________________________________________________________________\n\n");
}

void print_slot_machine_interface( user *player ){
    printf("Balance: %0.2lf$\tToken: %0.2lf$\n", (*player).money, (*player).token );
    printf("%c===========================================%c\n"TOP);
    printf("%c <1>Play the slot machine ( 1$ )           %c\n"MID);
    printf("%c <2>Play 10 turns( 10$ bonus 1 turn )      %c\n"MID);
    printf("%c <3>Exchange Token.                        %c\n"MID);
    printf("%c <0>Back                                   %c\n"MID);
    printf("%c===========================================%c\n"BOT);
    printf("[ Select ]:");
}
void slot_machine( ColorInfor *color, user *player ){
    bool    check;
    int     select;
    char    enter;
    do{
        print_color( color );
        fflush(stdin);
        check = true;
        draw_slot_machine();
        set_color( (*color).code );
        print_slot_machine_interface( player );
        while( scanf("%d%c", &select, &enter)!=2 || enter!='\n' || select<0 || select>3 ){
            fflush(stdin);
            printf("Please select the options only.\n");
            printf("[ Select ]:");
        }
        if(select == 1)         play_one( player );
        else if(select == 2)    play_ten( player );
        else if(select == 3)    exchange_token( player );
        else if(select == 0)    check = false;

    }while( check == true );
}

void play_one( user *player ){
    int  turn = 1;
    if( (*player).token >= 1.0 ){
        (*player).token -= 1.0;
        printf("-1$ cent\n");
        play_machine( player, turn );
    }
    else
        printf("Not enough token, please go exchange token. ");

    printf("[ Press any key ]");
    getch();
}

void play_ten( user *player ){
    int  turn = 11;
    if( (*player).token >= 10.0 ){
        (*player).token -= 10.0;
        printf("-10$\n");
        play_machine( player, turn );
    }
    else{
        printf("Not enough money, please go exchange token. ");
    }
    fflush( stdin );
    printf("[ Press any key ]");
    getch();
    system( "CLS" );
}

void play_machine( user *player, int turn){
    int     slot[MAXSLOT];
    int     max_equal = ( ( MAXSLOT*MAXSLOT ) - MAXSLOT )/2;
    int     index, index_2, index_3;
    for( index = 1 ; index <= turn ; index++){
        int num_of_equal = 0;
        for( index_2 = 0 ; index_2 < MAXSLOT ; index_2++){
            slot[index_2] = get_random();
        }
        for( index_2 = 0 ; index_2 < MAXSLOT ; index_2++){
            for( index_3 = index_2+1 ; index_3 < MAXSLOT ; index_3++ ){
                if( slot[index_2] == slot[index_3] ){
                    num_of_equal++;
                }
            }
        }
        //================k*k/2 - k/2=====================
        printf(" Rolling");
        wait_random();
        printf("\n");
        for( index_2 = 0 ; index_2 < MAXSLOT ; index_2++){
            printf("( %d )", slot[index_2]);
        }
        if( num_of_equal >= 0 && num_of_equal <3 ){
            printf(" Good luck next time\n");
        }
        if( num_of_equal >= 3*(3-1)/2 && num_of_equal < 4*(4-1)/2 ){
            printf(" You won 5$\n");
            (*player).token += 5.0;
        }
        if( num_of_equal >= 4*(4-1)/2 && num_of_equal < max_equal ){
            printf(" You won 30$\n");
            (*player).token += 30.0;
        }
        if( num_of_equal == max_equal ){
            printf(" Congratulation! You won 1000$\n");
            (*player).token += 1000.0;
            if( slot[0] == 9 )            {
                printf(">>>YOU WIN A SPECIAL REWARD +9999$<<<\n");
                (*player).token += 9999.0;
            }
        }
        if( num_of_equal > max_equal)
            printf("Error\n");
    }
}

int get_random( void ){
    return rand()%10;
}

// Roulette
//____________________________________________________________________________________________________________________

void draw_roulette( void ) {
    int c = 219;
    set_color( 0x00A );
    printf("\n");
    printf("\t\t  %c  %c  %c       %c %c %c     %c         %c %c %c %c    %c %c %c %c %c    %c %c %c %c %c   %c %c %c %c    \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\t\t  %c      %c    %c       %c   %c         %c              %c            %c       %c          \n",c,c,c,c,c,c,c,c,c);
    set_color( 0x00E );
    printf("\t\t  %c  %c        %c       %c   %c         %c %c %c %c        %c            %c       %c %c %c %c    \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    set_color( 0x00F );
    printf("\t\t  %c    %c      %c       %c   %c         %c              %c            %c       %c          \n",c,c,c,c,c,c,c,c,c);
    printf("\t\t  %c      %c      %c %c %c     %c  %c  %c   %c %c %c %c        %c            %c       %c %c %c %c    \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    set_color( 0x003 );
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}
void print_roulette_interface( user *player ){
    printf("Balance: %0.2lf$\tToken: %0.2lf$\n", (*player).money, (*player).token );
    printf("%c================================================%c\n"TOP);
    printf("%c <1>. Start game ( Ratio 1:35 )                 %c\n"MID);
    printf("%c <2>. Exchange Token                            %c\n"MID);
    printf("%c <0>. Back                                      %c\n"MID);
    printf("%c================================================%c\n"BOT);
    printf("[ Select ]: ");
}
void roulette( ColorInfor *color, user *player){
    int     number, select;
    bool    check;
    char    enter;
    do{
        print_color( color );
        draw_roulette();
        set_color( (*color).code );
	print_roulette_interface( player );
        fflush(stdin);
        check = false;
        if(scanf("%d%c", &select, &enter)!=2 || enter!='\n'){
            printf("Select the options only.\n");
            wait_random();
            printf("\n");
        }
        else if( select == 1 ){
            do{
                print_color( color );
                play_roulette( player );
                set_color( (*color).code - (1 << 10) );
            }while( ask_again( (*player).token ) );
        }
        else if ( select == 2 ){
            exchange_token( player );
        }
        else if ( select == 0 ){
            check = true;
        }
        else
            printf("Select the options only\n");
    }while( check == false );
}
void play_roulette( user *player ) {
    char    enter;
    int     guess, number;
    double  bet_money;

    printf("\nChoose a number ( 0 -> 36 ): ");
    while(scanf("%d%c", &guess, &enter)!=2 || enter!='\n' || guess > 37 || guess < 0) {
        printf("Try again.\n");
        printf("\nChoose a number ( 0 -> 36 ): ");
        fflush(stdin);
    }
    scan_bet_money( &bet_money, player );
    if( bet_money != 0 ) {
        printf("\n>>You bet %0.2lf$ on the number %d\n", bet_money, guess);
        printf(">>[ Press any key ] to spin the Roulette\n");
        fflush(stdin);
        getch();

        number = run_roulette();
        printf("The ball is rolling");
        wait_random();
        wait_random();
        printf("\nThe ball has landed on number %d\n", number);
        if( guess == number ) {
            (*player).token += bet_money*36;
            printf("Winner Winner! + %0.2lf$ to your pocket\n", bet_money*35);
        }
        else {
            printf("You lose. LOLOLOLOLOL!\n\n");
        }
    }else
        printf("Canceled.\n");
    fflush( stdin );
}

bool scan_bet_money( double *bet_money, user *player ){
    char    enter;
    printf("( Balance: %0.2lf$\tToken: %0.2lf$ )\n", (*player).money, (*player).token );
    while( true ){
        *bet_money = 0;
        fflush(stdin);
        if( (*player).token < 10 ){
            printf("You don't have enough Token to play.");
            return false;
        }else{
            printf("The amount you want to bet( minimum 10$ ): ");
            if( scanf("%lf%c", bet_money, &enter)!=2 || enter!='\n' || *bet_money < 10){
                printf("Try again!\n");
            }
            else if( *bet_money > (*player).token ){
                printf("Not enough Token.\n");
            }
            else{
                (*player).token -= (*bet_money);
                printf(" -%0.2lf$\n", *bet_money);
                return true;
            }
        }
    }
}

int run_roulette( void ){
    return rand()%37;;
}

// SICBO
//____________________________________________________________________________________________________________________

void draw_sicbo( void ) {
    int c = 219;
    printf("\n");
    set_color(13);
    printf("\t\t\t\t    %c%c%c%c%c   %c%c%c%c%c%c%c    %c%c%c%c%c%c   %c%c%c%c%c%c     %c%c%c%c%c    \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\t\t\t\t   %c           %c      %c      %c  %c     %c   %c     %c   \n",c,c,c,c,c,c,c,c);
    set_color(5);
    printf("\t\t\t\t   %c%c%c%c%c%c      %c      %c         %c%c%c%c%c%c    %c     %c   \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    set_color(4);
    printf("\t\t\t\t        %c      %c      %c      %c  %c     %c   %c     %c   \n",c,c,c,c,c,c,c,c);
    printf("\t\t\t\t   %c%c%c%c%c    %c%c%c%c%c%c%c    %c%c%c%c%c%c   %c%c%c%c%c%c     %c%c%c%c%c    \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    set_color( 0x003 );
    printf("________________________________________________________________________________________________________________________\n\n");
}

void print_sicbo_interface( user *player ){
    printf("Balance: %0.2lf$\tToken: %0.2lf$\n", (*player).money, (*player).token );
    printf("%c===============================================%c\n"TOP);
    printf("%c <1>. Start game                               %c\n"MID);
    printf("%c <2>. Exchange Token                           %c\n"MID);
    printf("%c <0>. Back                                     %c\n"MID);
    printf("%c===============================================%c\n"BOT);
    printf("[ Select ]: ");
}

void sicbo( ColorInfor *color, user *player ){
    int     select;
    char    enter;
    bool    check;
    do {
        print_color( color );
        check = false;
        fflush( stdin );
        draw_sicbo();
        set_color( (*color).code );
        print_sicbo_interface( player );
        if( scanf("%d%c", &select, &enter)!=2 || enter!='\n' || select < 0 || select > 2) {
            printf("Please select the options only");
            wait_random();
            printf("\n");
        }
        else switch ( select ) {
            case 1:
                choose_play( color, player );
                break;
            case 2:
                exchange_token( player );
                break;
            case 0:
                check = true;
                break;
            default:
                printf("Something has gone wrong. Please contact us: 0901481153\n");
            }
    }while( check == false );
}

void choose_play( ColorInfor *color, user *player ){
    int     select, key;
    char    enter;
    do{
        print_color( color );
        fflush(stdin);
        printf(">>>\n");
        printf("%c====================================================%c\n"TOP);
        printf("%c <1>. Guess Over-Under ( Ratio 1:1 )                %c\n"MID);
        printf("%c <2>. Guess Total points of dices( Ratio 1:10 )     %c\n"MID);
        printf("%c <0>. Back                                          %c\n"MID);
        printf("%c====================================================%c\n"BOT);
        do{
            printf("[ Select ]: ");
            key = scanf("%d%c", &select, &enter);
            if( key != 2 ||enter != '\n' || select < 0 || select > 2 ){
                printf("Please enter the options only.");
            }
        }while( key == -1 );
        if( select == 1){
            do{
                play_over_under( color, player );
                set_color( (*color).code - (1 << 10) );
            }while( ask_again( (*player).token ) );
        }
        else if( select == 2){
            do{
                play_total_points( color, player );
                set_color( (*color).code - (1 << 10) );
            }while( ask_again( (*player).token ) );
        }
    }while( select != 0 );
}

void play_over_under( ColorInfor *color, user *player ){
    char    select, choice, enter, result;
    int     check = 0, sum;
    double  bet_money;
    print_color( color );
    printf(">>OVER-UNDER\n\n");
    if( scan_bet_money( &bet_money, player ) ) {
        do{
            check = 0;
            fflush( stdin );
            printf("You choose over or under ( O or U ): ");
            check = scanf("%c%c", &select, &enter);
            select = toupper( select );

            if( check != 2 || enter!='\n' || ( select!='O' && select!='U' ) ){
                printf("Please enter O or U only\n");
                check = -1;
            }
            else if( select == 'O'){
                printf(" You choose Over.\n");
                check = 1;
            }
            else{
                printf(" You choose Under.\n");
                check = 1;
            }
        }while( check == -1 );
    }
    if( check == 1 ){
        fflush(stdin);
        printf("Rolling");
        shake_dice( &sum );
        if ( sum >= 4 && sum <=10) {
            printf(" %d points -> Result: Under\n", sum);
            result = 'U';
        }
        else if( sum >= 11 && sum <=17){
            printf(" %d points -> Result: Over\n", sum);
            result = 'O';
        }
        if ( select == result ) {
            printf("You won!!! +%0.2lf$\n", bet_money*2);
            (*player).token += bet_money*2;
        }
        else{
            printf("You lose LOLOLOLOL!!!\n");
        }
    }
}
void play_total_points( ColorInfor *color, user *player ){
    char    choice, enter;
    int     guess, sum, check = 0;
    double  bet_money;
    print_color( color );
    printf(">>Guess Point\n\n");
    if( scan_bet_money( &bet_money, player ) ) {
        do{
            check = 0;
            fflush( stdin );
            printf("Your guess for the total point( 3 -> 18 ): ");
            if( scanf("%d%c", &guess, &enter)!= 2 || enter!='\n' || guess < 3 || guess > 18 ){
                printf("Please choose in the range only\n");
                check = -1;
            }
            else{
                printf(" You guess %d\n", guess);
                check = 1;
            }
        }while( check == -1 );
    }
    if( check == 1) {
        fflush(stdin);
        printf("Rolling");
        shake_dice( &sum );
        printf("\n");
        printf("Total points: %d\n", sum);
            if ( guess == sum ){
            printf("You won!!! +%0.2lf$\n", bet_money*10);
            (*player).token += bet_money*10;
        }
        else{
            printf("You lose LOLOLOLOLOLOL!!!\n");
        }
    }
}

void shake_dice( int *sum ){
    *sum = 0;
    int  index;
    for ( index = 1; index <= 3 ; index++ ){
        int point = get_random_dice();
        wait_random();
        printf("\n");
        switch ( point ) {
            case 1:
                printf(" *********\n");
                printf(" *       *\n");
                printf(" *   #   *\n");
                printf(" *       *\n");
                printf(" *********\n");
                break;
            case 2:
                printf(" *********\n");
                printf(" * #     *\n");
                printf(" *       *\n");
                printf(" *     # *\n");
                printf(" *********\n");
                break;
            case 3:
                printf(" *********\n");
                printf(" * #     *\n");
                printf(" *   #   *\n");
                printf(" *     # *\n");
                printf(" *********\n");
                break;
            case 4:
                printf(" *********\n");
                printf(" * #   # *\n");
                printf(" *       *\n");
                printf(" * #   # *\n");
                printf(" *********\n");
                break;
            case 5:
                printf(" *********\n");
                printf(" * #   # *\n");
                printf(" *   #   *\n");
                printf(" * #   # *\n");
                printf(" *********\n");
                break;
            case 6:
                printf(" *********\n");
                printf(" * #   # *\n");
                printf(" * #   # *\n");
                printf(" * #   # *\n");
                printf(" *********\n");
                break;
            default:
                printf("Something has gone wrong. Please contact us: 0901481153\n");
        }
        ( *sum ) += point;
    }
}

int get_random_dice(void){
    return rand()%6 + 1;
}

bool ask_again( double token ){
    char    select;
    fflush( stdin );
    hide_cursor();
    printf("\t\t\t\t%c===========================================%c\n"TOP);
    printf("\t\t\t\t%c                Play again?                %c\n"MID);
    printf("\t\t\t\t%c             [ Y ]       [ N ]             %c\n"MID);
    printf("\t\t\t\t%c===========================================%c\n"BOT);
    while( select != 'Y' && select != 'y' && select != 'N' && select != 'n' ){
        if( kbhit()){
            select = getch();
        }
    }
    fflush( stdin );
    appear_cursor();
    if( select == 'Y' || select == 'y' ){
        if( token > 9 )
            return true;
        else{
            printf("Not enough token. ");
            printf("[ Press any key ]\n\n");
            getch();
            return false;
        }
    }
    else{
        return false;
    }
}

//time
//____________________________________________________________________________________________________________________

void wait_random( void ) {
    clock_t start = clock();;
    int     pause = CLOCKS_PER_SEC;
    while( clock() < start + pause/3 );
    printf(".");
    while( clock() < start + pause*2/3 );
    printf(".");
    while( clock() < start + pause );
    printf(".");
}
void wait_login_exit( void ) {
    clock_t start   = clock();
    int     loading = 1.5*CLOCKS_PER_SEC;
    while( clock() < start + loading/4 );
    printf(".");
    while( clock() < start + loading/2 );
    printf(".");
    while( clock() < start + loading*3/4 );
    printf(".");
    while( clock() < start + loading );
}
void wait_half_sec( void ){
    clock_t start = clock();
    int pause = CLOCKS_PER_SEC;
    while( clock()< start + pause/2 );
}

// The end
//______________________________________________________________________________

void check_end_consonent( ColorInfor *color, user *player ){

    if( ( (*player).money + (*player).token ) < 1  && (*player).hope > 0 ){
        the_end( color, player );
    }
    if( (*player).money >= 100000 && (*player).hope > 0 ){
        the_end( color, player );
    }
}
void the_end( ColorInfor *color, user *player ){
    (*player).hope--;
    print_color( color );
    if( (*player).hope == 0 && ( (*player).money + (*player).token <1 ) ){
        set_color( 0 << 10 | 0 << 4 |14 );
        hide_cursor();
        printf("\n\n%c You have run out of money and tokens. \n", 248); wait_half_sec();
        printf("%c And in desperation, Mr. Trong helped you pay your debt and your daughter's medicine.\n", 248); wait_half_sec();
        printf("%c He sent you 1000$ to buy a plane ticket to meet your daughter.\n\n", 248); wait_half_sec();
        printf(" Balance + 1000$\n"); wait_half_sec();
        (*player).money += 1000.0;
        printf("[ Press Enter ]...");
        getchar();
        select_the_end( color, player );
    }
    if( (*player).money >= 100000.0 ){
        set_color( 0 << 10 | 0 << 4 |14 );
        printf("\n\n%c You have earn enough money. Now it's time to go home.\n\n", 248); wait_half_sec();
        fflush( stdin );
        select_the_end( color, player );
    }
}
void select_the_end( ColorInfor *color, user *player ){
    char select;
    set_color( (*color).code );
    printf("What will you do?\n");
    printf("[  ESC  ] to go home... { WARNING: Your data will be removed}\n");
    printf("[ Enter ] to stay...\n\n");
    hide_cursor();
    while( select != 27 && select != 13  ){
        if( kbhit()){
            select = getch();
        }
    }
    if( select == 13 ){
        printf("WELCOME BACK\n");
        wait_half_sec(); wait_half_sec(); wait_half_sec(); wait_half_sec();
        fflush( stdin );
    }
    else{
        remove((*player).username );
        printf("Never comeback here.");
        wait_half_sec();wait_half_sec();wait_half_sec();wait_half_sec();
        fflush( stdin );
        print_exit_interface();
        exit( 0 );
    }
}
void print_exit_interface( void ){
    set_color( 0 );
    system( "CLS" );
    set_color( 0x00C );
    int c = 219;
    printf("\t\t                %c%c%c%c%c%c   %c       %c %c%c%c%c%c%c%c     %c%c%c%c%c%c   %c       %c %c%c%c%c%c%c%c               \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\t\t                %c     %c   %c     %c  %c           %c     %c   %c     %c  %c                     \n",c,c,c,c,c,c,c,c,c,c);
    printf("\t\t                %c     %c    %c   %c   %c           %c     %c    %c   %c   %c                     \n",c,c,c,c,c,c,c,c,c,c);
    printf("\t\t                %c%c%c%c%c%c      %c%c%c    %c%c%c%c%c%c      %c%c%c%c%c%c      %c%c%c    %c%c%c%c%c%c                \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\t\t                %c     %c      %c     %c           %c     %c      %c     %c                     \n",c,c,c,c,c,c,c,c);
    printf("\t\t                %c     %c      %c     %c           %c     %c      %c     %c                     \n",c,c,c,c,c,c,c,c);
    printf("\t\t                %c%c%c%c%c%c       %c     %c%c%c%c%c%c%c     %c%c%c%c%c%c       %c     %c%c%c%c%c%c%c               \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    set_color( 0x003 );
    printf("________________________________________________________________________________________________________________________\n");
}
