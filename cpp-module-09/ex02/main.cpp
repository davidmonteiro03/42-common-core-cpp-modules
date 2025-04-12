#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>

static bool checkValue(const std::string &str)
{
	if (str.empty())
		return false;
	std::size_t i = 0;
	while (i < str.size() && std::isspace(str[i]))
		i++;
	bool hasDigits = i < str.size() && std::isdigit(str[i]);
	while (i < str.size() && std::isdigit(str[i]))
		i++;
	while (i < str.size() && std::isspace(str[i]))
		i++;
	return i == str.size() && hasDigits;
}

template <typename A, typename B>
std::ostream &operator<<(std::ostream &os, const std::pair<A, B> &pair)
{
	return os << "(" << pair.first << ", " << pair.second << ")";
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vector)
{
	for (typename std::vector<T>::const_iterator it = vector.begin(); it != vector.end(); it++)
	{
		if (it != vector.begin())
			os << " ";
		os << *it;
	}
	return os;
}

static std::vector<int> argsListToVector(char **argv, const int &size)
{
	std::vector<int> vector;
	for (int i = 0; i < size; i++)
	{
		if (!checkValue(std::string(argv[i])))
			throw std::exception();
		vector.push_back(std::atoi(argv[i]));
	}
	return vector;
}

static bool comparePairs(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	return a.first < b.first;
}

static std::vector<std::pair<int, int> > sortPairs(const std::vector<int> &vector)
{
	std::vector<std::pair<int, int> > pairs;
	for (std::size_t i = 0; i + 1 < vector.size(); i += 2)
	{
		int first = vector[i];
		int second = vector[i + 1];
		if (first < second)
			std::swap(first, second);
		pairs.push_back(std::make_pair(first, second));
	}
	std::sort(pairs.begin(), pairs.end(), comparePairs);
	return pairs;
}

static std::vector<int> pairsLeftPart(const std::vector<std::pair<int, int> > &pairs)
{
	std::vector<int> vector;
	for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
		vector.push_back(it->first);
	return vector;
}

static std::vector<int> pairsRightPart(const std::vector<std::pair<int, int> > &pairs)
{
	std::vector<int> vector;
	for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
		vector.push_back(it->second);
	return vector;
}

static std::vector<std::size_t> generateJacobsthalSequence(std::size_t n)
{
	std::vector<std::size_t> sequence;
	std::size_t a = 0, b = 1;
	while (sequence.size() < n)
	{
		sequence.push_back(a);
		std::size_t next = a + 2 * b;
		a = b;
		b = next;
	}
	return sequence;
}

static void smartInsert(std::vector<int> &vector, const std::vector<int> &minorElements)
{
	std::vector<std::size_t> jacobsthal = generateJacobsthalSequence(minorElements.size());
	for (std::size_t i = 0; i < minorElements.size(); i++)
	{
		std::size_t index = (i < jacobsthal.size()) ? jacobsthal[i] : i;
		if (index >= minorElements.size())
			index = i;
		std::vector<int>::iterator it = std::lower_bound(vector.begin(), vector.end(), minorElements[index]);
		vector.insert(it, minorElements[index]);
	}
}

int main(int argc, char **argv)
{
	try
	{
		std::vector<int> vector = argsListToVector(argv + 1, argc - 1);
		std::vector<std::pair<int, int> > pairs = sortPairs(vector);
		std::vector<int> minorElements = pairsRightPart(pairs);
		std::vector<int> result = pairsLeftPart(pairs);

		smartInsert(result, minorElements);

		std::cout << "Before: " << vector << std::endl;
		std::cout << "After: " << result << std::endl;
	}
	catch (const std::exception &)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
