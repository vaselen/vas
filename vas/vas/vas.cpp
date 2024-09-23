#include <iostream>
#include <fstream>
using namespace std;

struct Pipe {
    string namepipe = "None";
    double length = 0.0;
    int diameter = 0;
    bool repair = false;
};

struct Station
{
    string namecs = "None";
    int workshops = 0;
    int act_workshops = 0;
    int efficiency = 0;
};

int check_int(int& i)

{
    cin >> i;
    while (cin.fail() || cin.peek() != '\n' || i <= 0)

    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter an int type > 0\n";
        cin >> i;
    }
    return i;
}
double check_double(double& d)
{
    cin >> d;
    while (cin.fail() || cin.peek() != '\n' || d <= 0)

    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter a double type > 0\n";
        cin >> d;

    }
    return d;

}

bool check_bool(bool& b)
{
    cin >> b;
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter a bool type\n";
        cin >> b;

    }
    return b;
}

Pipe AddPipe()

{
    Pipe new_pipe;
    cout << endl << "Adding a new pipe:" << endl;
    cout << "Enter the name of the pipe: ";
    cin >> new_pipe.namepipe;

    cout << "Enter the length of the pipe: ";
    check_double(new_pipe.length);

    cout << "Enter the pipe diameter: ";
    check_int(new_pipe.diameter);

    cout << "Enter the repair status: ";
    check_bool(new_pipe.repair);

    return new_pipe;
}

Station AddStation()

{
    Station new_station;
    cout << endl << "Adding a new station:" << endl;
    cout << "Enter the name of the station: ";
    cin >> new_station.namecs;

    cout << "Enter the number of workshops: ";
    check_int(new_station.workshops);

    cout << "Enter the number of working workshops: ";
    check_int(new_station.act_workshops);

    cout << "Enter the station efficiency as a %: ";
    check_int(new_station.efficiency);

    return new_station;
}

void PrintAddPipe(Pipe& new_pipe)

{
    cout << endl << "Info about your pipe:" << endl;
    if (new_pipe.namepipe == "None")
    {
        cout << "No pipe available!\n";
    }
    else
    {
        cout << "Name: " << new_pipe.namepipe << "\tLength: " << new_pipe.length

            << "\tDiameter: " << new_pipe.diameter << "\tRepair: " << new_pipe.repair << endl;
    }
}

void PrintAddStation(Station& new_station)

{
    cout << endl << "Info about your station:" << endl;
    if (new_station.namecs == "None")
    {
        cout << "No station available!\n";
    }
    else
    {
        cout << "Name: " << new_station.namecs << "\tNumber of workshops: " << new_station.workshops

            << "\tNumber of working workshops: " << new_station.act_workshops << "\tEfficiency: " << new_station.efficiency << endl;
    }
}



int main()
{
    Pipe pipe0;
    Station station0;
    int command;
    while (true) {
        cout << "Choose command" << endl
            << "1. Add pipe" << endl
            << "2. Add CS" << endl
            << "3. Show all objects" << endl
            << "4. Edit pipe" << endl
            << "5. Edit CS" << endl
            << "6. Save" << endl
            << "7. Download" << endl
            << "8. Exit " << endl;
        cin >> command;
        if (cin.fail() || command < 1 || command > 8)
        {
            cout << " There is no such command" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }


        switch (command)
        {
        case 1: //add pipe
        {
            pipe0 = AddPipe();
            PrintAddPipe(pipe0);
            break;
        }
        case 2: //add station
        {
            station0 = AddStation();
            PrintAddStation(station0);
            break;
        }
        case 3:
        {
            cout << "jeiw" << endl;
            break;
        }
        case 4:
        {
            cout << "slwo" << endl;
            break;
        }
        case 5:
        {
            cout << "slwo" << endl;
            break;
        }
        case 6:
        {
            cout << "slwo" << endl;
            break;
        }
        case 7:
        {
            cout << "slwo" << endl;
            break;
        }
        case 8:
        {
            return false;
            break;
        }
        }

    }
    return 0;
}