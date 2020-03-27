#include "Processor.h"

Processor::Processor(int nid) {
	this->id = nid;
}

int Processor::getId() {
	return this->id;
}
