#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Pipe 
{
    string namepipe;
    double length;
    int diameter;
    bool repair;
};

struct Station
{
    string namecs;
    int workshops;
    int act_workshops;
    int efficiency;
};

int check_int(int min, int max) {
    int i;
    while ((cin >> i).fail() || cin.peek() != '\n' || i<min || i>max)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "Enter the int value in range ["<<min <<"; "<<max<<"]"<<endl;
    }
    return i;
}

double check_double(int min, int max) {
    double i;
    while ((cin >> i).fail() || cin.peek() != '\n' || i<min || i>max)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "Entet the double value in range [" <<min << "; " << max << "]" << endl;
    }
    return i;
}

void pipe_create(Pipe& new_pipe)
{
    cout << endl << "Adding a new pipe:" << endl;
    cout << "Enter the name of the pipe: ";
    cin >> ws;
    getline(cin, new_pipe.namepipe);

    cout << "Enter the length of the pipe: ";
    new_pipe.length=check_double(1,10000);

    cout << "Enter the pipe diameter: ";
    new_pipe.diameter = check_int(1, 10000);

    cout << "Enter the repair status: ";
    new_pipe.repair = check_int(0, 1);
}

void print_pipe(Pipe& new_pipe)
{
    cout << endl << "Info about your pipe:" << endl;
    if (new_pipe.namepipe == "")
    {
        cout << "No pipe available\n";
    }
    else
    {
        cout << "Name: " << new_pipe.namepipe << "\tLength: " << new_pipe.length

            << "\tDiameter: " << new_pipe.diameter << "\tRepair: " << new_pipe.repair << endl;
    }
}

void pipe_repair(Pipe& new_pipe)
{
    if (new_pipe.namepipe == "")
    {
        cout << "No pipe available\n";
    }
    else
    {
        new_pipe.repair = (!new_pipe.repair);
        cout << "The repair status has been changed\n";
        print_pipe(new_pipe);
    }
}

void station_create(Station& new_station)
{
    cout << endl << "Adding a new station:" << endl;
    cout << "Enter the name of the station: ";
    cin >> ws;
    getline(cin, new_station.namecs);

    cout << "Enter the number of workshops: ";
    new_station.workshops = check_int(0, 10000);

    cout << "Enter the number of working workshops: ";
    new_station.act_workshops = check_int(0, new_station.workshops);

    cout << "Enter the station efficiency as a %: ";
    new_station.efficiency = check_int(0, 100);
}

void print_station(Station& new_station)
{
    cout << endl << "Info about your station:" << endl;
    if (new_station.namecs == "")
    {
        cout << "No station available\n";
    }
    else
    {
        cout << "Name: " << new_station.namecs << "\tNumber of workshops: " << new_station.workshops

            << "\tNumber of working workshops: " << new_station.act_workshops << "\tEfficiency: " << new_station.efficiency << "%" << endl;
    }
}

void station_repair(Station& new_station)
{
    if (new_station.namecs == "")
    {
        cout << "No station available\n";
    }
    else
    {
        cout << "Enter the new value of working workshops <= " << new_station.workshops<<": ";
        new_station.act_workshops = check_int(0, new_station.workshops);
        print_station(new_station);
    }
}

void in_file_pipe(ofstream& fout, const Pipe& pipe) {
    if (pipe.namepipe == "") {
        cout << "There is no data about the pipe to write to the file\n";
    }
    else {
        fout << "pipe" << endl;
        fout << pipe.namepipe << endl;
        fout << pipe.length << endl;
        fout << pipe.diameter << endl;
        fout << pipe.repair << endl;
        cout << "The data about the pipe is written\n";
    }
}

void in_file_station(ofstream& fout, const Station& station) {
    if (station.namecs == "") {
        cout << "There is no data about the station to write to the file\n";
    }
    else {
        fout << "station" << endl;
        fout << station.namecs << endl;
        fout << station.workshops << endl;
        fout << station.act_workshops << endl;
        fout << station.efficiency << endl;
        cout << "The data about the station is written\n";
    }
}

void from_file_pipe(ifstream& fin, Pipe& pipe) {
    cout << "The data about the pipe was read from the file" << endl;
    cout << "Info about your pipe: " << endl;
    getline(fin >> ws, pipe.namepipe);
    cout << "Name: " << pipe.namepipe << endl;
    fin >> pipe.length;
    cout << "Length:" << pipe.length << endl;
    fin >> pipe.diameter;
    cout << "Diameter:" << pipe.diameter << endl;
    fin >> pipe.repair;
    cout << "Repair:" << pipe.repair << endl;
}

void from_file_station(ifstream& fin, Station& station) {
    cout << "The data about the station was read from the file" << endl;
    cout << "Info about your station: " << endl;
    getline(fin >> ws, station.namecs);
    cout << "Name: " << station.namecs << endl;
    fin >> station.workshops;
    cout << "Number of workshops: " << station.workshops << endl;
    fin >> station.act_workshops;
    cout << "Number of working workshops: " << station.act_workshops << endl;
    fin >> station.efficiency;
    cout << "Efficiency: " << station.efficiency << endl;
}

void all_from_file(ifstream& fin, Pipe& pipe, Station& station) {
    string line;
    while (getline(fin >> ws, line)) {
        if (line == "pipe") {
            from_file_pipe(fin, pipe);
        }
        else if (line == "station") {
            from_file_station(fin, station);
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
        command = check_int(1, 8);

        switch (command)
        {
        case 1: //add pipe
        {
            pipe_create(pipe0);
            print_pipe(pipe0);
            break;
        }
        case 2: //add station
        {
            station_create(station0);
            print_station(station0);
            break;
        }
        case 3: //show all objects
        {
            print_pipe(pipe0);
            print_station(station0);
            break;
        }
        case 4: //repair pipe
        {
            pipe_repair(pipe0);
            break;
        }
        case 5: //repair station
        {
            station_repair(station0);
            break;
        }
        case 6: //writing to the file
        {
            ofstream fout;
            fout.open("vivod.txt", ios::out);
            if (fout.is_open()) {
                in_file_pipe(fout, pipe0);
                in_file_station(fout, station0);
                fout.close();
            }
            break;
        }
        case 7: //reading from the file
        {
            ifstream fin;
            fin.open("vivod.txt", ios::in);
            if (fin.is_open()) {
                all_from_file(fin, pipe0, station0);
                if (pipe0.namepipe == "") {
                    cout << "There is no data about the pipe in the file\n";
                }
                if (station0.namecs == "") {
                    cout << "There is no data about the station in the file\n";
                }
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