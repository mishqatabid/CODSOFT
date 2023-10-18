#include <iostream>
using namespace std;

// Function to perform addition
double addition(double x, double y) {
    return x + y;
}

// Function to perform subtraction
double subtract(double x, double y) {
    return x - y;
}

// Function to perform multiplication
double multiply(double x, double y) {
    return x * y;
}

// Function to perform division
double divide(double x, double y) {
    if (y == 0) {
        cout << "IMPOSSIBLE AS DENOMINATOR IS 0" << endl;
        return 0;
    }
    return x / y;
}

int main() {
    double num1, num2;
    int operation;
    char opt;
    
	cout << "    -------------------- BASIC CALCULATOR --------------------" <<endl;

	do{
	    cout << "[+] ENTER 1ST NUMBER: ";
	    cin >> num1;
	
		cout << "[+] ENTER 2ND NUMBER: ";
	    cin >> num2;
	
	    cout << "\n[+] CHOOSE THE OPTION:";
	    cout << "\n\n[+] ADDITION (+)" <<endl;
	    cout << "[+] SUBTRACTION (-)" <<endl;
	    cout << "[+] MULTIPLICATION (*)" <<endl;
	    cout << "[+] DIVISION (/)" <<endl;
	    cout << "\nSELECT OPERATION (1-4)" <<endl;
	    
	    cin >> operation;
	
	    double result;
	
		
	    switch (operation) {
	        case 1:
	            result = addition(num1, num2);
	            cout << "RESULT: " << num1 << " + " << num2 << " = " << result << endl;
	            break;
	        case 2:
	            result = subtract(num1, num2);
	            cout << "RESULT: " << num1 << " - " << num2 << " = " << result << endl;
	            break;
	        case 3:
	            result = multiply(num1, num2);
	            cout << "RESULT: " << num1 << " * " << num2 << " = " << result << endl;
	            break;
	        case 4:
	            result = divide(num1, num2);
	            cout << "RESULT: " << num1 << " / " << num2 << " = " << result << endl;
	            break;
	        default:
	            cout << "INVALID OPERATION" << endl;
	            return 1;
	    }
	    
	    cout << "\n[+] DO YOU WANT TO CONTINUE (Y/N)" <<endl;
	    cin >> opt;
	    
	}while(opt == 'Y' || opt == 'y');
	
    return 0;
}

