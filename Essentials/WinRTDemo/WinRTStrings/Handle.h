#pragma once

template<typename Traits>
class Handle
{
    using Pointer = typename Traits::Pointer;

    Pointer m_value;

    void Close() noexcept
    {
        if (*this)
        {
            Traits::Close(m_value);
        }
    }

public:

    Handle(Handle const &) = delete;
    Handle & operator=(Handle const &) = delete;

    explicit Handle(Pointer value = Traits::Invalid()) noexcept:
    m_value(value)
    {

    }

    Handle(Handle && other) noexcept:
    m_value(other.Detach())
    {

    }

    Handle & operator=(Handle && other) noexcept
    {
        if (this != &other)
        {
            Attach(other.Detach());
        }

        return *this;
    }

    ~Handle() noexcept
    {
        Close();
    }

    explicit operator bool() const noexcept
    {
        return m_value != Traits::Invalid();
    }

    Pointer Get() const noexcept
    {
         return m_value;
    }

    Pointer * GetAddressOf() noexcept
    {
        ASSERT(!*this);
        return &m_value;
    }

    Pointer Detach() noexcept
    {
        Pointer value = m_value;
        m_value = Traits::Invalid();
        return value;
    }

    bool Attach(Pointer value = Traits::Invalid()) noexcept
    {
        if (m_value != value)
        {
            Close();
            m_value = value;
        }

        return static_cast<bool>(*this);
    }

    void Swap(Handle & other) noexcept
    {
        std::swap(m_value, other.m_value);
    }
};

template<typename Traits>
void swap(Handle<Traits> &left,
          Handle<Traits> &right) noexcept
{
    left.Swap(right);
}