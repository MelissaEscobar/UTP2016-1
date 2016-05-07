#include <iostream>
using namespace std;

int main(){
	char name[50];
	char quest[80];
	char velocity[80];
	cout<<"What's your name?";
	cin.getline(name,49);
	cout<<"What's your quest";
	cin.getline(quest,79);
	cout<<"What's the velocity of an unladen swallow?";
	cin.getline(velocity,79);

	cout<<"Name:::"<<name<<endl;
	cout<<"Quest::"<<quest<<endl;
	cout<<"Velocity::"<<velocity<<endl;



	return 0;
}
