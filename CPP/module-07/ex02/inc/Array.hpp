/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:11:31 by sokim             #+#    #+#             */
/*   Updated: 2022/07/13 18:29:22 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
private:
	T				*array_;
	unsigned int	size_;

public:
	Array() : array_(NULL), size_(0) {}

	Array(unsigned int n) : array_(new T[n]), size_(n) {}

	Array(const Array<T> &origin) {
		array_ = new T[origin.size()];
		size_ = origin.size();
		for (unsigned int i = 0; i < size_; i++)
			array_[i] = origin.array_[i];
	}

	Array &operator=(const Array<T> &origin) {
		if (this == &origin)
			return (*this);
		else if (size_ > 0)
			delete[] array_;

		size_ = origin.size();
		array_ = new T[size_];
		for (unsigned int i = 0; i < size_; i++)
			array_[i] = origin.array_[i];

		return (*this);
	}

	~Array() {
		delete[] array_;
	}

	const unsigned int	&size() const {
		return (size_);
	}

	// 마치 배열처럼 인덱스로 접근 가능하도록 [] 연산자 오버로딩
	T &operator[](long int idx) const {
		if (idx < 0 || idx >= size_)
			throw IndexOutOfRangeException();
		return (array_[idx]);
	}

	class IndexOutOfRangeException : public std::exception {
	public:
		const char	*what() const throw() {
			return ("Index is out of range!");
		}
	};
};

#endif
