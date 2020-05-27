#pragma once

#include <ostream>
#include <streambuf>

#include "easylogging++.h"

/// Logging class for X-Plane.
/// @author Lee C Baker
/// @date 28 August 2018
//
/// @copyright 2018 Lee C Baker

class XPLoggingBuffer : public std::streambuf {
	std::string prefix_;
	bool next_has_prefix = true;
    bool enabled = true;
protected:
	virtual int_type overflow (int_type c) {
	    static std::stringstream data;
	    if (c != EOF && enabled) {
//			if(next_has_prefix) {
//				data << prefix_;
//			}
//            if (static_cast<char>(c) == '\n') {
//                LOG(INFO) << data.str();
//                data.str(std::string());
//            } else {
//                data << static_cast<char>(c);
//            }
	    }
	    return c;
	}

public:
    void setEnabled(bool e) { enabled = e; }
	void setPrefix(const std::string & prefix) { prefix_ = prefix;}
};

class XPLogger : public std::ostream {
    XPLoggingBuffer logging_buffer;
public:
    XPLogger() : std::ostream(&logging_buffer), logging_buffer() {}
	void setPrefix(const std::string & prefix) { logging_buffer.setPrefix(prefix); }
    void setEnabled(bool e) { logging_buffer.setEnabled(e); }
};

extern XPLogger xplog;
