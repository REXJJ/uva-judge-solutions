#include <bits/stdc++.h>

using namespace std;

void print(){}
template<typename T,typename... Args>
void print(T Contents, Args... args) 
{
#ifdef DBG
	std::cout<< (Contents) << std::endl;print(args...);
#endif
}

// template <int N>
// struct Factorial 
// {
//      static constexpr int value = N * Factorial<N - 1>::value;
// };

// template <>
// struct Factorial<0> 
// {
//     static constexpr int value = 1;
// };


// template <int N>
// struct Expand 
// {
//      static constexpr std::array<int,1> value = {Factorial<N>::value};
// };

template <int N>
constexpr int metafactorial()
{
     return N * metafactorial<N - 1>();
}

template <>
constexpr int metafactorial<0>() 
{
    return 1;
}

template <int I>
struct squared {
    squared<I - 1> rest;
    int x;
    squared() : x((I - 1) * (I - 1)) {}
};

template <>
struct squared<1> {
    int x;
    squared() : x(0) {}
};

const int ARRAY_SIZE = 5;

template <int N, int I=N-1>
class Table : public Table<N, I-1>
{
public:
    static const int dummy;
};

template <int N>
class Table<N, 0>
{
public:
    static const int dummy;
    static int array[N];
};

template <int N, int I>
const int Table<N, I>::dummy = Table<N, 0>::array[I] = I*I + 0*Table<N, I-1>::dummy;

template <int N>
int Table<N, 0>::array[N];

template class Table<ARRAY_SIZE>;



int main()
{
	const int *compilerFilledArray = Table<ARRAY_SIZE>::array;
    for (int i=0; i < ARRAY_SIZE; ++i)
        std::cout<<compilerFilledArray[i]<<std::endl;
	int n;
	cin>>n;
	std::array<int,1> value = {metafactorial<5>()};
	squared<5> s;
	cout << "3 squared is " << reinterpret_cast<int*>(&s)[3] << endl;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		int ans=value[0];
		cout<<ans<<endl;
	}
	
	return 0;
}
