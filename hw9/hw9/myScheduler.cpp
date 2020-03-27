#include "myScheduler.h"

MyScheduler::MyScheduler(int num_processors, int initial_id) {
	// loop through and create the specified amount of processor objects
	for (int i = 0; i < num_processors; i++) {
		Processor newProc(i);
		this->free_pool.push(newProc);
	}
	this->next_id = initial_id;
}

MyScheduler::~MyScheduler() {
	delete &(this->job_wait_heap);
	delete &(this->running_job_list);
}

bool MyScheduler::tick(std::string job_desc, int procs, int ticks) {
	bool runflag = true;

	// only if there is something to be inserted is something inserted
	if (job_desc != "NULL") {
		this->insertJob(job_desc, procs, ticks);
	}
	// decrement all timers
	this->decrementTimer();
	while (runflag) {
		if (this->FindShortest()->get_processors() <= this->checkAvailability()) {
			this->runJob();
			this->deleteShortest();
			runflag = true;
		}
		else {
			runflag = false;
		}
	}

	if (this->job_wait_heap.empty() && this->running_job_list.empty()) return false;

	return true;
}

void MyScheduler::insertJob(std::string job_desc, int procs, int ticks) {
	Job * newJob;
	newJob->set_name(job_desc);
	newJob->set_processors(procs);
	newJob->set_ticks(ticks);
	newJob->set_id(this->next_id);
	this->next_id++;
	std::cout << "Added to wait queue: ID: " << newJob->get_id() << "Desc: " << job_desc << "Procs: " << procs << "Ticks: " << ticks << std::endl;
	job_wait_heap.push(newJob);
}

Job * const MyScheduler::FindShortest() {
	return job_wait_heap.top();
}

void MyScheduler::deleteShortest() {
	job_wait_heap.pop();
}

int MyScheduler::checkAvailability() {
	return this->free_pool.size();
}

void MyScheduler::runJob() {
	Job * newJob = job_wait_heap.top();
	std::cout << "Added to run list: ID: " << newJob->get_id() << "Desc: " << newJob->get_name() << "Procs: " << newJob->get_processors() << "Ticks: " << newJob->get_ticks() << std::endl;
	running_job_list.push_back(newJob);
}

void MyScheduler::decrementTimer() {
	// make sure list is not empty, loop through and decrememnt all timers, if a job finishes relase the procs and erase
	if (!(this->running_job_list.empty())) {
		for (std::list<Job*>::iterator it = this->running_job_list.begin(); it != this->running_job_list.end(); ++it) {
			(*it)->set_ticks((*it)->get_ticks() - 1);
			if ((*it)->get_processors() == 0) {
				this->releaseProcs((*it));
				this->running_job_list.erase(it);
			}
		}
	}
}

void MyScheduler::releaseProcs(Job * delete_job) {
	std::cout << "Finished running: ID: " << delete_job->get_id() << "Desc: " << delete_job->get_name() << "Procs: " << delete_job->get_processors() << "Ticks: " << delete_job->get_ticks() << std::endl;
	for (int i = 0; i < delete_job->get_processors(); i++) {
		this->free_pool.push(delete_job->pop_top());
	}
}