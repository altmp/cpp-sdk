#pragma once

#define _USE_MATH_DEFINES

#include <cstddef>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <ostream>

namespace alt
{
    static constexpr double PI = M_PI;
    static constexpr double TWO_PI = 2 * PI;

    template<class T, std::size_t W>
    class VectorLayout
    {
    public:
        using Element = T;

        static const std::size_t Width = W;

        VectorLayout() : elements{ 0 } { };
        VectorLayout(const Element(&_elements)[Width]) {
            for (size_t i = 0; i < Width; i++)
            {
                elements[i] = _elements[i];
            }
        };
        VectorLayout(const Element& el) { };

        template <typename... Args, typename = typename std::enable_if<sizeof...(Args) == Width>::type>
        VectorLayout(const Args&... args) : elements{ Element(args)... } { }

        template<class ULayout, typename = typename std::enable_if<ULayout::Width >= Width>::type>
        VectorLayout(const ULayout& _layout)
        {
            std::copy(&_layout[0], &_layout[Width], elements);
        }

        Element& operator[](std::size_t key) { return elements[key]; };
        const Element& operator[](std::size_t key) const { return elements[key]; };

        friend std::ostream& operator<<(std::ostream& stream, const VectorLayout& layout)
        {
            stream << "Vector<" << typeid(Element).name() << ", " << Width << ">{ ";

            for (std::size_t i = 0; i < Width; ++i)
            {
                if (i != 0) stream << ", ";
                stream << layout.elements[i];
            }

            return stream << " }";
        }

    private:
        Element elements[Width];
    };

    template<class T, std::size_t W>
    class VectorLayoutAligned
    {
    public:
        using Element = T;

        static const std::size_t Width = W;

        VectorLayoutAligned() : elements{ 0 } { };
        VectorLayoutAligned(const Element(&_elements)[Width]) {
            for (size_t i = 0; i < Width; i++)
            {
                elements[i] = _elements[i];
            }
        };
        VectorLayoutAligned(const Element& el) { };

        template <typename... Args, typename = typename std::enable_if<sizeof...(Args) == Width>::type>
        VectorLayoutAligned(const Args&... args) : elements{ Element(args)... } { }

        template<class ULayout, typename = typename std::enable_if<ULayout::Width >= Width>::type>
        VectorLayoutAligned(const ULayout& _layout)
        {
            std::copy(&_layout[0], &_layout[Width], elements);
        }

        Element& operator[](std::size_t key) { return elements[key]; };
        const Element& operator[](std::size_t key) const { return elements[key]; };

        friend std::ostream& operator<<(std::ostream& stream, const VectorLayoutAligned& layout)
        {
            stream << "Vector<" << typeid(Element).name() << ", " << Width << ">{ ";

            for (std::size_t i = 0; i < Width; ++i)
            {
                if (i != 0) stream << ", ";
                stream << layout.elements[i];
            }

            return stream << " }";
        }

    private:
        alignas(16) Element elements[Width];
    };

    template<class T, std::size_t W, class _Layout = VectorLayout<T, W>>
    class Vector : public _Layout
    {
    public:
        using Layout = _Layout;
        using Element = T;

        static const std::size_t Width = Layout::Width;

        Vector() = default;
        Vector(const T(&_elements)[W]) : Layout{ _elements } { };
        Vector(const Layout& layout) : Layout{ layout } { };

        template <typename... Args, typename = typename std::enable_if<sizeof...(Args) == Width>::type>
        Vector(const Args&... args) : Layout{ Element(args)... } { }

        template<class ULayout, typename = typename std::enable_if<ULayout::Width >= Width>::type>
        Vector(const ULayout& _layout) : Layout{ _layout } { }

        T LengthSqr()
        {
            T result = 0;

            for (std::size_t i = 0; i < Width; ++i)
                result += ((*this)[i] * (*this)[i]);

            return result;
        }

        T Length()
        {
            return sqrt(LengthSqr());
        }

        friend Vector& operator-=(Vector& lhs, const Vector& rhs)
        {
            for (std::size_t i = 0; i < Width; ++i)
                lhs[i] -= rhs[i];

            return lhs;
        }

        friend Vector operator-(const Vector& lhs, const Vector& rhs)
        {
            Vector result = lhs;
            return (result -= rhs);
        }

