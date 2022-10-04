#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>

int main(){

    // Clearing out the terminal.
    start: // Label to restart the program upon completing an operation.
    system("cls||clear");

    // Printing the Title Screen.
    printf("##############################################################################\n");
    printf("#                   _      _  _             _                                #\n");
    printf("#                  | |    (_)| |           | |                               #\n");
    printf("#                  | |__   _ | |__   _   _ | |_  ___  ___                    #\n");
    printf("#                  | '_ \\ | || '_ \\ | | | || __|/ _ \\/ __|                   #\n");
    printf("#                  | |_) || || |_) || |_| || |_|  __/\\__ \\                   #\n");
    printf("#                  |_.__/ |_||_.__/  \\__, | \\__|\\___||___/                   #\n");
    printf("#             _____                   __/ |        _                         #\n");
    printf("#            / ____|                 |___/        | |                        #\n");
    printf("#           | |      ___   _ __ __   __ ___  _ __ | |_  ___  _ __            #\n");
    printf("#           | |     / _ \\ | '_ \\\\ \\ / // _ \\| '__|| __|/ _ \\| '__|           #\n");
    printf("#           | |____| (_) || | | |\\ V /|  __/| |   | |_|  __/| |              #\n");
    printf("#            \\_____|\\___/ |_| |_| \\_/  \\___||_|    \\__|\\___||_|              #\n");
    printf("#                                                                            #\n");
    printf("#                                                                            #\n");
    printf("############################## made by Faber C. ##############################");

    // Printing the menu.
    printf("\n\n                  Please select the unit you want to convert:\n\n\n");
    printf("              Decimal Units:                      Binary Units:\n\n");
    printf("           [1] KB (Kilobyte)                      [5] KiB (Kibibytes)\n\n");
    printf("           [2] MB (Megabyte)                      [6] MiB (Mebibytes)\n\n");
    printf("           [3] GB (Gigabyte)                      [7] GiB (Gibibytes)\n\n");
    printf("           [4] TB (Terabyte)                      [8] TiB (Tebibytes)\n\n");
    printf("                                [0] Explanation\n");
    
    // The actual menu system.
    unitin: // Label to loop the "_getch()" for "unitin".
    char unitin;
    unitin = _getch();
    if (unitin == '0'){ // Explanation.
        system("cls||clear");
        printf("This little program I wrote can convert units used for digital information.\nKilo/Mega/Giga/Terabytes are units consisted by multiples of 10 bytes,\nwhile Kibi/Mebi/Gibi/Tibibytes are units consisted by multiples of 2 bytes.\nIf you convert 100GB to GiB, you'll see that the value in Gibibytes will\n\"decrease\" from 100 to around 93 because of this units differences.\nSo, when setting up partitions on a drive, keep in mind these differences\nand that each Operating System displays units in it's own way. Windows,\nfor example, displays files and disks sizes in \"GB\" while it's actually\nvalues of Gibibytes and not Gigabytes.");
        printf("\n\nPress any key to return.");
        getchar();
        goto start;
    }else if(unitin == '1' || unitin == '2' ||  unitin == '3' || unitin == '4' || unitin == '5' ||
    unitin == '6' || unitin == '7' || unitin == '8'){}else{
            goto unitin;
        }

    // Printing the second part of the menu.
    system("cls||clear");
    printf("\n\n                  Now, select the unit you want to convert to:\n\n\n");
    printf("              Decimal Units:                      Binary Units:\n\n");
    printf("           [1] KB (Kilobyte)                      [5] KiB (Kibibytes)\n\n");
    printf("           [2] MB (Megabyte)                      [6] MiB (Mebibytes)\n\n");
    printf("           [3] GB (Gigabyte)                      [7] GiB (Gibibytes)\n\n");
    printf("           [4] TB (Terabyte)                      [8] TiB (Tebibytes)\n\n");

    // The actual menu system for the second part.
    unitout: // Label to loop the "_getch()" for "unitout".
    char unitout;
    unitout = _getch();
    if(unitout == '1' || unitout == '2' ||  unitout == '3' || unitout == '4' || unitout == '5' ||
    unitout == '6' || unitout == '7' || unitout == '8'){}else{
            goto unitout;
        }

    // Checking if the answers are the same units.
    if(unitin == unitout){
        system("cls||clear");
        printf("Redundancy error.\nPress any key to restart the program.");
        getchar();
        goto start;
    }

    // Creating variables.
    double // Byte values of binary Units.
    tibb = pow(2,40),
    gibb = pow(2,30),
    mibb = pow(2,20),
    kibb = pow(2,10);
    double // Byte values of Decimal Units.
    kbb = pow(1000,1),
    mbb = pow(1000,2),
    gbb = pow(1000,3),
    tbb = pow(1000,4);

    // Asking for the user to type a value.
    double sv, value;
    system("cls||clear");
    printf("Type the value you wish to convert:\n>");
    scanf("%lf", &value);
    sv = value; // Storing the value in another variable so the result displays both original and converted values.

    // Creating Strings.
    char in1[20], ou1[20]; // Strings to store the chosen units so the result display both in and out units.

    // Making the conversion.
    if(unitin == '1'){
        value = value * kbb;
        char in2[20] = "KB";
        strcpy(in1, in2);
    }else if(unitin == '2'){
        value = value * mbb;
        char in2[20] = "MB";
        strcpy(in1, in2);
    }else if(unitin == '3'){
        value = value * gbb;
        char in2[20] = "GB";
        strcpy(in1, in2);
    }else if(unitin == '4'){
        value = value * tbb;
        char in2[20] = "TB";
        strcpy(in1, in2);
    }else if(unitin == '5'){
        value = value * kibb;
        char in2[20] = "KiB";
        strcpy(in1, in2);
    }else if(unitin == '6'){
        value = value * mibb;
        char in2[20] = "MiB";
        strcpy(in1, in2);
    }else if(unitin == '7'){
        value = value * gibb;
        char in2[20] = "GiB";
        strcpy(in1, in2);
    }else if(unitin == '8'){
        value = value * tibb;
        char in2[20] = "TiB";
        strcpy(in1, in2);
    }

    // Making the conversion Phase 2.
    if(unitout == '1'){
        value = value / kbb;
        char ou2[20] = "KB";
        strcpy(ou1, ou2);
    }else if(unitout == '2'){
        value = value / mbb;
        char ou2[20] = "MB";
        strcpy(ou1, ou2);
    }else if(unitout == '3'){
        value = value / gbb;
        char ou2[20] = "GB";
        strcpy(ou1, ou2);
    }else if(unitout == '4'){
        value = value / tbb;
        char ou2[20] = "TB";
        strcpy(ou1, ou2);
    }else if(unitout == '5'){
        value = value / kibb;
        char ou2[20] = "KiB";
        strcpy(ou1, ou2);
    }else if(unitout == '6'){
        value = value / mibb;
        char ou2[20] = "MiB";
        strcpy(ou1, ou2);
    }else if(unitout == '7'){
        value = value / gibb;
        char ou2[20] = "GiB";
        strcpy(ou1, ou2);
    }else if(unitout == '8'){
        value = value / tibb;
        char ou2[20] = "TiB";
        strcpy(ou1, ou2);
    }

    // Printing the results.
    system("cls||clear");
    printf("\n%.0lf %s is equal to %.3lf %s\n\n", sv, in1, value, ou1);

    // Asking if the user wish to restart the program.
    printf("Restart the program?\n(Y/N)");
    reset:
    int reset = _getch();
    if(reset == 'Y' || reset == 'y'){
        goto start;
    }else if(reset == 'N' || reset == 'n'){
        return 0;
    }else{
        goto reset;
    }

}