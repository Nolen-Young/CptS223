#include "myScheduler.h"
#include <fstream>

void main() {
	std::string job_desc;
	int procs;
	int ticks;
	MyScheduler sch(24, 0);
	std::ifstream ifile;
	ifile.open("jobInput.txt");
	bool runflag = true;
	while (runflag) {
		if (ifile.eof()) {
			runflag = sch.tick("NULL", 0, 0);
		}
		else {
			ifile >> job_desc;
			ifile >> procs;
			ifile >> ticks;
			sch.tick(job_desc, procs, ticks);
		}
	}
}