        bool operator==(const Vector& other) const
        {
            if (Width != other.Width)
                return false;

            for (std::size_t i = 0; i < Width; ++i)
            {
                if ((*this)[i] != other[i])
                    return false;
            }

            return true;
        }

        bool operator!=(const Vector& other) const
        {
            return !(*this == other);
        }
    };

    template<class T, std::size_t W, class _Layout = VectorLayoutAligned<T, W>>
    class VectorAligned : public _Layout
    {
    public:
        using Layout = _Layout;
        using Element = T;

        static const std::size_t Width = Layout::Width;

        VectorAligned() = default;
        VectorAligned(const T(&_elements)[W]) : Layout{ _elements } { };
        VectorAligned(const Layout& layout) : Layout{ layout } { };

        template <typename... Args, typename = typename std::enable_if<sizeof...(Args) == Width>::type>
        VectorAligned(const Args&... args) : Layout{ Element(args)... } { }

        template<class ULayout, typename = typename std::enable_if<ULayout::Width >= Width>::type>
        VectorAligned(const ULayout& _layout) : Layout{ _layout } { }

        T LengthSqr()
        {
            T result = 0;

            for (std::size_t i = 0; i < Width; ++i)
                result += ((*this)[i] * (*this)[i]);

            return result;
        }

        T Length()
        {
            return sqrt(LengthSqr());
        }

        friend VectorAligned& operator-=(VectorAligned& lhs, const VectorAligned& rhs)
        {
            for (std::size_t i = 0; i < Width; ++i)
                lhs[i] -= rhs[i];

            return lhs;
        }

        friend VectorAligned operator-(const VectorAligned& lhs, const VectorAligned& rhs)
        {
            VectorAligned result = lhs;
            return (result -= rhs);
        }
    };

    template<class T> using Vector2 = Vector<T, 2>;
    using Vector2f = Vector2<float>;
    using Vector2i = Vector2<int>;

    template<class T> using Vector3 = Vector<T, 3>;
    using Vector3f = Vector3<float>;
    using Vector3i = Vector3<int>;

    template<class T> using Vector4 = Vector<T, 4>;
    using Vector4f = Vector4<float>;
    using Vector4i = Vector4<int>;

    template<class T, std::size_t W, std::size_t H>
    class MatrixLayout
    {
    public:
        using Row = Vector<T, W>;
        using Element = typename Row::Element;
        using Transposed = MatrixLayout<T, H, W>;

        static const std::size_t Width = Row::Width;
        static const std::size_t Height = H;

        MatrixLayout() = default;
        MatrixLayout(const Row(&_rows)[Height]) { std::copy(_rows, &_rows[Height], rows); };

        MatrixLayout(const Row& row) : rows{ row } { };

        MatrixLayout(const Element(&elements)[Width * Height])
        {
            std::copy((Row*)elements, &((Row*)elements)[Height], rows);
        };

        template<class... Args, typename = typename std::enable_if<sizeof...(Args) == Height>::type>
        MatrixLayout(const Args&... args) : rows{ Row(args)... } { }

        template<class ULayout, typename = typename std::enable_if<ULayout::Height == Height>::type>
        MatrixLayout(const ULayout& _layout)
        {
            std::copy(&_layout[0], &_layout[Height], rows);
        }

        Row& operator[](std::size_t key) { return rows[key]; };
        const Row& operator[](std::size_t key) const { return rows[key]; };

        friend std::ostream& operator<<(std::ostream& stream, const MatrixLayout& layout)
        {
            stream << "\nMatrix<" << typeid(Element).name() << ", " << W << ", " << H << ">{\n";

            for (std::size_t i = 0; i < H; ++i)
            {
                if (i != 0) stream << ",\n";
                stream << "  ";
                for (std::size_t j = 0; j < W; ++j)
                {
                    if (j != 0) stream << ", ";
                    stream << layout.rows[i][j];
                }
            }

            return stream << "\n}\n";
        }

    private:
        Row rows[Height];
    };

    template<class T, std::size_t W, std::size_t H, class _Layout = MatrixLayout<T, W, H>>
    class Matrix : public _Layout
    {
    public:
        using Layout = _Layout;
        using Row = typename Layout::Row;
        using Element = typename Layout::Element;
        using Transposed = Matrix<T, H, W, typename Layout::Transposed>;

