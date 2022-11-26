#pragma once
#include <memory>
#include <iostream>

// Init list is C++11
//https://learn.microsoft.com/fr-fr/cpp/standard-library/vector-class?view=msvc-170&viewFallbackFrom=vs-2019

namespace ft
{
	template< class T, class Alloc = std::allocator<T> >
	class Vector
	{
		public:
			// Missing iterators and difference_type typedefs
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef std::ptrdiff_t difference_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::size_type size_type;
		
			explicit Vector(const allocator_type &alloc = allocator_type()): _data(NULL), _size(0),
				_capacity(0), _allocator(alloc)
			{return ;}
			explicit Vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()):
				_size(n), _capacity(n), _allocator(alloc)
			{
				_data = _allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					_allocator.construct(_data + i, val);
				return ;
			}

			Vector &operator=(Vector const &rhs) {(void)rhs; return (*this);};

			// What to do if n is not in range ?
			reference operator[](size_type n) {return (this->_data[n]);}
			const_reference operator[](size_type n) const {return (this->_data[n]);}

			void assign(InputIterator first, InputIterator last);
			void assign(size_type count, value_type const &value);
		
		private:
			pointer _data;
			size_type _size, _capacity;
			allocator_type _allocator;
	};
}