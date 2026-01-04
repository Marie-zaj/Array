#pragma once
template <typename T>
class Array
{
    T* m_data;
    int m_size;
    int m_capacity;
    int m_grow;

public:
    Array()
    {
        m_data = nullptr;
        m_size = 0;
        m_capacity = 0;
        m_grow = 1;
    }

    ~Array()
    {
        delete[] m_data;
    }

    int GetSize() const
    {
        return m_size;
    }

    void SetSize(int size, int grow = 1)
    {
        if (grow > 0)
            m_grow = grow;

        if (size <= m_capacity)
            return;

        T* newData = new T[size];

        for (int i = 0; i < m_size; i++)
            newData[i] = m_data[i];

        delete[] m_data;
        m_data = newData;
        m_capacity = size;
    }

    int GetUpperBound() const
    {
        return m_size - 1;
    }

    bool IsEmpty() const
    {
        return m_size == 0;
    }

    void FreeExtra()
    {
        if (m_size == m_capacity)
            return;

        T* newData = new T[m_size];

        for (int i = 0; i < m_size; i++)
            newData[i] = m_data[i];

        delete[] m_data;
        m_data = newData;
        m_capacity = m_size;
    }

    void RemoveAll()
    {
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
        m_capacity = 0;
    }

    T GetAt(int index) const
    {
        return m_data[index];
    }

    void SetAt(int index, const T& value)
    {
        if (index < m_size)
            m_data[index] = value;
    }

    T& operator[](int index)
    {
        return m_data[index];
    }
    void Add(const T& value)
    {
        if (m_size >= m_capacity)
            SetSize(m_size + m_grow, m_grow);

        m_data[m_size] = value;
        m_size++;
    }

    void Append(const Array<T>& other)
    {
        for (int i = 0; i < other.m_size; i++)
            Add(other.m_data[i]);
    }

    Array<T>& operator=(const Array<T>& other)
    {
        if (this == &other)
            return *this;

        delete[] m_data;

        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_grow = other.m_grow;

        m_data = new T[m_capacity];

        for (int i = 0; i < m_size; i++)
            m_data[i] = other.m_data[i];

        return *this;
    }

    T* GetData()
    {
        return m_data;
    }

    void InsertAt(int index, const T& value)
    {
        if (index < 0|| index > m_size)
            return;

        Add(value);
        for (int i = m_size - 1; i > index; i--)
            m_data[i] = m_data[i - 1];

        m_data[index] = value;
    }

    void RemoveAt(int index)
    {
        if (index < 0 || index >= m_size)
            return;

        for (int i = index; i < m_size - 1; i++)
            m_data[i] = m_data[i + 1];

        m_size--;
    }
};