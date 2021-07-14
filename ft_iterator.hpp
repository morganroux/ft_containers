/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 11:57:54 by mroux             #+#    #+#             */
/*   Updated: 2021/07/14 13:26:02 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTITERATOR_HPP
#define FTITERATOR_HPP
#include <iostream>
namespace ft
{
	//------------- TAGS -------------//
	struct input_iterator_tag
	{
	}; // Input Iterator
	struct output_iterator_tag
	{
	}; // Output Iterator
	struct forward_iterator_tag
	{
	}; // Forward Iterator
	struct bidirectional_iterator_tag
	{
	}; // Bidirectional Iterator
	struct random_access_iterator_tag
	{
	}; // Random-access Iterator

	//------------- TRAITS -------------//
	template <class Iter>
	class iterator_traits
	{
	public:
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		typedef typename Iter::iterator_category iterator_category;
	};

	template <class T>
	class iterator_traits<T *>
	{
	public:
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template <class T>
	class iterator_traits<const T *>
	{
	public:
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T *pointer;
		typedef const T &reference;
		typedef random_access_iterator_tag iterator_category;
	};

	//------------- ITERATOR -------------//
	template <class Category, class T, class Distance = ptrdiff_t,
			  class Pointer = T *, class Reference = T &>
	struct iterator
	{
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

	//------------- REVERSE ITERATOR -------------//
	template <class Iter>
	class ReverseIterator
	{
	public:

		typedef				Iter												iterator_type;
		typedef typename 	ft::iterator_traits<Iter>::iterator_category		iterator_category;
		typedef typename 	ft::iterator_traits<Iter>::value_type				value_type;
		typedef typename 	ft::iterator_traits<Iter>::difference_type			difference_type;
		typedef typename 	ft::iterator_traits<Iter>::pointer					pointer;
		typedef typename 	ft::iterator_traits<Iter>::reference				reference;

		ReverseIterator() {_current = iterator_type(); };
		ReverseIterator(iterator_type it) { _current = it; };
		ReverseIterator(ReverseIterator<iterator_type> const& rev_it){ _current = rev_it._current; };
		ReverseIterator& operator=(ReverseIterator const& other) { _current = other._current; return (*this); };
		ReverseIterator& operator++() { _current--; return *this; };
		ReverseIterator operator++(int)
		{
			ReverseIterator retval = *this;
			++(*this);
			return retval;
		}
		ReverseIterator& operator--() { _current++; return *this; };
		ReverseIterator operator--(int)
		{
			ReverseIterator retval = *this;
			--(*this);
			return retval;
		}
		ReverseIterator operator+(int n) { _current -= n; return *this; };
		ReverseIterator operator+(ReverseIterator other);
		ReverseIterator operator-(int n) { _current -= n; return *this; };
		difference_type operator-(ReverseIterator other) { return -(_current - other._current); }
		bool operator==(ReverseIterator const &other) const { return (_current == other._current); };
		bool operator!=(ReverseIterator const &other) const { return !this->operator==(other); };
		typename iterator_type::value_type &operator*() { return *(_current - 1); };
		typename iterator_type::value_type const &operator*() const { return *(_current); };

	private:

		iterator_type	base() { return _current;};
		iterator_type 	_current;

	};
}

#endif
