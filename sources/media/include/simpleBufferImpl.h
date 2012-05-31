/** 
* @file
* Definition of SimpleBuffer class template
*
* Provides functions to convert signal into its spectrum using Fast Fourier Transform algorithm
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __SIMPLE_BUFFER_IMPL_H__
#define __SIMPLE_BUFFER_IMPL_H__

template <typename T, class CONTAINER>
SimpleBuffer<T, CONTAINER>::SimpleBuffer(const T* data, unsigned int count, size_t elSize) throw(...)
{
	set(data, count, elSize);
}


template <typename T, class CONTAINER>
inline const CONTAINER& SimpleBuffer<T, CONTAINER>::get() const throw(...)
{
	if (!buffer_.get())
		buffer_ = std::auto_ptr<CONTAINER>(new CONTAINER); /// new may throw bad alloc

	return *buffer_;
}


template <typename T, class CONTAINER>
inline CONTAINER& SimpleBuffer<T, CONTAINER>::getWritable() throw(...)
{
	return const_cast<CONTAINER&>(get());
}


template <typename T, class CONTAINER>
void SimpleBuffer<T, CONTAINER>::set(const T* data, unsigned int count, size_t elSize) throw(...)
{
	if (buffer_.get())
		clear();
	else
		buffer_ = std::auto_ptr<CONTAINER>(new CONTAINER); /// new may throw bad alloc
	
	if (!buffer_.get())
		throw std::bad_alloc();

	// buffer_->assign(data, data + count); /// that would be little faster but is not fully safe ("cutting" effect) and cannot be used with every container type

	for (unsigned int i=0; i<count; ++i)
		buffer_->insert(buffer_->end(), *(reinterpret_cast<const char*>(data) + elSize*i)); /// avoids "cutting" effect when T is base class and "data" points to derived class array
}


template <typename T, class CONTAINER>
inline unsigned int SimpleBuffer<T, CONTAINER>::getSize() const throw()
{
	if (!buffer_.get())
		return 0;

	return buffer_->size();
}


template <typename T, class CONTAINER>
inline void SimpleBuffer<T, CONTAINER>::clear() throw()
{
	if (buffer_.get())
		return buffer_->clear();
}

#endif