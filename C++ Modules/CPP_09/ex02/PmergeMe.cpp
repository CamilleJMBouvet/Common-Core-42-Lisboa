/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:58:37 by cbouvet           #+#    #+#             */
/*   Updated: 2025/03/19 14:37:22 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include "PmergeMe.hpp"

//----------------- Constructor/Destructor -----------------
PmergeMe::PmergeMe()
{
	throw (std::runtime_error(ERR_CONSTRUCTOR));
}

PmergeMe::PmergeMe(int size, int *unsorted, std::queue<int> que): _type("queue"), _size(size)
{
	(void)que;
	if (!unsorted)
		throw (std::runtime_error(ERR_EMPTY));
	if (size == 1)
		throw (std::runtime_error(ERR_SINGLETON));

	clock_t start = clock();

	this->mergeInsertQue(unsorted);

	clock_t end = clock();
	this->_duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
}

PmergeMe::PmergeMe(int size, int *unsorted, std::vector<int> vct): _type("vector"), _size(size)
{
	(void)vct;

	if (!unsorted)
		throw (std::runtime_error(ERR_EMPTY));
	if (size == 1)
		throw (std::runtime_error(ERR_SINGLETON));

	clock_t start = clock();

	this->mergeInsertVct(unsorted);

	clock_t end = clock();
	this->_duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
}

PmergeMe::PmergeMe(int size, int *unsorted, std::set<int> set): _type("set"), _size(size)
{
	(void)set;

	if (!unsorted)
		throw (std::runtime_error(ERR_EMPTY));
	if (size == 1)
		throw (std::runtime_error(ERR_SINGLETON));

	clock_t start = clock();

	this->_set.insert(unsorted, unsorted + size);

	clock_t end = clock();
	this->_duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
}

PmergeMe::PmergeMe(PmergeMe const &src): _que(src._que)
{
	this->_que = src._que;
	this->_vct = src._vct;
	this->_set = src._set;
	this->_type = src._type;
	this->_size = src._size;
	this->_duration = src._duration;
}

PmergeMe::~PmergeMe()
{}

//---------------- Copy assignement operator ---------------
PmergeMe	&PmergeMe::operator=(PmergeMe const &src)
{
	if (this != &src)
	{
		this->_que = src._que;
		this->_vct = src._vct;
		this->_set = src._set;
		this->_type = src._type;
		this->_size = src._size;
		this->_duration = src._duration;
	}
	return (*this);
}

//-------------------- Action functions --------------------
void	PmergeMe::mergeInsertQue(int *unsorted)
{
	std::queue<std::pair<int, int> > que;

	for (int i = 0; i < this->_size; i += 2)
	{
		std::pair<int, int> p(unsorted[i], -1);
		if (!(this->_size % 2) || i != this->_size -1)
			p = std::make_pair(unsorted[i], unsorted[i +1]);
		que.push(p);
	}

	std::queue<std::pair<int, int> > tmp;
	while (!que.empty())
	{
		if (que.front().first > que.front().second && que.front().second != -1)
			std::swap(que.front().first, que.front().second);
		tmp.push(que.front());
		que.pop();
	}
	que = tmp;

	while (!que.empty())
		this->_que.push(findSmallest(que));
}

void	PmergeMe::mergeInsertVct(int *unsorted)
{
	std::vector<std::pair<int, int> > vct;

	for (int i = 0; i < this->_size; i += 2)
	{
		std::pair<int, int> p(unsorted[i], -1);
		if (!(this->_size % 2) || i != this->_size -1)
			p = std::make_pair(unsorted[i], unsorted[i +1]);
		vct.push_back(p);
	}

	std::vector<std::pair<int, int> >::iterator it = vct.begin();

	for (; it != vct.end(); ++it)
		if (it->first > it->second && it->second != -1)
			std::swap(it->first, it->second);

	while (!vct.empty())
		this->_vct.push_back(findSmallest(vct));
}

int	PmergeMe::findSmallest(std::queue<std::pair<int, int> > &que)
{
	int smallest = que.front().first;
	std::queue<std::pair<int, int> > tmp;

	while (!que.empty())
	{
		if (que.front().first < smallest)
			smallest = que.front().first;
		tmp.push(que.front());
		que.pop();
	}

	while (!tmp.empty())
	{
		if (tmp.front().first == smallest)
		{
			tmp.front().first = -1;
			std::swap(tmp.front().first, tmp.front().second);
			if (tmp.front().first != -1)
				que.push(tmp.front());
		}
		else
			que.push(tmp.front());
		tmp.pop();
	}

	return (smallest);
}

int	PmergeMe::findSmallest(std::vector<std::pair<int, int> > &vct)
{
	std::vector<std::pair<int, int> >::iterator it1 = vct.begin();
	std::vector<std::pair<int, int> >::iterator it2 = ++vct.begin();

	int smallest = it1->first;
	for (; it2 != vct.end(); ++it2)
		if (it1->first > it2->first)
			it1 = it2;

	smallest = it1->first;
	it1->first = it1->second;
	it1->second = -1;
	if (it1->first == -1)
		vct.erase(it1);

	return (smallest);
}

void	PmergeMe::printSorted()
{
	if (this->_type == "queue" && !this->_que.empty())
	{
		std::queue<int> tmp;
		while (!this->_que.empty())
		{
			std::cout << GREY << this->_que.front() << " ";
			tmp.push(this->_que.front());
			this->_que.pop();
		}
		this->_que = tmp;
	}
	else if (this->_type == "vector" && !this->_vct.empty())
		for (std::vector<int>::iterator it = this->_vct.begin(); it != this->_vct.end(); ++it)
			std::cout << GREY << *it << " ";
	else if (this->_type == "set" && !this->_set.empty())
		for (std::set<int>::iterator it = this->_set.begin(); it != this->_set.end(); ++it)
			std::cout << GREY << *it << " ";
	std::cout << R << std::endl;
}

void	PmergeMe::printTime()
{
	if (this->_type == "set")
		std::cout << std::endl << PURPLE "BONUS: For best efficieny, use a " GREY "set" PURPLE ":" \
		<< std::endl << PURPLE "It automatically sorts the data upon insertion!" R << std::endl;

	std::cout << GREY "Time to process range of " BLUE << this->_size \
	<< GREY " with " PINK "std::" << this->_type \
	<< GREY ": " BLUE << this->_duration << GREY " us" R << std::endl;
}
