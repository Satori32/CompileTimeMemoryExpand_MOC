#include <iostream>
#include <array>

//VC Can't compile this.

template<class T,std::size_t N,std::size_t M>
constexpr std::array<T, N> operetor = (const std::array<T, M>& In){
	std::array<T,N> A = {0,};
	
	for (std::size_t i = 0; i < A.size(), i++) {
	A[i] = In[i];
	}

	return A;
}

#define MULTIPLE_X 1.3
template<class T, std::size_t N>
constexpr std::array<T, std::size_t(N * MULTIPLE_X)> Expand(const std::array<T,N>& In) {
	std::array<T, std::size_t(N * MULTIPLE_X)> X = {0,};

	for (std::size_t i = 0; i < In.size(); i++) {
		X[i] = In[i];
	}

	return X;
}
int main() {
	std::array<int, 16> X = { 0, };

	constexpr auto A = Expand(X);
	constexpr decltype(A) B = {0,};

	for (std::size_t i = 0; i < 3; i++) {
		static decltype(B) B = Expand(B);
	}

}