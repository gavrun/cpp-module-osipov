#include <concepts>
#include <iterator>
#include <type_traits>
#include <iostream>
#include <vector>
#include <string>
#include <complex>

// concept requires operators < and > to be valid for type and convertible to bool
template <typename T>
concept Sortable = requires (const T & a, const T & b) {
	{ a < b } -> std::convertible_to<bool>;
	{ a > b } -> std::convertible_to<bool>;
};

// iterator-based template with constraint on value_type via concept
template <std::forward_iterator Itr>
	requires Sortable<std::iter_value_t<Itr>>
bool is_sorted(Itr first, Itr last, bool ascending = true) {
	if (first == last) return true; // empty range sorted
	Itr prev = first;
	for (Itr it = std::next(first); it != last; ++it) {
		if (ascending) {
			if ((*it) < (*prev)) return false;
		}
		else {
			if ((*it) > (*prev)) return false;
		}
		prev = it;
	}
	return true;
}

// wrapper overload, requires type to have begin/end and value_type to be Sortable
template <typename Container>
	requires (requires(Container& c) { std::begin(c); std::end(c); } && Sortable<typename Container::value_type>)
bool is_sorted(const Container& c, bool ascending = true) {
	return is_sorted(std::begin(c), std::end(c), ascending);
}

int main()
{
	std::cout << "Sorting Template!\n";

	std::vector<int> vi1{ 1, 2, 2, 7, 9 };
	std::cout << "v[int] sorted? " << (is_sorted(vi1) ? "yes" : "no") << "\n";

	std::vector<int> vi2{ 6, 2, 2, 7, 5 };
	std::cout << "v[int] sorted? " << (is_sorted(vi2) ? "yes" : "no") << "\n";

	std::vector<std::string> vs1{ "apple", "banana", "pear", "banana" };
	std::cout << "v[string] sorted? " << (is_sorted(vs1) ? "yes" : "no") << "\n";

	int ar[5] = { 6, 2, 2, 7, 5 };
	//bool ok = is_sorted(ar);

	std::vector<std::complex<double>> vc{
		{1.0, 2.0}, {2.0, -1.0}
	};
	//bool ok = is_sorted(vc);

	return 0;
}

