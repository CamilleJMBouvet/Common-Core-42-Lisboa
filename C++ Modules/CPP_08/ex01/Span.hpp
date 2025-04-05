/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:35:23 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/22 14:25:01 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

// -LIBRARIES-
# include <algorithm>
# include <climits>
# include <vector>

// -CLASS-
class Span
{
	public:
		Span(unsigned int n);
		Span(Span const &src);
		~Span();

		Span	&operator=(Span const &src);

		unsigned int		get_n()const;
		std::vector<int> get_vct()const;
		std::vector<int> &access_vct();
		

		void	addNumber(int nb);
		int		shortestSpan();
		int		longestSpan();

		class SpanException: public std::exception
		{
		};
		class EmptySpanException: public SpanException
		{
			public:
				virtual char const *what()const throw();
		};
		class MaxCapacityException: public SpanException
		{
			public:
				virtual char const *what()const throw();
		};

	private:
		Span();

		unsigned int _n;
		std::vector<int> _vct;
};

#endif
