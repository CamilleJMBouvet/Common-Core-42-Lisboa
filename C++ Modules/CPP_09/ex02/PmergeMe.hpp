/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:56:46 by cbouvet           #+#    #+#             */
/*   Updated: 2025/03/19 14:40:09 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

// -LIBRARIES-
# include <iostream>
# include <queue>
# include <vector>
# include <set>

// -MACROS-
// NULL
# ifndef NULL
#  define NULL	0
# endif
// Errors
# define ERR_CONSTRUCTOR	"Forbidden constructor"
# define ERR_EMPTY			"empty unsorted array"
# define ERR_SINGLETON		"Only one element found, no sorting possible"
// Colours
# define GREY		"\001\033[1;37m\002"
# define PINK		"\001\033[1;38;5;225m\002"
# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define RED		"\001\033[1;31m\002"
# define R			"\001\033[1;00m\002"

// -CLASS-
class PmergeMe
{
	public:
		PmergeMe(int size, int *unsorted, std::queue<int> que);
		PmergeMe(int size, int *unsorted, std::vector<int> vct);
		PmergeMe(int size, int *unsorted, std::set<int> set);
		PmergeMe(PmergeMe const &src);
		~PmergeMe();

		PmergeMe	&operator=(PmergeMe const &src);

		void	mergeInsertQue(int *unsorted);
		void	mergeInsertVct(int *unsorted);

		int		findSmallest(std::queue<std::pair<int, int> > &que);
		int		findSmallest(std::vector<std::pair<int, int> > &vct);

		void	printSorted();
		void	printTime();

	private:
		PmergeMe();

		std::queue<int> _que;
		std::vector<int> _vct;
		std::set<int> _set;

		std::string _type;
		int	_size;
		double _duration;
};

#endif
