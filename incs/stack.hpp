/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 09:47:54 by mroux             #+#    #+#             */
/*   Updated: 2021/07/25 13:52:57 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSTACK_HPP
#define FTSTACK_HPP
#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <typeinfo>
#include "metafunctions.hpp"
#include "vector.hpp"

namespace ft
{
	// TODO : add a custom tester
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef typename container_type::size_type size_type;

		template <class U, class UContainer>
		friend bool operator==(const stack<U, UContainer> &lhs, const stack<U, UContainer> &rhs);

		template <class U, class UContainer>
		friend bool operator!=(const stack<U, UContainer> &lhs, const stack<U, UContainer> &rhs);

		template <class U, class UContainer>
		friend bool operator<(const stack<U, UContainer> &lhs, const stack<U, UContainer> &rhs);

		template <class U, class UContainer>
		friend bool operator<=(const stack<U, UContainer> &lhs, const stack<U, UContainer> &rhs);

		template <class U, class UContainer>
		friend bool operator>(const stack<U, UContainer> &lhs, const stack<U, UContainer> &rhs);

		template <class U, class UContainer>
		friend bool operator>=(const stack<U, UContainer> &lhs, const stack<U, UContainer> &rhs);

		explicit stack(const container_type &ctnr = container_type()) : _ctnr(ctnr){};
		bool empty() const { return _ctnr.empty(); }
		size_type size() const { return _ctnr.size(); }
		value_type &top() { return _ctnr.back(); }
		value_type const &top() const { return _ctnr.back(); }
		void push(const value_type &val) { _ctnr.push_back(val); }
		void pop() { _ctnr.pop_back(); }

	private:
		container_type _ctnr;
	};

	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs._ctnr == rhs._ctnr); }

	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return !(lhs == rhs); }

	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs._ctnr < rhs._ctnr); }

	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return !(lhs > rhs); }

	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (rhs < lhs); }

	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return !(lhs < rhs); }
}
#endif