        static const std::size_t Width = Layout::Width;
        static const std::size_t Height = Layout::Height;

        Matrix() = default;
        Matrix(const Row(&rows)[Height]) : Layout{ rows } { };

        Matrix(const Row& row) : Layout{ row } { };

        Matrix(const Element(&elements)[Width * Height]) : Layout{ elements } { };

        template<class... Args, typename = typename std::enable_if<sizeof...(Args) == Height>::type>
        Matrix(const Args&... args) : Layout{ Row(args)... } { }

        template<class ULayout, typename = typename std::enable_if<ULayout::Height == Height>::type>
        Matrix(const ULayout& _layout) : Layout{ _layout } { }

        Transposed Transpose()
        {
            Transposed mx;

            for (std::size_t i = 0; i < W; ++i)
                for (std::size_t j = 0; j < H; ++j)
                    mx[i][j] = (*this)[j][i];

            return mx;
        }
    };

    using DXMatrix = Matrix<float, 4, 4>;

    class PointLayout
    {
    public:
        using Element = float;

        static const std::size_t Width = 3;

        PointLayout() : x{ 0 }, y{ 0 }, z{ 0 } { };
        PointLayout(float _x, float _y, float _z) : x{ _x }, y{ _y }, z{ _z } { }
        PointLayout(const float(&elements)[Width]) : x{ elements[0] }, y{ elements[1] }, z{ elements[2] } { }

        template<class ULayout, typename = typename std::enable_if<ULayout::Width >= Width>::type>
        PointLayout(const ULayout& _layout)
        {
            std::copy(&_layout[0], &_layout[Width], &x);
        }

        float& operator[](std::size_t key) { return (&x)[key]; };
        const float& operator[](std::size_t key) const { return (&x)[key]; };

        friend std::ostream& operator<<(std::ostream& stream, const PointLayout& layout)
        {
            return stream << "Point{ x: " << layout.x << ", y: " << layout.y << ", z: " << layout.z << " }";
        }

        float x, y, z;
    };

    class alignas(16) PointLayoutAligned
    {
    public:
        using Element = float;

        static const std::size_t Width = 3;

        PointLayoutAligned() : x{ 0 }, y{ 0 }, z{ 0 } { };
        PointLayoutAligned(float _x, float _y, float _z) : x{ _x }, y{ _y }, z{ _z } { }
        PointLayoutAligned(const float(&elements)[Width]) : x{ elements[0] }, y{ elements[1] }, z{ elements[2] } { }

        template<class ULayout, typename = typename std::enable_if<ULayout::Width >= Width>::type>
        PointLayoutAligned(const ULayout& _layout)
        {
            std::copy(&_layout[0], &_layout[Width], &x);
        }

        float& operator[](std::size_t key) { return (&x)[key]; };
        const float& operator[](std::size_t key) const { return (&x)[key]; };

        friend std::ostream& operator<<(std::ostream& stream, const PointLayoutAligned& layout)
        {
            return stream << "Point{ x: " << layout.x << ", y: " << layout.y << ", z: " << layout.z << " }";
        }

        float x, y, z;
    };

    class PointPaddedLayout : public PointLayout
    {
    public:
        PointPaddedLayout() = default;
        PointPaddedLayout(float x, float y, float z) : PointLayout{ x, y, z } { }
        PointPaddedLayout(const float(&elements)[Width]) : PointLayout{ elements } { }

        template<class ULayout>
        PointPaddedLayout(const ULayout& layout) : PointLayout{ layout } { }

    private:
        float pad = 0.f;
    };

    using Point = Vector<float, 3, PointLayout>;
    using PointPadded = Vector<float, 3, PointPaddedLayout>;
    using PointAligned = VectorAligned<float, 3, PointLayoutAligned>;

    using Position = Point;
    using PositionPadded = PointPadded;
    using PositionAligned = PointAligned;

    class RotationLayout
    {
    public:
        using Element = float;

        static const std::size_t Width = 3;

