#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

using namespace std;


int main(int argc, char** argv) {

	int s = (int) argv[2];
	string path = argv[1];

	for (const auto& entry : fs::directory_iterator(path))  {

		
		const auto filenameStr = entry.path().string();

		if (filenameStr.substr(filenameStr.find_last_of(".") + 1) == "txt") {


			cout << filenameStr << endl;
			ofstream fin(filenameStr, fstream::out || fstream::in);
			ifstream fin2(filenameStr, fstream::out || fstream::in);
			string line;
			vector<string>lines;
			if (fin.is_open()) {
				while (getline(fin2, line)) {
					string temp = std::to_string(s);
					if (temp[1] != ' ') {
						line.replace(0, 2, temp);
						lines.push_back(line);
					}
					else {
						line.replace(0, 1, temp);
						lines.push_back(line);
					}
				}
			}
			fin2.close();
			if (fin.is_open()) {
				for (int i = 0; i < lines.size(); i++) {
					fin << lines[i] << endl;
				}
			}
			fin.close();
		}
		else {
			continue;
		}

	}
	return 0;
}