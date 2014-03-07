/*!
 * \file Singleton.hpp
 * \brief File containing the declaration of the Singleton template class.
 */

#ifndef SINGLETON_HPP_
#define SINGLETON_HPP_

#include <boost/utility.hpp>
#include <boost/thread/once.hpp>
#include <boost/scoped_ptr.hpp>

/*!
 * \class Singleton
 * \brief Template singleton class, implemented in a Boost-singleton manner.
 * Object is stored in scoped_ptr and instance initialization is protected by Boost::call_once.
 * Warning: If T's constructor throws, instance() will return a null reference.
 */
namespace Templates {
	template<class T>
	class Singleton : private boost::noncopyable
	{
	public:
	   /*!
		* Method returns a non-copyable reference to stored object instance.
		*/
		static T& instance()
		{
    		// Initialize object only once.
			//std::cout<<std::endl<<"singleton instance called"<<std::endl<<std::endl;
			boost::call_once(initSingleton, flag);
			// Return reference to object.
			return *t;
		}
	protected:
		Singleton() {}
		//virtual ~Singleton() {}
		~Singleton() {}
	private:
		/*!
		 * Method initializates the object and calls it's constructor.
		 */
		static void initSingleton()
		{
    		// Call constructor of the T object.
			//std::cout<<std::endl<<"singleton init called"<<std::endl<<std::endl;
			t.reset(new T());
		}
		static boost::scoped_ptr<T> t;
		static boost::once_flag flag;
	};
}
/*!
 * Initialization of scoped pointer.
 */
template<class T> boost::scoped_ptr<T> Templates::Singleton<T>::t(0);

/*!
 * Initialization of once_flag.
 */
template<class T> boost::once_flag Templates::Singleton<T>::flag = BOOST_ONCE_INIT;

#endif /* SINGLETON_HPP_ */
