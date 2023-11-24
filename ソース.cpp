#include <iostream>
#include <array>

//VC Can't compile this.

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