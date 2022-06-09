#ifndef __SPAN_HPP__
# define __SPAN_HPP__

# include <vector>
# include <cstdlib>
# include <climits>
# include <iostream>

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const &src);
		virtual	~Span(void);

		Span	&operator=(Span const &rhs);

		// Accessor

		size_t	size(void) const;

		// Exception class

		class NoSlotLeftError : public std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return "Error: Span class already full";
			}
		};

		class TooFewIntegerError : public std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return "Error: Span class contain too few arguments";
			}
		};

		// Member Function

		void	addNumber(int i);
		void	addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
		int		shortestSpan(void);
		int		longestSpan(void);


	private:
		Span(void);

		unsigned int		_max_size;
		std::vector<int>	_vector;
};

#endif // **************************************************** __SPAN_HPP__ //
