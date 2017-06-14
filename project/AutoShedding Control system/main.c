#include <stdio.h>
#include <stdlib.h>
#include "graphics_lib.h"
#include "ls.h"
#include "DateConverter.h"
#include "AutoShedding.h"
#include"show_now_ls.h"
void option_menu()
{
    int menu_s;
    xnMenu main_xnMenu;
    ShowConsoleCursor(NO);
    main_xnMenu.lx=1;main_xnMenu.ly=15,main_xnMenu.items=5;main_xnMenu.width=20;main_xnMenu.now_pos=1;
    main_xnMenu.item_char[1]="Make LS schedule";
    main_xnMenu.item_char[2]="View LS schedule";
    main_xnMenu.item_char[3]="Power Control";
    main_xnMenu.item_char[4]="-";
    main_xnMenu.item_char[5]="Exit";
    GO_TOP
    print_xnMenu(main_xnMenu);
    menu_s=handle_xnMenu(main_xnMenu);
    switch(menu_s){
    case 1:

        break;
    case 2:
        break;
    case 3:
        break;
    case 5:
        DrawBox1(10,10,20,3,176);
        gotoxy(11,11);
        printf("Are you sure FORCE to exit?(\"control system may be crash!first sign out.\")(y/n):");
        if(getchar()=='y' || getchar()=='Y')
            exit(EXIT_SUCCESS);
        show_now_loadshedding();
        break;
    default:
        show_now_loadshedding();
        break;
    }
}

int main()
{
    TextColor(128);
    show_now_loadshedding();
    option_menu();
    getch();
    TextColor(128);
    DrawBox0(0,0,80,25,177);
    return 0;
}
