/**
 * @file QueueException.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 1-23-14
 *
 * Queue exception class that counts as a logic error.
 */

#include <stdexcept>
#include <string>
using namespace std;

#ifndef QUEUEXCEPTION_H
#define QUEUEXCEPTION_H

class QueueException : public logic_error
{
public:
   QueueException(const string& message = "")
      : logic_error(message.c_str())
   {}  // end constructor
}; 
#endif// end QueueException
