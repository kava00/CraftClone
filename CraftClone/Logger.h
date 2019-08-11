#pragma once

#include "Common.h"


enum LogLevel {
	Fatal,
	Error,
	Warning,
	Info,
	Debug
};

struct Log {
	std::string ll;
	std::string time;
	std::string desc;
};

class Logger
{
public:
	void log(const LogLevel& ll, const std::string& msg);
	void fatal(const std::string& msg);
	void error(const std::string& msg);
	void warning(const std::string& msg);
	void info(const std::string& msg);
	void debug(const std::string& msg);

	const std::vector<Log>& getLogs() { return mLogs; }

	void logToFile(bool v) { mLogToFile = v; }

	Logger();
	~Logger();

private:
	std::vector<Log> mLogs;
	std::unique_ptr<std::ofstream> mLogFile;
	bool mLogToFile;
};


inline Logger* getLogger() {
	static std::unique_ptr<Logger> log = std::make_unique<Logger>();
	return log.get();
}
