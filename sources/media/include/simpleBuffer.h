/** 
* @file
* Declaration of SimpleBuffer class
*
* It represents abstract data buffer
*/

/// Lukasz Rychter
/// Maciej Sikora

#ifndef __SIMPLE_BUFFER_H__
#define __SIMPLE_BUFFER_H__

#include <vector>

namespace media /// namespace for media processing modules
{

/// Declaration of class template representing abstract data buffer
template <typename T, class CONTAINER=std::vector<T> > /// CONTAINER may be STL's vector, deque, list, set, multiset, map, multimap or another compatible class template
class SimpleBuffer
{
public:
	SimpleBuffer() throw() {}; /// default constructor - construct empty buffer
	SimpleBuffer(const T* data, unsigned int count, size_t elSize=sizeof(T)) throw(...); /// constructor that allows to set buffer content. elSize may be used to fix "cutting" problem - when size of T is less than real object size pointed by "data". May throw bad_alloc
	
	inline const CONTAINER&		get() const throw(...); /// gets const reference (read only) to the container. May throw bad_alloc
	inline CONTAINER&			getWritable() throw(...); /// gets writable reference to the container. May throw bad_alloc
	void						set(const T* data, unsigned int count, size_t elSize=sizeof(T)) throw(...); /// allows to set buffer content. elSize may be used to fix "cutting" problem - when size of T is less than real object size pointed by "data". May throw bad_alloc

	inline unsigned int			getSize() const throw(); /// returns number of elements
	inline void					clear() throw(); /// removes buffer contents

	inline unsigned char		getElementSize() const throw() { return sizeof(T); }; /// returns size of the element

	typedef T element_type;

protected:
	mutable std::auto_ptr<CONTAINER> buffer_;  /// mutable set because of get function
};

#include "simpleBufferImpl.h"

}; //namespace

#endif
