#ifndef UTILS_HPP
# define UTILS_HPP

namespace	ft
{
	/**
	 * Enable_if.
	 *
	 * (Substitution Failure Is Not An Error).
	 */
	template< bool B, class T = void >
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	/**
	 * Is_integral.
	 *
	 * Checks whether T is an integral type.
	 */
	template<class Type>
    struct is_integral
    {
        static const bool value = false;
    };

	template<>
	struct is_integral<bool>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<char>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<signed char>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<wchar_t>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<short>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned short>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<int>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<long>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned long>
    {
        static const bool value = true;
    };
    
    template<>
    struct is_integral<float>
    {
        static const bool value = false;
    };

    template<>
    struct is_integral<double>
    {
        static const bool value = false;
    };

    template<>
    struct is_integral<long double>
    {
        static const bool value = false;
    };
}

#endif
