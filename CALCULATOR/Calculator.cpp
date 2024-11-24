#include <iostream>
#include <cstring>
#include <chrono>

using namespace std;

class Measure_Time_Execution{
private:
	chrono::high_resolution_clock::time_point  StartTime;
	chrono::high_resolution_clock::time_point  EndTime;

public:
	void start()
	{
		StartTime = chrono::high_resolution_clock::now();
	}

	void stop()
	{
		EndTime = chrono::high_resolution_clock::now();
	}

	double DurationMilliseconds() const{
		return chrono::duration_cast<chrono::milliseconds>(EndTime - StartTime).count();
	}

	double DurationMicroseconds() const{
		return chrono::duration_cast<chrono::microseconds>(EndTime - StartTime).count();
	}

	double DurationNanoSeconds() const{
		return chrono::duration_cast<chrono::nanoseconds>(EndTime-StartTime).count();
	}

	void PrintDuration(const string& label = "Execution Time") const{
		cout << label << ": " << DurationMilliseconds() << "ms (" << DurationMicroseconds() << " microseconds)" << "( " <<  DurationNanoSeconds() << " "  << "Nano Seconds )" <<endl;
	}
};

class Calculator{
public:
	long long  a,b;
	void Add(long long a, long long b)
	{
		long long c=a+b;
		cout << "Addition is " << c << endl; 
	}
	void Substract(long long a, long long b)
	{
		long long c = a-b;
		cout << "Substraction is " << c << endl; 	
	}
	void Multipy(long long a,long long b)
	{
		long long c = a*b;
		cout << "Multiplication is " << c << endl; 
	}

	void Division(long long a,long long b)
	{
		if(b == 0)
		{
			cout << "ERROR :Trying to divide with 0";
			return;
		}
		else
		{
			long long c = a/b;
			cout << "Division is " << c << endl; 	
		}
		
	}

};


int main()
{
	freopen("D:\\C++\\PROJECTS\\CALCULATOR\\inputf.in","r",stdin);
	freopen("D:\\C++\\PROJECTS\\CALCULATOR\\outputf.in","w",stdout);
	Calculator Cal;
	Measure_Time_Execution Timer;

	Timer.start();
	cout << "Hi User" << endl;
	cout << "what Operations you want to perform" << endl;
	cout << "We have Lots of Options please Input" << endl;
	cout << "1/ Add, 2/ Substract ,3/ Multipy, 4/Division " << endl;
	long long UserInput = 0;
	long long a = 0;
	long long b = 0;
	//system("echo %cd%"); // Windows

	if (!(cin >> UserInput)) {
        cerr << "Error reading UserInput from inputf.in" << endl;
        return 1;
    }
    if (!(cin >> a >> b)) {
        cerr << "Error reading numbers a and b from inputf.in" << endl;
        return 1;
    }
	cin >> UserInput;
    cout << "You selected operation: " << UserInput << endl;

    cout << "Input Numbers" << endl;
    cin >> a;
    cin >> b;
    cout << "You entered numbers: " << a << " and " << b << endl;
	

    
	
		switch(UserInput)
		{
			case 1: Cal.Add(a,b);break;
			case 2: Cal.Substract(a,b);break;
			case 3: Cal.Multipy(a,b);break;
			case 4: Cal.Division(a,b);break;
			default: cout << "Invalid option!" << endl;
			break;

		}
	Timer.stop();
	Timer.PrintDuration("Loop Execution Time");
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}