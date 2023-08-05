#include <iostream>
#include <conio.h>
#define	  stop __asm nop
using namespace std;

int main() {
	{
		cout << "Var1" << endl;
		cout << "Enter a,d,s,w (0-exit)" << endl;
		char key;
		bool flag = true;
		do {

			std::cin >> key;
			switch (key)
			{
			case 'a':
				cout << "<\n" << endl;
				break;
			case 'd':
				cout << ">\n" << endl;
				break;
			case 'w':
				cout << "^\n" << endl;
				break;
			case 's':
				cout << "v\n" << endl;
				break;
			case '0':
				flag = false;
				break;
			default:
				cout << "Error input" << endl;
				break;
			}
		} while (flag);
		stop
	}
	{
		cout << "Var2" << endl;
		cout << "Enter a,d,s,w (ESC-exit)" << endl;
		enum KeyInput { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd', ESC = 27 };
		int key;
		bool flag = true;
		do {

			key = _getch();
			switch (key)
			{
			case LEFT:
				cout << "<\n" << endl;
				break;
			case RIGHT:
				cout << ">\n" << endl;
				break;
			case UP:
				cout << "^\n" << endl;
				break;
			case DOWN:
				cout << "v\n" << endl;
				break;
			case ESC:
				flag = false;
				break;
			default:
				cout << "Error input" << endl;
				break;
			}
		} while (flag);
		stop
	}

	{
		cout << "Var3" << endl;
		cout << "Enter UP,DOWN,LEFT,RIGHT (ESC-exit)" << endl;
		enum KeyInput { UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, ESC = 27 };
		unsigned int key;
		bool flag = true;
		do {
			key = _getch();
			if (key == 224)
				key = _getch();
			switch (key)
			{
			case LEFT:
				cout << "<\n" << endl;
				break;
			case RIGHT:
				cout << ">\n" << endl;
				break;
			case UP:
				cout << "^\n" << endl;
				break;
			case DOWN:
				cout << "v\n" << endl;
				break;
			case ESC:
				flag = false;
				break;
			default:
				cout << "Error input" << endl;
				break;
			}
		} while (flag);
		stop
	}
	return 0;
}