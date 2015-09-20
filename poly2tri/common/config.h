#ifndef CONFIG_H
#define CONFIG_H

#if defined(_WIN32) && defined(_MSC_VER)
#	if defined(POLY2TRI_LIBRARY)
#		define KAKA_EXPORT __declspec(dllexport)
#	else
#		define KAKA_EXPORT __declspec(dllimport)
#	endif
#else
#		define KAKA_LIBRARY
#endif

#endif // CONFIG_H

