#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING

#include <fmt/core.h>
#include <fmt/chrono.h>
#include <string>
#include <string_view>
#include <chrono>
#include <ctime>

//using namespace std;


// 1 "Dec: 42, Hex: 0x2a, Bin: 0b101010"
std::string format_int_all_bases(int n) {
	return fmt::format("Dec: {}, Hex: {:#x}, Bin: {:#b}", n, n, n);
}

// 2 "Default: 3.14159 | Fixed: 3.14 | Sci: 3.142e+00"
std::string format_float_three_ways(double v) {
	return fmt::format("Default: {} | Fixed: {:.2f} | Sci: {:.3e}", v, v, v);
}

// 3 Logger: [YYYY-MM-DD HH:MM:SS] [LEVEL] message
enum class Level {
	Info,
	Warning,
	Error
};

constexpr std::string_view level_name(Level lvl) {
	switch (lvl) {
	case Level::Info:    return "INFO";
	case Level::Warning: return "WARNING";
	case Level::Error:   return "ERROR";
	}
	return "UNKNOWN";
}

std::string log_line(Level lvl, std::string_view message) {
	using std::chrono::system_clock;
	auto now = system_clock::now();
	std::time_t tt = system_clock::to_time_t(now);

#ifdef _WIN32
	std::tm tm{};
	localtime_s(&tm, &tt);
#else
	std::tm tm = *std::localtime(&tt);
#endif

	// fmt cannot format tm by {:%Y-%m-%d ...}
	//return fmt::format("[{:%Y-%m-%d %H:%M:%S}] [{}] {}", tm, level_name(lvl), message);

	// Format time with fmt's chrono formatter
	auto ts = fmt::format("{:%Y-%m-%d %H:%M:%S}", tm);
	
	return fmt::format("[{}] [{}] {}", ts, level_name(lvl), message);
}


int main()
{
	fmt::print("{}\n", format_int_all_bases(42));
	fmt::print("{}\n", format_float_three_ways(3.14159));

	fmt::print("{}\n", log_line(Level::Info, "Application started"));
	fmt::print("{}\n", log_line(Level::Warning, "Low disk space"));
	fmt::print("{}\n", log_line(Level::Error, "Failed to open file"));

	return 0;
}

