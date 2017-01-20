#include <vector>
using namespace std;

int main(){
	string command;
	Series s;
	cout << "Enter which series: ";
	while (cin >> command) {
		if (command == "Geometric") {
			s.geometricSeries();
		}
		else if (command == "P-series") {
			s.p_Series();
		}
		else if (command == "Power") {
			cout << "power" << endl;
		}
		else {
			cout << "Not a command." << endl;
		}
	}
}
