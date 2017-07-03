
///	Random class - random number generator
#ifndef _Random_H
#define _Random_H
class Random {
	private:
		long int state;

		static const long int A = 48271;
        static const long int M = 2147483647;
        static const long int Q = 44488;
        static const long int R = 3399;

	public:
		/// Constructors
		explicit Random();

		/// @return [0,1] Within the range of random numbers
		double NextDouble();
		int NextInt();
};

#endif
