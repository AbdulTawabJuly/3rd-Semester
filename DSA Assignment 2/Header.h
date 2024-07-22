#pragma once
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<ctime>
#include<Windows.h>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
void LoadRules()
{
    cout << "\t \"RULES OF THE GAME\"\n\n";
    cout << " Rules are very Simple : \n";
    cout << "1-> Try to Grab the Treasure\n";
    cout << "2-> Avoid Devil Which is Hidden in the Maze Somewhere \n";
    cout << "3-> There is a Portal in the Room\n";
    cout << "* if you reached the Portal a coin will be Tossed to decide your FAITH\n";
    cout << "* if HEAD comes you will be Transported to the next Room \n";
    cout << "* In case of Tail you will be transported to the Previous Room\n";
    cout << "4-> There is A Gasper in The Room Also Which Will Transport You to the Treasure Room \n";
    cout << "\n";
    cout << "\t \"PLAY WISELY\" \n\n";
}
void LoadTitle()
{
    cout << "$$$$$$$$\\ " << "\n";
    cout << "\\__$$  __| " << "\n";
    cout << "   $$ | $$$$$$\\   $$$$$$\\   $$$$$$\\   $$$$$$$\\ $$\\   $$\\  $$$$$$\\   $$$$$$\\        $$ |  $$ |$$\\   $$\\ $$$$$$$\\ $$$$$$\\    $$$$$$\\   $$$$$$\\  " << "\n";
    cout << "   $$ |$$  __$$\\ $$  __$$\\  \\____$$\\ $$  _____|$$ |  $$ |$$  __$$\\ $$  __$$\\       $$$$$$$$ |$$ |  $$ |$$  __$$\\\\_$$  _|  $$  __$$\\ $$  __$$\\ " << "\n";
    cout << "   $$ |$$ |  \\__|$$$$$$$$ | $$$$$$$ |\\$$$$$$\\  $$ |  $$ |$$ |  \\__|$$$$$$$$ |      $$  __$$ |$$ |  $$ |$$ |  $$ | $$ |    $$$$$$$$ |$$ |  \\__|" << "\n";
    cout << "   $$ |$$ |      $$   ____|$$  __$$ | \\____$$\\ $$ |  $$ |$$ |      $$   ____|      $$ |  $$ |$$ |  $$ |$$ |  $$ | $$ |$$\\ $$   ____|$$ |      " << "\n";
    cout << "   $$ |$$ |      \\$$$$$$$\\ \\$$$$$$$ |$$$$$$$  |\\$$$$$$  |$$ |      \\$$$$$$$\\       $$ |  $$ |\\$$$$$$  |$$ |  $$ | \\$$$$  |\\$$$$$$$\\ $$ |      " << "\n";
    cout << "   \\__|\\__|       \\_______| \\_______|\\_______/  \\______/ \\__|       \\_______|      \\__|  \\__| \\______/ \\__|  \\__|  \\____/  \\_____/ \\__/" << "\n";
    cout << "\n\n\n\n";
}

#endif // HEADER_H_INCLUDED
