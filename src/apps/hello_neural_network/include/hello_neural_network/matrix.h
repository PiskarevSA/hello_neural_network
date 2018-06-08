#pragma once

#include <array>

template <std::size_t M, std::size_t N, typename T>
struct Matrix
{
    template<std::size_t L, std::size_t MM, std::size_t NN, typename TT>
    friend Matrix<L, NN, TT> operator*(const Matrix<L, MM, TT>& m1,
                                        const Matrix<MM, NN, TT>& m2);

    T value(std::size_t row, std::size_t col) const {
        return values[row * N + col];}

    void setValue(std::size_t row, std::size_t col, T value) {
        values[row * N + col] = value;}

    std::array<T, M * N> values;
};

template <std::size_t L, std::size_t M, std::size_t N, typename T>
Matrix<L, N, T> operator*(const Matrix<L, M, T>& m1, const Matrix<M, N, T>& m2)
{
    Matrix<L, N, T> result;
    for (std::size_t row = 0; row < L; ++row) {
        for (std::size_t col = 0; col < N; ++col) {
            T sum{};
            for (std::size_t i = 0; i < M; ++i)
                sum += m1.value(row, i) * m2.value(i, col);
            result.setValue(row, col, sum);
        }
    }
    return result;
}
