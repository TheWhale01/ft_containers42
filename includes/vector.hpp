#pragma once
#include <memory>
#include <sstream>
#include <iostream>
#include <stdexcept>

namespace ft
{
	template< class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			//missing reverse iterators
            typedef T value_type;
            typedef std::size_t size_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef pointer iterator;
            typedef const_pointer const_iterator;
            typedef typename std::ptrdiff_t difference_type;

			// CONSTRUCTORS
            explicit vector(const allocator_type &alloc = allocator_type()): _data(NULL), _size(0), _capacity(0), _allocator(alloc) {}
            explicit vector(size_type n, const value_type &val = value_type(),
				const allocator_type &alloc = allocator_type()): _size(n), _capacity(n), _allocator(alloc)
			{
				_data = _allocator.allocate(_capacity);
				for (size_type i = 0; i < n; i++)
					_allocator.construct(_data + i, val);
			}

            template <class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
			{
				if (first > last)
					throw (std::length_error());
				_size = last - first;
				_capacity = _size;
				_data = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(_data + i, *(first + i));
			}
            vector(const vector &x): _data(NULL), _size(0), _capacity(0) {*this = x;}

			// DESTRUCTOR
			~vector(void)
			{
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_data + i);
				_allocator.deallocate(_data, _capacity);
			}

			// OPERATOR OVERLOAD
			vector &operator=(vector const &rhs)
			{
				if (this == &rhs)
					return (*this);
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_data + i);
				if (_capacity)
					_allocator.deallocate(_data, _capacity);
				_data = _allocator.allocate(rhs.capacity());
				_capacity = rhs.capacity();
				for (size_type i = 0; i < rhs.size(); i++)
					_allocator.construct(_data + i,	rhs[i]);
				_size = rhs.size();
				return (*this);
			}

			// ITERATORS
			// missing reverse iterators
			iterator begin(void) {return (_data);}
			iterator end(void) {return (_data + _size);}
			const_iterator begin(void) const {return (_data);}
			const_iterator end(void) const {return (_data + _size);}

			// CAPACITY
			bool empty(void) const {return (_size != 0);}

			void reserve(size_type n)
			{
				if (n <= _capacity)
					return ;
				pointer new_arr = _allocator.allocate(n);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(new_arr + i, *(_data + i));
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(new_arr + i);
				if (_capacity)
					_allocator.deallocate(_data, _capacity);
				_capacity = n;
				_data = new_arr;
			}

			void resize(size_type n, value_type val = value_type())
			{
				if (_size > n)
				{
					for (size_type i = n; i < _size; i++)
						_allocator.destroy(_data + i);
					_size = n;
				}
				else if (_size < n)
				{
					if (_capacity < n)
						reserve(_capacity * 2 > n ? _capacity * 2 : n);
					for (size_type i = 0; i < _size; i++)
						_allocator.construct(_data + i, val);
					_size = n;
				}
			}

			size_type size(void) const {return (_size);}
			size_type max_size(void) const {return (_allocator.max_size());}
			size_type capacity(void) const {return (_capacity);}

			// ELEMENT ACCESS
			pointer data(void) {return (_data);}
			const_pointer data(void) const {return (_data);}

			reference back(void) {return (*(_data + (_size - 1)));}
			reference front(void) {return (*_data);}
			reference at(size_type n)
			{
				std::stringstream err;

				if (n >= _size)
				{
					err << "vector::_M_range_check: __n (which is " <<
						n << ") >= this->size() (which is " << _size << ")";
					throw (std::out_of_range(err.str()));
				}
				return (*(_data + n));
			}
			reference operator[](size_type n) {return (*(_data + n));}

			const_reference back(void) const {return (*(_data + (_size - 1)));}
			const_reference front(void) const {return (*_data);}
			const_reference at(size_type n) const
			{
				std::stringstream err;

				if (n >= _size)
				{
					err << "vector::_M_range_check: __n (which is " <<
						n << ") >= this->size() (which is " << _size << ")";
					throw (std::out_of_range(err.str()));
				}
				return (*(_data + n));
			}
			const_reference operator[](size_type n) const {return (*(_data + n));}

			// MODIFIERS
			template<class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				if (first > last)
					throw (std::logic_error("vector"));
				clear();
				if (last - first > static_cast<difference_type>(_capacity))
					reserve(last - first);
				_size = last - first;
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(_data + i, *(first + i));
			}

			void assign(size_type n, const value_type& val)
			{
				clear();
				if (n > _capacity)
					reserve(n);
				_size = n;
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(_data + i, val);
			}

			void push_back(const value_type& val)
			{
				if (_size == _capacity || !_capacity)
					reserve(_capacity ? _capacity * 2 : 1);
				_allocator.construct(_data + _size++, val);
			}

			void insert(iterator position, size_type n, const value_type &val)
			{
				pointer tab;
				size_type i = 0;
				difference_type start;

				if(position < begin()  || position > end())
					throw (std::logic_error("vector"));
				start = position - begin();
				tab = new value_type[end() - position]();
				for (iterator it = position; it < end(); it++)
					tab[i++] = *it;
				if (_size == _capacity || _size + n > _capacity)
					reserve(_capacity ? _capacity * 2 : n);
				for (size_type i = 0; i < n; i++)
				{
					*(_data + start++) = val;
					_size++;
				}
				i = 0;
				for (iterator it = position + n; it != end(); it++)
					*it = tab[i++];
				delete [] tab;
			}

			void pop_back(void) {if (_size) _size--;}

			void clear(void)
			{
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_data + i);
				_size = 0;
			}

			void erase(iterator position)
			{
				pointer tab;
				size_type i = 0;
				difference_type start;
				
				if (position < begin() || position >= end())
					throw (std::logic_error("vector"));
				start = position - beign();
				tab = new value_type[end() - position - 1]();
				for (iterator it = position + 1; it != end(); it++)
					tab[i++] = *it;
				_size--;
				_allocator.destroy(_data + position);
			}

			iterator insert(iterator position, const value_type &val)
			{
				value_type tmp1;
				value_type tmp2;
				difference_type start;

				if(position < begin()  || position > end())
					throw (std::logic_error("vector"));
				start = position - begin();
				if (_size == _capacity)
					reserve(_capacity ? _capacity * 2 : 1);
				tmp1 = *(_data + start);
				_allocator.construct(_data + start, val);
				_size++;
				while (_data + (++start) != end())
				{
					tmp2 = *(_data + start);
					_allocator.construct(_data + start, tmp1);
					tmp1 = tmp2;
				}
				return (position);
			}

			template<class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last)
			{
				size_t i = 0;
				pointer tab;
				difference_type n;
				difference_type start;

				if(position < begin()  || position > end()
					|| first > last || last < first)
					throw (std::logic_error("vector"));
				n = last - first;
				start = position - begin();
				tab = new value_type[end() - position]();
				for (iterator it = position; it < end(); it++)
					tab[i++] = *it;
				if (_size == _capacity || _size + n > _capacity)
					reserve(_capacity ? _capacity * 2 : n);
				for (; first < last; first++)
					_data[start++] = *first;
				_size += n;
				i = 0;
				for (iterator it = position + n; it != end(); it++)
					*it = tab[i++];
				delete [] tab;
			}

		private:
			pointer _data;
			size_type _size;
			size_type _capacity;
			allocator_type _allocator;
	};
}
