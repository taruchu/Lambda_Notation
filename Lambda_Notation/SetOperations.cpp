
#include "SetOperations.h"

namespace setoperations
{
	char* OutOfRangeExc::GetMessage()
	{
		return message;
	}

	void OutOfRangeExc::SetMessage(char* msg)
	{
		message = msg;
		return;
	}
};