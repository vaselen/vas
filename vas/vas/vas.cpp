#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Pipe 
{
    string namepipe="None";
    double length=0;
    int diameter=0;
    bool repair = false;
};

struct Station
{
    string namecs="None";
    int workshops=0;
    int act_workshops=0;
    int efficiency=0;
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

int check_int_efficiency(int& e)
{
    cin >> e;
    while (cin.fail() || cin.peek() != '\n' || (e < 0) || (e >= 100))
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter an int type >= 0 and <= 100: \n";
        cin >> e;
    }
    return e;
}

void AddPipe(Pipe& new_pipe)
{
    cout << endl << "Adding a new pipe:" << endl;
    cout << "Enter the name of the pipe: ";
    cin >> ws;
    getline(cin, new_pipe.namepipe);

    cout << "Enter the length of the pipe: ";
    check_double(new_pipe.length);

    cout << "Enter the pipe diameter: ";
    check_int(new_pipe.diameter);

    cout << "Enter the repair status: ";
    check_bool(new_pipe.repair);
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

void RepairPipe(Pipe& new_pipe)
{
    if (new_pipe.namepipe == "None")
    {
        cout << "No pipe available!\n";
    }
    else
    {
        cout << "Enter the new repair status: ";
        check_bool(new_pipe.repair);
        PrintAddPipe(new_pipe);
    }
}

void AddStation(Station& new_station)
{
    cout << endl << "Adding a new station:" << endl;
    cout << "Enter the name of the station: ";
    cin >> ws;
    getline(cin, new_station.namecs);

    cout << "Enter the number of workshops: ";
    check_int(new_station.workshops);

    cout << "Enter the number of working workshops: ";
    cin >> new_station.act_workshops;
    while (cin.fail() || cin.peek() != '\n' || new_station.act_workshops < 0  || new_station.act_workshops > new_station.workshops)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nThe number of working workshops must be >=0 and <= the number of workshops:\n";
        cin >> new_station.act_workshops;
    }

    cout << "Enter the station efficiency as a %: ";
    check_int_efficiency(new_station.efficiency);
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

            << "\tNumber of working workshops: " << new_station.act_workshops << "\tEfficiency: " << new_station.efficiency << "%" << endl;
    }
}

void RepairStation(Station& new_station)
{
    if (new_station.namecs == "None")
    {
        cout << "No station available!\n";
    }
    else
    {
        cout << "Enter the new number of working workshops: ";
        cin >> new_station.act_workshops;
        while (cin.fail() || cin.peek() != '\n' || new_station.act_workshops < 0 || new_station.act_workshops > new_station.workshops)
        {
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "\nThe number of working workshops must be >=0 and <= the number of workshops:\n";
            cin >> new_station.act_workshops;
        }
        PrintAddStation(new_station);
    }
}

void in_file(ofstream& fout, const Pipe& pipe, const Station& station) {
    if (pipe.namepipe == "None") {
        cout << "There is no data about the pipe to write to the file\n";
    }
    else {
        fout << pipe.namepipe << endl;
        fout << pipe.length << endl;
        fout << pipe.diameter << endl;
        fout << pipe.repair << endl;
        cout << "The data about the pipe is written\n";
    }
    if (station.namecs == "None") {
        cout << "There is no data about the station to write to the file\n";
    }
    else {
        fout << station.namecs << endl;
        fout << station.workshops << endl;
        fout << station.act_workshops << endl;
        fout << station.efficiency << endl;
        cout << "The data about the station is written\n";
    }
}

void from_file_pipe(ifstream& fin, Pipe& pipe) {
    string line;
    while (getline(fin, line)) {
        if (line.find("pipe", 0) == 0) {
            cout << "The data about the pipe was read from the file" << endl;
            cout << "Info about your pipe: " << endl;
            getline(fin, pipe.namepipe);
            cout << "Name: " << pipe.namepipe << endl;
            fin >> pipe.length;
            cout << "Length:" << pipe.length << endl;
            fin >> pipe.diameter;
            cout << "Diameter:" << pipe.diameter << endl;
            fin >> pipe.repair;
            cout << "Repair:" << pipe.repair << endl;
        }
        else {
            cout << "There is no data about the pipe in the file" << endl;
        }
        /*if (line.find("station", 0) == 0) {
            cout << "The data about the station was read from the file" << endl;
            cout << "Info about your station: " << endl;
            getline(fin, station.namecs);
            cout << "Name: " << station.namecs << endl;
            fin >> station.workshops;
            cout << "Number of workshops: " << station.workshops << endl;
            fin >> station.act_workshops;
            cout << "Number of workshops: " << station.act_workshops << endl;
            fin >> station.efficiency;
            cout << "Efficiency: " << station.efficiency << endl;
        }
        else {
            cout << "There is no data about the station in the file" << endl;
        }*/
        break;
    }
}

void from_file_station(ifstream& fin, Station& station) {
    string line;
    int k = 0;
    while (getline(fin, line)) {
        k++;
        if (k == 6) {
            if (line.find("station", 0) == 0) {
                cout << "The data about the station was read from the file" << endl;
                cout << "Info about your station: " << endl;
                getline(fin, station.namecs);
                cout << "Name: " << station.namecs << endl;
                fin >> station.workshops;
                cout << "Number of workshops: " << station.workshops << endl;
                fin >> station.act_workshops;
                cout << "Number of working workshops: " << station.act_workshops << endl;
                fin >> station.efficiency;
                cout << "Efficiency: " << station.efficiency << endl;
            }
            else {
                cout << "There is no data about the station in the file" << endl;
            }
            break;
        }
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
            cout << "There is no such command" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }


        switch (command)
        {
        case 1: //add pipe
        {
            AddPipe(pipe0);
            PrintAddPipe(pipe0);
            break;
        }
        case 2: //add station
        {
            AddStation(station0);
            PrintAddStation(station0);
            break;
        }
        case 3: //show all objects
        {
            PrintAddPipe(pipe0);
            PrintAddStation(station0);
            break;
        }
        case 4: //repair pipe
        {
            RepairPipe(pipe0);
            break;
        }
        case 5: //repair station
        {
            RepairStation(station0);
            break;
        }
        case 6:
        {
            ofstream fout;
            fout.open("vivod.txt", ios::out);
            if (fout.is_open()) {
                in_file(fout, pipe0, station0);
                fout.close();
            }
            break;
        }
        case 7:
        {
            ifstream fin;
            fin.open("vivod.txt", ios::in);
            if (fin.is_open()) {
                from_file_pipe(fin, pipe0);
                from_file_station(fin, station0);
                fin.close();
            }
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