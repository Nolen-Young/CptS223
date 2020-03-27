#include "job.h"

Job::Job() {
	this->processors = 0; 
	this->ticks = 0;
	this->job_description = "NULL";
}

Job::Job(int p, int t, std::string job_desc) {
	this->processors = p;
	this->ticks = t;
	this->job_description = job_desc;
}

bool Job::decrement() {
	this->ticks--;
	if (this->ticks == 0) return true;
	return false;
}

int Job::get_processors() {
	return this->processors;
}

void Job::set_processors(int p) {
	this->processors = p;
}

void Job::set_ticks(int i) {
	this->ticks = i;
}

int Job::get_ticks() {
	return this->ticks;
}

int Job::get_id() {
	return this->id;
}

void Job::set_id(int i) {
	this->id = i;
}

void Job::set_name(std::string name) {
	this->job_description = name;
}

std::string Job::get_name() {
	return this->job_description;
}

Processor Job::pop_top() {
	Processor proc = this->procs.top();
	this->procs.pop();
	return proc;
}
