#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <string>

#pragma comment(lib, "winmm.lib")
#define CYAN    "\033[36m"      /* Cyan */
#define RESET   "\033[0m"

using namespace std;

int main()
{
    string forstop;

    cout << CYAN << " ______________________________________________" << RESET << endl;
    cout << CYAN << "|                                             |" << RESET << endl;
    cout << CYAN << "|              Music Library                  |" << RESET << endl;
    cout << CYAN << "|_____________________________________________|" << RESET << endl;
    cout << CYAN << "|                                             |" << RESET << endl;
    cout << CYAN << "| 1. Gotye                                    |" << RESET << endl;
    cout << CYAN << "| 2. Dandelions                               |" << RESET << endl;
    cout << CYAN << "| 3. Closer - The Chainsmokers ft. Halsey     |" << RESET << endl;
    cout << CYAN << "| 4. Bones                                    |" << RESET << endl;
    cout << CYAN << "| 5. Blinding Lights                          |" << RESET << endl;
    cout << CYAN << "| 6. Beggin                                   |" << RESET << endl;
    cout << CYAN << "| 7. Arcade                                   |" << RESET << endl;
    cout << CYAN << "| 8. Exit                                     |" << RESET << endl;
    cout << CYAN << "|_____________________________________________|" << RESET << endl;

    string wanna ="";
    bool Is_quit = true;


    while(Is_quit){
    cout << "\nEnter Your Choice : ";
    int Choice;
    cin >> Choice;
    cin.ignore(); // Clear the newline character from the input buffer

    switch (Choice) {
    case 1:
        cout << "Playing Gotye\n";
        PlaySound(TEXT("Gotye.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        getline(cin, forstop);
        PlaySound(0, 0, 0);
        cout << "Stopped Music \n";

        cout<<"\nDo you want to Quit?   (Yes/No)   : ";
        cin>>wanna;
        if(wanna == "Yes")
         Is_quit = false;
       else if(wanna == "No")
         Is_quit = true;
         else cout << "\nInvalid Choice..."<<endl;
        break;

    case 2:
        cout << "Playing Dandelions\n";
        PlaySound(TEXT("Dandelions.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        getline(cin, forstop);
        PlaySound(0, 0, 0);
        cout << "Stopped Music \n";

         cout<<"\nDo you want to Quit?   (Yes/No)   : ";
        cin>>wanna;
        if(wanna == "Yes")
         Is_quit = false;
        else if(wanna == "No")
         Is_quit = true;
         else cout << "\nInvalid Choice..."<<endl;
        break;

    case 3:
        cout << "Playing Closer - The Chainsmokers ft. Halsey\n";
        PlaySound(TEXT("Closer - The Chainsmokers ft. Halsey.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        getline(cin, forstop);
        PlaySound(0, 0, 0);
        cout << "Stopped Music \n";

         cout<<"\nDo you want to Quit?   (Yes/No)   : ";
        cin>>wanna;
        if(wanna == "Yes")
         Is_quit = false;
        else if(wanna == "No")
         Is_quit = true;
         else cout << "\nInvalid Choice..."<<endl;
        break;

    case 4:
        cout << "Playing Bones\n";
        PlaySound(TEXT("Bones.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        getline(cin, forstop);
        PlaySound(0, 0, 0);
        cout << "Stopped Music \n";

         cout<<"\nDo you want to Quit?   (Yes/No)   : ";
        cin>>wanna;
        if(wanna == "Yes")
         Is_quit = false;
        else if(wanna == "No")
         Is_quit = true;
         else cout << "\nInvalid Choice..."<<endl;
        break;

    case 5:
        cout << "Playing Blinding Lights\n";
        PlaySound(TEXT("Blinding Lights.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        getline(cin, forstop);
        PlaySound(0, 0, 0);
        cout << "Stopped Music \n";

         cout<<"\nDo you want to Quit?   (Yes/No)   : ";
        cin>>wanna;
        if(wanna == "Yes")
         Is_quit = false;
        else if(wanna == "No")
         Is_quit = true;
         else cout << "\nInvalid Choice..."<<endl;
        break;

    case 6:
        cout << "Playing Beggin\n";
        PlaySound(TEXT("Beggin.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        getline(cin, forstop);
        PlaySound(0, 0, 0);
        cout << "Stopped Music \n";

         cout<<"\nDo you want to Quit?   (Yes/No)   : ";
        cin>>wanna;
        if(wanna == "Yes")
         Is_quit = false;
        else if(wanna == "No")
         Is_quit = true;
         else cout << "\nInvalid Choice..."<<endl;
        break;

    case 7:
        cout << "Playing Arcade\n";
        PlaySound(TEXT("Arcade.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        getline(cin, forstop);
        PlaySound(0, 0, 0);
        cout << "Stopped Music \n";

        cout<<"\nDo you want to Quit?   (Yes/No)   : ";
        cin>>wanna;
        if(wanna == "Yes")
         Is_quit = false;
        else if(wanna == "No")
         Is_quit = true;
         else cout << "\nInvalid Choice..."<<endl;
        break;

     case 8:
        cout << "\nExiting...\n";
        Is_quit = false;
        break;

    default:
        cout << "\nInvalid Output!!!" << endl;
        break;
    }

    }
       return 0;

}
