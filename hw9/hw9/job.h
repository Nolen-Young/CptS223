#include <string>
#include "Processor.h"
#include <stack>

class Job {
public:
	// funtions
	Job();
	Job(int p, int t, std::string job_desc);
	bool decrement();
	int get_processors();
	void set_processors(int p);
	void set_ticks(int i);
	int get_ticks();
	int get_id();
	void set_id(int i);
	void set_name(std::string name);
	std::string get_name();
	Processor pop_top();


private:
	// variables
	int processors;
	int ticks;
	int id;
	std::string job_description;
	std::stack <Processor> procs;

};

// This class turns the priority queue from a max heap to a min heap
class MyComparator {
public:
	int operator() (Job * j1, Job * j2)
	{
		return j1->get_ticks() > j2->get_ticks();
	}
};