        RotationLayout(float _roll, float _pitch, float _yaw) : roll{ Normalize(_roll) }, pitch{ Normalize(_pitch) }, yaw{ Normalize(_yaw) } { }
        RotationLayout() : RotationLayout(0, 0, 0) { };
        RotationLayout(const float(&elements)[Width]) : RotationLayout(elements[0], elements[1], elements[2]) { }

        template<class ULayout, typename = typename std::enable_if<ULayout::Width >= Width>::type>
        RotationLayout(const ULayout& _layout)
        {
            std::copy(&_layout[0], &_layout[Width], &roll);
        }

        float& operator[](std::size_t key) { return (&roll)[key]; };
        const float& operator[](std::size_t key) const { return (&roll)[key]; };

        friend std::ostream& operator<<(std::ostream& stream, const RotationLayout& layout)
        {
            return stream << "Rotation{ roll: " << layout.roll << ", pitch: " << layout.pitch << ", yaw: " << layout.yaw << " }";
        }

        void Normalize()
        {
            roll = Normalize(roll);
            pitch = Normalize(pitch);
            yaw = Normalize(yaw);
        }

        float roll, pitch, yaw;

    private:
        static float Normalize(float ang)
        {
            return (float)(fmod(fmod(ang - PI, TWO_PI) + TWO_PI, TWO_PI) - PI);
        }
    };

    class RotationPaddedLayout : public RotationLayout
    {
    public:
        RotationPaddedLayout() = default;
        RotationPaddedLayout(float roll, float pitch, float yaw) : RotationLayout{ roll, pitch, yaw } { }
        RotationPaddedLayout(const float(&elements)[Width]) : RotationLayout{ elements } { }

        template<class ULayout>
        RotationPaddedLayout(const ULayout& layout) : RotationLayout{ layout } { }

    private:
        float pad = 0.f;
    };

    using Rotation = Vector<float, 3, RotationLayout>;
    using RotationPadded = Vector<float, 3, RotationPaddedLayout>;

    class Quaternion
    {
    public:
        float x = 0.f;
        float y = 0.f;
        float z = 0.f;
        float w = 0.f;

        Quaternion() = default;
        Quaternion(float _x, float _y, float _z, float _w): x(_x),y(_y),z(_z),w(_w) {}
    };

    class ViewMatrixLayout
    {
    public:
        using Row = Vector4f;
        using Element = typename Row::Element;
        using Transposed = ViewMatrixLayout;

        static const std::size_t Width = Row::Width;
        static const std::size_t Height = 4;

        ViewMatrixLayout() = default;
        ViewMatrixLayout(const Row(&_rows)[Height]) { std::copy(_rows, &_rows[Height], &right); };

        ViewMatrixLayout(const Row& row) : right{ row } { };

        ViewMatrixLayout(const Element(&elements)[Width * Height])
        {
            std::copy((Row*)elements, &((Row*)elements)[Height], &right);
        };

        ViewMatrixLayout(const Vector4f& _right, const Vector4f& _up, const Vector4f& _forward, const Vector4f& _pos) : right{ _right }, up{ _up }, forward{ _forward }, pos{ _pos } { }

        template<class ULayout, typename = typename std::enable_if<ULayout::Height == Height>::type>
        ViewMatrixLayout(const ULayout& _layout)
        {
            std::copy(&_layout[0], &_layout[Height], &right);
        }

        Row& operator[](std::size_t key) { return (&right)[key]; };
        const Row& operator[](std::size_t key) const { return (&right)[key]; };

        friend std::ostream& operator<<(std::ostream& stream, const ViewMatrixLayout& layout)
        {
            return stream << "\nViewMatrix{"
                << "\n  right:   " << layout.right
                << "\n  up:      " << layout.up
                << "\n  forward: " << layout.forward
                << "\n  pos:     " << layout.pos
                << "\n}\n";
        }

        Vector4f right, up, forward, pos;
    };

    using ViewMatrix = Matrix<float, 4, 4, ViewMatrixLayout>;

    inline bool IsValidCoord(float val)
	{
		static float MIN_COORD = -32768.f;
		static float MAX_COORD = 32767.f;

		return !std::isnan(val) && !std::isinf(val) && val <= MAX_COORD && val >= MIN_COORD;
	}

    inline bool IsValidPosition(const Position& p)
    {
		return IsValidCoord(p.x) && IsValidCoord(p.y) && IsValidCoord(p.z);
    }
}
