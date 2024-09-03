#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>

// Check what lib is necessary
#include <vector>
#include <set>

using namespace std;

// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date{
	public:
		// constructs 
		Date (const int& new_year, const int& new_month, const int& new_day){
			Year  = new_year;
			Month = new_month;
			Day   = new_day;
		}

		int GetYear() const {return Year;}
		int GetMonth() const {return Month;}
		int GetDay() const {return Day;};

	private:
		int Year;
		int Month;
		int Day;	
};

bool operator < (const Date & lhs, const Date & rhs){
	if (lhs.GetYear() == rhs.GetYear()){
		if(lhs.GetMonth() == rhs.GetMonth()){
			return lhs.GetDay() < rhs.GetDay();
		}
		return lhs.GetMonth() < rhs.GetMonth();
	}
	return lhs.GetYear() < rhs.GetYear();
}

class Database{
	public:
		void AddEvent(const Date & date, const string & event){
			year_events[date].insert(event);
		}
			
		bool DeleteEvent(const Date & date, const string & event){
			bool flag_del;
			if ((year_events.count(date) != 0) && (year_events.at(date).count(event) != 0)){
				flag_del = true;
				year_events[date].erase(event);
			}else{
				flag_del = false;
			}
			return flag_del;
		}
		int  DeleteDate(const Date & date){
			int amount_events = year_events[date].size();
			year_events.erase(date);
			return amount_events;
		}

		void Find(const Date & date) const{
			if (year_events.count(date) != 0){
				set<string> events = year_events.at(date);
				for (const auto& event : events){
					cout << event << endl;
				}
			}
		}

		void Print() const{
			cout << setfill('0');
			for (const auto& item : year_events){
				for (const auto& event : item.second){
					cout << setw(4) << item.first.GetYear()  << '-'
						 << setw(2) << item.first.GetMonth() << '-'
						 << setw(2) << item.first.GetDay() << ' '
						 << event << endl;
				}
			}
		}

	private:
		map<Date, set<string>> year_events;
};

vector<string> Parser(const string& command){
	stringstream line(command);
	vector<string> result;
	string word;
	while (line >> word){
		result.push_back(word);
	}
	return result;
}

Date Parser_Date(const string& string_date){
	int year, month, day;
	stringstream str_stream(string_date);
	str_stream >> year;
	if ((str_stream.fail()) || (str_stream.peek() != '-')){
		throw runtime_error("Wrong date format: " + string_date);
	}

	str_stream.ignore(1);
	str_stream >> month;
	if ((str_stream.fail()) || (str_stream.peek() != '-')){
		throw runtime_error("Wrong date format: " + string_date);
	}


	str_stream.ignore(1);
	str_stream >> day;
	if ((str_stream.fail()) || (str_stream.peek() != EOF)){
		throw runtime_error("Wrong date format: " + string_date);
	}
	
	if ((month <= 0) || (month > 12)){
		throw runtime_error("Month value is invalid: " + to_string(month));
	}
	if ((day <= 0) || (day > 31)){
		throw runtime_error("Day value is invalid: " + to_string(day));
	}

	return Date(year, month, day);
}

int main(){
	Database db;

	string command;
	while (getline(cin, command)){
		try{
			vector<string> operations = Parser(command);
			if (operations.size() != 0){
				if (operations[0] == "Add"){
					Date date = Parser_Date(operations[1]);
					db.AddEvent(date, operations[2]);
				}else if(operations[0] == "Del"){
					Date date = Parser_Date(operations[1]);
					if (operations.size() == 2){
						int amount_events = db.DeleteDate(date);
						cout << "Deleted " << amount_events << " events" << endl;
					}else if (operations.size() == 3){
						bool flag_del = db.DeleteEvent(date, operations[2]);
						if (flag_del){
							cout << "Deleted successfully" << endl;
						} else{
							cout << "Event not found" << endl;
						}
					}
				}else if(operations[0] == "Find"){
					Date date = Parser_Date(operations[1]);
					db.Find(date);
				}else if(operations[0] == "Print"){
					db.Print();
				} else{
					throw runtime_error("Unknown command: " + operations[0]);
				}
			}
			// Считайте команды с потока ввода и обработайте каждую
		}
		catch (exception& ex){
			cout << ex.what() << endl;
		}
	}
	return 0;
}