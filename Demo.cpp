/**
 * Demo program for snowman exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-02
 */

#include "snowman.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;
int GiveMeNumLen(int length,bool good)//if good = true return good number with length of 8 and digits betwen 1-4 else if good == false return same number but negative
{
    int sum = 0;
    int digit = 0;
    for (int i = 0 ; i < length; i++)
    {
        digit = rand() % 4 + 1;//good digit is 1-4 
        sum += digit * pow(10,i);
    }
    if (good)
        return sum;
    return sum * -1;
}
int main() {
	srand(time(NULL));
	int num = 0;
	  cout<< "random snowmans : " <<endl;
	for (int i = 0 ; i < 100 ; i++)
	{
	  num = GiveMeNumLen(8,true);
	  cout<< "snowman id : " << num <<endl;
	  cout << ariel::snowman(num) << endl; 
	}
	cout << "Lift ur hands up!" << endl;
	cout << ariel::snowman(12222222) << endl; 
	cout << ariel::snowman(11122222) << endl; 
    cout << ariel::snowman(12122233) << endl;  
	cout << "Left hand up!" << endl;
	cout << ariel::snowman(11142322) << endl; 
	cout << ariel::snowman(41232444) << endl; 
	cout << ariel::snowman(21242111) << endl; 
	cout << "Right hand up!" << endl;
	cout << ariel::snowman(12313211) << endl; 
	cout << ariel::snowman(43313222) << endl; 
	cout << ariel::snowman(31241244) << endl; 
	cout << "Hands down!" << endl;
	cout << ariel::snowman(12223322) << endl; 
	cout << ariel::snowman(11123322) << endl; 
    cout << ariel::snowman(12123333) << endl;  
	cout << "No hands at all!" << endl;
	cout << ariel::snowman(12314411) << endl; 
	cout << ariel::snowman(43314422) << endl; 
	cout << ariel::snowman(31244444) << endl; 





}
