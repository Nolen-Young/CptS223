#pragma once
#include <queue>
#include <vector>
#include <list>
#include <stack>
#include "Processor.h"
#include "job.h"
#include <iostream>


class MyScheduler {
public:
	// public functions, only constructor and destructor and tick and insertJob should be accessed;
	MyScheduler(int num_processors, int initial_id);
	~MyScheduler();
	bool tick(std::string job_desc, int procs, int ticks); // runs the whole tick
	void insertJob(std::string job_desc, int procs, int ticks);

private:
	// variables
	std::stack <Processor> free_pool;
	int next_id;
	std::priority_queue <Job *, std::vector<Job*>, MyComparator> job_wait_heap;
	std::list <Job*> running_job_list;

	// functions0 
	Job *const FindShortest();
	void deleteShortest();
	int checkAvailability();
	void runJob();
	void decrementTimer();
	void releaseProcs(Job * delete_job);
};