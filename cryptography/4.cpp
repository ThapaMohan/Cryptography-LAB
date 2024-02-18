#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream fout;

	string line = "aaa";
    string txt = ".txt";
	// by default ios::out mode, automatically deletes
	// the content of file. To append the content, open in ios:app
	// fout.open("sample.txt", ios::app)
    for (int i = 0; i <= 1000000; i++) {
        string name = to_string(i);
        string fname = name + txt;

        // Open the file outside the loop
        fout.open(fname);

        // Execute a loop if the file is successfully opened
       while (fout) {
            for (int j = 0; j <= 10000; j++) {
                // Generate large text content, you can modify this as needed
                fout << "This is line " << j << " in file " << i << endl;
            }
            
            // Write line in the file
            //fout << line << endl;
		fout.close();
    	}
	}
}