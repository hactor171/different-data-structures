#include "Generator.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;




Generator::Generator()
{
}


Generator::~Generator()
{
}

void Generator::generate(int n, string filename)
{
	fstream file;
	file.open(filename, ios::out);
	if (file.good() == false)
	{
		cout << "File not exist";
		exit(0);
	}
	srand(time(NULL));
	while (n--)
	{
		//file<<111<<6 + rand() % (12 - 6 + 1)<<endl;
		file<<rand()<<endl;
		file.flush();
	}
	file.close();
}

