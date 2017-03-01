#include "MyForm.h"  //            The header file of the form
using namespace Menuforms;            //            The name of the namespace in MyForm.h
[STAThreadAttribute]                   //            Run this program in STA mode
int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	MyForm fm;                     //            The form to be created and shown
	fm.ShowDialog();             //            Show the form

	TTF_Quit();
	SDL_Quit();
	return 0;
}