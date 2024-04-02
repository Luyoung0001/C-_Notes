#ifndef FORMAT_H_
#define FORMAT_H_
#include <algorithm>
#include <ios>
// format stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

format setFormat();
void restore(format f, precis p);


#endif