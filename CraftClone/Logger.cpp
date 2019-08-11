#include "Logger.h"


void Logger::log(const LogLevel & ll, const std::string & msg)
{

	std::string logLevelString = "DEBUG";
	std::string logTime = "12:34:56";

	switch (ll) {
	case LogLevel::Debug:
		logLevelString = "DEBUG";
		break;
	case LogLevel::Info:
		logLevelString = "INFO";
		break;
	case LogLevel::Warning:
		logLevelString = "WARNING";
		break;
	case LogLevel::Error:
		logLevelString = "ERROR";
		break;
	case LogLevel::Fatal:
		logLevelString = "FATAL";
		break;
	}

	Log l = { logLevelString, logTime, msg };
	mLogs.push_back(l);

	std::string log = format("[%s][%s]%s\r\n", logLevelString.c_str(), logTime.c_str(), msg.c_str());

	if (mLogToFile) {
		mLogFile->write(log.c_str(), log.size());
		mLogFile->flush();
	}

	std::cout << log;
}

void Logger::fatal(const std::string & msg)
{
	log(LogLevel::Fatal, msg);
}

void Logger::error(const std::string & msg)
{
	log(LogLevel::Error, msg);
}

void Logger::warning(const std::string & msg)
{
	log(LogLevel::Warning, msg);
}

void Logger::info(const std::string & msg)
{
	log(LogLevel::Info, msg);
}

void Logger::debug(const std::string & msg)
{
	log(LogLevel::Debug, msg);
}

Logger::Logger()
{
	debug("Initial log");
	mLogToFile = false;
	mLogFile = std::make_unique<std::ofstream>("log.txt", std::ofstream::binary);
}

Logger::~Logger()
{
	mLogFile->close();
	mLogFile = nullptr;
}